#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;
int B;
long long N;
long long maxM;
vector< pair<long long,int> > bar;

int BS()
{
    long long s=0;
    long long e=maxM*((N/B)+1);

    while(e-s>1)
    {
        long long mid = s + (e-s)/2;

        long long p=0;
        for(int i=0; i<B; i++)
        {
            long long add = (mid/bar[i].first);
            if(add*bar[i].first == mid)
                p += add;
            else
                p += (add+1);
        }

        if(p<N)
            s=mid;
        else
            e=mid;
    }

    //cout << s << " " << e << endl;
    long long p=0;
    vector<long long> numS;
    vector<long long> numE;
    for(int i=0; i<B; i++)
    {
        long long add = (s/bar[i].first);
        if(add*bar[i].first == s)
        {
            p += add;
            numS.push_back(add);
        }
        else
        {
            add++;
            p += add;
            numS.push_back(add);
        }
    }
    for(int i=0; i<B; i++)
    {
        long long add = (e/bar[i].first);
        if(add*bar[i].first == e)
        {
            //p += add;
            numE.push_back(add);
        }
        else
        {
            add++;
            //p += add;
            numE.push_back(add);
        }
    }

    for(int i=0; i<B; i++)
    {
        if(numE[i]>numS[i])
        {
            p += (numE[i] - numS[i]);
        }
        if(p>=N)
            return bar[i].second;
    }
    return -1;
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T;
    long long x;
    cin >> T;

    for(int t=0; t<T; t++)
    {
        cin >> B >> N;
        bar.clear();
        maxM=0;
        for(int i=0; i<B; i++)
        {
            cin >> x;
            bar.push_back(make_pair(x,i+1));
            maxM = max(maxM,x);
        }

        //sort(bar.begin(), bar.end());

        cout << "Case #" << t+1 << ": " << BS() << endl;
    }
    return 0;
}
