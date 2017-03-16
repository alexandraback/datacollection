#include <iostream>
#include <sstream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define XINF INT_MAX
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
int a[100];
int G[110][110];
int main()
{
	ios::sync_with_stdio(false);
    freopen("B-small-attempt1.in","r",stdin);
	freopen("b.out","w",stdout);
	int t;
	cin>>t;
	int cas=1;
	while(t--){
        int r,c,n;
        cin>>r>>c>>n;
        cout<<"Case #"<<cas++<<": ";
        if(n<=(r*c+1)/2){
            cout<<0<<endl;
            continue;
        }
        for(int i=0;i<r*c;i++)a[i]=0;
        for(int i=0;i<n;i++)a[i]=1;
        sort(a,a+r*c);
        int ans = 10000;
        do{
            for(int i=0;i<r*c;i++){
                if(a[i]){
                    G[i/c][i%c]=1;
                }
            }
            int num=0;
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(!G[i][j])continue;
                    if(i+1<r&&G[i+1][j])num++;
                    if(j+1<c&&G[i][j+1])num++;
                    G[i][j]=0;
                }
            }
            ans=min(num,ans);
        }while(next_permutation(a,a+r*c));
        cout<<ans<<endl;
	}
	return 0;
}



