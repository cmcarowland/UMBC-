import subprocess
process = subprocess.Popen(["git", "log", "--format=%s%n%b"], stdout=subprocess.PIPE)
output = process.communicate()[0]

lines = output.split('\n')
features = []
fixes = []
refactors = []
chores = []

for line in lines:
	if "fix: " in line:
		fixes.append(line[4:])
	elif "feat: " in line:
		features.append(line[5:])
	elif "refactor: " in line:
		refactors.append(line[10:])
	elif "chore: " in line:
		chores.append(line[7:])

oFile = open('ChangeLog.md', 'wb')
oFile.write("# Change Log\n\n")

oFile.write("## NEW\n")
for f in features:
	oFile.write('- ' + f + '\n')

oFile.write("\n## FIXES\n")
for f in fixes:
	oFile.write('- ' + f + '\n')

oFile.write("\n## Refactors\n")
for f in refactors:
	oFile.write('- ' + f + '\n')
	
oFile.write("\n## Chores\n")
for f in chores:
	oFile.write('- ' + f + '\n')
	
oFile.close()
