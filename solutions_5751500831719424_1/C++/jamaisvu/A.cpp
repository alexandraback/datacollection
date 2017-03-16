#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define MP make_pair
#define PB push_back
#define TR(it,c) for( typeof(c.begin()) it = c.begin(); it != c.end(); ++it )
#define TRR(it,c) for( typeof(c.rbegin()) it = c.rbegin(); it != c.rend(); ++it
#define REP(i,a) for (int i = 0; i < (a); i++)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)

#define DRI(a) int a; scanf("%d", &a);
#define DRII(a, b) int a, b; scanf("%d %d", &a, &b);
#define RI(a) scanf("%d", &a);
#define RII(a, b) scanf("%d %d", &a, &b);

#define MM(arr, num) memset((arr), (num), sizeof((arr)))

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long ll;
typedef unsigned long long ull;
/*******************************************************/
int cs, N;

char s[105][105];
char ns[105][105];

int len[105];
int nlen[105];
int num[105];
int p[105];
int OUT;

int sol( int a){
      int out = 0;
      REP(i,N){
        //cout << num[i] << endl;
        out += abs(a-num[i]);
      }
      return out;
}


bool solve(){

      REP(i,N){
          scanf("%s",s[i]);
          len[i] = strlen(s[i]);
        }
        REP(i,N){
          nlen[i] = 1;

          ns[i][0] = s[i][0];
          FOR(j,1,len[i]-1){
            if( s[i][j] != s[i][j-1] )ns[i][nlen[i]++  ] = s[i][j];
          }

        }

        FOR(i,1,N-1) if( nlen[i] != nlen[i-1] ) return false;


        REP(i,nlen[0]){
          REP(j,N){
           // cout << ns[j][i] << " " <<  ns[0][i] << endl;
            if (ns[j][i] != ns[0][i])return false;
          }
        }

        OUT = 0;


        REP(i,N)p[i] = 1;

        while(p[0] <= len[0]){

            REP(i,N)num[i] = 1;
            FOR(i,0,N-1){
                while( p[i] < len[i] && s[i][p[i]] == s[i][p[i]-1] ){p[i]++;  num[i]++; }
            }

            int MIN = INF;
            FOR(i,1,100){
                MIN = min ( sol(i), MIN);
            }
            //cout << MIN << "." << endl;
            OUT += MIN;

            REP(i,N)p[i]++;

        }



        return true ;

}

int main() {

    	//freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
      freopen("A-large.in","r",stdin);freopen("A-large.out","w",stdout);


    scanf("%d",&cs);
    FOR(ii,1,cs){

        RI(N);


        if ( !solve() )printf("Case #%d: Fegla Won\n",ii );
        else printf("Case #%d: %d\n",ii, OUT );
    }


    return 0;
}
