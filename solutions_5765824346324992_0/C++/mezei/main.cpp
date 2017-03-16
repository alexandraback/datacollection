#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>

using namespace std;

struct barber
{
    int id;
    long long ready;
};

class mycomparison
{
public:
  bool operator() (const barber& lhs, const barber&rhs) const
  {
    if (lhs.ready < rhs.ready || (lhs.ready == rhs.ready && lhs.id < rhs.id))
        return false;
    else
        return true;
  }
};

int main()
{
    int T;
    scanf("%d", &T);

    for (int t=1; t<=T; t++) {
            int B, N;
            scanf("%d %d", &B, &N);

            int M[1000];
            double M_rec = 0;
            for(int i=0; i<B; i++) {
                scanf("%d", &M[i]);
                M_rec += 1/(double)M[i];
            }


            priority_queue <barber, vector<barber>, mycomparison> q;

            int done = 0;
            int K = max(0, N-1000);
            for(int i=0; i<B; i++) {
                //printf("%d\n", i);
                int p = K/(M_rec*M[i]);

                barber b;
                b.id=i;
                b.ready=((long long)p)*(long long)M[i];
                done += p;
                //printf("%lld ", p);
                q.push(b);
            }

            //printf("%d / %d\n", done, N);

            N-=done;

            for(int i=1; i<N; i++) {
                barber server = q.top();
                //printf("%d ", server.id+1);
                server.ready=server.ready + (long long)M[server.id];
                q.pop();
                q.push(server);
            }

            barber b = q.top();
            printf("Case #%d: %d\n", t, b.id+1);
    }

    return 0;
}
