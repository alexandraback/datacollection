#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<climits>
#include<vector>
#include<stack>
#include<set>
#include<math.h>
using namespace std;
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define sint(i) scanf("%d",&i)
#define ss(s) scanf("%s",s)
#define pii pair<int,int>
#define mp(i,j) make_pair(i,j)
#define ll long long
#define MAX 1000000000
#define MOD 1000000007
#define vi vector<int>
#define vvi vector < vi >
#define pb(i) push_back(i);
#define tr(v,it) for(it=v.begin();it!=v.end();it++)
int main()
{
    freopen("test.in", "r", stdin);
    freopen("file.out", "w", stdout);
    int i;
    int t;
    cin>>t;
    int test;
    FOR(test,1,t)
    {
        int n;
        cin>>n;
        pii p[27];
int sum=0;
        FOR(i,1,n)
        {
            cin>>p[i].first;
            p[i].second=i;
            sum+=p[i].first;
        }
        cout<<"Case #"<<test<<": ";
        while(sum)
        {
            sort(p+1,p+n+1);
            reverse(p+1,p+n+1);
            if((p[1].first==p[2].first) && n>=3 && p[3].first!=0 && p[1].first==1)
            {
                sum--;
                p[1].first--;
                cout<<((char)('A'-1+p[1].second))<<" ";
            }
            else if(p[1].first==p[2].first)
            {
                sum=sum-2;
                p[1].first--;
                p[2].first--;
                cout<<((char)('A'-1+p[1].second))<<((char)('A'-1+p[2].second))<<" ";
            }
            else
            {
                sum--;
                p[1].first--;
                cout<<((char)('A'-1+p[1].second))<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
