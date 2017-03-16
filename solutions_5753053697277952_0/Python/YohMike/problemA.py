import os
import sys
import itertools

d = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def output_format(answer,test_case):
    output = "Case #%d:" % (test_case+1)
    output += " %s" % str(answer)
    output +="\n"
    return output



if __name__ == "__main__":
    #f = open("A-practice.in",'r')
    #f = open("A-large.in",'r')
    f = open("A-small-attempt0.in",'r')
    test_cases = int(f.readline())
    #out = open("results_A_p_0.txt",'w')
    out = open("results_A_s_0.txt",'w')
    #out = open("results_A_l_0.txt",'w')
    

    print test_cases
    for index in range(test_cases):
        print "\nTest case #%d"%index
        answer = ""
        Ps = int(f.readline())
        print Ps
        parties = [int(x) for x in f.readline().strip("\n").split(" ")]
        print parties
        while max(parties) > 0 and sum(parties)>3:
            index_max = parties.index(max(parties))
            first = d[index_max]
            parties[index_max] -= 1
            index_max = parties.index(max(parties))
            second = d[index_max]
            parties[index_max] -= 1
            answer += first + second + " "
        if sum(parties)==2:
            index_max = parties.index(max(parties))
            first = d[index_max]
            parties[index_max] -= 1
            index_max = parties.index(max(parties))
            second = d[index_max]
            parties[index_max] -= 1
            answer += first + second + " "
        elif sum(parties) == 3:



            index_max = parties.index(max(parties))
            first = d[index_max]
            parties[index_max] -=1
            answer += first + " "

            index_max = parties.index(max(parties))
            first = d[index_max]
            parties[index_max] -= 1
            index_max = parties.index(max(parties))
            second = d[index_max]
            parties[index_max] -= 1
            answer += first + second + " "
        elif sum(parties) == 1:
            index_max = parties.index(max(parties))
            first = d[index_max]
            parties[index_max] -=1
            answer += first + " "

        



        

        
        output = output_format(answer,index)
        print output
        out.write(output)
