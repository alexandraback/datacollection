
#============================================

curProblem = "A";
curAttempt = 1;
curType = "example";
#curType = "practice";
#curType = "small";
curType = "large";

exampleString = """
1
3
500 400 300
""";

def getInput():
    if curType == "example": return exampleString;

    fileName = "%s-"%(curProblem);
    if curType == "large": fileName = "%s-large.in"%(curProblem);
    if curType == "small": fileName = "%s-small-attempt%d.in"%(curProblem,curAttempt);
    if curType == "practice": fileName = "%s-small-practice.in"%(curProblem);

    with open(fileName, "rt") as f:
        buf = f.readlines();

    return "".join(buf);

def parseInput(buf):
    buf = buf.split("\n");
    buf = filter(len,buf);

    t = int(buf[0]); buf=buf[1:];
    outBuf = [];
    for _ in xrange(1,t+1):
        print buf[0];
        n = int(buf[0]); buf=buf[1:];
        w = map(int,buf[0].split());
        buf = buf[1:];

        outBuf.append([n, w]);
        pass;
    return outBuf;

def solveProblem(rnd, (n,w)):
    arr = [];
    while sum(w) > 0:
        tarr = [];
        _,i = max( (v,i) for i,v in enumerate(w) );

        w[i] -= 1;
        tarr.append(i);
        if all( 2*v <= sum(w) for v in w ):
            arr.append([i]);
            continue;

        _,i = max( (v,i) for i,v in enumerate(w) );
        w[i] -= 1;
        tarr.append(i);
        s = sum(w);
        if any( 2*v > s for v in w ):
            print "ERROR CONDITION";
            exit(0);

        arr.append(tarr);

    arr = [ "".join( chr(ord("A") + x) for x in v) for v in arr ];
    arr = " ".join(arr);

    return arr;

#============================================

from time import time;

if __name__ == '__main__':
    inputData = parseInput(getInput());
    outfile = "%s.out"%(curProblem);

    start=time();
    with open(outfile,"wt") as f:
        for rnd, inp in enumerate(inputData):
            res = solveProblem(rnd, inp);
            st="Case #%d: %s\n"%(rnd+1,res);
            print st[:-1]; f.write(st);

    print "Total time: %fs"%(time()-start);

#============================================
