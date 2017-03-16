#include <bits/stdc++.h>
using namespace std;
int cnt[26];
struct entry
{
    int val,let;
    entry(int _val,int _let)
    {
        val=_val;
        let=_let;
    }
    bool operator <(const entry &a) const
    {
        return val<a.val;
    }
};
void main2()
{
    for(int i=0;i<26;i++) cnt[i]=0;
    int n;
    scanf("%d",&n);
    priority_queue<entry> pq;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        sum+=x;
        pq.push({x,i});
    }
    while(!pq.empty())
    {
        //printf("CURSUM=%d\n",sum);
        entry topp=pq.top();
        pq.pop();
        printf("%c",(char)(topp.let+(int)'A'));
        if(topp.val>1) pq.push({topp.val-1,topp.let});
        sum--;
        if(pq.empty()) break;
        if(sum==2) {printf(" ");continue;}
        topp=pq.top();
        pq.pop();
        printf("%c",(char)(topp.let+(int)'A'));
        if(topp.val>1) pq.push({topp.val-1,topp.let});
        sum--;
        printf(" ");
    }
    printf("\n");
}
#define FILE true
int main()
{
    if(FILE){
    freopen("A.txt","r",stdin);
    freopen("Aout.txt","w",stdout);
    }
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        main2();
    }
}
