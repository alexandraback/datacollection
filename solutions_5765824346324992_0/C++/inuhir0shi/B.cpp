
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;
template<class T> inline bool amax (T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool amin (T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> ostream& operator << (ostream &os, const vector<T> &v) { os << "["; for (typename vector<T>::const_iterator it = v.begin(); it != v.end(); it++) { os << (it != v.begin() ? ", " : "") << *it; } os << "]"; return os; }
template<class T> ostream& operator << (ostream &os, const set<T> &s) { os << "["; for (typename set<T>::const_iterator it = s.begin(); it != s.end(); it++) { os << (it != s.begin() ? ", " : "") << *it; } os << "]"; return os; }
template<class Key, class Val> ostream& operator << (ostream &os, const map<Key, Val> &m) { os << "{"; for (typename map<Key, Val>::const_iterator it = m.begin(); it != m.end(); it++) { os << (it != m.begin() ? ", " : "") << it->first << ":" << it->second; } os << "}"; return os; }
template<class T, class S> ostream& operator << (ostream &os, const pair<T, S> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
template <class Target, class Source> inline Target lexical_cast (const Source &s) { Target t; stringstream ss; ss << s; ss >> t; return t; }

//> v < ^ (clock wise)
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
const int INFI = 1<<28;
const long long int INFL = 1LL<<60;
const double INFD = 1e+300;
const float INFF = 1e+100;
const double EPS = 1e-8;


int gcd(int x,int y){
    if(y == 0)return x;
    else return gcd(y, x % y);
}
int lcm(int x,int y){
    return x*y / gcd(x,y);
}
int main(){
    cout.setf(ios::fixed); cout.precision(10);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int C =0;
    while (T--) {
        int B, N1;
        cin >> B >> N1;
        vector<int> M(B);
        for (int i = 0; i < B; i++) {
            cin >> M[i];
        }

        int L = M[0];
        for (int i = 1; i < B; i++) {
            L = lcm(L, M[i]);
        }
        int sum = 0;
        for (int i = 0; i < B; i++) {
            sum += L / M[i];
        }
        int ans;
        int N = (N1-1)%sum;
        //cout << N1 << " -> " << N << endl;
        if (N == 0) {
            ans = 1;
        } else {
            N++;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
            for (int i = 0; i < B; i++) Q.push(make_pair(0, i));
            int idx = 1;
            while (true) {
                pair<int,int> t = Q.top();
                Q.pop();
                if (idx == N) {
                    ans = t.second + 1;
                    break;
                }
                t.first += M[t.second];
                Q.push(t);
                idx++;
            }
        }
        cout << "Case #" << ++C << ": " << ans << endl;
    }
    return 0;
}
