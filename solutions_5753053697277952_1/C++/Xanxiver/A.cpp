#include<bits/stdc++.h>
#define MAX 10000
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define ellapse printf("Time : %0.3lf\n",clock()*1.0/CLOCKS_PER_SEC);
using namespace std;/*//E,SE,S,SW,W,NW,N,NEint dr[8]={0,1,1,1,0,-1,-1,-1};int dc[8]={1,1,0,-1,-1,-1,0,1};*/
typedef long long l64d;
typedef unsigned long int ud;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
bool cmp(pii a, pii b) {    return a.fi > b.fi;}
int main()
{
    #ifdef Xanxiver
    freopen("A-large(1).in","r",stdin);
    freopen("A-large(1).out","w",stdout);
    #endif
    //std::ios::sync_with_stdio(false);    int t,n,a;    pii p[30];    scanf("%d",&t);    for(int i=1;i<=t;i++) {        printf("Case #%d: ", i);        int tot = 0;        scanf("%d",&n);        for(int j=0;j<n;j++) {            scanf("%d",&a);            tot+=a;            p[j] = mp(a, j);        }        while(tot) {            sort(p, p + n,cmp);            printf("%c",p[0].sc + 'A');            p[0].fi--;            tot--;            sort(p, p + n,cmp);            if(p[0].fi * 2 > tot) {                printf("%c", p[0].sc + 'A');                p[0].fi--;                tot--;            }            printf(" ");        }        printf("\n");    }
}
