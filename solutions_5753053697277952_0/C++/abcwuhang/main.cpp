#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n;
struct node{
    char ch;
    int num;
    bool operator<(const node &a) const
    {
        return num<a.num;
    }
    node(char ccc,int nn)
    {
        ch=ccc;
        num=nn;
    }
    node()
    {
        ch=0;
        num=0;
    }
} a[300];
priority_queue<node*> q;
node *look[100];
int up(int x,int y)
{
    if (x%y==0) return x/y;
    return x/y+1;
}
bool valid()
{
    int top=-1;
    while (!q.empty())
    {
        look[++top]=q.top();
        q.pop();
    }
    int sum=0;
    bool err=false;
    for (int i=0;i<=top;++i)
        sum+=look[i]->num;
    for (int i=0;i<=top;++i)
        if (look[i]->num>up(sum,top+1))
        {
            //printf("err %d %d!\n",look[i].num,up(sum,top+1));
            return false;
        }
    for (int i=0;i<=top;++i)
        q.push(look[i]);
}
void add(char ch)
{
    int top=-1;
    bool flag=false;
    while (!q.empty())
    {
        look[++top]=q.top();
        q.pop();
        if (look[top]->ch==ch)
        {
            look[top]->num++;
            flag=true;
            break;
        }
    }
    if (!flag) look[++top]=new node(ch,1);
    for (int i=0;i<=top;++i)
        q.push(look[i]);
}
void show()
{
    printf("\nshow\n");
    int top=-1;
    while (!q.empty())
    {
        look[++top]=q.top();
        printf("%d ",look[top]->num);
        q.pop();
    }
    printf("\n");
    for (int i=0;i<=top;++i)
        q.push(look[i]);
}
int main()
{
    //freopen("test.txt","r",stdin);
    freopen("A-small-attempt2.in","r",stdin);
    freopen("A-small-attempt2.out","w",stdout);
    int testcases;
    scanf("%d",&testcases);
    for (int ii=1;ii<=testcases;++ii)
    {
        printf("Case #%d:",ii);
        scanf("%d",&n);
        while (!q.empty())
            q.pop();
        int total=0;
        for (int i=0;i<n;++i)
        {
            int x;
            scanf("%d",&x);
            q.push(new node('A'+i,x));
            total+=x;
            a[i].ch='A'+i;
            a[i].num=x;
        }
        /*while (!q.empty())
        {
            node *n1=q.top();
            q.pop();
            n1->num--;
            if (n1->num>0)
            {
                q.push(n1);
            }
            if (q.empty())
            {
                printf(" %c",n1->ch);
                break;
            }
            node *n2=q.top();
            q.pop();
            n2->num--;
            if (n2->num>0)
            {
                q.push(n2);
            }
            if (valid())
            {
                printf(" %c%c",n1->ch,n2->ch);
            }
            else
            {
                printf(" %c",n1->ch);
                add(n2->ch);
            }
            show();
        }*/
        while (total>0)
        {
            sort(a,a+n);
            char n1;
            for (int i=n-1;i>=0;--i)
                if (a[i].num)
                {
                    n1=a[i].ch;
                    --total;
                    --a[i].num;
                    break;
                }
            if (total==2)
            {
                printf(" %c",n1);
                continue;
            }
            sort(a,a+n);
            char n2;
            for (int i=n-1;i>=0;--i)
                if (a[i].num)
                {
                    n2=a[i].ch;
                    --total;
                    --a[i].num;
                    break;
                }
            int party=0;
            for (int i=0;i<n;++i)
                if (a[i].num) ++party;
            bool validi=true;
            if (party)
                for (int i=0;i<n;++i)
                    if (a[i].num>up(total,party))
                    {
                        validi=false;
                        break;
                    }
            if (validi)
            {
                printf(" %c%c",n1,n2);
            }
            else
            {
                printf(" %c",n1);
                for (int i=0;i<n;++i)
                    if (a[i].ch==n2)
                    {
                        a[i].num++;
                        ++total;
                        break;
                    }
            }
        }
        if (ii<testcases) printf("\n");
    }
    return 0;
}
