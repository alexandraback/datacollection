
# coding: utf-8

# In[40]:

import heapq

def get_res(P):
    N = len(P);
    res = '';
    cnt = sum(P)
    while cnt > 0:
        cnt_new = cnt;
        if cnt % 2 == 0:
            threshold = cnt // 2;
        else:
            threshold = cnt // 2 + 1;
        for i in range(N):
            if P[i] >= threshold:
                P[i] -= 1;
                cnt_new -= 1;
                res += chr(ord('A') + i);
        if cnt_new == cnt:
            for i in range(N):
                if P[i] >= 1:
                    P[i] -= 1;
                    cnt_new -= 1;
                    res += chr(ord('A') + i);
                    break;
        cnt = cnt_new;
        res = res + ' ';
    return(res.strip())



fin_name = 'A-small-attempt0.in';
fout_name = 'A-small-attempt0.out';
fout = open(fout_name, 'w');
with open(fin_name, 'r') as fin:
    T = int(next(fin));
    for case in range(1, T+1):
        N = int(next(fin));
        P = list(map(int, next(fin).strip().split()));
        #print(P)
        res = get_res(P);
        #print(res)
        line = 'Case #{0}: {1}\n'.format(str(case), res);
        fout.write(line);
fout.close();


# In[ ]:



