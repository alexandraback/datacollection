
 #include <vector>
 #include <list>
 #include <map>
 #include <set>
 #include <deque>
 #include <queue>
 #include <stack>
 #include <bitset>
 #include <algorithm>
 #include <functional>
 #include <utility>
 #include <sstream>
 #include <iostream>
 #include <iomanip>
 #include <cstdio>
 #include <cmath>
 #include <fstream>
 #include <cstdlib>
 #include <ctime>
 #include <string>
 #include <cstring>
 using namespace std;



int main() {
//    freopen("/Users/fengyelei/Desktop/in.in", "r", stdin);
//    freopen("/Users/fengyelei/Desktop/out", "w", stdout);
    ifstream cin("/Users/fengyelei/Desktop/in.in");
    ofstream cout("/Users/fengyelei/Desktop/out");
    
    int T, t, i, j, k;
    
    int n;
    
    cin>>T;
    for (t=1;t<=T;t++) {
        vector<string> v;
        vector<int> c[100];
        string s;
        cin>>n;
        for (i=0; i<n; i++) {
            cin>>s;
            v.push_back(s);
        }
        string x = "", y;
        for (i=0; i<v.size(); i++) {
            y = "";
            s = v[i];
            int count = 1;
            for (j=0; j<s.length(); j++) {
                if (j>0 && s[j]!=s[j-1]) c[i].push_back(count), count=1, y+=s[j-1];
                else count++;
            }
            c[i].push_back(count);
            y+=s[s.length()-1];
            if (x != "" && x != y) break;
            x = y;
        }
        cout<<"Case #"<<t<<": ";
        if (i != v.size()) cout<<"Fegla Won\n";
        else {
            int res = 0;
            for (i=0; i<c[0].size(); i++) {
                int p = 100000, q;
                for (j=0; j<v.size(); j++) {
                    q = 0;
                    for (k=0; k<v.size(); k++) {
                        q += abs(c[j][i]-c[k][i]);
                    }
                    p = min(p, q);
                }
                res += p;
            }
            cout<<res<<endl;
        }
    }
    return 0;
}
