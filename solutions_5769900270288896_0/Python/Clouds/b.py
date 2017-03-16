import sys

def dbgprint(func):
    def newfunc(*args, **kwds):
        ret = func(*args, **kwds)
        print(args, '->', ret, file=sys.stderr)
        return ret
    return newfunc

#@dbgprint
def calc(r,c,a):
    if 2*a<=r*c+1:
        return 0
    b=r*c-a
    z=r*(c-1)+c*(r-1)
    aa=int(((r-2)*(c-2)+1)/2)
    if b<=aa:
        return z-4*b
    b=b-aa
    z=z-aa*4
    aa=int((r-2)/2)*2+int((c-2)/2)*2+(r%2+c%2)%2
    if b<=aa:
        return z-3*b
    b=b-aa
    z=z-aa*3
    aa=2
    if b<=aa:
        return z-2*b
    b=b-aa
    z=z-aa*2
    aa=2
    bz=0
    if r%2+c%2!=1:
        bz=2
    if b<=aa:
        return z-bz*b
    raise "ERR"

def case(i):
    ln1=sys.stdin.readline();
    (r,c,a)=(int(x) for x in ln1.split(" "))
    print("Case #"+str(i)+": "+str(calc(r,c,a)))

if __name__ == "__main__":
    n=int(sys.stdin.readline())
    [case(i) for i in range(1,n+1)]
