
/*
Author : Vivek Hamirwasia

A programmer started to cuss,
Because getting to sleep was a fuss.
As he lay there in bed,
Looping 'round in his head,
Was: while(!asleep()) sheep++;

 */
#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
#include<climits>
#include<cstring>
using namespace std;

#define CLR(a,x) memset(a,x,sizeof(a))
#define PB push_back
#define INF 1000000000
#define MOD 1000000007
#define MP make_pair
#define tr(container , it) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define LLD long long
#define VI vector < int >
#define PII pair < int , int >

#define gi(x) scanf("%d",&x)
#define gl(x) scanf("%lld",&x)
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf("%s",x)

#define pis(x) printf("%d ",x)
#define pls(x) printf("%lld ",x)
#define pin(x) printf("%d\n",x)
#define pln(x) printf("%lld\n",x)
#define pds(x) printf("%.12f ",x)
#define pdn(x) printf("%.12f\n",x)
#define pnl() printf("\n")
#define MAX 1000000000
string s;
int cnt[103][103];
char ch[103][103];
int pos[103];
vector<int> V[103];
int main()
{
    int t;
    cin>>t;
    int kase = 0;
    while(t--)
    {
	kase++;

	for(int i=0;i<=100;i++)
	    V[i].clear();

	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	    cin>>s;
	    int len = s.size();
	    pos[i]  = 0;
	    ch[i][pos[i]] = s[0];
	    cnt[i][pos[i]]  = 1;
	    int j = 1;
	    while(j<len)
	    {
		if(s[j]==s[j-1])
		{
		    cnt[i][pos[i]]++;
		}
		else
		{
		    pos[i]++;
		    ch[i][pos[i]] = s[j];
		    cnt[i][pos[i]] = 1;
		}
		j++;
	    }
	}


	int God = pos[0]+1;

	for(int j=0;j<God;j++)
	    V[j].PB(cnt[0][j]);

	bool f = 1;
	for(int i=1;i<n;i++)
	{
	    if(pos[i] + 1 != God)
	    {
		f = 0;
		break;
	    }

	    for(int j=0;j<God;j++)
	    {
		if(ch[i][j] != ch[i-1][j])
		{
		    f = 0;
		    break;
		}
		else
		    V[j].PB(cnt[i][j]);
	    }

	    if(!f)
		break;
	}

	cout<<"Case #"<<kase<<": ";

	if(!f)
	{
	    cout<<"Fegla Won\n";
	    continue;
	}

	int ans = 0;
	for(int j=0;j<God;j++)
	{
	    sort(V[j].begin(), V[j].end());
	    int med = V[j][n/2];
	    for(int i=0;i<n;i++)
		ans += abs(V[j][i]-med);
	}

	cout<<ans<<endl;

    }

    return 0;
}
