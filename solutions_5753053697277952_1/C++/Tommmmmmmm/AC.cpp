#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pi;
int main(){
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int _;scanf("%d",&_);
    int cas=1;
    while(_--){
        printf("Case #%d:",cas++);
        int n;
        scanf("%d",&n);
        priority_queue<pi>q;
        int tot=0;
        for(int i=1;i<=n;i++){
            int x;scanf("%d",&x);
            q.push(pi(x,i));
            tot+=x;
        }
        while(!q.empty()){
            putchar(' ');
            pi u=q.top();q.pop();
            u.first--;
            putchar('A'+u.second-1);
            if(u.first)q.push(u);
            tot--;
            if(q.size()&&q.top().first+q.top().first>tot){
                pi v=q.top();q.pop();
                putchar('A'+v.second-1);
                v.first--;
                tot--;
                if(v.first)q.push(v);
            }
        }
        puts("");
    }
}
