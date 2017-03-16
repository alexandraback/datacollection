#include <stdio.h>
#include <algorithm>
using namespace std;
int cnt,n,tot;
struct emp
{
    int l;
    char c;
}heap[50];
void upheap (int x)
{
    int y;

    while(x>1){
        y=x/2;
        if(heap[x].l<heap[y].l)
            return ;
        swap(heap[x],heap[y]);
        x=y;
    }

    return ;
}
void downheap (void)
{
    int x=1,y;

    while(x*2<=cnt){
        y=x*2;
        if(y+1<=cnt && heap[y].l<heap[y+1].l)
            y++;
        if(heap[x].l>heap[y].l)
            return ;
        swap(heap[x],heap[y]);
        x=y;
    }

    return ;
}
void solve (void)
{
    int i,j;
    emp tmp;

    while(tot>0){

        printf(" ");
        tmp=heap[1];
        printf("%c",tmp.c);
        tmp.l--;
        heap[1]=heap[cnt--];
        downheap();
        if(tmp.l>0){
            heap[++cnt]=tmp;
            upheap(cnt);
        }
        tot--;

        if(tot>1 && tot-1<2*max(heap[2].l,cnt>=3?heap[3].l:heap[2].l)) continue;

        tmp=heap[1];
        printf("%c",tmp.c);
        tmp.l--;
        heap[1]=heap[cnt--];
        downheap();
        if(tmp.l>0){
            heap[++cnt]=tmp;
            upheap(cnt);
        }
        tot--;
    }
    printf("\n");

    return ;
}
int main (void)
{
    int i,j,t;
    emp tmp;

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        for(j=tot=0;j<n;j++){
            scanf("%d",&tmp.l);
            tot+=tmp.l;
            tmp.c='A'+j;
            heap[++cnt]=tmp;
            upheap(cnt);
        }
        printf("Case #%d:",i+1);
        solve();
    }

    return 0;
}
