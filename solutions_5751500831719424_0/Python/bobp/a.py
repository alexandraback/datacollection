#!/usr/bin/python
import sys
import math
import heapq 
import fractions
import copy
import argparse
import IPython
import ipdb

sys.setrecursionlimit(5000)

author="@".join(["bobp"+"fled","gmail.com"])

class solver:
    """ implements case specific code """
    def __init__(self):
        global pc
        self.pc = pc

    def parse(self):
        [self.n]=map(int,getline().split());
        self.ss=[]
        for i in range(self.n):
            [s]=getline().split()
            self.ss.append(s)

    def getrle(self,s):
        cs=[]
        rls=[]
        c=s[0]
        rl=1
        for l in s[1:]:
            if(l!=c):
                cs.append(c)
                rls.append(rl)
                c=l
                rl=1
            else:
                rl+=1
        cs.append(c)
        rls.append(rl)
        return (cs,rls)

    def calcmoves(self,nums):
        nums.sort()
        median=(nums[len(nums)/2])
        ret=0
        for n in nums:
            ret+=abs(n-median)
        return ret

    def solve(self):
        (cs,rls)=self.getrle(self.ss[0])
        rl_table=[rls]
        for s in self.ss[1:]:
            (cstmp,rls)=self.getrle(s)
            if(cstmp!=cs):
                return "Fegla Won"
            rl_table.append(rls)
        ret=0
        for i in range(len(rl_table[0])):
            nums=map(lambda x:x[i],rl_table)
            ret+=self.calcmoves(nums)
        return ret

class precomputer:
    """ 
    implements code that is not case specific such as generating a large
    table that can be used by all testcases
    """
    def __init__(self):
        debug("precomputer.__init__()",level=5)

def main():
    [cases]=map(int,getline().split());
    for caseid in range(1,cases+1):
        docase=(args.testcase is None or caseid in args.testcase)
        if docase:
            debug("Start Case:",caseid,level=5)
        s=solver()
        s.parse()
        if docase:
            debug("Solving Case:",caseid,level=5)
            result=s.solve()
            putline("Case #"+str(caseid)+": "+str(result))

def getline():
    line=args.infile.readline()
    debug("input:",line,level=5,nl=0)
    return line
    

def putline(*arg,**keywords):
    try:
        nl=keywords["nl"];
    except KeyError:
        nl=1
    line=" ".join(map(str,arg))
    if(nl):
        line+='\n'
    args.outfile.write(line)
    debug("output:",line,level=5,nl=0)

def put(*arg):
    putline(*arg,nl=0)

def debug(*arg,**keywords):
    try:
        level=keywords["level"];
    except KeyError:
        level=10
    try:
        nl=keywords["nl"];
    except KeyError:
        nl=1
    if(args.debug>=level):
        args.dbgfile.write(' '.join(map(str,arg)))
        if(nl):
            args.dbgfile.write('\n')

def doargs(argv=sys.argv[1:]):
    global args
    parser=argparse.ArgumentParser(description="solution by "+author)
    parser.add_argument("infile",nargs='?',type=argparse.FileType("r"),default=sys.stdin)
    parser.add_argument("outfile",nargs='?',type=argparse.FileType("w"),default=sys.stdout)
    parser.add_argument("-t",'--testcase',type=int,action="append")
    parser.add_argument("-d",'--debug',type=int,default=8)
    parser.add_argument("-i",'--interactive',action="store_true")
    parser.add_argument("-ipdb","--ipdb",action="store_true")
    parser.add_argument("dbgfile",nargs='?',type=argparse.FileType("w"),default=sys.stderr)
    args=parser.parse_args(argv)

def cleanup():
    if(args.infile!=sys.stdin):
        args.infile.close()
    if(args.outfile!=sys.stdout):
        args.outfile.close()
    if(args.dbgfile!=sys.stderr):
        args.dbgfile.close()

def setup():
    global pc
    try:
        pc
    except NameError:
        pc=precomputer()
    pass;

def run(argstring=None):
    if(not argstring is None):
        doargs(argstring.split())
    if(args.ipdb):
        ipdb.set_trace()
    setup()
    main()
    cleanup()
    if(args.ipdb):
        ipdb.set_trace()

if __name__=="__main__":
    from IPython.core import ultratb
    sys.excepthook = ultratb.FormattedTB(mode='Verbose',color_scheme='Linux', call_pdb=1)
    doargs()
    setup()
    if(args.interactive):
        IPython.embed()
    else:
        run()
