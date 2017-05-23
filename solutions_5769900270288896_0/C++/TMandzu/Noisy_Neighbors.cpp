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

int solve(){
    memset(c,0,sizeof(c));
    cin>>N>>M>>C;
    int num = N*M;
    int ANSWER = INF;
    for (int i=0;i<(1<<num);i++){
        int k = 0;
        int sul = 0;
        for (int x = 0; x < N;x++)
            for (int y = 0; y <M; y++)
            c[x][y]=(i&(1<<k))>0, k++, sul+=c[x][y];
        if (sul != C)
            continue;
        int ans = 0;

        for (int x = 0; x < N;x++)
            for (int y = 0; y <M; y++){
                if (c[x][y] && c[x+1][y])
                    ans++;
                if (c[x][y] && c[x][y+1])
                    ans++;
            }

        ANSWER = min(ANSWER, ans);
    }
    return ANSWER;
}

int main(){
    freopen("text2.in","r",stdin);   freopen("text2.out","w",stdout);
    int t;
    cin>>t;
    for (int test = 1; test <= t; test++){
        cout<<"Case #"<<test<<": "<<solve()<<endl;
    }
}







