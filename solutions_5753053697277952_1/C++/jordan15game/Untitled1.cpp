#pragma comment(linker, "/STACK:65536000")
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<queue>
#include<iostream>
#include<time.h>
#include <list>
#include <numeric>
#include <complex>
#define forn(i,n) for(int i=0;i<n;i++)
#define clr(a,b) memset(a,b,sizeof(a))
#define ll long long
#define ull unsigned long long
#define lowb(i) (i&(-i))
#define bug(n,m,x) forn(i,n){forn(j,m)printf("%d ",x[i][j]);puts("");}puts("")
#define sqr(x) ((x)*(x))
using namespace std;
const int inf=1<<30;
const double eps=1e-8;
const double pi=acos(-1.0);
//const ll mod = 9223372034707292160LL;
//const double inf = 1e10;
const double E=2.718281828459;


int n,m;
int ti=1,t;
int a[30];

int main(){
#ifdef jordan13game
    freopen("C:\\D\\in.txt","r",stdin);
    freopen("C:\\D\\out.txt","w",stdout);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int tot=0;
        for(int i=0;i<n;i++)cin>>a[i],tot+=a[i];
        printf("Case #%d:",ti++);
        while(tot){
            vector<int> b;
            int *p=max_element(a,a+n);
            b.push_back(p-a);
            tot--;(*p)--;
            p=max_element(a,a+n);
            if(*p>tot/2){
                b.push_back(p-a);
                tot--;
                (*p)--;
            }
            printf(" ");
            for(int i=0;i<b.size();i++)printf("%c",'A'+b[i]);
        }
        puts("");
    }
    return 0;
}




