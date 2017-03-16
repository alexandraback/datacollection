"""
Google Code Jam 2014 Round 1A Problem B

Author  : chaotic_iak
Language: Python 3.4.2
"""

################################################### SOLUTION

import math

def initialize():
    pass

def solve():
    b,n = read()
    m = read()
    lo = 0
    hi = 10**14
    while hi-lo > 1:
        if compute((lo+hi)//2, m) >= n:
            hi = (lo+hi)//2 + (lo+hi) % 2
        else:
            lo = (lo+hi)//2
    time = lo if compute(hi, m) >= n else hi
    avail = [i for i in range(b) if time % m[i] == 0]
    write(avail[n-1-compute(time, m)]+1)

def compute(time, m):
    ans = 0
    for i in m:
        ans += time//i
        if time % i: ans += 1
    return ans

#################################################### HELPERS

# 0  : Single testcase, solve() only
# str: Multiple testcase, print output_format before
#                         %d replaced with case number
output_format = "Case #%d: "

filename = input().strip()
sfile = None
tfile = None
if filename != "":
    sfile = open(filename + ".in", "r")
    sfile.seek(0)
    tfile = open(filename + ".out", "w")

def read(mode=2):
    # 0: String
    # 1: List of strings
    # 2: List of integers
    if sfile:
        input_line = sfile.readline().strip()
    else:
        input_line = input().strip()
    if mode == 0: return input_line
    if mode == 1: return input_line.split()
    if mode == 2: return list(map(int, input_line.split()))

def write(s="\n"):
    if s is None: s = ""
    if isinstance(s, list): s = " ".join(map(str, s))
    s = str(s)
    if tfile:
        tfile.write(s)
    else:
        print(s, end="")

if output_format == 0:
    solve()
else:
    initialize()
    total_cases = int(read(0))
    for case_number in range(1, total_cases+1):
        write(output_format.replace("%d", str(case_number)))
        solve()
        write("\n")
