#!/usr/bin/python

"""Usage:
    X.py < X.in > X.out
"""

################################################################################
# util functions

logging = False

globalCase = 0
def log(string="", case=0):
    global globalCase
    if logging:
        if case > 0:
            globalCase = case
            string = "started case - %s" % string
        print("Case #%d: %s" % (globalCase, string))
    
################################################################################
# main

if __name__ == '__main__':
    import sys
    r = sys.stdin.readline
    cases = int(r())
    for c in xrange(cases):
        log(case=c+1)

        answer = int(r())-1
        log("answer: {}".format(answer))
        for i in range(4):
            if i == answer:
                row1 = set(r().split())
            else:
                r()
        log("row1: {}".format(row1))

        answer = int(r())-1
        log("answer: {}".format(answer))
        for i in range(4):
            if i == answer:
                row2 = set(r().split())
            else:
                r()
        log("row2: {}".format(row2))

        response = row1 & row2
        log("response: ".format(response))
        if len(response)==0:
            response = "Volunteer cheated!"
        elif len(response)==1:
            response = list(response)[0]
        else: 
            response = "Bad magician!"


        print 'Case #{}: {}'.format(c + 1, response)
