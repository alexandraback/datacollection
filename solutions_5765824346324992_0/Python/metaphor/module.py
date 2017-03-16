f = open('B-small-attempt2.in', 'r')
#f = open('input.in', 'r')
g = open('output.txt', 'w')

def solve(array, nth, index):
    M = array + []
    result = 0
    #print len(array), nth
    if len(array) >= nth:
        result = nth
    else:
        curr = len(array)
        minium = 0
        group = 0
        has_group = False
        group_order = {}
        for i in range(len(array)):
            group_order[i+1] = i
        while (curr < nth):
            fast = min(array)
            array = [i - fast for i in array]
            if min(array) == 0 and max(array) == 0:
                has_group = True
                group = curr - len(array)
                break
            curr = curr + 1
            minium = min(array)
            result = array.index(minium)
            group_order[curr] = result
            array[array.index(minium)] += M[array.index(minium)]
        if has_group:
            #print nth
            remainder = nth % len(group_order)
            #print group_order, remainder
            if remainder == 0:
                remainder += len(group_order)
            result = group_order[remainder]
        result = result + 1
    
    print "Case #" + str(index) + ": " + str(result)
    g.write("Case #" + str(index) + ": " + str(result) + "\n")
            
    
    

case = int(f.readline())
for index in range(1, case+1):
    linee = f.readline().split()
    length = int(linee[0])
    nth = int(linee[1])
    lineo = f.readline().split()
    array = [int(i) for i in lineo]       
    solve(array, nth, index)
    #if index == 6:
    #    break
