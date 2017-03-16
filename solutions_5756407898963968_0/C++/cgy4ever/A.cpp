#include <algorithm>
#include <iostream>
#include <iomanip>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
//#include <ctime>
#include <map>
using namespace std;

vector <int> getIt()
{
	vector <int> ret;
	int row;
	cin >> row;
	for(int i = 1; i <= 4; i++)
		for(int j = 1; j <= 4; j++)
		{
			int t;
			cin >> t;
			if(i == row)
				ret.push_back(t);
		}
	return ret;
}

vector <int> intersection(vector <int> a, vector <int> b)
{
	vector <int> ret;
	map <int, bool> have;
	for(int i = 0; i < a.size(); i++)
		have[a[i]] = true;
	for(int i = 0; i < b.size(); i++)
		if(have.count(b[i]))
			ret.push_back(b[i]);
	return ret;
}

void solve()
{
	vector <int> a = getIt();
	vector <int> b = getIt();
	vector <int> c = intersection(a, b);
	if(c.size() == 0) cout << "Volunteer cheated!" << endl;
	if(c.size() > 1) cout << "Bad magician!" << endl;
	if(c.size() == 1) cout << c[0] << endl;	
}

int MAIN()
{
	int TestCase;
	cin >> TestCase;
	for(int caseID = 1; caseID <= TestCase; caseID ++)
	{
		cout << "Case #" << caseID << ": ";
		solve();
	}
	return 0;
}

int main()
{
	//srand((unsigned)time(NULL));
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	return MAIN();
}
