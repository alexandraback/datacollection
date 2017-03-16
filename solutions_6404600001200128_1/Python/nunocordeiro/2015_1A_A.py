# encoding: UTF-8

from __future__ import absolute_import, division

import collections
import itertools
import sys
import functools

class gcj:
    IN = open('D:\code jam\input.in', 'r')
    OUT = open('D:\code jam\output.txt', 'w')
    buf = None

    identity = lambda x: x

    @classmethod
    def _read_line(cls):
        if cls.buf:
            res = cls.buf
            cls.buf = None
        else:
            res = cls.IN.readline()
        if not res:
            raise EOFError()
        return res

    @classmethod
    def line(cls, conv=identity):
        line = cls._read_line()
        return conv(line.rstrip(b'\r\n'))

    @classmethod
    def splitline(cls, conv=identity):
        line = cls._read_line()
        return [conv(x) for x in line.split()]

    @classmethod
    def whitespace(cls):
        line = None
        while not line:
            line = cls._read_line()
            i = 0
            l = len(line)
            while i < l and line[i].isspace():
                i += 1
            line = line[i:]
        cls.buf = line

    @classmethod
    def token(cls, conv=identity):
        cls.whitespace()
        line = cls._read_line()
        i = 0
        l = len(line)
        while i < l and not line[i].isspace():
            i += 1
        cls.buf = line[i:] if i < l else None
        return conv(line[:i])

    @classmethod
    def tokens(cls, cnt, conv=identity):
        #tokens=[]
        #for _ in range(cnt):
        #    tokens.append(cls.token(conv))
        #return tokens   
        return [cls.token(conv) for _ in range(cnt)]

    current_case = 0

    @classmethod
    def case(cls):
        cls.current_case += 1
        return 'Case #{}:'.format(cls.current_case)
    
    @classmethod
    def writefile(cls, case, solve):
        cls.OUT.write( case + " " + str(solve) + '\n')
        return
    
def solve():
    #Get Variables
    N = gcj.token(int) #can be token(int) or tokens(N, int) # can be int or str
    m = gcj.tokens(N, int)
    print('m:',m )    
    #print('M:', M)    

#METHOD 1
    met1=0
    met2=0
    i=1
    while i<N:
        x = m[i-1]-m[i]
        if x>0:
            met1+=x 
        if x>met2:
            met2=x

        i+=1
    print('met2:', met2)
#METHOD 2
    i=0
    neg=0
    while i<N-1:
        if m[i] < met2:
            neg+= met2 - m[i]
           
        i+=1
    
    met2=(N-1)*met2 - neg
    
    result = str(met1) + " " + str(met2)
    return result



def main():
    t = gcj.token(int)
    for _ in range(t):
        case = gcj.case()
        if case == "Case #34:":
            j=1
        result = solve()
        
        gcj.writefile(case, result)
        print(case, result)

main()
