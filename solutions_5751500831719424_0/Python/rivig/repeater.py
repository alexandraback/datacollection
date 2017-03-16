import sys, string

def repeater(n, ss):
    ans = 0
    ps = [0 for s in ss]
    has_letters = True
    while has_letters:
        # Check that current position is homogenious
        # in letters and take run lengths
        runs = [0 for s in ss]
        cur_letter = ''
        for i in range(n):
            pos = ps[i]
            s = ss[i]
            a = s[pos]
            if not cur_letter:
                cur_letter = a
            elif cur_letter != a:
                return "Fegla Won"
            run = 1
            pos += 1
            while pos < len(s) and s[pos] == cur_letter:
                run += 1
                pos += 1
            ps[i] = pos
            runs[i] = run
            has_letters = has_letters and (pos < len(s))
#        print "runs of ", cur_letter, runs
        runs.sort()
        if len(runs) % 2 == 1:
            mid = runs[(len(runs)-1)/2]
        else:
            l2 = len(runs)/2
            mid = (runs[l2-1] + runs[l2])/2
        for run in runs:
            ans += abs(run - mid)
    # Check that we exhausted sequence simultaneously
    for i in range(n):
        if ps[i] < len(ss[i]):
            return "Fegla Won"
    return ans

def main(args):
    f = file(args[1])
    ncases = int(f.readline())
    for i in range(ncases):
        line = f.readline()
        line = line.rstrip()
        n = int(line)
        ss = []
        for j in range(n):
            line = f.readline()
            ss.append(line.rstrip())
#        print "Case", i+1
        ans = repeater(n, ss)
        sys.stdout.write("Case #%d: %s\n" % (i+1, ans))

if __name__ == "__main__":
    main(sys.argv)