__author__ = 'kanhua'

import numpy as np


def calc_1(M):


    aM=np.array(M,dtype=np.int64)

    diffM=aM[1:]-aM[0:-1]

    eat=diffM[diffM<0]


    return -sum(eat)

def calc_2(M):

    aM=np.array(M,dtype=np.int64)

    diffM=-(aM[1:]-aM[0:-1])

    max_r=np.max(diffM)

    max_r=np.ones(aM[0:-1].shape,dtype=np.int64)*max_r

    eat=np.fmin(aM[0:-1],max_r)

    return sum(eat)




def run_contest(in_file="stest.in",out_file="stest.out"):

    fp=open(in_file,'r')
    op=open(out_file,'w')


    N=int(fp.readline())
    print(N)

    for i in range(N):
        K=int(fp.readline())
        M=list(map(int,fp.readline().split()))
        #print(calc_1(M))
        print(calc_2(M))

        op.write("Case #%s: "%(i+1))
        op.write(str(calc_1(M)))
        op.write(" ")
        op.write(str(calc_2(M)))
        op.write("\n")

    pass

if __name__=="__main__":

    run_contest(in_file="A-large.in")




