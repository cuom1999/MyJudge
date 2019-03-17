from subprocess import call
from os import listdir, getcwd, remove
from os.path import isfile, join, splitext, abspath, split

LINK = split(getcwd())[0] + '\\'

def readInpTail():
	configFile = open('config.txt', 'r')
	data = list(map(str, configFile.read().split()))

	inpTail = data[1]

	return inpTail

def testcase(i):
	return 'test' + str(i) + '.txt'


if __name__ == '__main__':
	inpTail = readInpTail()

	oldPath = LINK + 'ImportTests\\TestCases\\'
	newPath = LINK + 'TestCases\\'

	# clear the TestCases folder
	for f in listdir(newPath):
		remove(join(newPath, f))

	# copy and rename files
	inpFiles = [splitext(f) for f in listdir(oldPath) if (isfile(join(oldPath, f)) and (splitext(f)[1] == inpTail))]

	for i in range(len(inpFiles)):
		f = inpFiles[i]

		curName = f[0] + f[1]
		newName = testcase(i + 1)
		call(['copy', join(oldPath, curName), join(newPath, newName)], shell = True)

	# change data in Number_Of_Tests.txt
	f = open(LINK + 'Data\\Number_Of_Tests.txt', 'w')
	f.write(str(len(inpFiles)))


