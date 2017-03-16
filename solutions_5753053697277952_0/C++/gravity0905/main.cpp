#include <bits/stdc++.h>
#define INF 1000000000
#define mod 1000000007
#define vi vector<int>
#define vit vector<int>::iterator
#define ll long long
#define ii pair<int, int>
#define vii vector<ii>
#define pb push_back
#define mp make_pair
using namespace std;
class comp
    {
    public:
        bool operator()(pair<int,int> &x, pair<int, int> &y)
        {
         return x.first<y.first;
        }
    };

static int P[100];
int main()
{
    int T;
    scanf("%d", &T);
    for(int ctr=1; ctr<=T; ctr++)
    {
        int N,sum=0;
        scanf("%d", &N);
        for(int i=0; i<N; i++)
         {
            scanf("%d", &P[i]);
            sum += P[i];
         }
        priority_queue< ii , vector<ii>, comp> pq;
        for(int i=0; i<N; i++)
            pq.push(mp(P[i], i));
        cout<<"Case #"<<ctr<<": ";
        while(!pq.empty())
        {
            ii x;
            x = pq.top();
            pq.pop();
            x.first--;
            cout<<(char)('A'+x.second);
            if(x.first)
                pq.push(x);
            sum--;
            if(!pq.empty())
            {
                x = pq.top();
                pq.pop();
                x.first--;
                sum--;
                if(!pq.empty() && pq.top().first > sum/2)
                {
                    x.first++;
                    sum++;
                    pq.push(x);
                    cout<<" ";
                    continue;
                }
                cout<<(char)('A'+x.second);
                if(x.first)
                    pq.push(x);
            }

            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
