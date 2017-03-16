import sys
import copy
#sys.setrecursionlimit(1500)
from operator import itemgetter

def calculate(N, nums):
    # sort descending
    sortednums = sorted(nums, key = itemgetter(0), reverse=True)
    # how many politicians are there?
    
    totalpoliticians = 0#reduce(lambda x, y: x[0] + y[0], sortednums)
    for x in sortednums:
        totalpoliticians += x[0]
    print totalpoliticians
        
    
    # what about case where we have 2 and 2?  remove both from 1st will
    # mean second one will have majority

    # what about the case where removing two will leave just 1 from a single party?
    # we need to be careful - if there are 3 left, and removing two would leave a single party with
    # just 1, we need to instead remove just 1 and remove two on the next round
    evacplan = ''
    evacuated = 0
    while evacuated < totalpoliticians:


        

        if totalpoliticians - evacuated == 3:
            # just going to remove one!
            sortednums[0][0] -= 1
            evacuated += 1
            evacplan += sortednums[0][1] + ' ' 
        # remove the top two
        elif sortednums[0][0] >= 2 and sortednums[0][0] != sortednums[1][0]:
            sortednums[0][0] -= 2
            evacplan+=sortednums[0][1]+sortednums[0][1]+' '
            evacuated += 2
        elif sortednums[0][0] == sortednums[1][0]:
            sortednums[0][0] -= 1
            sortednums[1][0] -= 1
            evacplan += sortednums[0][1]+sortednums[1][1] +' '
            evacuated += 2
        else:
            sortednums[0][0] -= 1
            evacplan+=sortednums[0][1]#+sortednums[0][1]
            evacuated += 1
            # find next non-zero thing and subtract from that
            for x in xrange(1,len(sortednums)):
                if sortednums[x][0] > 0:
                    sortednums[x][0] -= 1
                    evacplan += sortednums[x][1]+ ' '
                    evacuated += 1
                    break
        sortednums = sorted(sortednums, key = itemgetter(0), reverse=True)
        print sortednums
    return evacplan 
        
infile = open(sys.argv[1],'r')

numcases = int(infile.readline().strip())
outfile = open(sys.argv[1].replace('.in','.out'),'w')
for n in range(numcases):
    numparties = infile.readline().strip()
    partynums = []
    for i, x in enumerate(infile.readline().strip().split()):
        partynums.append([int(x), chr(65+i)])
    evac = calculate(numparties, partynums)
    
    

    outfile.write("Case #" + str(n+1)+": " + evac.strip() + '\n')
    print ("Case #" + str(n+1)+": " + evac.strip() + '\n')

outfile.close()
