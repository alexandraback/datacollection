/*===============*\
|  ID: TMANDZU    |
|    LANG: C++    |
\*===============*/
//Tornike Mandzulashvili
//std::ios_base::sync_with_stdio (false);

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
#include <assert.h>
#include <queue>
#include <iostream>
#include <set>
#include <cstring>
#include <deque>
#include <fstream>
#include <bitset>

#define endl '\n'
#define deb(x) cout << "> " << #x << " : " << (x) << endl;
#define EPS (1e-9)
#define Pi 3.1415926535897932384626433832795028841971
#define hash1 1000003
#define hash2 1000033
#define INF 1000000500
#define pb push_back
#define mp make_pair
#define S size()
#define MX(aa,bb) (aa>bb?aa:bb)
#define MN(aa,bb) (aa<bb?aa:bb)
#define fi first
#define se second
#define PI pair < int , int >
#define REP(i,a,n) for(i=a;i<n;i++)
#define big long long
#define VI vector < int >
#define DID (long long)
#define ll long long
#define AL(a) (a).begin(),(a).end()
#define INFF DID INF*INF
#define debug 1

using namespace std;

int c[20][20];
int N,M,C;

int solve1(int k,int raod){
    VI v;
    if (C <= raod)
        return 0;
    for (int i=0;i<N;i++)
        for (int j=0;j<M;j++)
    if ((i+j)%2==k){
        int ans = 0;
        if (i+1 <N)
            ans++;
        if (j+1<M)
            ans++;
        if (i-1>=0)
            ans++;
        if (j-1>=0)
            ans++;
        v.pb(ans);
    }
    sort(AL(v));
    int sul = 0;
    for (int i=0;i<C-raod;i++)
        sul+=v[i];
    return sul;
}

int solve(){
    cin>>N>>M>>C;
    return min(solve1(1,(N*M+1)/2), solve1(0,(N*M)/2));
}

int main(){
    freopen("text2.in","r",stdin);   freopen("text2.out","w",stdout);
    int t;
    cin>>t;
    for (int test = 1; test <= t; test++){
        cout<<"Case #"<<test<<": "<<solve()<<endl;
    }
}







