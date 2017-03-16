import sys

def solve(n, p):
    sm = sum(p)
    ans = ""
    while sm>0:
        mx = 0
        for i, k in enumerate(p):
            if (p[mx]<k):
                mx = i
        mx2 = (mx+1) % n
        for i, k in enumerate(p):
            if (mx!=i and p[mx2]<k):
                mx2 = i            
        if p[mx]>=2 and (p[mx]>p[mx2]+1 or mx==mx2):
            ans += chr(ord('A')+mx)*2+" "
            p[mx] -= 2
        elif (sm==1 or sm==3):
            ans += chr(ord('A')+mx)+" "
            p[mx] -= 1
            sm+=1
        else:
            ans += chr(ord('A')+mx)+chr(ord('A')+mx2)+" "
            p[mx] -= 1
            p[mx2] -= 1
        print p
        sm-=2
    return ans

#input_filename = sys.argv[1]
input_filename = "A-large.in"#"in.txt" 

with open(input_filename, "r") as infile:
    with open("out.txt", "w") as outfile:
        tnum = int(infile.readline())
        for t in xrange(tnum):
            N = int(infile.readline().strip())
            P = map(int, infile.readline().split())
            ans = solve(N, P)
            outfile.write("Case #%d: %s\n" % (t+1, ans))
            print (t+1, ans)
        