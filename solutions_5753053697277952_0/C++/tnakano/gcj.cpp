#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <bits/stdc++.h>
using namespace std;
using i8  = int8_t;  using u8  = uint8_t;
using i16 = int16_t; using u16 = uint16_t;
using i32 = int32_t; using u32 = uint32_t;
using i64 = int64_t; using u64 = uint64_t;
using f32 = float_t; using f64 = double_t;
using usize = size_t;using str = string;
template <class T> using vec = vector<T>;
#define times(n, i) for (i32 i = 0; i < (n); i++)
#define range(n, m, i) for (i32 i = (n); i < (m); i++)
#define upto(n, m, i) for (i32 i = (n); i <= (m); i++)
#define downto(n, m, i) for (i32 i = (n); i >= (m); i--)
#define foreach(xs, x) for (auto &x : (xs))
#define all(xs) (xs).begin(), (xs).end()
#define sortall(xs) sort(all(xs))
#define reverseall(xs) reverse(all(xs))
#define uniqueall(xs) (xs).erase(unique(all(xs)), (xs).end())
#define maximum(xs) *max_element(all(xs))
#define minimum(xs) *min_element(all(xs))
const i64 MOD = 1000000007;

str solve(i32 n, set<pair<i32, char>> p) {
    vec<char> ans;

    while (p.size()) {
        i32 xv = (--p.end())->first;
        i32 xc = (--p.end())->second;
        p.erase((--p.end()));
        ans.emplace_back(xc);
        if (xv > 1)
            p.insert(make_pair(xv - 1, xc));
    }

    str ret = "";
    times(ans.size(), i) {
        ret += ans[i];
        if (i % 2 == 0 && ans.size() - i - 1 == 2) {
            ret += " ";
            ret += ans[i+1];
            ret += ans[i+2];
            break;
        }
        if (i % 2 == 1 && i < ans.size() - 1)
            ret += " ";
    }

    return ret;
}

i32 main()
{
    i32 t;
    cin >> t;
    vec<i32> n(t);
    vec<set<pair<i32, char>>> p(t);
    times(t, i) {
        cin >> n[i];
        times(n[i], j) {
            i32 v; cin >> v;
            p[i].insert(make_pair(v, 'A'+j));
        }
    }
    times(t, i) {
        str ans = solve(n[i], p[i]);
        cout << "Case #" << (i+1) << ": " << ans << endl;
    }
    return 0;
}