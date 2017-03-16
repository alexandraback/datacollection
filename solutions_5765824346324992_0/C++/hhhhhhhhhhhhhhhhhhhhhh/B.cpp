#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(0==b)return a;
    return gcd(b,a%b);
}

int lcm(int a,int b){
    int gg=gcd(a,b);
    return a/gg*b;
}

int a[20];

struct Re{
    int x,t;
    Re(){}
    Re(int x,int t):x(x),t(t){}
    bool operator<(const Re& re)const{
        if(t==re.t)return x>re.x;
        return t>re.t;
    }
};

int ans[10000000];
int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
    int test;
    scanf("%d",&test);
    for(int _=1;_<=test;_++){
        int m;
        scanf("%d",&m);
        int n;
        scanf("%d",&n);
        int tmp=1;
        for(int i=0;i<m;i++){
            scanf("%d",&a[i]);
            tmp=lcm(tmp,a[i]);
        }

        int ss=0;
        for(int i=0;i<m;i++){
            ss+=tmp/a[i];
        }

        priority_queue<Re> que;
        for(int i=0;i<m;i++){
            que.push(Re(i,0));
        }

        for(int i=0;!que.empty();i++){
            Re u=que.top();
            que.pop();
            ans[i]=u.x;
            if(u.t+a[u.x]>=tmp)continue;
            que.push(Re(u.x,u.t+a[u.x]));
        }

        n--;
        n%=ss;
        printf("Case #%d: %d\n",_,ans[n]+1);
    }
    return 0;
}
