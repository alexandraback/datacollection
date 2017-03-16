#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define MP make_pair
#define F first
#define S second

const string V = "Volunteer cheated!";
const string B = "Bad magician!";

void solve(int test)
{
    int r;
    cin >> r;
    set<int> one;
    set<int> both;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++) {
            int x;
            cin >> x;
            if (i == r)
                one.insert(x);
        }
    cin >> r;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++) {
            int x;
            cin >> x;
            if (i == r && one.count(x))
                both.insert(x);
        }
    cout << "Case #" << test << ": ";
    if (both.size() == 0)
        cout << V;
    else if (both.size() > 1)
        cout << B;
    else
        cout << *both.begin();
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    for (int q = 1; q <= t; q++)
        solve(q);

    return 0;
}
