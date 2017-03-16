import copy
import itertools

if __name__ == '__main__':
    T = input()
    for t in xrange(1, T + 1):
        N = int(raw_input())
        group = set()
        strings = []
        for i in xrange(N):
            tmp = []
            tmp2 = []
            for k, g in itertools.groupby(raw_input()):
                tmp.append(k)
                tmp2.append(len(list(g)))
            group.add(tuple(tmp))
            strings.append(copy.deepcopy(tmp2))
        if len(group) == 1:
            strings = zip(*strings)
            ret = 0
            for i in xrange(len(strings)):
                avg = int(sum(strings[i]) * 1.0 / len(strings[i]) + 0.5)
                for j in xrange(len(strings[0])):
                    ret += abs(avg - strings[i][j])
            print "Case #%d: %d" % (t, ret)
        else:
            print "Case #%d: Fegla Won" % t



