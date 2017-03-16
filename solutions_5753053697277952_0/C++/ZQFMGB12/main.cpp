#include <iostream>
#include <cstdio>
#include <queue>
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair

using namespace std;

int T,N;
int cnt[30],sum;
priority_queue<pii> pq;
queue<pii> ans;

bool allLess(int n){
    for (int i = 0; i < N; i++){
        if (cnt[i] > n) return 0;
    }
    return 1;
}

int main(){
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    scanf("%d",&T);
    for (int z = 1; z <= T; z++){
        scanf("%d",&N);
        for (int i = 0; i < N; i++){
            scanf("%d",&cnt[i]);
            pq.push(mp(cnt[i],i));
            sum += cnt[i];
        }
        while(1){
            pii p1 = pq.top(); pq.pop();
            pii p2 = pq.top(); pq.pop();
            int n1 = p1.F,n2 = p2.F;
            if (n1 == 0) break;
            if (n1 == 1 || n2 == 0){
                //this should never happen
            }
            //n1-=2
            cnt[p1.S]-=2;
            if (allLess((sum-2)/2)){
                sum -= 2;
                pq.push(mp(n1-2,p1.S)), pq.push(mp(n2,p2.S));
                ans.push(mp(p1.S,p1.S));
                continue;
            }else cnt[p1.S] += 2;
            //n1-- n2--
            cnt[p1.S]--, cnt[p2.S]--;
            if (allLess((sum-2)/2)){
                sum -= 2;
                pq.push(mp(n1-1,p1.S)), pq.push(mp(n2-1,p2.S));
                ans.push(mp(p1.S,p2.S));
                continue;
            }else cnt[p1.S]++,cnt[p2.S]++;
            //n1--
            cnt[p1.S]--;
            if (allLess((sum-1)/2)){
                sum--;
                pq.push(mp(n1-1,p1.S)), pq.push(mp(n2,p2.S));
                ans.push(mp(p1.S,-1));
                continue;
            }
            printf("ERROR REACHED END\n");
        }
        printf("Case #%d: ",z);
        while(!ans.empty()){
            pii cur = ans.front();ans.pop();
            if (cur.S == -1) printf("%c ",(char)('A'+cur.F));
            else printf("%c%c ",(char)('A'+cur.F),(char)('A'+cur.S));
        }
        printf("\n");
    }
    return 0;
}