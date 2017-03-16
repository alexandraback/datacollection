#!/usr/bin/env python


def read():
    ret = []
    for i in range(int(raw_input())):
        ret.append(raw_input())
    return ret


def work(cases, sList):
    ch_n_List = []
    
    for s in sList:
        ch_n_List.append([])
        idx = 0
        while idx < len(s):
            nexIdx = idx
            while nexIdx < len(s) and s[nexIdx] == s[idx]:
                nexIdx += 1
            ch_n_List[-1].append((s[idx], nexIdx - idx))
            idx = nexIdx


    isOk = True
    for i in range(len(sList)):
        if len(ch_n_List[i]) != len(ch_n_List[0]):
            isOk = False
            break

        for j in range(len(ch_n_List[i])):
            if ch_n_List[i][j][0] != ch_n_List[0][j][0]:
                isOk = False
                break
        
        if not isOk:
            break

    
    if not isOk:
        print "Case #%d: Fegla Won" % cases
        return
    

    ans = 0
    for i in range(len(ch_n_List[0])):
        minV = 1<<20
        for base in range(1, 100 + 1):
            tot = 0
            for j in range(len(ch_n_List)):
                tot += abs(base - ch_n_List[j][i][1])
            minV = min(minV, tot)
        ans += minV

    print "Case #%d: %d" % (cases, ans)

   
if __name__ == "__main__":
    for i in range(int(raw_input())):
        work(i + 1, read())
