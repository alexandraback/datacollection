#include <bits/stdc++.h>
using namespace std;

int main(void) {
    freopen("in.txt", "rt", stdin);
    freopen("test.txt", "wt", stdout);
    int t, n;
    cin >> t;
    for(int tc = 1; tc <= t; ++tc)
    {
        cin >> n;
        int a[n], i, m = 1e9;
        set <pair <int, int> > s;
		set<pair <int, int> >::reverse_iterator rit;
        for(i = 0; i < n; ++i)
        {
            cin >> a[i];
            if(m > a[i])
                m = a[i];
            s.insert(make_pair(a[i], i));
        }
        cout << "Case #" << tc << ": ";
		bool ev = 0;
		do {
            ev = 0;
			rit = s.rbegin();
			if ((*rit).first > m) {
				ev = 1;
				cout << (char)('A' + (*rit).second) << " ";
				pair <int, int> x = (*rit);
				a[x.second]--;
				s.erase(x);
				s.insert(make_pair(a[x.second], x.second));
			}
		}while(ev);
		for (int j = 0; j < m; j++)
		{
			for (i = 0; i < (n - 2); i++)
				cout << (char)('A' + i) << " ";
			cout << (char)('A' + n - 2) << (char)('A' + n - 1) << " ";
		}
        cout << "\n";
    }
    return 0;
}
