__author__ = 'kanhua'


import functools
from operator import itemgetter


def gcd(*numbers):
    """Return the greatest common divisor of the given integers"""
    from fractions import gcd
    return functools.reduce(gcd, numbers)

def lcm(*numbers):
    """Return lowest common multiple."""
    def lcm(a, b):
        return (a * b) // gcd(a, b)
    return functools.reduce(lcm, numbers, 1)


def p_barber(M,C):

    blcm=lcm(*M)
    ftlist=list()
    for b,mk in enumerate(M):


        mtk=[mk*i for i in range(int(blcm/mk))]

        for ft in mtk:
            ftlist.append((b,ft))

        #print(ftlist)

    ftlist=sorted(ftlist,key=itemgetter(0))
    ftlist=sorted(ftlist,key=itemgetter(1))


    C=(C-1)%len(ftlist)
    print(ftlist)

    print(ftlist[C][0]+1)
    #print(ftlist[C][1])

    return ftlist[C][0]+1



def run_contest(in_file="stest.in",out_file="stest.out"):

    fp=open(in_file,'r')
    op=open(out_file,'w')


    N=int(fp.readline())

    for i in range(N):
        B,C=tuple(map(int,fp.readline().split()))
        M=list(map(int,fp.readline().split()))


        op.write("Case #%s: "%(i+1))
        op.write(str(p_barber(M,C)))
        op.write("\n")



if __name__=="__main__":

    run_contest(in_file="B-small-attempt1.in")
