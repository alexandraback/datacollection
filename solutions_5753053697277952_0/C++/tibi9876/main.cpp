#include <fstream>
#include <queue>
#include <utility>
using namespace std;

priority_queue <pair<int,char> > h;
pair <int,char> p,q;
int i,x,n,t,w,s;


int main()
{
    ifstream f("in.txt");
    ofstream g("out.txt");
    f >> t;
    for (w=1;w<=t;w++)
    {
        g << "Case #" << w << ": ";
        f >> n;
        s=0;
        for (i=1;i<=n;i++)
        {
            f >> x;
            h.push(make_pair(x,'A'+i-1));
            s+=x;
        }
        while (h.top().first!=0)
        {
            p=h.top();
            h.pop();
            s--;
            p.first--;
            h.push(p);
            q=h.top();
            h.pop();
            s--;
            q.first--;
            if (h.top().first>s/2)
            {
                q.first++;
                s++;
                h.push(q);
                g << p.second << ' ';
            }
            else
            {
                h.push(q);
                g << p.second << q.second << ' ';
            }
        }
        g << "\n";
        while (!h.empty())
            h.pop();
    }
    return 0;
}
