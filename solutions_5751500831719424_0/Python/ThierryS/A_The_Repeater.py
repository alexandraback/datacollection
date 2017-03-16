import sys
import itertools


def main():

    T = int(sys.stdin.readline())
    
    for case in range(1,T+1):
        nb_string = int(sys.stdin.readline()) 
        string = []
        
        for _ in range(nb_string):
            string.append(sys.stdin.readline()[:-1])
        assert(len(string) == nb_string)
        
        #Test if there is a solution
        tmp = 0
        no_solution = False
        for i, word in enumerate(string):
            #a = [[k,len(list(g))] for k, g in itertools.groupby(word)]
            #print len(a)
            if i==0:
                tmp = [[k,len(list(g))] for k, g in itertools.groupby(word)]
            else:   
                tmp2 = [[k,len(list(g))] for k, g in itertools.groupby(word)]
                if not len(tmp) == len(tmp2):
                    #print len(tmp), len(tmp2)
                    no_solution = True
                    break
                for j in range(len(tmp2)):
                    if not tmp[j][0] == tmp2[j][0]:
                        no_solution = True
                        break
       
        if no_solution:
            print 'Case #%d: Fegla Won' %(case)
            
        else:
            #print tmp
            #print tmp2
            nb_it = len(tmp)
            #print nb_it
            count = 0
            for i in range(nb_it):
                count += abs(tmp[i][1] - tmp2[i][1])
            print 'Case #%d: %d' %(case, count)
            
main()
