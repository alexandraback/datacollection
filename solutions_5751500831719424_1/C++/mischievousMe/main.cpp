#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <valarray>
#include <algorithm>
#include <queue>
#include <cstdio>
#include<stack>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include<climits>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define pi 2.0*acos(0.0)

int cnt;

string shorten(string s) {
    int n = (int)s.size();
    int i = 0;
    string t;
    while(i<n) {
        if( ((i-1)>=0) && (s[i-1] == s[i]) ) {
            
        }
        else {
            t += s[i];
        }
        ++i;
    }
    return t;
}

int main() {
    freopen("/Users/shalini/Downloads/A2.txt","r",stdin);
    freopen("/Users/shalini/Downloads/A3.txt","w",stdout);
    int t,x = 0;
    cin>>t;
    while(t--) {
        ++x;
        int n;
        cin>>n;
        string s,t;
        bool fl = 0;
        cnt = 0;
        vector<string>v;
        while(n--) {
            cin>>s;
            v.pb(s);
            s = shorten(s);
            if(t == "") {
                t = s;
            }
            else if(t != s) {
                fl = 1;
            }
        }
        if(!fl) {
        n = (int)v.size();
        vector<int>w;
        vector<vi >ww;
        for(int i = 0;i < n;++i) {
            int j = 0;
            int c = 1;
            int m = (int)v[i].size();
            int k = 0;
            vi my_w;
            while(j<m) {
                if( ((j-1)>=0) && (v[i][j-1]==v[i][j]) ) {
                    ++c;
                }
                else {
                    if(i == 0) {
                        w.pb(c);
                    }
                    else {
                        w[k] = max(w[k],c);
                        
                    }
                    my_w.pb(c);
                    c = 1;
                    ++k;
                }
                ++j;
            }
            if(i == 0) {
                w.pb(c);
            }
            else {
                w[k] = max(w[k],c);
            }
            my_w.pb(c);
            ww.pb(my_w);
        }
        int m = (int)w.size();
        for(int i = 0;i < m;++i) {
            int mn = 100000000;
            int c = 0;
            for(int j = 1;j <= w[i];++j) {
                c = 0;
                for(int k = 0;k < n;++k) {
                    c += abs(ww[k][i]-j);
                }
                mn = min(mn,c);
            }
            cnt += mn;
            
        }
        }
        if(fl) {
            cout<<"Case #"<<x<<": "<<"Fegla Won\n";
        }
        else {
            cout<<"Case #"<<x<<": "<<cnt<<"\n";
        }
    }
    return 0;
}