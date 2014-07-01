import random, os

HEIGHT = 75
WIDTH = 75

MIN_ELEV = 1000
MAX_ELEV = 2000


def main():
	fileString = ''
	elevArray = []

	fileString += 'ncols ' + str(WIDTH) + '\n'
	fileString += 'nrows ' + str(HEIGHT) + '\n'
	fileString += 'xllcorner 0.0\n'
	fileString += 'yllcorner 0.0\n'
	fileString += 'cellsize 10.0\n'

	for i in xrange(HEIGHT*WIDTH):
		value = ( (MAX_ELEV-MIN_ELEV)*random.random() ) + MIN_ELEV
		elevArray.append(value)

	currentCol = 0
	currentRow = 0
	i = 0
	while elevArray:
		fileString += str(elevArray[i])
		if currentCol >= WIDTH:
			print "Shifting rows"
			currentRow += 1
			currentCol = 0
			fileString += '\n'
		else:
			fileString += ' '

		currentCol += 1
		elevArray.pop(0)

	print fileString

	filePrefix = 'testFile'
	fileExt = 'grd'
	fileNum = 0
	while os.path.exists(filePrefix + str(fileNum) + '.' + fileExt):
		fileNum += 1

	fileName = filePrefix + str(fileNum) + '.' + fileExt

	with open(fileName, 'w') as outFile:
		outFile.write(fileString) 

main()