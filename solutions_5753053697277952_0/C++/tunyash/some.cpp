#include "bits/stdc++.h"
using namespace std;

#define pb push_back
void solve(int test)
{
	int n;
	cin >> n;
	vector<string> plan;
	vector<int> cnt(n);
	for (int i = 0; i < n; i++) cin >> cnt[i];
	while (true)
	{
		/// for (int i = 0; i < n; i++) cout << cnt[i] << ' ';
		// cout << endl;
	     int x = max_element(cnt.begin(), cnt.end()) - cnt.begin();
	   //  cout << "x=" << x << endl;
	     if (cnt[x] == 0) break;
	     int mc = 0;
	     
	     for (int i = 0; i < n; i++)
	          if (cnt[i] == cnt[x]) mc++;
	   //  cout <<"!" << endl;
	     string s = "";
	     if (mc != 2)
	     {
	         s.pb(char(x+'A'));
	         cnt[x]--;
	     }
	     else
	     {
	     	for (int i = 0; i < n; i++)
	     	   if (cnt[i] == cnt[x]) {s.pb(char('A')+i);}
	     	int g = cnt[x];
	     	for (int i = 0; i < n; i++)
	     	   if (cnt[i] == g) cnt[i]--;
	     	assert(s.size() == 2);
	     }
	   //  cout << s << endl;
	     plan.pb(s);
	}
	cout << "Case #" << test << ": ";
	for (int i = 0; i < (int)plan.size(); i++)
	    cout << plan[i] << " \n"[i==(int)plan.size()-1];
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) solve(i+1);
	return 0;
}