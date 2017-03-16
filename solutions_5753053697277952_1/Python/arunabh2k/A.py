#!/usr/bin/python
import copy
import sys
sys.setrecursionlimit(1000000)

def getMax(dic):
    mkey = 'A';
    for key in dic:
        if dic[key] >= dic[mkey]:
            mkey = key
    return mkey
def isMajority(dic):
    mkey = getMax(dic)
    sum = 0
    for key in dic:
        if key != mkey:
            sum += dic[key]
    if sum < dic[mkey]:
        return True
    return False

def process(dic, result):
    mkey = getMax(dic)
    if dic[mkey] == 0:
        return result
    dic[mkey] = dic[mkey] - 1
    result = result + str(mkey)
    if isMajority(dic):
        nmkey = getMax(dic)
        dic[nmkey] = dic[nmkey] - 1
        result = result + str(nmkey)
    result = result + " "
    return process(dic, result)

f = open('sample.txt', 'r')
tc = int(f.readline())
#print tc
for index in range(tc):
    result = ""
    ct = int(f.readline())
    vals = f.readline().rstrip().split(" ")
    A=ord('A')
    dic = {}
    for i in range(ct):
        ch = chr(A+i)
        dic[ch] = int(vals[i])

    result = process(dic, result)

    print "CASE #" + str(index+1) + ": " + result
