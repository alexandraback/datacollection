#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <utility>
#include <functional>
#include <string>
#include <algorithm>

#include <cstring>
#include <cstdio>
#include <memory.h>
#include <ctime>
#include <cassert>
#include <cmath>
#include <iomanip>

#define eps e-8

using namespace std;
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define ll long long int
//#define INF 1000000000


void solve() {
    ll T;
    cin>>T;
    forn(t, T) {
        cout<<"Case #"<<t+1<<": ";
        int n;
        cin>>n;
        vector<pair<int, int>> v(n);
        forn(i, n) {
            cin>>v[i].first;
            v[i].second = i;
        }
        while(true) {
            sort(v.begin(), v.end());
            if(v[n-1].first == 0) {
                break;
            }
            bool isOk = true;
            int s = 0;
            forn(p, n) {
                s+=v[p].first;
            }
            forn(j, n) {
                int a = v[j].first;
                int b = s-a;
                if(j==n-1) {
                    a-=1;
                } else {
                    b-=1;
                }
                if(a>b)
                {
                    isOk = false;
                    break;
                }
            }
            if(isOk) {
                cout<<char('A'+v[n-1].second)<<" ";
                v[n-1].first--;
            } else {
                cout<<char('A'+v[n-1].second)<<char('A'+v[n-2].second)<<" ";
                v[n-1].first--;
                v[n-2].first--;
            }
        }
        cout<<endl;
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
#ifdef diametralis
    freopen("/Users/oxo/Documents/codeforces/IO/input.txt", "rt", stdin);
    freopen("/Users/oxo/Documents/codeforces/IO/output.txt", "wt", stdout);
#endif
    solve();
#ifdef diametralis
    cerr << "Time == " << clock() << endl;
#endif
}