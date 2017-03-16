import sys

def main():
  filename = sys.argv[1]
  fileIn = open(filename, 'r')
  fileOut = open("out.txt", 'w')
  T = int(fileIn.readline())
  for case in range(T):
    firstChoice = int(fileIn.readline())
    firstGrid = []
    firstGrid.append(map(int,fileIn.readline().split(' ')))
    firstGrid.append(map(int,fileIn.readline().split(' ')))
    firstGrid.append(map(int,fileIn.readline().split(' ')))
    firstGrid.append(map(int,fileIn.readline().split(' ')))
    secondChoice = int(fileIn.readline())
    secondGrid = []
    secondGrid.append(map(int,fileIn.readline().split(' ')))
    secondGrid.append(map(int,fileIn.readline().split(' ')))
    secondGrid.append(map(int,fileIn.readline().split(' ')))
    secondGrid.append(map(int,fileIn.readline().split(' ')))
    answer = solveCase(firstChoice,firstGrid,secondChoice,secondGrid)
    fileOut.write("Case #"+str(case+1)+": "+answer+"\n")
  fileOut.close()
  fileIn.close()

def solveCase(firstChoice,firstGrid,secondChoice,secondGrid):
  firstOptions = set(firstGrid[firstChoice-1])
  secondOptions = set(secondGrid[secondChoice-1])
  intersection = firstOptions.intersection(secondOptions)
  l = len(intersection)
  if l == 1:
    return str(intersection.pop())
  elif l > 0:
    return "Bad magician!"
  else:
    return "Volunteer cheated!"

main()
