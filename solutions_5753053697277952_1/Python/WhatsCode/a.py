inp = open('a.in')
out = open('a.out', "w")

debug_model = False

T = int(raw_input()) if debug_model else int(inp.readline())

ary = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

def cnt(dictr):
    ans = []
    for d in dictr:
        if dictr[d] > 0:
           ans.append([dictr[d], d])
    return ans

for i in xrange(T):
    answer = ""
    N = int(raw_input()) if debug_model else int(inp.readline())
    ps = raw_input().split() if debug_model else inp.readline().split()
    dic = {}
    for j in xrange(len(ps)):
        dic[ary[j]] = int(ps[j])

    tmp = cnt(dic)
    tmp.sort()
    if len(tmp) == 2:

        for x in xrange(tmp[0][0]):
            answer += ' ' + str(tmp[0][1])+str(tmp[1][1])
        if debug_model:
            print "Case #" + str(i+1) + ":" + answer
        else:
            out.write("Case #" + str(i+1) + ":" + answer + '\n')

    else:

        while tmp[-1][0] > tmp[-2][0]:
            answer += ' ' + str(tmp[-1][1])
            tmp[-1][0] -= 1
        for x in xrange(len(tmp)-2):
            for j in xrange(tmp[x][0]):
                answer += ' ' + str(tmp[x][1])
        for x in xrange(tmp[-1][0]):
            answer += ' ' + str(tmp[-1][1])+str(tmp[-2][1])

        if debug_model:
            print "Case #" + str(i+1) + ":" + answer
        else:
            out.write("Case #" + str(i+1) + ":" + answer + '\n')








