import math
from collections import Counter

class Importer:
    ''' Reads the file, and queues up inputs'''
    def __init__(self,file):
        self.file = file
        self.fhandle = open(self.file, 'r')
        self.T = int(self.fhandle.readline())

    def pop(self):
        self.P = int(self.fhandle.readline())
        word = [int(x) for x in list(self.fhandle.readline().strip().split(' '))]
        return (self.P,word)

class Exporter:
    ''' writes output in proper format, line by line'''
    def __init__(self,file):
        self.file = file
        with open(self.file, 'w'): pass
        self.fhandle = open(self.file, 'w')
        self.ind = 1


    def put(self,ans):
        outs = 'Case #'+str(self.ind)+':'
        outs += ' '+str(ans)
        outs+='\n'
        self.fhandle.write(outs)
        self.ind += 1

def majorityExists(evac):
    bL = [x>=sum(arg)/2 for x in arg]
    return sum(bL)>1


class Runner(object):
    ''' Run algo one case at a time'''

    def run(self, P,arg):

        maxP = arg.index(max(arg))
        evacBack = []
        sortArg = [i[0] for i in sorted(enumerate(arg), key=lambda x:x[1])]
        Out = arg
        In = [0]*P
        while(sum(Out)>0):
            for i in range(P):
                if Out[sortArg[i]]>0:
                    if i == P-1:
                        evacBack.append((sortArg[i],))
                        Out[sortArg[i]]-=1
                        In[sortArg[i]]+=1
                    else:
                        evacBack.append((sortArg[i],sortArg[i+1]))
                        Out[sortArg[i]]-=1
                        Out[sortArg[i+1]]-=1
                        In[sortArg[i]]+=1
                        In[sortArg[i+1]]+=1
                    break

        print(evacBack)
        outs = ''
        for i in range(len(evacBack)-1,-1,-1):
            if len(evacBack[i])==2:
                outs+= ' '+chr(evacBack[i][0]+65)+chr(evacBack[i][1]+65)
            else:
                outs+= ' '+chr(evacBack[i][0]+65)
        print(outs)
        return(outs)










if __name__=='__main__':
    print(Runner)
    read = Importer('A-large.in')
    sol = Runner()
    write = Exporter('output.txt')
    for i in range(read.T):
        (P,arg) = read.pop()
        print(arg)
        ans = sol.run(P,arg)
        print(ans)
        write.put(ans)
