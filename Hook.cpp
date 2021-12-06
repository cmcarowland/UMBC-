#include <iostream>
#include <Windows.h>
template<typename T>
T RVA(LPVOID base, long offset)
{
	return (T)((PBYTE)base + offset);
}
using namespace std;

typedef int (_stdcall *MBA)(HWND, LPCSTR, LPCSTR, UINT);
MBA messageBoxAddress;

int _stdcall HookedMessageBox(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType) 
{
	std::cout << "Testing\n";
	std::cout << "Text: " << (LPCSTR)lpText << "\nCaption: " << (LPCSTR)lpCaption << std::endl;
	return messageBoxAddress(NULL, lpText, lpCaption, uType);
}

void ChangePtrInImportTable(string funcName, LPVOID method)
{
	LPVOID imageBase = GetModuleHandleA(NULL);
	PIMAGE_DOS_HEADER dosHeaders = (PIMAGE_DOS_HEADER)imageBase;
	PIMAGE_NT_HEADERS ntHeaders = RVA<PIMAGE_NT_HEADERS>(imageBase, dosHeaders->e_lfanew);

	PIMAGE_IMPORT_DESCRIPTOR importDescriptor = NULL;
	IMAGE_DATA_DIRECTORY importsDirectory = ntHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
	importDescriptor = RVA<PIMAGE_IMPORT_DESCRIPTOR>(imageBase, importsDirectory.VirtualAddress);
	LPCSTR libraryName = NULL;
	HMODULE library = NULL;
	PIMAGE_IMPORT_BY_NAME functionName = NULL;

	while (importDescriptor->Name != NULL)
	{
		libraryName = RVA<LPCSTR>(imageBase, importDescriptor->Name);
		library = LoadLibraryA(libraryName);

		if (library)
		{
			PIMAGE_THUNK_DATA originalFirstThunk = NULL, firstThunk = NULL;
			originalFirstThunk = RVA<PIMAGE_THUNK_DATA>(imageBase, importDescriptor->OriginalFirstThunk);
			firstThunk = RVA<PIMAGE_THUNK_DATA>(imageBase, importDescriptor->FirstThunk);

			while (originalFirstThunk->u1.AddressOfData != NULL)
			{
				functionName = RVA<PIMAGE_IMPORT_BY_NAME>(imageBase, originalFirstThunk->u1.AddressOfData);

				// find MessageBoxA address
				if (std::string(functionName->Name).compare(funcName) == 0)
				{
					SIZE_T bytesWritten = 0;
					DWORD oldProtect = 0;
					VirtualProtect((LPVOID)(&firstThunk->u1.Function), 8, PAGE_READWRITE, &oldProtect);

					// swap MessageBoxA address with address of hookedMessageBox
					firstThunk->u1.Function = (DWORD_PTR)method;
				}
				originalFirstThunk++;
				firstThunk++;
			}
		}

		importDescriptor++;
	}
}


int main()
{
	messageBoxAddress = MessageBoxA;
	
	ChangePtrInImportTable("MessageBoxA", HookedMessageBox);
	
	MessageBoxA(NULL, "hi", "HOOKED", MB_OK);

	ChangePtrInImportTable("MessageBoxA", messageBoxAddress);

	MessageBoxA(NULL, "hi", "UNHOOKED", MB_OK);

	return 0;
}
