#include<bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    int t; scanf("%d",&t);
    for(int test=1;test<=t;test++){
        int n; scanf("%d",&n);
        priority_queue<pii>q;
        for(int i=0;i<n;i++){
            int x; scanf("%d",&x);
            q.push(mp(x,i));
        }
        printf("Case #%d: ",test);
        while(!q.empty()){
            if(q.size()==2){
                pii ja=q.top(); q.pop();
                pii ja2=q.top(); q.pop();
                int roz=ja.f-ja2.f;
                while(roz--){
                    printf("%c ",ja.s+'A');
                }
                while(ja2.f--){
                    printf("%c%c ",ja.s+'A',ja2.s+'A');
                }
            }
            else{
                pii ja=q.top(); q.pop();
                printf("%c ",ja.s+'A');
                ja.f--;
                if(ja.f>0)q.push(ja);
            }
        }
        puts("");
    }
    return 0;
}
