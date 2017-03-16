#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>

#define xx first
#define yy second
#define mod 1000000007
#define pb push_back
#define mp make_pair
//#define MAX 2000000000
using namespace std;

int dirx[8] = {1,0,-1,0,1,-1,-1,1};
int diry[8] = {0,1,0,-1,1,1,-1,-1};

string str[105];
vector<int>s[105];
int dp[200][200] = {0};

main() {
    freopen("input.in","r",stdin);
    freopen("The_Repeater","w",stdout);
    int test,i,n,a[101],m, j, cnt, mn, ret, ans;
    cin >> test;
    for(int t=1;t<=test;t++) {
        cin >> n;
        for(i=0;i<n;i++) {cin >> str[i];s[i].clear();}
        for(i=0;i<n;i++) {
            m = str[i].size();
            for(j=0;j<m;j++) {
                s[i].pb(str[i][j]);
                int k = j;cnt = 0;
                while(j<m&&str[i][j]==str[i][k]){cnt++; j++;}j--;
                dp[i][s[i].size()-1] = cnt;
            }
        }
        for(i=1;i<n;i++) {
            for(j=0;j<s[i].size();j++)
                if(s[i][j]!=s[0][j]||s[i].size()!=s[0].size()) break;
            if(j<s[i].size()) break;
        }
        if(i<n) {
            printf("Case #%d: Fegla Won\n",t);continue;
        }
        ret = 0;
        m = s[0].size();
        for(i=0;i<m;i++) {
            mn = 10000000;
            for(int l=0;l<=200;l++) {
                ans = 0;
                for(j=0;j<n;j++) {
                    ans += abs(dp[j][i]-l);
                }
                mn = min(mn, ans);
            }
            ret += mn;
        }
        printf("Case #%d: %d\n",t,ret);continue;
    }

    return 0;
}

