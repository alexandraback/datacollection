#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <ctime>
#include <fstream>
#include <cmath>
#include <functional>

using namespace std;

#define mp make_pair
#define pb push_back
#define F first
#define S second

const int INF = 1000000000;
const int C = 1000000;
const int mda = 1337 +  14664;

int c[40];

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        //freopen("encryption.in", "r", stdin);
        //freopen("encryption.out", "w", stdout);
    #endif // LOCAL
    int T;
    cin >> T;
    for (int t=1; t<=T; t++){
        int n;
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> c[i];
        priority_queue<pair<int, int> > q;
        for (int i=0; i<n; i++)
            q.push(mp(c[i], i));
        cout << "Case #" << t << ": ";
        while (n > 2){
            pair<int, int> x = q.top();
            q.pop();
            cout << (char)(x.S + 'A') << ' ';
            x.F--;
            if (x.F == 0){
                n--;
                continue;
            }
            q.push(x);
        }
        int k = q.top().F;
        string s = "";
        s += (char)('A' + q.top().S);
        q.pop();
        s += (char)('A' + q.top().S);
        for (int j=0; j<k; j++){
            cout << s;
            if (j == k-1) cout << endl;
            else cout << " ";
        }
    }
    return 0;
}
