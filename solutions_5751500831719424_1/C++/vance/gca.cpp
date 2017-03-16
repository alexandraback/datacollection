#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string f(string s){
    string ret = "";
    ret += s[0];
    for (int i = 1;i<s.size();i++){
        if(s[i] != s[i-1])
            ret += s[i];
    }
    return ret;
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int t, n, i, j;
    string s[200], mm;
    int p[200];
    scanf("%d",&t);
    for(int cnt =1; cnt<= t;cnt++){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            cin>>s[i];
        }

        mm = f(s[0]);
        int ok = 1;
        for(i=1;i<n;i++){
            if(f(s[i])!=mm)
            {
                ok = 0;
                break;
            }
        }
        if(!ok){
            printf("Case #%d: Fegla Won\n",cnt);
            continue;
        }
        memset(p,0,sizeof(p));
        int ret = 0;
        for(i=0;i<mm.size();i++){
            vector<int>v;
            v.clear();
            for(j=0;j<n;j++){
                int t = 0;
                while(p[j] < s[j].size() && s[j][p[j]] == mm[i]){
                    p[j]++;
                    t++;
                }
                v.push_back(t);
            }
            sort(v.begin(),v.end());
            int mid = v[v.size()/2];
            for(j=0;j<n;j++){
                ret += abs(mid - v[j]);
            }
        }
        printf("Case #%d: %d\n",cnt,ret);
    }
    return 0;
}
