#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string s[1000];
int p[1000];

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int n;
        cin >> n;
        for(int i  = 0 ; i < n; ++i) {
            cin >> s[i];
            p[i] = 0;
        }
        
        int ans  = 0;
        bool ok = true;
        char pr = '4';
		
        for (int i = 0; ; ++i) {
            bool ed = true;
            for (int j = 0 ; j < n; ++j)
                if (p[j] < s[j].size())
                    ed = false;
            if (ed)
                break;
            
			int cnt = 0;
			for (int j = 0; j < n; ++j) {
				if (p[j] < s[j].size() && s[j][p[j]] == pr)
					cnt++;
			}
			if (cnt == 0) {
				for (int j = 0; ok && j < n; ++j) {
					if (p[j] >= s[j].size() || s[j][p[j]] != s[0][p[0]])
						ok = false;
				}
				if (!ok)
					break;
				pr = s[0][p[0]];
				for (int j = 0; j < n; ++j) ++p[j];
				
			} else {
				ans += min(n - cnt, cnt);
				for (int j = 0; j < n; ++j) {
					if (p[j] < s[j].size() && s[j][p[j]] == pr)
						p[j]++;
				}
			}
        }

		cout << "Case #" << test <<	": ";
		if (ok == false) {
			cout << "Fegla Won" << endl;
		} else {
			cout << ans << endl;
		}
    }
    return 0;
}

//C:\Users\Mykola\Documents\Visual Studio 2010\Projects\acm\acm