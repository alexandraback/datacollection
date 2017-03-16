#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <map>
#include <fstream>
#include <ctime>
#include <climits>
#include <bitset>
#include <cmath>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
 
#define FOR(i,f,t) for(int i = f;i<t;i++)
#define For(i, t) for(int i = 0;i<t;i++)
#define ITER(it, a) for(typeof (a.begin()) it = a.begin();it != a.end();it++)
#define range(cont) cont.begin(), cont.end()
#define mp(i,j) make_pair(i,j)
#define pb push_back
#define inf 100000

using namespace std;
using namespace std::tr1;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int cc,n;
string x[110];
char buff[100000];
int st[110], cont[110];

int change(int wh, int to){
    int ans = 0,i = 0,j=0;
    while(i < x[wh].size() && j < x[to].size()){
        int ti =i, tj = j;
        while(x[wh][i] == x[wh][ti])ti++;
        while(x[to][j] == x[to][tj])tj++;

        if(x[wh][i] != x[to][j])break;
        else{
            ans += abs((tj - j) - (ti - i));
            i = ti;
            j = tj;
        }
    }
    if(i < x[wh].size() || j < x[to].size())ans = inf;
    return ans;
}


int main() {

    scanf("%d\n", &cc);
    For(cas, cc){
        scanf("%d\n", &n);
        For(i, n){
            gets(buff);
            x[i] = buff;
        }
        For(i, 110)st[i] = 0;

        int ans = 0,fin = 0;
        while(true){
            int mv = inf, mx = 0;
            For(i ,n)if(x[i][st[i]] != x[0][st[0]]){ans = inf;break;}
            For(i, n){
                cont[i] = st[i];
                while(x[i][st[i]] == x[i][cont[i]]){cont[i]++;}
                if(cont[i] >= x[i].size()){
                    //printf("%d\n", cont[i]);
                    fin = 1;
                }
                mx = max(cont[i] - st[i], mx);
            }
            /*For(i, n){
                printf("%d\n", cont[i]);
            }*/

            FOR(i ,1,mx+1){
                int t = 0;
                For(j,n)t += abs(cont[j] - st[j] - i); 
                mv = min(t, mv);
            }
            For(i,n)st[i] = cont[i];
            ans += mv;
            if(fin){
                For(i, n)if(x[i].size() > cont[i])ans = inf;
                break;
            }
        }

        printf("Case #%d: ", cas+1);
        if(ans >= inf)puts("Fegla Won");
        else printf("%d\n" , ans);
    }
    return 0;
}