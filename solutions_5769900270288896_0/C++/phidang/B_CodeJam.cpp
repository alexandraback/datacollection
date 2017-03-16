#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>

using namespace std;

#define openfile {freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);}
#define debug 01

int n, r, c, t, kq;
char a[20][20];

string cv(int x) {
    string s="";
    while (x>0) {
        s=char(x%2+48)+s;
        x/=2;
    }
    return s;
}

void solve() {
    kq=1e9;
    for (int e=0; e<65536; e++) {
        string s = cv(e);
        if (s.length()>r*c) break;
        int sum=0;
        for (int j=0; j<s.length(); j++) {
            if (s[j]=='1') {
                sum++;
            }
        }
        if (sum==n) {
            int x=0;
            for (int i=0; i<r; i++) {
                for (int j=0; j<c; j++) {
                    if (x<s.length()) {
                        a[i][j]=s[x];
                        x++;
                    }
                    else a[i][j]='0';
                }
            }
            int res=0;
            for (int i=1; i<r; i++)
                if (a[i][0]=='1' && a[i-1][0]=='1') res++;
            for (int i=1; i<c; i++) {
                if (a[0][i]=='1' && a[0][i-1]=='1') res++;
            }
            for (int i=1; i<r; i++) {
                for (int j=1; j<c; j++) {
                    if (a[i][j]=='1') {
                        if (a[i-1][j]=='1') res++;
                        if (a[i][j-1]=='1') res++;
                    }
                }
            }
            if (kq>res) {
                //cout<<s<<endl;
                kq=res;
            }
        }
    }
    cout<<kq<<endl;
}

int main()
{
    if (debug) openfile;
    cin>>t;
    for (int x=0; x<t; x++) {
        cin>>r>>c>>n;
        printf("Case #%d: ", x+1);
        solve();
    }
    return 0;
}
