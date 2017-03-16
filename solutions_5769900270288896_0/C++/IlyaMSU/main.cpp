#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>
#include<functional>




using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-5;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
const ll mod = 1000 * 1000 * 1000 + 7;
const ll N = 1001;
//const int M = 10000000;

int f(int a4, int a3, int a2, int k) {
    if (k <= a4)
        return 4 * k;
    int res = 4 * a4;
    k -= a4;
    if (k <= a3)
        return res + 3 * k;
    res += 3 * a3;
    k -= a3;
    return res + 2 * k;
}

int solve2(int r, int c, int n) {
    if (r > c)
        swap(r, c);
    if (r == 1) {
        n -= (c + 1) / 2;
        if (n <= 0)
            return 0;
        if (c & 1)
            return 2 * n;
        else
            return 2 * n - 1;
        

    }
    int m = (r * c + 1) / 2;
    if (n <= m)
        return 0;
    int res = (r - 1) * c + (c - 1) * r;
    int k = r * c - n;

    int a4 = ((r - 2) * (c - 2) + 1) / 2;
    int a2 = 2;
    if ((r & 1) && (c & 1))
        a2 += 2;
    int a3 = m - a4 - a2;
    int b4 = (r - 2) * (c - 2) - a4;
    int b2 = 4 - a2;
    int b3 = 2 * r + 2 * c - 8 - a3;
    
    int sub = max(f(a4, a3, a2, k), f(b4, b3, b2, k));
    return res - sub;

}

int ones(int n) {
    int res = 0;
    while (n) {
        if (n & 1)
            ++res;
        n /= 2;
    }
    return res;
}

int solve1(int r, int c, int n) {
    int up = 1 << (r * c);
    int res = r * c * 4;
    int ans = 0;
    for (int i = 0; i < up; ++i) {
        if (ones(i) == n) {
            int cur = 0;
            for (int j = 0; j < r * c; ++j) {
                for (int k = j + 1; k < r * c; ++k) {
                    if (((i >> j) & 1) && ((i >> k) & 1)) {
                        if ((j + c == k) || ((j + 1 == k) && ((j % c) != c - 1)))
                            ++cur;
                    }
                }
            }
            if (cur < res) {
                res = cur;
                ans = i;
            }
        }
    }
    
    return res;

}

int solve() {
    int r, c;
    cin >> r >> c;
    int n;
    cin >> n;
    if (solve1(r, c, n) != solve2(r, c, n)) {
        cerr << "1111111111111111111111\n";
        cerr << solve1(r, c, n) << endl;
        cerr << solve2(r, c, n) << endl;
    }
    return solve2(r, c, n);
    
    


}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tt;

    cin >> tt;
    for (int i = 0; i < tt; ++i) {
        cout << "Case #" << i + 1 << ": " << solve() << endl;
        std::cerr << i << endl;
    }
    return 0;
}
