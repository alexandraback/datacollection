from time import clock
import sys
# stderr isn't piped to a.out when we do  (py3 a.py < a.in) > a.out
print = lambda *s: sys.stderr.write(str(s[0])+"\n") if len(s)==1 else print(s)

#---------------------------------------------

"""

method b: it's obvious we minimize by putting the mushrooms on at
    the end of the 10s-interval just as Bartholomew did
first figure out the max positive difference between two consecutive
    (i.e. make two passes through the list)

method a: sum up all positive differences

"""

def run(a):

    method_a = 0
    lamo = len(a)-1
    for i in range(lamo):
        diff = a[i] - a[i+1]
        if diff > 0:
            method_a += diff

    method_b = 0
    maxdiff = max(a[i] - a[i+1] for i in range(lamo))
    print(maxdiff)
    if maxdiff < 0:  maxdiff = 0
    for i in range(lamo):
        ai = a[i]
        diff = ai - a[i+1]
        if ai < maxdiff:
            method_b += ai
        else:
            method_b += maxdiff

    return str(method_a)+" "+str(method_b)

#---------------------------------------------

def read_case():
    input()
    return [int(n) for n in input().split()]

if __name__ == "__main__":
    for i in range(int(input())):
        outstr = "Case #"+str(i+1)+": "+str(run(read_case()))
        print(outstr+" @ t="+str(clock()))
        sys.stdout.write(outstr+"\n")

