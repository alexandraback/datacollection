# insight:
#  - must be an order of chars such that each string has 1 <= k out of each
#    string, else impossible
#
# - treat each char in turn
#
# -   3  6  7
# -
# -   work per char = distance from mean ?


from math import *


def memo(fn):
  m = {}
  def inner(*args):
    key = tuple(args)
    if not key in m:
      m[key] = fn(*args)
    return m[key]
  return inner


def succ(xs):
    res = []

    for i in range(len(xs)):
        s = xs[:i] + xs[i] + xs[i:]
        res.append(s)

    for i in range(1, len(xs)):
        if xs[i-1] == xs[i]:
            s = xs[:i-1] + xs[i:]
        res.append(s)

    return list(set(res))


def char_up(xs):
    accum = [xs[0], 1]
    res = []

    for x in xs+'.':
        if x != accum[0]:
            res.append(accum)
            accum = [x, 1]
        else:
            accum[1] += 1

    return res


def solve_one():
    N = int(raw_input())

    ys = [[] for k in range(120)]

    for i in range(N):
        xs = raw_input().strip()
        for j, c in enumerate(char_up(xs)):
            ys[j].append(c)

    res = 0
    for y in ys:
        if not y:
            break
        if not len(set(x[0] for x in y)) == 1:
            return 'Fegla Won'
        sums = sum(x[1] for x in y)
        hi = ceil(sums/float(N))
        lo = float(sums/float(N))

        costh = sum(abs(x[1] - hi) for x in y)
        costl = sum(abs(x[1] - lo) for x in y)

        if len(y) == 1:
            return 'Fegla Won'
        cost = abs(y[0][1] - y[1][1])
        assert cost == costh or cost == costl

        res += int(min(costh, costl))

    return str(res)



    #return str(dist[ys0]) if ys0 in dist else 'Fegla won'


for i in range(1, int(raw_input())+1):
    print 'Case #%d: %s' % (i, solve_one(),)
