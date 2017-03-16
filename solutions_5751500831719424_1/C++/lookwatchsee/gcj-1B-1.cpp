#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int solve(vector<string>& v, const int n) {
    vector<int> p(n,0);
    int ans=0;
    while (p[0]<v[0].length()) {
        char ch=v[0][p[0]];
        vector<int> len;
        for (int i=0;i<n;++i) {
            int cnt=0;
            while (p[i]<v[i].length()
                    && v[i][p[i]]==ch) {
                p[i]++;
                cnt++;
            }
            if (cnt==0) {
                return -1;
            }
            len.push_back(cnt);
        }
        sort(len.begin(), len.end());
        int m=len[(n-1)/2];
        for (int i=0;i<n;++i) {
            ans+=abs(m-len[i]);
        }
    }
    for (int i=0;i<n;++i) {
        if (p[i] != v[i].length()) {
            return -1;
        }
    }
    return ans;
}
int main(int argc, char* argv[]) {
    int T;
    cin>>T;
    for (int t=1;t<=T;++t) {
        int n;
        cin>>n;
        vector<string> v;
        for (int i=0;i<n;++i) {
            string s;
            cin>>s;
            v.push_back(s);
        }
        int ans = solve(v, n);
        if (ans>=0) {
            cout<<"Case #"<<t<<": "<<ans<<endl;
        } else {
            cout<<"Case #"<<t<<": "<<"Fegla Won"<<endl;
        }
    }
    return 0;
}
