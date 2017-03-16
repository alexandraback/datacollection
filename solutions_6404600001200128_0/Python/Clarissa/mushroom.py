
import fileinput

def calculateAnyNumber(values):
    totalEaten = 0
    for i in range(len(values)-1):
        if values[i] > values[i+1]:
            totalEaten += values[i] - values[i+1]
    return totalEaten
            
def calculateLinear(values):
    maxRate = 0
    for i in range(len(values)-1):
        difference = values[i] - values[i+1]
        if difference > maxRate:
            maxRate = difference
    
    totalEaten = 0
    for i in range(len(values)-1):
        if values[i] < maxRate:
            totalEaten += values[i]
        else:
            totalEaten += maxRate
    return totalEaten 
    
def main():
    firstLine = True
    count = 1
    skipLine = True #firstLine will cover the first line
    
    for line in fileinput.input():
        skipLine = not skipLine
        if firstLine:
            firstLine = False
            continue
        elif skipLine:
            continue
        
        values = [int(num) for num in line.split()]
        anyEaten = calculateAnyNumber(values)
        linearEaten = calculateLinear(values)
        
        print("Case #" + str(count) + ": " + str(anyEaten) + " " \
            + str(linearEaten))
        count += 1
          
main()