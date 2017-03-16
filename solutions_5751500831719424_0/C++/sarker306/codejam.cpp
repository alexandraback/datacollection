#include <cstdio>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <bitset>

#define FOR(i, a, b) for (i = (a); i <= (b); i++)
#define REP(i, a) for (i = 0; i < (a); i++)
#define ALL(v) (v).begin(), (v).end()
#define SET(a, x) memset((a), (x), sizeof(a))
#define SZ(a) ((int)(a).size())
#define CL(a) ((a).clear())
#define SORT(x) sort(ALL(x))
#define mp make_pair
#define pb push_back
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

#define filer() freopen("in.txt","r",stdin)
#define filew() freopen("out.txt","w",stdout)

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

char str[101][101];
int N;
vector<char> run[101];
vector<int> runLen[101];

int main(){
    int test, ks;
    
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    while ( scanf("%d", &test) == 1 ){
        for ( ks = 1 ; ks <= test ; ks++ ){
            scanf("%d", &N);
            
            for ( int i = 0 ; i < N ; i++ ){
                scanf("%s", str[i]);
                
                char ch = str[i][0];
                int lenth = 1;
                for ( int j = 1 ; str[i][j] != 0 ; j++ ){
                    if ( ch != str[i][j] ){
                        run[i].push_back(ch);
                        runLen[i].push_back(lenth);
                        lenth = 1;
                        ch = str[i][j];
                    }
                    
                    else lenth++;
                }

                run[i].push_back(ch);
                runLen[i].push_back(lenth);
                
                /*cout << run[i].size() << endl;
                /*for ( int j = 0 ; j < run[i].size() ; j++ ) printf("(%c, %d) ", run[i][j], runLen[i][j]);
                puts("");*/
            }
            
            printf("Case #%d: ", ks);
            int res = 0;
            int flag = 1;
            
            for ( int j = 1 ; j < N ; j++ ){
                if ( run[j].size() != run[j-1].size() ) flag = 0;
            }
            
            if ( flag == 1 ){
                for ( int i = 0 ; i < run[0].size() ; i++ ){
                    vector<int> tmp;
                    char ch = run[0][i];
                    for ( int j = 0 ; j < N ; j++ ){
                        if ( run[j][i] == ch ) tmp.push_back(runLen[j][i]);
                        else flag = 0;
                    }

                    if ( flag == 0 ) break;
                    
                    if ( tmp.size() == 0 ) continue;
                    if ( tmp.size() != N ) flag = 0;
                    sort(tmp.begin(), tmp.end());

                    int sm = 0;
                    for ( int j = 0 ; j < N ; j++ ){
                        sm += abs(tmp[N/2] - tmp[j]);
                    }

                    res += sm;
                }
            }
            
            
            if ( !flag ) printf("Fegla Won\n");
            else printf("%d\n", res);
            
            for ( int i = 0 ; i < N ; i++ ) run[i].clear() , runLen[i].clear();
        }
    }
    
    return 0;
}
