path = "C:/Users/Helge/Downloads/"
filename = "A-large.in"
input_file = open(path+filename, 'r')
output = open(path + 'output', 'w')

numberOfTestcases = input_file.readline()
def readLineList():
    return input_file.readline().replace('\n', '').split(' ')
        
    
def writeOut(s, count):
    s = 'Case #' + str(count+1) + ': ' + s
    print(s)
    output.write(s + '\n')  
    
for i in range(0, int(numberOfTestcases)):
    N = int(input_file.readline().replace('\n', ''))
    M = list(map(int, readLineList()))
    first = 0
    rate = 0
    for j in range(1,N):
        first += max(0,-M[j]+M[j-1])
        rate = max(rate,-M[j]+M[j-1])
    
    second = 0
    for j in range(1,N):
        second += min(rate,M[j-1])
        
    writeOut(str(first)+" "+str(second), i)

output.close()