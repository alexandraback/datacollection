import functools

path = "C:/Users/Helge/Downloads/"
filename = "B-small-attempt1.in"
input_file = open(path+filename, 'r')
output = open(path + 'output', 'w')


numberOfTestcases = input_file.readline()
def readLineList():
    return input_file.readline().replace('\n', '').split(' ')
        
    
def writeOut(s, count):
    s = 'Case #' + str(count+1) + ': ' + s
    print(s)
    output.write(s + '\n')  

def gcd(a, b):
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

def lcmm(*args):
    return functools.reduce(lcm, args)

for i in range(0, int(numberOfTestcases)):
    [B, N] = list(map(int, readLineList()))
    M = list(map(int, readLineList()))
    L = lcmm(*M)
    A = sum(list(map(lambda x: L/x,M)))
    N = N % A
    if N == 0:
        N = A
    next_customer = 1
    occ = [0]*B
    while next_customer <= N:
        for j in range(0,B):
            if occ[j] == 0:
                if next_customer ==N:
                    barber = j + 1
                next_customer +=1
                occ[j] = M[j]
            occ[j] -= 1
        
        
    writeOut(str(barber), i)

output.close()