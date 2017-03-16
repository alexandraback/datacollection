#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<algorithm>
#include<map>
#include<stdlib.h>
#include <iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<set>
using namespace std;
const double eps = 1e-12;
const double dinf = 99999999999.99;

 vector<string> a;

string change(string a){
    string tmp;
    tmp += a[0];
    for(int i = 0; i < a.length(); i ++){
        if(a[i - 1] == a[i])
            continue;
        tmp += a[i];
    }
    return tmp;
}

int getsum(vector<int> a, int n){
    sort(a.begin(),a.end());
    int sum = 0;
    for(int i = 0; i < n; i ++){
        sum += abs(a[i] - a[n >> 1]);
    }
    return sum;
}

int cal(int n){
    string camp = change(a[0]);
    for(int i = 0; i < n; i ++){
        if(camp != change(a[i]))
            return -1;
    }
    vector<string> b = a;
    vector<int> c(n);
    int sum = 0;
    for(int i = 0; i < camp.length(); i ++){
        for(int j = 0; j < n; j ++){
            int ct = 0;
            while(ct < b[j].length() && b[j][ct] == camp[i]) ct ++;
            c[j] = ct;
            b[j] = b[j].substr(ct, b[j].length() - ct);
        }
        sum += getsum(c,n);
    }
    return sum;
}

int main()
{
      freopen("As.in","r",stdin);
    freopen("A.txt","w",stdout);
    int T;
    scanf("%d",&T);
    int cas = 1;
    while(T--){
        cout<<"Case #"<<cas<<": ";
        int n;
        cin>>n;
        a.resize(n);
        for(int i = 0; i < n; i ++){
            cin>>a[i];
        }
        int ans = cal(n);
        if(ans >= 0){
            cout<<ans<<endl;
        }else{
            cout<<"Fegla Won"<<endl;
        }
        cas++;
    }
    return 0;
}
