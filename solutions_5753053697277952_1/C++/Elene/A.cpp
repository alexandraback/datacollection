#include <bits/stdc++.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define F first
#define S second
#define pp pair<int,int>
#define mp make_pair
#define pb push_back
#define ll long long
#define INF 2000000
#define P 1000000007
#define E 10000000
#define vec vector<vector<ll> >
using namespace std;
const int N=100005;

int T;
vector<pair<int,char> > v;

int main()
{   freopen("A-large.in","r",stdin);
    freopen("output.txt","w",stdout);


    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            v.pb(mp(x,char('A'+i-1)));
        }

        cout<<"Case #"<<t<<":";
        sort(v.rbegin(),v.rend());

        while(v.size()){
            if(v.size()==2 && v[0].F==v[1].F){
                v[0].F--;
                v[1].F--;
                cout<<" "<<v[0].S<<v[1].S;
            }else{
               cout<<" "<<v[0].S;
                v[0].F--;
            }
            sort(v.rbegin(),v.rend());


            while(v.size() && v.back().F==0)v.pop_back();
        }
        cout<<endl;

        v.clear();

    }

    return 0;
}
