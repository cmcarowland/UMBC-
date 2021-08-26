#include "Taxes.h"
	
namespace Taxes
{
	double Round(double num, int places)
	{
		double outNum = num;
		if(places > 0)
		{
			int place = 0;
			
			for(int i = 0; i < places; i ++)
			{
				if(place == 0)
				{
					place = 10;
				}
				else
				{
					place *= 10;
				}
			}
			
			outNum = round(num * place) / place;
		}
		
		return outNum;
	}

	double GetTaxAmount(double &total)
	{
		return Round(total * taxRate, 2);
	}
	
	double GetTotal(double &total)
	{
		return Round(total + GetTaxAmount(total), 2);
	}
}

