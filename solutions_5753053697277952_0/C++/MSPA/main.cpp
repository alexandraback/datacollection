#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>

const int N = 1e5+3;
const int inf = 1e9;

typedef long long ll;

using namespace std;

bool solve()
{
    int n;
    scanf("%d",&n);
    vector<pair<int, char>> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i].first);
        v[i].second = (char)(i+'A');
    }
    sort(v.begin(), v.end());
    while (v[n-1].first > v[n-2].first) {
        printf("%c ", v[n-1].second);
        v[n-1].first--;
    }
    
    for (int i = 0; i < n - 2; ++i)
        for (int j = 0; j < v[i].first; ++j)
            printf("%c ", v[i].second);
    for (int i = 0; i < v[n-1].first; ++i)
        printf("%c%c ", v[n-2].second, v[n-1].second);
    puts("");
    return false;
}

int main()
{
        freopen("input.txt","r", stdin);
        freopen("output.txt", "w", stdout);
    int countTests;
    scanf("%d", &countTests);
    for (int curTest = 1; curTest <= countTests; ++curTest) {
        printf("Case #%d: ", curTest);
        solve();
    }
    
    return 0;
}
