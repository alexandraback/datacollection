#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
    int data;
    char indx;
};
vector<node> a;
bool cmp(node x,node y)
{
    return y.data<x.data;
}
void doit()
{
    int n;
    scanf("%d",&n);
    a.clear();
    int num = 0;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        node p;
        p.data = x;
        p.indx = 'A'+i;
        a.push_back(p);
        num +=x;
    }
    if(num%2 == 1&& num !=1)
    {
        sort(a.begin(),a.end(),cmp);
         printf("%c ",a[0].indx);
         a[0].data --;
         num--;
    }
    while(num)
    {
        sort(a.begin(),a.end(),cmp);
        if(num == 1||num == 2)
        {
            printf("%c",a[0].indx);
            a[0].data -- ;
            if(a[0].data == 1)printf("%c",a[0].indx);
            else if(a[1].data == 1)printf("%c",a[1].indx);
            break;
        }
        if(a[0].data == a[1].data)
        {
            printf("%c%c ",a[0].indx,a[1].indx);
            a[0].data -- ;
            a[1].data -- ;
            num-=2;
        }else
        {
            printf("%c%c ",a[0].indx,a[0].indx);
            a[0].data -- ;
            a[0].data -- ;
            num-=2;
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        doit();
        printf("\n");
    }
}
