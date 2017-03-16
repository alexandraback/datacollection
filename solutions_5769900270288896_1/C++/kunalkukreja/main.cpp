#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include<iomanip>
using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define pb push_back
#define sz size()
#define ln length()
#define fore(i,a,b) for(int i=a;i<b;i++)
#define fores(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define mp make_pair
#define ff first
#define ss second
#define sc(a) scanf("%d",&a)
#define md 1000000007

int main() {
	freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	fore(z,0,t)
	{
		printf("Case #%d: ",z+1);
		int r,c,n;
		cin>>r>>c>>n;
		int tot = r*c;
		if(n<=(tot+1)/2)
        {
            cout<<0<<endl;
            continue;
        }
        vector<vi> mat(r,vi(c,0));
        if(tot%2==0)
        {
            fore(i,0,r)
            {
                for(int j = i%2;j<c;j+=2)
                    mat[i][j] = 1;
            }
            vi nos;
            fore(i,0,r)
            {
                fore(j,0,c)
                {
                    if(mat[i][j]==1)
                        continue;
                    int count = 0;
                    if(i!=0)
                        count++;
                    if(i!=r-1)
                        count++;
                    if(j!=0)
                        count++;
                    if(j!=c-1)
                        count++;
                    nos.pb(count);
                }
            }
            sort(all(nos));
            int add = n-(tot/2);
            ll fa = 0;
            fore(i,0,add)
                fa+=nos[i];
            cout<<fa<<endl;
        }
        else
        {
            vector<vi> mat2(r,vi(c,0));
            fore(i,0,r)
            {
                for(int j = i%2;j<c;j+=2)
                    mat[i][j] = 1;
                for(int j = (i+1)%2;j<c;j+=2)
                    mat2[i][j] = 1;
            }
            vi nos,nos2;
            fore(i,0,r)
            {
                fore(j,0,c)
                {
                    if(mat[i][j]==1)
                        continue;
                    int count = 0;
                    if(i!=0)
                        count++;
                    if(i!=r-1)
                        count++;
                    if(j!=0)
                        count++;
                    if(j!=c-1)
                        count++;
                    nos.pb(count);
                }
            }
            fore(i,0,r)
            {
                fore(j,0,c)
                {
                    if(mat2[i][j]==1)
                        continue;
                    int count = 0;
                    if(i!=0)
                        count++;
                    if(i!=r-1)
                        count++;
                    if(j!=0)
                        count++;
                    if(j!=c-1)
                        count++;
                    nos2.pb(count);
                }
            }
            sort(all(nos));
            sort(all(nos2));
            int add2 = n-(tot/2);
            int add = add2-1;
            ll fa1 = 0,fa2 = 0;
            fore(i,0,add)
                fa1+=nos[i];
            fore(i,0,add2)
                fa2+=nos2[i];
            cout<<min(fa1,fa2)<<endl;
        }
	}
	return 0;
}
