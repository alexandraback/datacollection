'''
Created on Apr 12, 2014

@author: ignacio
'''

import sys
import logging
if "--debug" in sys.argv:
    logging.basicConfig(level=logging.DEBUG)

def main():
    cases = int(sys.stdin.readline())
    logging.debug(cases)
    for case in xrange(cases):
        resp = run_case()
        print "Case #%s: %s" % (case + 1, resp,)
    
def run_case():
    first = extract_row()
    second = extract_row()
    possible = first & second
    logging.debug("%s", possible)
    if not possible:
        return "Volunteer cheated!"
    elif len(possible) > 1:
        return "Bad magician!"
    return possible.pop()
    
def extract_row():
    row_number = int(sys.stdin.readline())
    rows = [sys.stdin.readline() for _x in xrange(4) ]
    return set(int(val) for val in  rows[row_number - 1].split())

if __name__ == "__main__":
    main()