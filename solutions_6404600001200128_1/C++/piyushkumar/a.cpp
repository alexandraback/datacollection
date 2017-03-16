#include <algorithm>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cstdarg>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

#define ll long long int
#define pb push_back
#define fr(i,n)     for(int i=0;i<n;i++)
#define init(mem,v) memset(mem,v,sizeof(mem))
typedef pair<int,int> pii;

#if __cplusplus > 199711L
    void read(){}
    template<typename... T>
    void read(int& head, T&... tail) {scanf("%d",&head); read(tail...);}

    #define DB(args...) { cerr << __LINE__<< ": "; vector<string> _v = split(#args, ','); err(_v.begin(), args); }
    vector<string> split(const string& s, char c) {
        vector<string> v;stringstream ss(s);string x;
        while (getline(ss, x, c)) v.push_back(x);
        return move(v);
    }
    void err(vector<string>::iterator it) {cerr<<endl;}
    template<typename T, typename... Args>
    void err(vector<string>::iterator it, T a, Args... args) {
        cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << "  "; err(++it, args...);
    }
#else
    #define DB(args...)
    void read(int& head) {scanf("%d",&head);}
#endif

#define mx 1005
int amt[mx];

int main(){
    int t;
    read(t);
    fr(ii,t){
        int n;
        read(n);
        fr(i,n) read(amt[i]);

        int ans1=0,ans2=0;
        int rt=0;

        fr(i,n-1){
            if(amt[i+1] < amt[i]) ans1+=amt[i]-amt[i+1];
            rt=max(rt,amt[i]-amt[i+1]);
        }
        fr(i,n-1){
            ans2+=min(amt[i],rt);
        }
        printf("Case #%d: %d %d\n",ii+1,ans1,ans2);
    }
}
