#include<cstdio>
#include<queue>
using namespace std;

struct nod{
    int s;
    char p;
    bool operator<(const nod &t)const {
        return s < t.s;
    }
};
int main() {

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T, ca=1;
    scanf("%d", &T);
    while(T--) {
        int n, sm = 0;

        priority_queue<nod> pq;
        printf("Case #%d:", ca++);
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            nod tmp;
            scanf("%d", &tmp.s);
            tmp.p = i+'A';
            pq.push(tmp);
            sm += tmp.s;
        }

        while(!pq.empty()) {
            nod tmp = pq.top();
            pq.pop();
            printf(" %c", tmp.p);
            if(tmp.s != 1) {
                tmp.s--;
                pq.push(tmp);
            }
            if(sm %2 == 0 && !pq.empty()) {
                tmp = pq.top();
                pq.pop();
                printf("%c", tmp.p);
                if(tmp.s != 1) {
                    tmp.s--;
                    pq.push(tmp);
                }
                sm--;
            }
            sm--;
        }
        puts("");
    }
    return 0;
}
