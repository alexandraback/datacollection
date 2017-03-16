#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <tuple>
#include <cmath>
#include <climits>
using namespace std;

#define SORT(l) std::sort(l.begin(), l.end())
#define IS_ALPH(c) ((c>='a' && c<='z') || (c>='A' && c<='Z'))
#define IS_NUM(c) (c>='0' && c<='9')
#define FOR(a, min, max) for(int a=min; a<max; ++a)
#define FORS(a, str) for(int a=0; a<str.length(); ++a)
#define FORV(a, vec) for(int a=0; a<vec.size(); ++a)
#define MAX(a, b) ((a > b) ? (a) : (b))
#define MIN(a, b) ((a < b) ? (a) : (b))
#define COUTV(v) FORV(i,v) { cout << v[i]; if(i<v.size()-1) cout << ","; else cout << endl; }

int main() {
    
    int T;
    cin >> T;
    int cur_case = 0;
    while(T--) {
        int n;
        cin >> n;
        vector<int> m(n);
        for(int i=0; i<n; ++i) {
            cin >> m[i];
        }

        int total = 0;
        int max_eaten=0;
        for(int i=1; i<m.size(); ++i) {
            if(m[i] < m[i-1]) {
                total += m[i-1] - m[i];
                max_eaten = max(max_eaten, m[i-1]-m[i]);
            }
        }

        //she must eat at least max_eaten each 10 seconds
        int const_total = 0;
        for(int i=0; i<m.size()-1; ++i) {
           const_total += min(max_eaten, m[i]); 
        }

        cout << "Case #" << ++cur_case << ": " << total << " " << const_total << endl;
    }

    return 0;
}
