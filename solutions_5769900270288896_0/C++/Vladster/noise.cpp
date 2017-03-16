#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#define INP_FILE "B-small-attempt1.in"
#define OUT_FILE "output.txt"

#define rp(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define L(s) (int)s.size()
#define mp make_pair
#define pii pair<int,int>
//#define x first 
#define y second
#define inf 1000000000
#define vi vector<int>
#define vvi vector<vi >
#define ll long long
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define C(u) memset((u),0,sizeof((u)))
#define ull unsigned ll
#define uint unsigned int

int nd(int r, int x) 
{
    int g = r -r/2;
    if (x<=g) return 0;
    return 2*(x-g);
}

int bb(int r, int q,int w)
{
    return max(0, q+w-r);
}

int solve1(int r, int c, int n)
{
    int s = r*c;
    s = s - s/2;
    if (n<=s) return 0;
    if (n==r*s) return 2*r*s -r-c;
    if(c>r) swap(r,c);
    int a = n%c;
    int b = c-a;
    int z = n/c;
    int ans = a*nd(r,z+1) + b*nd(r,z);
    --a;
    int t=min(a,b);
    ans += 2*t*bb(r, z+1,z);
    a-=t;b-=t;
    if(a>0) ans+= a * bb(r,z+1,z+1);
    else if(b>0) {
        --b;
        ans+=bb(r, z+1,z);
        if(b>0) ans+= b*bb(r, z,z);
    }
    return ans;
}

int solve2(int r, int c, int n)
{
    /*{
    int s = r*c;
    s = s - s/2;
    if (n<=s) return 0;
    if (n==r*s) return 2*r*s -r-c;
    }/**/
    int up=1<<(r*c);
    int best=4*r*c;
    for(int it=0; it<up;++it)
    {
        int d=0,g=it; while(g){++d; g=g&(g-1);}
        if (d!=n) continue;
        int f=0;
        rp(i, r) {
            rp(j, c-1) {
                if ( (it&(1<<(i*c+j))) && (it&(1<<(i*c+j+1))) )
                    ++f;
            }
        }
        rp(i, r-1) {
            rp(j, c) {
                if ( (it&(1<<(i*c+j))) && (it&(1<<((i+1)*c+j))) )
                    ++f;
            }
        }
        best=min(best, f);
    }
    return best;
}

int main()
{
	freopen( INP_FILE , "r" , stdin );
	freopen( OUT_FILE , "w" , stdout );
	int tstCnt;
	cin>>tstCnt;

	for(int tst=1;tst<=tstCnt;tst++)
	{
        int r,c,n;cin>>r>>c>>n;
        int ans = solve2(r,c,n);
        printf("Case #%d: %d\n",tst, ans);
		//printf("Case #%d: ",tst);
	}
	
	return 0;
}