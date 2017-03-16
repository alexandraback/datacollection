from multiprocessing import Pool


def solve(n, nums):
    res = []
    s = 0
    m = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    s = sum(nums)
    ts = ""
    for i in xrange(len(nums)):
        if nums[i] > 0:
            ts += m[i]
    if len(ts) == 2:
        for i in xrange(s/2):
            res.append(ts)
        return " ".join(res)
    while s > 0:
        if s == 2:
            ts = ""
            for i in xrange(len(nums)):
                if nums[i] > 0:
                    ts += m[i]
            res.append(ts)
            break
        mx = 0
        mi = -1
        for i in xrange(len(nums)):
            if (nums[i] > mx):
                mx = nums[i]
                mi = i
        res.append(m[mi])
        nums[mi] -= 1
        s -= 1
    return " ".join(res)


p = Pool(8)
pr = []
with open("in.txt", "r") as fin:
    t = int(fin.readline())
    for i in xrange(t):
        n = int(fin.readline())
        nums = map(int, fin.readline().strip().split())
        pr.append(p.apply_async(solve, (n, nums)))
    p.close()
    p.join()
    with open("out.txt", "w") as fout:
        i = 0
        for res in pr:
            i += 1
            fout.write("Case #%d: %s\n" % (i, str(res.get())))
