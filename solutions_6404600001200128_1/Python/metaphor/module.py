f = open('A-large.in', 'r')
#f = open('input.in', 'r')
g = open('output.txt', 'w')

def solve(array, index):
    sum1 = 0
    sum2 = 0
    maxdiff = 0
    for i in range(0, len(array)-1):
        if array[i] > array[i+1]:
            sum1 = sum1 + array[i] - array[i+1]
            if (array[i] - array[i+1]) > maxdiff:
                maxdiff = array[i] - array[i+1]
    for i in array[:-1]:
        sum2 = sum2 + min(maxdiff, i)
            
    print "Case #" + str(index) + ": " + str(sum1) + " " + str(sum2)
    g.write("Case #" + str(index) + ": " + str(sum1)+ " " + str(sum2) + "\n")
            
    
    

case = int(f.readline())
for index in range(1, case+1):
    linee = f.readline().split()
    length = int(linee[0])
    lineo = f.readline().split()
    array = [int(i) for i in lineo]       
    solve(array, index)
