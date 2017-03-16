#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair <int,int > PII;
#define FOR(i,x,y)  for(int i = x;i < y;++ i)
#define IFOR(i,x,y) for(int i = x;i > y;-- i)
#define pb  push_back
#define mp  make_pair
#define fi  first
#define se  second

const int maxn = 100000;

char str[maxn];

void work(){
    priority_queue <PII >   q;
    int n,p,len = 0;
    scanf("%d",&n);
    FOR(i,0,n)  scanf("%d",&p),q.push(mp(p,i));
    while(!q.empty()){
        PII u = q.top();    q.pop();
        str[len++] = u.se+'A';
        u.fi -= 1;
        if(u.fi)    q.push(u);
    }
    if(len%2){
        printf(" %c",str[0]);
        for(int i = 1;i < len;i += 2)   printf(" %c%c",str[i],str[i+1]);
    }
    else{
        for(int i = 0;i < len;i += 2)   printf(" %c%c",str[i],str[i+1]);
    }
    printf("\n");
}

int main(){
    //freopen("A-large.in","r",stdin);
    //freopen("A.out","w",stdout);
    int T,tCase = 0;  scanf("%d",&T);
    while(T--){
        printf("Case #%d:",++tCase);
        work();
    }
    return 0;
}
