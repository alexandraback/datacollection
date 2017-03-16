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
#include <cstdio>
#include <set>
#include <unordered_map>
#include <iomanip>
using namespace std;
#define db(a) (cout << (#a) << " = " << (a) << endl)
typedef long long ll;

int N;
vector<int> S;

int main()
{
  ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int tt=0;tt<T;tt++)
	{
		cin>>N;
		S.clear();
		for(int i=0;i<N;i++)
		{
			int x;
			cin>>x;
			S.push_back(x);
		}
		
		cout << "Case #" << tt+1 << ":";
		while(true)
		{
			vector<size_t> mpos;
			int maxv = 0;
			for(size_t i =0;i<S.size();i++)
			{
				if(S[i] > maxv) {mpos.clear(); maxv = S[i];}
				if(S[i] == maxv) mpos.push_back(i);
			}
			if(maxv == 0) break;
			if(mpos.size() == 1 || mpos.size() > 2)
			{
				cout << " " << char('A'+mpos[0]);
				S[mpos[0]]--;
			}
			else if(mpos.size() == 2)
			{
				cout << " " << char('A'+mpos[0]) << char('A'+mpos[1]);
				S[mpos[0]]--;
				S[mpos[1]]--;
			}
		}
		
		cout << "\n";
		}
  return 0;
}
