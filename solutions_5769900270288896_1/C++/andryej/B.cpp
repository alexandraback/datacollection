#include <queue>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

#define print       for(int i=0;i<R;++i) \
                              for(int j=0;j<C || !puts("");++j) \
                                 printf("%c ",T[i][j]? 'X' : '.');
#define CNT(i,j)    CHCK(i+1,j) + \
                    CHCK(i-1,j) + \
                    CHCK(i,j+1) + \
                    CHCK(i,j-1)

#define ONB(i,j)    ((0<=i && i<R && 0<=j && j<C))
#define CHCK(i,j)   (ONB(i,j) ? T[i][j] : 0)


vector<vector<int > > T;
int R,C,N;

typedef pair<int,int> PII;

struct Cmp {
    bool operator()(const PII& a, const PII& b) const {
        int cA = CNT(a.first, a.second);
        int cB = CNT(b.first, b.second);
        return cA > cB;
    }   
};

bool cmp(const PII& a, const PII& b)
{
        int cA = CNT(a.first, a.second);
        int cB = CNT(b.first, b.second);
        return cA < cB;
}

int main()
{
    int ts;
    scanf("%d", &ts);
    for(int tta=1; tta <= ts; ++tta)
    {
        int res = 0;
        scanf("%d %d %d",&R, &C, &N);
        if (N <= ((R * C) >> 1)) res = 0;
        else
        {
            T.resize(R);
            for(int i=0;i<R;++i) T[i].resize(C);
            int W = 0;
            int x = 1;
            int n = N;
            for(int i = 0; i <  R; ++i)
                for(int j = 0, w=x&i; j < C; ++j, w^=1)
                    T[i][j] = w;
            vector<PII> kol;                     
            for(int i = 0; i <  R; ++i)
                for(int j = 0 ; j < C; ++j)
                {
                    if (!T[i][j]) kol.push_back(PII(i,j));
                    else --n;
                }
            sort(kol.begin(), kol.end(), cmp);
            int idx = 0;
            while (n)
            {
                PII node = kol[idx++];
               // printf("%d %d : %d\n",node.first, node.second, CNT(node.first, node.second));
                res += CNT(node.first, node.second);
                --n;
            }
            W = res;
            res  = 0;
            x=0;
            for(int i = 0; i <  R; ++i)
                for(int j = 0, w=!((!x)&i); j < C; ++j, w^=1)
                    T[i][j] = w;
            kol.clear();
            for(int i = 0; i <  R; ++i)
                for(int j = 0 ; j < C; ++j)
                {
                    if (!T[i][j]) kol.push_back(PII(i,j));
                }
            sort(kol.begin(), kol.end(), cmp);
            idx = 0;
            //printf("KOL SIZE %d | N %d\n",kol.size(),n);
            n = N-(R*C-kol.size());
            while (n)
            {
                PII node = kol[idx++];
                //printf("%d %d : %d\n",node.first, node.second, CNT(node.first, node.second));
                res += CNT(node.first, node.second);
                --n;
            }
            res = min(res,W);
        }
        printf("Case #%d: %d\n",tta,res);        
    }
    return 0;
}
