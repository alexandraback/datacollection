#include <stdio.h>
#include <queue>
using namespace std;

int max(int a, int b){ return a > b ? a : b; }
int min(int a, int b){ return a < b ? a : b; }
int mark[30];

priority_queue< pair<int, int> > q;

int main(){
    int T;
    scanf("%d", &T);
    for(int test=1; test<=T; test++){
        for(int i=0; i<30; i++) mark[i] = 0;
        int N;
        int num=0;
        int maxer1=0, max1=-1;
        int maxer2=0, max2=-1;
        scanf("%d", &N);
        printf("Case #%d: ", test);
        for(int i=0; i<N; i++){
            scanf("%d", &mark[i]), num += mark[i];
            q.push(make_pair(mark[i], i));
        }
        maxer1 = q.top().second;
        q.pop();
        maxer2 = q.top().second;
        q.pop();
        while(mark[maxer1] > mark[maxer2]){
            printf("%c ", 'A'+maxer1);
            mark[maxer1]--;
        }
        for(int i=0; i<N; i++){
            if(i == maxer1 || i == maxer2) continue;
            while(mark[i] > 0){ printf("%c ", 'A'+i); mark[i]--; }
        }
        while(mark[maxer1] > 0){
            printf("%c%c ", 'A'+maxer1, 'A'+maxer2);
            mark[maxer1]--;
        }
        while(!q.empty()) q.pop();
        printf("\n");
    }
    return 0;
}