#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
#define mem(name,value) memset(name,value,sizeof(name))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=100100,inf=0x3f3f3f3f;

int n;
struct Item
{
    int id,val;
    bool operator<(const Item &aa) const
    {
        if(val==aa.val) return id<aa.id;
        return val<aa.val;
    }
};

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);

    int T,cas=1;
    cin>>T;
    while(T--){
        printf("Case #%d:",cas++);
        priority_queue<Item>q;
        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            q.push((Item){i,x});
        }
        while(!q.empty()){
            if(q.size()==2){
                int x=q.top().val;
                int a=q.top().id; q.pop();
                int b=q.top().id; q.pop();
                for(int i=0;i<x;i++) printf(" %c%c",a+'A',b+'A');
                cout<<endl;
            }else{
                int x=q.top().val;
                int a=q.top().id; q.pop();
                printf(" %c",a+'A');
                if(--x) q.push((Item){a,x});
            }
        }
    }

}











