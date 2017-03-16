#!/bin/env python

input_file = None

import os
import sys

def group(lst, n):
  for i in range(0, len(lst), n):
    val = lst[i:i+n]
    if len(val) == n:
      yield tuple(val)



def main():
    cases = readone(int)
    output = []
    for case_num in range(1, cases + 1):
        ### Begin solution code
        num_trees = readone(int)
        tree_coords = []
        for t in range(num_trees):
            tree_coords.append(readmany(int))
        result = []
        for tree in tree_coords:
            min_removed = num_trees
            best_tree = tree
            for colinear_tree in tree_coords:
                if colinear_tree == tree:
                    continue
                slope = None
                intercept = None
                num_above = 0
                num_below = 0

                if tree[0] != colinear_tree[0]: # not vertical
                    slope = (tree[1] - colinear_tree[1]) / (tree[0] - colinear_tree[0])
                    intercept = tree[1] - tree[0] * slope
                for test_tree in tree_coords:
                    if test_tree == tree or test_tree == colinear_tree:
                        continue
                    # print 'using', tree, 'to', colinear_tree, ':', test_tree,
                    if slope is None: # vertical
                        if test_tree[0] > tree[0]:
                            num_above += 1
                            # print 'above'
                        elif test_tree[0] < tree[0]:
                            num_below += 1
                        #     print 'below'
                        # else:
                        #     print 'colinear'
                    else:
                        if test_tree[1] > slope * test_tree[0] + intercept:
                            num_above += 1
                            # print 'above'
                        elif test_tree[1] < slope * test_tree[0] + intercept:
                            num_below += 1
                        #     print 'below'
                        # else:
                        #     print 'colinear'
                if min(num_above, num_below) < min_removed:
                    best_tree = colinear_tree
                min_removed = min(min_removed, num_above, num_below)
                if min_removed == 0:
                    break
            result.append(str(min_removed))
            # result.append(' '.join([str(min_removed), str(tree), str(best_tree)]))
        ### End solution code
        output.append('Case #%d:\n' % (case_num,) + str('\n'.join(result)))
    output_file = open(output_filename, 'w')
    output_file.write('\n'.join(output))
    output_file.close()
    if output_filename.endswith('sample.out'):
        their_output = open('C-their-sample.out')
        for line_num, line in enumerate(output):
            their_line = their_output.readline().strip()
            if line == their_line:
                print line
            else:
                print line_num, ' yours :', line
                print line_num, ' theirs:', their_line
        their_output.close()
    else:
        print '\n'.join(output)

def readone(t):
    line = input_file.readline()
    assert(len(line.split()) == 1)
    return t(line.strip())

def readmany(t):
    return map(t, input_file.readline().split())

if __name__ == '__main__':
    input_file = sys.stdin
    output_filename = 'test.out'
    if os.path.exists('C-large.in'):
        input_file = open('C-large.in')
        output_filename = 'C-large.out'
    elif os.path.exists('C-small.in'):
        input_file = open('C-small.in')
        output_filename = 'C-small.out'
    elif os.path.exists('C-sample.in'):
        input_file = open('C-sample.in')
        output_filename = 'C-sample.out'
    main()
    input_file.close()