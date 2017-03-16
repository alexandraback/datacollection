#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>
typedef long long ll;typedef unsigned long long ull;
template <typename T>std::istream & operator >> (std::istream & input, std::vector<T> & a) {for (int i = 0; i < a.size(); ++i) {input >> a[i];}return input;}template <typename T>std::ostream & operator << (std::ostream & output, const std::vector<T> & a) {for (int i = 0; i < a.size(); ++i) {if (i != 0) output << ' ';output << a[i];}return output;}
template <typename T>class irange {public:class iterator {public:iterator(T value) : value(value), step(1) {}iterator(T value, T step) : value(value), step(step) {}bool operator != (const iterator & other) const {return value != other.value;}T const & operator * () const {return value;}iterator & operator ++ () {value += step;return *this;}private:T value;T step;};public:irange(T last) : first(0), last(last), step(1) {}irange(T first, T last) : first(first), last(last), step(1) {}irange(T first, T last, T step) : first(first), last(last), step(step) {}iterator begin() const {return iterator(first, step);}iterator end() const {if (step == 0) return iterator(last, step);if (0 < step and last < first) return iterator(first, step);if (step < 0 and first < last) return iterator(first, step);return iterator(first + ((last - first + (0 < step ? -1 : 1)) / step + 1) * step, step);}typedef T value_type;private:T const first;T const last;T const step;};typedef irange<long long> lrange;inline lrange range(lrange::value_type last) { return lrange(last); }inline lrange range(lrange::value_type first, lrange::value_type last) { return lrange(first, last); }inline lrange range(lrange::value_type first, lrange::value_type last, lrange::value_type step) { return lrange(first, last, step); }template <typename T> lrange index_of(const T & a) { return range(a.size()); }inline lrange range(std::istream & input) { lrange::value_type i; input >> i; return range(i); }inline lrange reverse_range(lrange::value_type last) { return range(last-1,-1,-1); }inline lrange reverse_range(lrange::value_type first, lrange::value_type last) { return range(last-1,first-1,-1); }inline lrange inclusive_range(lrange::value_type last) { return range(last+1); }inline lrange inclusive_range(lrange::value_type first, lrange::value_type last) { return range(first,last+1); }template <typename T> lrange reverse_index_of(const T & a) { return range(a.size()-1,-1,-1); }
template <typename T>T gcd(T a, T b) {if (b <= a) std::swap(a,b);while (a) {T a0 = a;a = b % a0;b = a0;}return b;}template <typename T>T lcm(T a, T b) {return (a * b) / gcd(a,b);}
using namespace std;
int solve_slowly(vector<int> const & m, int n) {
    int a = 0;
    priority_queue<pair<ll,int>,vector<pair<ll,int> >, greater<pair<ll,int> > > q;
    for (int i : range(n-1)) {
        if (a < m.size()) {
            q.push(make_pair(m[a], a));
            ++a;
        } else {
            auto p = q.top(); q.pop();
            q.push(make_pair(p.first + m[p.second], p.second));
        }
    }
    return a < m.size() ? a : q.top().second;
}
ll consumed(vector<int> const & m, ll t) {
    ll p = 0;
    for (int b : m) p += 1 + t / b;
    return p;
}
int solve_nicely(vector<int> const & m, int n) {
    ll low = 0, high = 100000ll * 1000000000ll * 2; // [low, high)
    while (low+1 < high) {
        ll mid = (low + high) / 2;
        ll p = consumed(m,mid);
        if (p < n) {
            if (low == mid) break;
            low = mid;
        } else if (n < p) {
            if (high == mid+1) break;
            high = mid+1;
        } else {
            if (high == mid+1) break;
            high = mid+1;
        }
    }
    for (ll t : range(low, high)) {
        ll p = consumed(m,t);
        if (n <= p) {
            p = consumed(m,t-1);
            for (int i : index_of(m)) {
                if (t % m[i] == 0) {
                    p += 1;
                }
                if (p == n) {
                    return i;
                }
            }
        }
    }
    assert (false);
}
void solve_prepare(vector<int> & m, int & n) {
    ll gcdm = 1; for (ll b : m) gcdm = gcd(gcdm, b);
    for (auto & b : m) b /= gcdm;
    ll lcmm = 1; for (ll b : m) lcmm = lcm(lcmm, b);
    int t = 0; for (ll b : m) t += lcmm / b;
    n %= t;
    if (n == 0) n = t;
}
int solve(vector<int> m, int n) {
   // solve_prepare(m,n);
   return solve_nicely(m,n);
}
int main() {
    ios_base::sync_with_stdio(false);
    for (int testcase : range(cin)) {
        int b, n; cin >> b >> n;
        vector<int> m(b); cin >> m;
        cout << "Case #" << testcase+1 << ": " << solve(m,n)+1 << endl;
    }
    return 0;
}
