#include<cstdio>
#include<iostream>
#include<queue>

using namespace std;

struct party
{
    char name;
    int num;
    bool operator<(const party &next) const{ return num < next.num; }
};

int main()
{
    int T;
    scanf("%d", &T);
    for(int i=0; i<T; ++i)
    {
        int N;
        int total = 0;
        party p[26+1];
        priority_queue<party> pq;
        scanf("%d", &N);
        for(int j=0; j<N; ++j)
        {
            p[j].name = 'A' + j;
            scanf("%d", &p[j].num);
            pq.push(p[j]);
            total += p[j].num;
        }
        printf("Case #%d:", i+1);
        while(total > 0)
        {
            double rate;
            bool flag = false;
            string now;
            party next;
            next = pq.top();
            pq.pop();
            now += next.name;
            total -= 1;
            next.num--;
            pq.push(next);
            next = pq.top();
            pq.pop();
            if(total > 1) rate = (double)(pq.top().num) / (total - 1);
            else flag = true;
            if(flag || rate <= 0.5)
            {
                now += next.name;
                total -= 1;
                next.num--;
            }
            pq.push(next);
            cout << " " << now;
        }
        cout << endl;
    }
    return 0;
}
