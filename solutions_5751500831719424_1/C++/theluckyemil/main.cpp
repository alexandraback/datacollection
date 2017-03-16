#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>

#define ll long long
#define mp make_pair
#define pii pair<int, int>

using namespace std;

const int maxn = 1e5+5;
const int md = 1e9+7;

int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int test; cin >> test;
    for (int it=0; it<test; it++) {
        int a, b, k;cin>>a>>b>>k;
        int ans=0;
        for (int i=0; i<a; i++) {
            for (int j=0; j<b; j++) {
                if ((i&j)<k) {
                    ans++;
                } else {
                  //  cout << i << " " << j << endl;
                }
            }
        }
        printf("Case #%d: %d\n", it+1, ans);
    }
    return 0;
}
