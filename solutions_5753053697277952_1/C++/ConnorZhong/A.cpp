#include<iostream>
#include<cstdio>
#include<algorithm>
#include<utility>
#include<queue>
using namespace std;
typedef pair< int ,int > P;
int T;
int N;
P senate[26];

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);

    cin>>T;
    for (int k = 1; k <= T; k++)
    {
        int p = 0;
        cin>>N;
        priority_queue<P> que;
        for (int i = 0; i < N; i++)
        {
            cin>>senate[i].first;
            p += senate[i].first;
            senate[i].second = i;
            que.push(senate[i]);
        }

        P a,b;
        cout<<"Case #"<<k<<": ";
        while(p > 0)
        {
            a = que.top();que.pop();
            b = que.top();que.pop();
            if (que.empty() or que.top().first == 0)
            {
                while (a.first > b.first)
                {
                    cout<<(char)('A'+a.second)<<" ";
                    a.first--;
                    p--;
                }
                while(a.first > 0)
                {
                    cout<<(char)('A'+a.second)<<(char)('A'+b.second)<<" ";
                    a.first--;
                    b.first--;
                    p-=2;
                }
            }
            else
            {
                while (a.first > b.first)
                {
                    cout<<(char)('A'+a.second)<<" ";
                    a.first--;
                    p--;
                }
                while (a.first > que.top().first)
                {
                    cout<<(char)('A'+a.second)<<(char)('A'+b.second)<<" ";
                    a.first--;
                    b.first--;
                    p-=2;
                }

                if (p == 3)
                {
                    cout<<(char)('A'+a.second)<<" ";
                    a.first--;
                    p--;
                }
                else
                {
                    cout<<(char)('A'+a.second)<<(char)('A'+b.second)<<" ";
                    a.first--;
                    b.first--;
                    p-=2;
                }
                que.push(a);
                que.push(b);

            }


        }//end while
//        sort(senate,senate+N);
    cout<<endl;

    }//end one test



    fclose(stdin);
    fclose(stdout);
}
