#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef unsigned long long ull;

#define rloop(i,a,b) for(i=a-1;i>=b;i--)
#define loop(i,a,b) for(i=a;i<b;i++)
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define gc getchar   
#define rz resize
#define all(x) x.begin(),x.end()
#define sz size

double rd()
{
	double ret = 0.0;
	char c = gc();
	while( (c<'0' || c>'9') && c!='.') 
		c = gc();
	while(c>='0' && c<='9') 
	{
		ret = 10 * ret + c - 48;
		c = gc();
	}
	if (c=='.')
	{
		c = gc();
		ll ten = 10;
		while(c>='0' && c<='9') 
		{
		  ret += (double)(c-48)/(ten*1.0);
		  ten *= 10;
		  c = gc();
		}	
	}
	return ret;
}

int ri()
{
	char c = gc();
	while((c<'0' || c>'9') && c!='-')
		c = gc();
	int ret = 0, neg = 1;
	if(c == '-')
	{
		neg = -1;
		c = gc();
	}
	while(c>='0' && c<='9')
	{
		ret = 10 * ret + c - 48;
		c = gc();
	}
	return ret * neg;
}

ll rl()
{
	char c = gc();
	while((c<'0' || c>'9') && c!='-')
		c = gc();
	ll ret = 0, neg = 1;
	if(c == '-')
	{
		neg = -1;
		c = gc();
	}
	while(c>='0' && c<='9')
	{
		ret = 10 * ret + c - 48;
		c = gc();
	}
	return ret * neg;		
}

string rs()
{
	char c = gc();
	while(c=='\n' || c==' ')
		c=gc();
	string ret="";
	while(c!=10 && c!=' ')
	{
		ret+=c;
		c=gc();
	}
	return ret;
}

char rc()
{
	char c = gc();
	while(c=='\n' || c==' ')
		c=gc();
	return c;
}


int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	ll t = rl(), caseno = 0;
	while (t--)
	{
		caseno++;
		ll n = rl(), i, sum = 0, j, index;
		vl a;
		loop (i, 0, n)
		{
			a.pb(rl());
			sum += a.back();
		}
		cout << "Case #" << caseno << ": ";
		while (sum--)
		{
			j = -1;
			index = 0;
			loop (i, 0, n)
			{
				if (a[i] > j)
				{
					j = a[i];
					index = i;
				}
			}
			a[index]--;
			cout << char(65 + index);

			j = -1;
			index = 0;
			loop (i, 0, n)
			{
				if (a[i] > j)
				{
					j = a[i];
					index = i;
				}
			}
			//cout << "sum = " << sum << "index=" << index << "a[in]="<< a[index] << endl;
			if (sum != 0 && 2 * a[index] > sum)
			{
				cout << char(65 + index);
				a[index]--;
				sum--;
			}
			cout << " ";
		}
		cout << endl;
	}
	return 0;
}