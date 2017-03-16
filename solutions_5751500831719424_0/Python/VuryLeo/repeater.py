import sys

def minify(string):
    ans = '' + string[0]
    for i in range(1, len(string)):
        if string[i] != ans[-1]:
            ans += string[i]
    return ans

def count(string):
    count = [1]
    for i in range(1, len(string)):
        if string[i] != string[i - 1]:
            count.append(1)
        else:
            count[-1] += 1
    return count

if __name__=='__main__':
    n = int(sys.stdin.readline())
    for i in range(n):
        sys.stdout.write("Case #{}: ".format(i + 1))
        n = int(sys.stdin.readline())
        ans = ''
        strs = [sys.stdin.readline() for i in range(n)]
        minis = map(minify, strs)
        sminis = set(minis)
        if len(sminis) != 1:
            ans = 'Fegla Won'
        else:
            counts = map(count, strs)
            cos = [sorted([l[i] for l in counts]) for i in range(len(counts[0]))]
            mids = [c[len(cos[i]) / 2] for c in cos]
            ans = sum([sum([abs(c[i] - mids[i]) for i in range(len(c))]) for c in counts])
        sys.stdout.write("{}\n".format(ans))

