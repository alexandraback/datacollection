#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <set>
#include <utility>
#include <stack>

#define rep(i,n) for(int i = 0; i < (n); i++)

using namespace std;

void solve();
void runCase();

void runCase()
{
    int n;
    cin >> n;
    vector<pair<int,char> > p(n);
    rep(i,n) {
        cin >> p[i].first;
        p[i].second = 'A'+i;
    }
    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());
    for(;;) {
        if(p[0].first == p[1].first) break;
        cout << p[0].second << ' ';
        p[0].first --;
    }
    
    reverse(p.begin(),p.end());
    rep(i,n-2) {
        for(;;) {
            if(p[i].first==0) break;
            cout << p[i].second << ' ';
            p[i].first --;
        }
    }
    
    reverse(p.begin(),p.end());
    for(;;) {
        if(p[0].first == 0) break;
        cout << p[0].second << p[1].second;
        p[0].first --; p[1].first --;
        if(p[0].first != 0) cout << ' ';
    }
    
    cout << endl;
    
}

void solve()
{
	int n;
    cin >> n;
	// scanf("%d",&n);
	// getchar();

	for(int i = 0; i < n; i++) {
        cout << "Case #" << i+1 << ": ";
		// printf("Case #%d: ",i+1);
		runCase();
		//runSample();
	}
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	solve();
	return 0;
}
