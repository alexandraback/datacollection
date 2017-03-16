#!/usr/bin/python3
# -*- coding: utf-8 -*-

import sys
import numpy

def repeater(path_to_conf):

    with open(path_to_conf) as f:
        content = f.readlines()
    t = int(content[0].replace("\n", ""))
    total = 1

    for i in range(0, t):
        n = int(content[total].replace("\n", ""))
        s = []
        total += 1
        for k in range(0, n):
            s.append(content[total+k].replace("\n", ""))
        total += n

        reference = [s[0][0]] + [s[0][k] for k in range(1, len(s[0])) if s[0][k] != s[0][k-1]]
        ok = True
        for k in range(0, len(s)):
            tmp = [s[k][0]] + [s[k][l] for l in range(1, len(s[k])) if s[k][l] != s[k][l-1]]
            if tmp != reference:
                ok = False
                break
        if not ok:
            print("Case #" + str(i+1) + ": Fegla Won")
            continue
        
        res = []
        for l in range(0, n):
            res.append([0] * len(reference))
        for l in range(0, n):
            last = s[l][0]
            j = 0
            for k in s[l]:
                if k != last:
                    last = k
                    j += 1
                res[l][j] += 1

        count = 0
        for k in range(0, len(reference)):
            median = int(numpy.median([res[j][k] for j in range(0, len(res))]))
            for j in range(0, len(res)):
                count += abs(res[j][k] - median)
        print("Case #" + str(i+1) + ":", count)
        

        
        
        
if __name__ == "__main__":
    if len(sys.argv) < 2:
        print(sys.argv[0] + " <path_to_config>")
    else:
        repeater(sys.argv[1])

