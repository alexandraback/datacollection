import sys
import itertools
import numpy as np

def all_same(iterator):
    return len(set(iterator)) <= 1

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
            string2 = []
            for word in string:
                string2.append([[k,len(list(g))] for k, g in itertools.groupby(word)])
            nb_it = len(tmp)
            #print nb_it
            count = 0
            for i in range(nb_it):
                letter = []
                for l in string2:
                    letter.append(l[i][1])
                #print 'letter', letter
                letter = np.asarray(letter)
                while not all_same(letter):
                    count += 1
                    mean = np.mean(letter)
                    index = np.argmax(np.abs(np.asarray(letter) - mean))
                    if letter[index] > mean:
                        letter[index] -= 1
                    else:
                        letter[index] += 1
                    #print i, letter
            print 'Case #%d: %d' %(case, count)
            
main()
