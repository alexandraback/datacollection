#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<map>
#include<iterator>
#include<set>
#include<stack>
#include<queue>
#include<fstream>
#include<iomanip>
#include<list>
#include <sstream>
#include<cmath>
#include<math.h>
#define rep(i,m,n) for(int i = (m); i < (n); i++)
#define repd(i,m,n) for(int i=(m); i > (n); i--)
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define endl '\n'
//#define x first
//#define y second
//#define b first
//#define e second
#define row first
#define col second
#define num first
#define lit second
using namespace std;
const ll MAX = (ll)1000*1000*1000;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
	freopen("input.in", "rt", stdin);
	freopen("output.out", "wt", stdout);
	int t,n,temp;
	cin >> t;
	vector<pair<int,char>> a;
	rep(i,0,t)
	{
		cin >> n;
		a.clear();
		rep(j,0,n)
		{
			cin >> temp;
			a.push_back(mp(temp,j + 'A'));
		}
		cout << "Case #"+ to_string(i + 1) + ": ";
		while (a.size() != 0)
		{
			sort(a.begin(),a.end());
		
			if (a.size() == 2 && a[0].num == a[1].num)
			{
				cout << a[0].lit << a[1].lit << " ";
				a[0].num--; a[1].num--;
			}
			else
			if (a[a.size()-1].num - 1 > a[a.size()-1].num)
			{
				cout << a[a.size()-1].lit << a[a.size()-1].lit << " ";
				a[a.size()-1].num--; a[a.size()-1].num--;
			}else
			{
				cout << a[a.size()-1].lit << " ";
				a[a.size()-1].num--;
			}
			while (a.size() != 0 && a[a.size()-1].num == 0)
				a.pop_back();
		}
		cout << endl;
	}

	return 0;
}

