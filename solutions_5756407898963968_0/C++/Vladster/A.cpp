#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
#include <iterator>

using namespace std;

#define INP_FILE "input.txt"
#define OUT_FILE "output.txt"

#define rp(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define L(s) (int)s.size()
#define mp make_pair
#define pii pair<int,int>
#define x first 
#define y second
#define inf 1000000000
#define VI vector<int>
#define ll long long
#define all(s) (s).begin(),(s).end()
#define C(u) memset((u),0,sizeof((u)))
#define ull unsigned ll
#define uint unsigned int


int main()
{
	freopen( INP_FILE , "r" , stdin );
	freopen( OUT_FILE , "w" , stdout );
	int tstCnt;
	cin>>tstCnt;

	for(int tst=1;tst<=tstCnt;tst++)
	{
        vector<int>  a,b;
        int n = 4;
        int row;
        cin>>row;
        rp(i, n) { 
            rp(j, n) {
                int t; cin>>t;
                if (i+1==row) {
                    a.pb(t);
                }
            }
        }
        cin>>row;
        rp(i, n) { 
            rp(j, n) {
                int t; cin>>t;
                if (i+1==row) {
                    b.pb(t);
                }
            }
        }
        vector<int> v; sort(all(a)); sort(all(b));
        set_intersection(all(a), all(b), back_inserter(v));
        printf("Case #%d: ",tst);
        if (v.size()==1) {
            printf("%d", v[0]);
        }else{
            printf(v.size()==0 ? "Volunteer cheated!" : "Bad magician!");
        }
        printf("\n");
	}
	
	return 0;
}