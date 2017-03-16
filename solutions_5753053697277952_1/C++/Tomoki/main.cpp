#include <iostream>
#include <iomanip>
#include <vector>
#include <valarray>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <complex>
#include <string>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cassert>

#include <unordered_set>
#include <unordered_map>
#include <random>
#include <thread>
#include <chrono>

using namespace std;

#define all(c) c.begin(), c.end()
#define repeat(i, n) for (int i = 0; i < static_cast<int>(n); i++)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define dump(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define dump(x) 
#endif

typedef complex<double> point;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "{";
    for(auto it = v.begin(); it != v.end(); ++it){
        if(it != v.begin()){
            os << ",";
        }
        os << *it;
    }
    return os << "}";
}

template <typename T>
T read_next(){
    T ret; cin >> ret;
    return ret;
}


template<typename T>
void isort(std::vector<T>& v, std::function<bool(T,T)> comp=less<T>()){
    sort(v.begin(), v.end(), comp);
}
template<typename T>
std::vector<T> sort(std::vector<T> v, std::function<bool(T,T)> comp=less<T>()){
    isort(v);
    return v;
}
template<typename T1, typename T2>
std::vector<T2> rmap(const std::vector<T1>& v, std::function<T2(T1)> f){
    std::vector<T2> t; t.reserve(v.size());
    for(const auto& i: v) t.push_back(f(i));
    return t;
}
std::vector<std::string> split(std::string str, char delim){
    std::vector<std::string> res;
    size_t current = 0, found;
    while((found = str.find_first_of(delim, current)) != std::string::npos){
        res.push_back(std::string(str, current, found - current));
        current = found + 1;
    }
    res.push_back(std::string(str, current, str.size() - current));
    return res;
}
string join(const std::vector<string>& v, string delim){
    string ret = "";
    for(auto it = v.begin(); it != v.end(); ++it){
        if(it != v.begin()){
            ret += delim;
        }
        ret += *it;
    }
    return ret;
}

bool check(const vector<int> &v){
    int m = *max_element(all(v));
    int s = accumulate(all(v), 0);
    return m*2 <= s;
}

vector<vector<int> > solve(vector<int> v){
    vector<vector<int> > ret;
    auto decr = [&](const vector<int> p){
        ret.push_back(p);
        for(int i: p) v[i]--;
    };
    int n = v.size();
    while(*max_element(all(v)) != 0){
        int m = *max_element(all(v));
        vector<int> c;
        for(int i=0;i<n;i++){
            if(v[i] == m){
                c.push_back(i);
            }
        }
        if(m == 1){
            if(c.size() % 2 == 1){
                decr({c[0]});
            } else {
                decr({c[0], c[1]});
            }
        } else if(c.size() == 1){
            decr(c);
        } else if(c.size() >= 2){
            decr({c[0], c[1]});
        }
        if(not check(v)){
            dump(v);
        }
    }
    return ret;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k; cin >> k;
    for(int t=0;t<k;t++){
        int n; cin >> n;
        vector<int> p(n);
        repeat(i,n) cin >> p[i];
        auto ret = solve(p);
        string r = "";
        for(vector<int> a : ret){
            r += " ";
            for(int i: a){
                r += 'A'+i;
            }
        }
        cout << "Case #" << (t+1) << ":" << r << endl;
    }
    return 0;
}
