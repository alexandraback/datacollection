#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

typedef long long ll;

ll MOD = 1e9+7;

ll Gcd(ll a,ll b){
	ll r;
	while(1) {
		r=b%a;if(r==0) return a;
		b=a;a=r;
	}
}

ll Pow(ll a ,int b ,int Mo){
    ll ans = 1;
    for (; b; b >>= 1, a = a * a % Mo)
        if (b&1) ans = ans * a % Mo;
    return ans;
}

long solve() {
	int N;
	cin>>N;
	std::vector<int> v(N);
	int S=0;
	for (int i = 0; i < N; ++i)
	{
		cin>>v[i];
		S+=v[i];
	}

	while(1) {
		int MAX = 0;
		for (int i = 0; i < N; ++i)
		{
			if(2*v[i]>S)
			{
				cerr<<"Error!!!\n";
			}
			if(v[MAX]<v[i])
				MAX = i;
		}
		if(v[MAX]==0)
			break;
		v[MAX]--;
		S--;

		int MAX2 = -1;
		for (int i = 0; i < N; ++i)
		
		{
			if(MAX2==-1 || v[MAX2]<v[i])
				MAX2 = i;
		}
		cout<<(char)('A'+MAX);
		if(MAX2!=-1 &&  MAX2!=MAX) {
			v[MAX2]--;
			S--;
int flag = 0;
           for (int i = 0; i < N; ++i)
		{
			if(2*v[i]>S)
			{
				flag=1;
			}
			
		}
		if(flag)
		{
			v[MAX2]++;
			S++;
			cout<<' ';
			continue;
		}



			cout<<(char)('A'+MAX2);
		}
		cout<<' ';
		

	}
	
}

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	
	
	int T;
	cin>>T;
	for (int i = 0; i < T; ++i)
	{
			cout<<"Case #"<<i+1<<": ";
			solve();
			cout<<endl;
	}
	

	return 0;
}

