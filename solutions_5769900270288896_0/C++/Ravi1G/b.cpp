#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
#include <iterator>
#define getI(a) scanf("%d", &a)
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define getL(a) scanf("%lld", &a)
#define wez(n) int (n); scanf("%d",&(n))
#define TESTS wez(testow); while(testow--)
#define F(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define MAX(a,b) ( (a) < (b) ? (b) : (a) )
#define MIN(a,b) ( (a) < (b) ? (a) : (b) )
#define tr(i,t) for (typeof((t).begin()) i=(t).begin(); i!=(t).end(); i++) // traverse an STL data structure
#define ALL(c) (c).begin(),(c).end() //handy for function like "sort()"
#define PRESENT(c,x) ((c).find(x) != (c).end())
#define CPRESENT(c,x) (find(ALL(c),x) != (c).end())
#define REMIN(a,b) (a)=min((a),(b))
#define REMAX(a,b) (a)=max((a),(b)) // set a to the maximum of a and b
#define SZ(x) ((int)((x).size()))
#define lastEle(vec) vec[vec.size()-1]
#define pb push_back
#define mp make_pair

//Debug Macros
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl
#define printA(a,L,R) FE(i,L,R) cerr << a[i] << (i==R?'\n':' ')
#define printV(a) printA(a,0,a.size()-1)



#define MODN 1000000007
#define INF  1000000000
#define PI 3.1415926535897932384626
#define LSOne(S) (S & (-S))
#define MAXN 110

using namespace std;

typedef vector<int> vi;
typedef vector< vi > vvi;
typedef pair<int,int> ii;
typedef long long ll;
int dp[16][16];

int bc(int n){
    int ans = 0;

    while(n){
        if(n%2) ans++;
        n = n /2;
    }
    return ans;
}
int ccc(int r, int c){
    int aa = 0;
    F(i,0,r){
        F(j,0,c-1){
            if(dp[i][j]==1 && dp[i][j+1]==1) aa++;
        }
    }
    F(i,1,r){
        F(j,0,c){
            if(dp[i][j]==1 && dp[i-1][j]==1) aa++;
        }
    }

    return aa;
}



int main(int argc, char const *argv[])
{

    int r , n, c , rc;

  int cno = 1;
  TESTS{
    getIII(r,c,n);
    rc = r*c;
    int ans=100000000;
    F(i,0,(1<<rc) ){
        if(bc(i)==n){

            F(j,0,rc){
                if(i & (1<<j)) dp[j/c][j%c]=1;
                else dp[j/c][j%c]=0;

            }
            ans = MIN(ans,ccc(r,c));
            //cerr<<ans<<" "<<i<<endl;
           // F(i,0,r) printA(dp[i],0,c-1);
        }

    }

    cerr<<cno<<endl;
    printf("Case #%d: %d\n", cno++, ans );
  }

  return 0;
}

