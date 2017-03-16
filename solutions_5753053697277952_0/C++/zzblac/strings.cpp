#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>
#include<set>
#include<string>
#include<queue>
using namespace std;
typedef long long LL;
const int maxn = 100005;
typedef struct Node{
    int id,cnt;
    friend bool operator < (Node a,Node b){
        return a.cnt<b.cnt;
    }
    Node(int id=0,int cnt=0):id(id),cnt(cnt){}
}Node;
priority_queue<Node> Q;
int n;
int main(){
    freopen("1.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,a,ca=0;
    scanf("%d",&t);
    while(t--){
        int cnt=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            Q.push(Node(i,a));
            cnt+=a;
        }
        printf("Case #%d:",++ca);
        while(!Q.empty()){
            Node u=Q.top();
            Q.pop();
            if(u.cnt>1) Q.push(Node(u.id,u.cnt-1));
            printf(" %c",u.id+'A');
            cnt--;
            Node v=Q.top();
            if(!Q.empty()){
                Node v=Q.top();
                Q.pop();
                if((Q.empty()||cnt-1 >= 2 * Q.top().cnt) && cnt - 1 >= 2 * (v.cnt-1)){
                    if(v.cnt>1) Q.push(Node(v.id,v.cnt-1));
                    printf("%c",v.id+'A');
                    cnt--;
                }
                else Q.push(v);
            }
        }
        printf("\n");
    }
    return 0;
}
