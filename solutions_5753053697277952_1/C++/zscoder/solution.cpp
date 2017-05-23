#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef long double ld;
typedef pair<int,int> ii;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
vector<ii> vec;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("A-large (1).in", "r", stdin);
	freopen("GCJ20161C-1.out", "w", stdout);
	int t; cin >> t;
	int T = 0;
	while(t--)
	{
		T++;
		cout << "Case #" << T << ": ";
		int n; cin >> n;
		vec.clear(); int cnt = 0;
		for(int i = 0; i < n; i++)
		{
			int x; cin >> x; cnt += x;
			vec.pb(ii(-x, i));
		}
		while(cnt > 0)
		{
			sort(vec.begin(), vec.end());
			char z;
			z = vec[0].se + 'A';
			cout << z;
			vec[0].fi++;
			cnt--;
			sort(vec.begin(), vec.end());
			if(vec[0].fi < 0 && (vec[0].fi < vec[1].fi))
			{
				z = vec[0].se + 'A';
				cout << z;
				vec[0].fi++;
				cnt--;
			}
			sort(vec.begin(), vec.end());
			if(-vec[0].fi*2 > cnt)
			{
				cout << "WARNING" << endl;
			}
			cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}
