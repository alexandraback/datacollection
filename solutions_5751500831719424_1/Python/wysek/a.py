FEGLA_WON="Fegla Won"

def convert(s):
        res = []
        prev = s[0]
        count = 0
        for letter in s:
                if letter == prev:
                        count += 1
                else:
                        res.append((prev, count))
                        prev = letter
                        count = 1
        res.append((prev, count))
        return res

def median(l):
        mid = len(l) // 2
        if len(l) % 2 == 1:
                return l[mid]
        return (l[mid] + l[mid-1])//2

def solve():
        N = int(input())
        d = []
        for n in range(N):
                d.append(input())
        #print(d)
        d = list(map(convert, d))
        #print(d)
        n = len(d[0])
        if not all([len(x) == n for x in d]):
                return FEGLA_WON
        result = 0
        for i in range(n):
                counts = []
                prev = d[0][i][0]
                for s in d:
                        letter = s[i][0]
                        if letter != prev:
                                return FEGLA_WON
                        counts.append(s[i][1])
                counts.sort()
                m = median(counts)
                #print (counts, m)
                result += sum([abs(x-m) for x in counts])
        return result

def main():
	T = int(input())
	for t in range(1, T+1):
		r = solve()
		print("Case #%d: %s" % (t, r))

if __name__ == '__main__':
	main()
