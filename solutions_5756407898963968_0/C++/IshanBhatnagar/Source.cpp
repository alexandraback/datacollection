#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <limits>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll	MOD = 1000000007LL;
const double PI = 2*acos(0);

int main(void)
{

	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	std::ios_base::sync_with_stdio(false);
	int i, j, k;

	int t, ans1, ans2, x;
	set<int> list;
	vector<int> matches;
	cin >> t;

	for(k=1; k<=t; ++k)
	{
		matches.clear();
		list.clear();

		cin >> ans1;
		for(i=0; i<4; ++i){
			for(j=0; j<4; ++j){
				cin >> x;
				if(i+1 == ans1)
					list.insert(x);
			}
		}

		cin >> ans2;
		for(i=0; i<4; ++i){
			for(j=0; j<4; ++j){
				cin >> x;
				if(i+1 == ans2)
					if(list.find(x) != list.end())
						matches.push_back(x);
			}
		}

		cout << "Case #" << k << ": ";
		if(matches.size() == 0)
			cout << "Volunteer cheated!\n";
		else if(matches.size() == 1)
			cout << matches[0] << "\n";
		else
			cout << "Bad magician!\n";

	}

	return 0;
} 