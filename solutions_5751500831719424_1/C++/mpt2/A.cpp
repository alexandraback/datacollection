#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <climits>
using namespace std;
#define db(a) (cout << #a << " = " << a << endl)
typedef long long ll;

string strs[128];
ll ind[128];
ll D[128];

int main()
{
  int T;
  cin>>T;
  for(int t=1;t<=T;t++)
  {
	int N;
	cin>>N;	
	for(int i=0;i<N;i++) {cin>>strs[i]; ind[i] = 0;}
	ll erg = 0;
	while(ind[0] != string::npos)
	{
		char c = strs[0][ind[0]];
		for(int i=0;i<N;i++) if(strs[i][ind[i]] != c) erg = -1;
		if(erg==-1) break;
		for(int i=0;i<N;i++)
		{
			ll d = strs[i].find_first_not_of(c, ind[i]);
			D[i] = d - ind[i];	
			if(d == string::npos) D[i] = strs[i].size() - ind[i];
			ind[i] = d;
		}	
		ll a = INT_MAX;
		ll minv(INT_MAX), maxv(0);
		for(int i=0;i<N;i++)
		{
			minv = min(minv, D[i]);
			maxv = max(maxv, D[i]);
		}
		for(ll i=minv;i<=maxv;i++)
		{
			ll curr = 0;
			for(int j=0;j<N;j++)
			{
				curr += abs(i - D[j]);
			}
			if(curr < a) a = curr;
		}
		erg += a;
	}
	for(int i=0;i<N;i++) if(ind[i] != string::npos) erg = -1;
	cout << "Case #" << t << ": ";
	if(erg == -1) cout << "Fegla Won\n";
	else cout << erg << "\n";
	
  }
  return 0;
}
