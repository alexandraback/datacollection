#include<stdio.h>
#include<queue>

using namespace std;

bool check(const priority_queue<pair<int,int> >& pq)
{
    if( pq.size() != 3 )
        return !pq.empty();
    return pq.top().first != 1;
}

int main()
{
    int T;
    freopen("A-large.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d",&T);

    for(int C = 1; C <= T; C++)
    {
        int n;
        priority_queue<pair<int,int>> pq;
        scanf("%d",&n);

        for(int i = 0; i < n; i++)
        {
            int cnt;
            scanf("%d",&cnt);
            pq.push(pair<int,int>(cnt,i));
        }

        printf("Case #%d:",C);
        while(check(pq))
        {
            pair<int,int> top = pq.top();
            pq.pop();

            printf(" %c",'A'+top.second);
            if(top.first > 1)
                pq.push(pair<int,int>(top.first-1,top.second));
            if(pq.empty())
                break;

            top = pq.top();
            pq.pop();
            printf("%c",'A'+top.second);
            if(top.first > 1)
                pq.push(pair<int,int>(top.first-1,top.second));
        }
        if( !pq.empty() )
        {
            pair<int,int> top = pq.top();
            pq.pop();
            printf(" %c",'A'+top.second);
            top = pq.top();
            pq.pop();
            printf(" %c",'A'+top.second);
            top = pq.top();
            printf("%c",'A'+top.second);
        }

        puts("");
    }

}
