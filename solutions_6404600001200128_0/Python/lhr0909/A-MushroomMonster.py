from multiprocessing import Pool, Manager
from copy import deepcopy
from itertools import *

def first_method(snapshots):
    result = 0
    last_snapshot = snapshots[0]
    for i in xrange(1, len(snapshots)):
        snapshot = snapshots[i]
        if snapshot < last_snapshot:
            result += last_snapshot - snapshot
            last_snapshot = snapshot
        else:
            last_snapshot = snapshot
    return result

def second_method(snapshots):
    result = 0
    max_rate = 0
    last_snapshot = snapshots[0]
    for i in xrange(1, len(snapshots)):
        snapshot = snapshots[i]
        rate = last_snapshot - snapshot
        if rate > max_rate:
            max_rate = rate
        last_snapshot = snapshot

    for i in xrange(len(snapshots) - 1):
        snapshot = snapshots[i]
        if snapshot < max_rate:
            result += snapshot
        else:
            result += max_rate
    return result

def solve(solve_input):
    snapshots, memoize_dict = solve_input
    answer = [str(first_method(snapshots)), str(second_method(snapshots))]

    return ' '.join(answer)

def solve_file(filename, use_threadpool):
    fin = open(filename + '.in', 'r')
    fout = open(filename + '.out', 'w')
    #data read
    inputs = []
    T = int(fin.readline())
    for case in xrange(T):
        fin.readline()
        snapshots = map(int, fin.readline().strip().split(' '))
        inputs.append(snapshots)
    #solve
    answers = []
    if use_threadpool:
        manager = Manager()
        memoize_dict = manager.dict()
        inputs_with_dict = map(lambda x: (x, memoize_dict), inputs)
        thread_pool = Pool(10)
        answers = thread_pool.map(solve, inputs_with_dict)
    else:
        memoize_dict = dict()
        inputs_with_dict = map(lambda x: (x, memoize_dict), inputs)
        answers = map(solve, inputs_with_dict)
    #output
    for i in xrange(1, len(answers) + 1):
        fout.write(("Case #%d: " % i) + str(answers[i-1]) + "\n")

    fin.close()
    fout.close()

if __name__ == "__main__":
    solve_file("A-small-attempt2", True)
