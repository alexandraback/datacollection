//#define WYTE
#include<bits/stdc++.h>
#define X first
#define Y second
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x)
#define ALL(x) (x).begin(),(x).end()
#define INIT(x,y) memset((x),(y),sizeof(x))
#define PQ priority_queue
#define IT iterator
#define INF 1e9
#define EPS 1e-9
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

vector< pair<pii,int> > v;
bool cmp_y(pair<pii,int> a,pair<pii,int> b)
{
    if(a.X.Y!=b.X.Y)return a.X.Y<b.X.Y;
    return a.X.X<b.X.X;
}
bool cmp_angle(pair<pii,int> a,pair<pii,int> b)
{
    return atan2(a.X.Y-v[0].X.Y,a.X.X-v[0].X.X)<atan2(b.X.Y-v[0].X.Y,b.X.X-v[0].X.X);
}
ll isLeft(pii p1,pii p2,pii p3)
{
    return (ll)(p2.X-p1.X)*(p3.Y-p1.Y)-(ll)(p2.Y-p1.Y)*(p3.X-p1.X);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,ii,n,x,y,i,tree,ans1,ans2,error;
    vi Stack;
    cin>>t;
    for(ii=1;ii<=t;ii++)
    {
        v.clear();
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>x>>y;
            v.emplace_back(mp(x,y),i);
        }
        cout<<"Case #"<<ii<<":\n";
        if(n<=3)
        {
            for(i=0;i<n;i++)
            {
                cout<<"0\n";
            }
            continue;
        }
        sort(ALL(v),cmp_y);
        sort(v.begin()+1,v.end(),cmp_angle);
        for(tree=0;tree<n;tree++)
        {
            Stack.clear();
            Stack.emplace_back(0);
            if(v[0].Y==tree)
            {
                cout<<"0\n";
                continue;
            }
            Stack.emplace_back(1);
            if(v[1].Y==tree)
            {
                cout<<"0\n";
                continue;
            }
            for(i=2;i<v.size();i++)
            {
                while(isLeft(v[*(Stack.end()-2)].X,v[*(Stack.end()-1)].X,v[i].X)<0)
                {
                    Stack.pop_back();
                }
                Stack.emplace_back(i);
                if(v[i].Y==tree)break;
            }
            ans1=0;
            for(i++;i<v.size();i++)
            {
                error=0;
                while(isLeft(v[*(Stack.end()-2)].X,v[*(Stack.end()-1)].X,v[i].X)<0)
                {
                    if(v[*(Stack.end()-1)].Y==tree)
                    {
                        error=1;
                        ans1++;
                        break;
                    }
                    Stack.pop_back();
                }
                if(!error)
                {
                    Stack.emplace_back(i);
                }
            }
            for(i=0;i<Stack.size();i++)
            {
                if(isLeft(v[*(Stack.end()-2)].X,v[*(Stack.end()-1)].X,v[Stack[i]].X)<0)
                {
                    ans1++;
                }
                else
                {
                    break;
                }
            }
            reverse(v.begin()+1,v.end());
            Stack.clear();
            Stack.emplace_back(0);
            Stack.emplace_back(1);
            if(v[1].Y==tree)
            {
                cout<<"0\n";
                reverse(v.begin()+1,v.end());
                continue;
            }
            for(i=2;i<v.size();i++)
            {
                while(isLeft(v[*(Stack.end()-2)].X,v[*(Stack.end()-1)].X,v[i].X)>0)
                {
                    Stack.pop_back();
                }
                Stack.emplace_back(i);
                if(v[i].Y==tree)break;
            }
            ans2=0;
            for(i++;i<v.size();i++)
            {
                error=0;
                while(isLeft(v[*(Stack.end()-2)].X,v[*(Stack.end()-1)].X,v[i].X)>0)
                {
                    if(v[*(Stack.end()-1)].Y==tree)
                    {
                        error=1;
                        ans2++;
                        break;
                    }
                    Stack.pop_back();
                }
                if(!error)
                {
                    Stack.emplace_back(i);
                }
            }
            for(i=0;i<Stack.size();i++)
            {
                if(isLeft(v[*(Stack.end()-2)].X,v[*(Stack.end()-1)].X,v[Stack[i]].X)>0)
                {
                    ans2++;
                }
                else
                {
                    break;
                }
            }
            reverse(v.begin()+1,v.end());
            cout<<min(ans1,ans2)<<"\n";
        }
    }
}
