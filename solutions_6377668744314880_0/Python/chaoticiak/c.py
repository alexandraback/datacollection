"""
Google Code Jam 2014 Round 1A Problem C

Author  : chaotic_iak
Language: Python 3.4.2
"""

################################################### SOLUTION

def initialize():
    pass

def solve():
    write("\n")
    n, = read()
    trees = [tuple(read()) for _ in range(n)]

    import itertools
    for t in range(n):
        scr = n-1
        for k in range(n+1):
            for idx in itertools.combinations(range(n), k):
                if t in idx and boundary(trees[t], [trees[i] for i in idx]):
                    scr = n-k
                    break
        write(scr)
        if t != n-1: write("\n")

def boundary(t, trees):
    for tr in trees:
        if tr != t and one_side(t, tr, trees): return True
    return False

def one_side(t1, t2, trees):
    eq = (t1[1]-t2[1], t2[0]-t1[0])
    ls = [eq[0]*t[0]+eq[1]*t[1] for t in trees]
    tgt = eq[0]*t1[0]+eq[1]*t1[1]
    return (min(ls) == tgt or max(ls) == tgt)

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
