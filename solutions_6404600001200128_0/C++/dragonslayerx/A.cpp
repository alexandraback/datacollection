 //You are weak? Why? Because You lack Hatred. - Itachi
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

#define MAX 200500
#define MOD 1000000007
#define INF 1e9

int main()
{
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #"<< t << ": ";
        int n;
        cin >> n;
        int a[MAX];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long mineatenA = 0, mineatenB = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i-1]) {
                mineatenA += a[i-1] - a[i];
            }
        }
        int minrate = 0;
        for (int i = 1; i < n; i++) {
            minrate = max(a[i-1] - a[i], minrate);
        }
        for (int i = 0; i < n-1; i++) {
            mineatenB += min(minrate, a[i]);
        }
        cout << mineatenA << " " << mineatenB << endl;
    }
}
