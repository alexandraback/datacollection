#include <iostream>
#include <algorithm>
#include <map>
#include <stack>
#include <time.h>
#include <vector>
#include <queue>
#include <set>
#include <random>
#include <string>
#include <fstream>

using namespace std;

#define ll long long

#define cin in
#define cout out
ifstream in("input.txt");
ofstream out("output.txt");

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test;
	cin >> test;
	for(int _ = 1; _ <= test; ++_)
	{
		int n;
		cin >> n;
		vector<int> v(n, 0);
		int sum = 0;
		for(int i = 0; i < n; ++i)
		{
			cin >> v[i];
			sum += v[i];
		}
		cout << "Case #" << _ << ": ";
		while(true)
		{
			vector<int> mxx(1, 0);
			for(int i = 1; i < n; ++i)
				if(v[mxx.back()] < v[i])
					mxx = vector<int>(1, i);
				else
					if(v[mxx.back()] == v[i])
						mxx.push_back(i);
			if(v[mxx.back()]==0)
			{
				cout << "\n";
				break;
			}
			if(mxx.size() & 1)
			{
				cout << char('A'+mxx.back()) << " ";
				v[mxx.back()]--;
				mxx.pop_back();
			}
			for(int i = 0; i < mxx.size(); i += 2)
			{
				cout << char('A'+ mxx[i]) << char('A'+mxx[i+1]) << " ";
				v[mxx[i]]--;
				v[mxx[i+1]]--;
			}
		}
	}

	return 0;
}
 