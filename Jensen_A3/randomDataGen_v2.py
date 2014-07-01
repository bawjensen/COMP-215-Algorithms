import random, os, math

MIN_ELEV = 1000
MAX_ELEV = 2000


def main():
	for i in xrange(2,22):
		numElements = int(i/2) * 100000
		print "Making new file with", numElements, "elements"

		height = int(math.sqrt(numElements))
		width = int(math.sqrt(numElements))

		print "Dimensions: %i, %i" % (width, height)

		fileString = ''
		elevArray = []

		fileString += 'ncols ' + str(width) + '\n'
		fileString += 'nrows ' + str(height) + '\n'
		fileString += 'xllcorner 0.0\n'
		fileString += 'yllcorner 0.0\n'
		fileString += 'cellsize 10.0\n'

		for i in xrange(height*width):
			value = ( (MAX_ELEV-MIN_ELEV)*random.random() ) + MIN_ELEV
			elevArray.append(value)

		currentCol = 0
		currentRow = 0
		i = 0
		while elevArray:
			fileString += str(elevArray[i])
			if currentCol >= (width-1):
				currentRow += 1
				currentCol = 0
				fileString += '\n'
			else:
				fileString += ' '

			currentCol += 1
			elevArray.pop(0)

		filePrefix = 'testFile'
		fileExt = 'grd'
		fileNum = 0
		while os.path.exists(filePrefix + str(fileNum) + '.' + fileExt):
			fileNum += 1

		fileName = filePrefix + str(fileNum) + '.' + fileExt

		with open(fileName, 'w') as outFile:
			outFile.write(fileString)

main()