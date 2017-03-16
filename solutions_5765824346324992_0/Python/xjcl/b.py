from time import clock
import sys
# stderr isn't piped to a.out when we do  (py3 a.py < a.in) > a.out
print = lambda *s: sys.stderr.write(str(s[0])+"\n") if len(s)==1 else print(s)
import math
import sys

sys.setrecursionlimit(100000)

#---------------------------------------------

"""
"numbered 1 thorugh B" now isn't this problem friendly to lua users

i think this is to be solved like the pancake pronlem:
    /assume/ a number of minutes and then calculate whether
    it is possible to make it in that number
hmm maybe add some binary search to it?
    e.g. if 1000 min is too few and 1500 too much do 1250

hm, shouldn't be possible as we have 100000 possible values per barber

one could convert it into a float (cuts/minute) and then
    guess based off that
yes this will definitely give us a good approx. let's try!


"""


def test_time(people, m, t, cache):

    served = 0
    for mi in m:
        served += math.ceil(t/mi)

    print("tt", people, m, t, cache, served)

    if served >= people:
        return test_time(people, m, t-1, served)

    # found the minute -> determine exact barber
    if served < people and cache >= people:
        cntdown = people - served
        print(cntdown)
        i = 0
        for i in range(len(m)):
            print(cntdown, t, m[i])
            if t % m[i] == 0:
                cntdown -= 1
                if cntdown == 0:
                    return (i+1)


def approx(people, m):

    cpm = sum(1/mi for mi in m)
    return math.floor(people/cpm)


def run(data):
    l1, m = data
    b, n = l1

    x = approx(n-1, m)

    print("x", x)

    ret = test_time(n, m, x+2, 0)

    return str(ret)

#---------------------------------------------

def read_case():
    return [[int(n) for n in input().split()] for i in range(2)]

if __name__ == "__main__":
    for i in range(int(input())):
        outstr = "Case #"+str(i+1)+": "+str(run(read_case()))
        print(outstr+" @ t="+str(clock()))
        sys.stdout.write(outstr+"\n")

