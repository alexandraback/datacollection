#include<stdio.h>
#include<stdlib.h>
#include<queue>

struct Senate{
    char party;
    int n;
    Senate(char _party = '\0', int _n = 0)
    {
        party = _party; n = _n;
    }
};

bool operator< (Senate a, Senate b)
{
    return a.n < b.n;
}

int main()
{
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("senate_small_output1.txt", "w", stdout);

    int t;  scanf("%d", &t);
    for(int _t = 1; _t <= t; _t++)
    {
        int n; int N[100]; int sum = 0;
        std::priority_queue<Senate> q;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &N[i]);
        printf("Case #%d:", _t);
        for(int i = 0; i < n; i++)
            {  if(N[i] != 0) q.push(Senate('A' + i, N[i])); sum += N[i];  }

        while(!q.empty())
        {
            //validate
            Senate temp = q.top();
            if(temp.n * 2 > sum)
                printf("%c", temp.party);
            else
                printf(" %c", temp.party);
            q.pop();
            temp.n--;
            sum--;
            if(temp.n != 0) q.push(temp);
        }

        printf("\n");
    }
}
