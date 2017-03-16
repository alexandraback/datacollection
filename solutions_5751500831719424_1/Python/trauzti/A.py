import sys
getint = lambda: int(raw_input())
getfloats = lambda: [float(z) for z in raw_input().split()]
getints = lambda: [int(z) for z in raw_input().split()]


# legal moves:
#   1 )repeat a character
#   2) delete adjacent and identical characters
#

# first check if it is possible by replacing all identical duplicates


# aaabbb  3A3B -> 2A3B -> 2A2B
# ab      1A1B -> 2A1B -> 2A2B
# aabb    2A2B

# splits the string into tuples, (count, char)
# example: split("aabb") == [(2,'A'), (2,'B')]
def split(s):
    last = None
    count = 1
    arr = []
    for i in xrange(len(s)):
        c = s[i]
        if c == last:
            count += 1
        else:
            if last != None:
                arr.append((count, last))
            count = 1
        last = c
    arr.append((count, c))
    return arr


# some builtin function for this? check if all elements are the same...
def same(sp):
    equal = True
    last = sp[0]
    for s in sp[1:]:
        if s != last:
            return False
        last = s
    return True

def tos(spl):
    return ''.join([x[1] for x in spl])

assert split("aabb") == [(2,'a'), (2,'b')]
assert split("gcj") == [(1,'g'), (1,'c'), (1, 'j')]
assert same( [tos(split("aabb")), tos(split("abb"))] )
assert not same( [tos(split("aabb")), tos(split("abbc"))] )


# example:
# minchanges([2,1,1]) == 2
# minchanges([3,1,2]) == 2

def minchanges(nums):
    #middle element
    nums.sort()
    if len(nums) % 2 == 0:
        t1 = len(nums) / 2
        t2 = t1-1
        diff1 = sum([abs(x-nums[t1]) for x in nums])
        diff2 = sum([abs(x-nums[t2]) for x in nums])
        return min(diff1, diff2)
    else:
        t1 = len(nums) / 2
        diff = sum([abs(x-nums[t1]) for x in nums])
        return diff


assert minchanges([2,1,1]) == 1
assert minchanges([3,1,2]) == 2
assert minchanges([5,3,1]) == 4

for t in xrange(1, 1+getint()):
    N = getint()
    ls = []
    sp = []
    chars = []

    for i in xrange(N):
        l = raw_input()
        ls.append(l)
        spl = split(l)
        sp.append(spl)
        chars.append(tos(spl))

    if not same(chars):
        s = "Fegla Won"
    else:
        # loop through every character
        s = 0
        for ci in xrange(len(chars[0])):
            changes = 0
            # find the middle number, change everything towards it
            nums = [x[ci][0] for x in sp]
            s += minchanges(nums)


    print "Case #%d: %s" % (t, s)
