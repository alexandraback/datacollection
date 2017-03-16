/*===============*\
|  ID: TMANDZU    |
|    LANG: C++    |
\*===============*/
//Tornike Mandzulashvili
//#pragma comment(linker,"/STACK:256000000")
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <iostream>
#include <set>
#include <cstring>
#include <deque>
#include <fstream>

#define deb(x) cout << "> " << #x << " : " << (x) << endl;
#define EPS 0.000000001
#define Pi 3.1415926535897932384626433832795028841971
#define hash1 1000003
#define hash2 1000033
#define md 1000000007
#define INF 1000000500ll
#define mp make_pair
#define pb push_back
#define S size()
#define MX(aa,bb) (aa>bb?aa:bb)
#define MN(aa,bb) (aa<bb?aa:bb)
#define fi first
#define se second
#define PI pair < ll ,ll  >
#define REP(i,a,n) for(i=a;i<n;i++)
#define sc scanf
#define pt prll f
#define big long long
#define VI vector <int >
#define DID (long long)
#define ll long long
#define AL(a) (a).begin(),(a).end()
#define INFF DID INF*INF

using namespace std;

string get(string s){
    string t="";
    for (int i=0;i<s.S;i++){
        if (t.S==0)
            t+=s[i];
        else
            if (t[t.S-1]!=s[i])
            t+=s[i];
    }
    return t;
}

VI get2(string s){
    string t="";
    VI x;
    int last=0;
    for (int i=0;i<s.S;i++){
        if (t.S==0)
            t+=s[i],last++;
        else
            if (t[t.S-1]!=s[i])
            t+=s[i],x.pb(last),last=1;
            else
            last++;
    }
    x.pb(last);
    return x;
}

ll doit(VI d){
    sort(AL(d));
    ll ans=0;
    for (int i=0;i<d.S;i++)
        ans+=abs(d[i]-d[d.S/2]);
    return ans;
}

string s[105];
VI v[105];

main(){
    freopen("text.in","r",stdin);
    freopen("text.out","w",stdout);

    int t;
    cin>>t;
    for (int tests=1;tests<=t;tests++){
        for (int i=0;i<=101;i++)
            v[i].clear();
        int N;
        cin>>N;
        string last="";
        bool ok=1;
        for (int i=0;i<N;i++){
            cin>>s[i];
            string x=get(s[i]);
            if (i==0)
                last=x;
            else {
                if (last!=x)
                    ok=false;
            }
        }
        if (!ok){
            cout<<"Case #"<<tests<<": Fegla Won"<<endl;
            continue;
        }
        ll ans=0;

        for (int i=0;i<N;i++){
            v[i]=get2(s[i]);
        }
        for (int j=0;j<v[0].S;j++){
            vector <int> d;
            for (int i=0;i<N;i++)
                d.pb(v[i][j]);
            ans+=doit(d);
        }

        cout<<"Case #"<<tests<<": "<<ans<<endl;
    }
}


