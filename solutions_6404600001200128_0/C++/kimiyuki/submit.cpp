#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
typedef long long ll;typedef unsigned long long ull;
template <typename T>std::istream & operator >> (std::istream & input, std::vector<T> & a) {for (int i = 0; i < a.size(); ++i) {input >> a[i];}return input;}template <typename T>std::ostream & operator << (std::ostream & output, const std::vector<T> & a) {for (int i = 0; i < a.size(); ++i) {if (i != 0) output << ' ';output << a[i];}return output;}
template <typename T>class irange {public:class iterator {public:iterator(T value) : value(value), step(1) {}iterator(T value, T step) : value(value), step(step) {}bool operator != (const iterator & other) const {return value != other.value;}T const & operator * () const {return value;}iterator & operator ++ () {value += step;return *this;}private:T value;T step;};public:irange(T last) : first(0), last(last), step(1) {}irange(T first, T last) : first(first), last(last), step(1) {}irange(T first, T last, T step) : first(first), last(last), step(step) {}iterator begin() const {return iterator(first, step);}iterator end() const {if (step == 0) return iterator(last, step);if (0 < step and last < first) return iterator(first, step);if (step < 0 and first < last) return iterator(first, step);return iterator(first + ((last - first + (0 < step ? -1 : 1)) / step + 1) * step, step);}typedef T value_type;private:T const first;T const last;T const step;};typedef irange<long long> lrange;inline lrange range(lrange::value_type last) { return lrange(last); }inline lrange range(lrange::value_type first, lrange::value_type last) { return lrange(first, last); }inline lrange range(lrange::value_type first, lrange::value_type last, lrange::value_type step) { return lrange(first, last, step); }template <typename T> lrange index_of(const T & a) { return range(a.size()); }inline lrange range(std::istream & input) { lrange::value_type i; input >> i; return range(i); }inline lrange reverse_range(lrange::value_type last) { return range(last-1,-1,-1); }inline lrange reverse_range(lrange::value_type first, lrange::value_type last) { return range(last-1,first-1,-1); }inline lrange inclusive_range(lrange::value_type last) { return range(last+1); }inline lrange inclusive_range(lrange::value_type first, lrange::value_type last) { return range(first,last+1); }template <typename T> lrange reverse_index_of(const T & a) { return range(a.size()-1,-1,-1); }
using namespace std;
ll method_1(vector<int> const & m) {
    ll result = 0;
    for (int i : range(1,m.size())) {
        if (m[i-1] > m[i]) {
            result += m[i-1] - m[i];
        }
    }
    return result;
}
ll method_2(vector<int> const & m) {
    ll result = (1ll<<60);
    for (int r : range(0,10000+1)) {
        ll eaten = 0;
        for (int i : range(0,m.size())) {
            if (result <= eaten) {
                eaten = -1;
                break;
            }
            if (m[i-1] - r > m[i]) {
                eaten = -1;
                break;
            }
            eaten += min(r, m[i-1]);
        }
        if (eaten != -1) {
            result = min(result, eaten);
        }
    }
    return result;
}
int main() {
    ios_base::sync_with_stdio(false);
    for (int testcase : range(cin)) {
        int n; cin >> n;
        vector<int> m(n); cin >> m;
        cout << "Case #" << testcase+1 << ": " << method_1(m) << " " << method_2(m) << endl;
    }
    return 0;
}
