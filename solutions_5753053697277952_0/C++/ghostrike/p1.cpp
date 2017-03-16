#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    //freopen("A-small-attempt0.in","r",stdin);
    //freopen("output.txt","w",stdout);
    int cs;
    cin>>cs;
    for (int k = 1; k <= cs; k++)
    {
        //cout<<"Case #"<<k<<": ";
        int n, party[26], t = 0;
        for (int i = 0; i < 26; i++)
        {
            party[i] = 0;
        }
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> party[i];
            t += party[i];
        }
        cout<<"Case #"<<k<<": ";
        while (t )
        {
            int maxn = 0, mf;
            for (int i = 0; i < n; i++)
            {
                if (party[i] > maxn)
                {
                    maxn = party[i];
                    mf = i;
                }
            }
            party[mf]--;
            t--;
            cout<<(char)(mf+'A');
            if(t==0){break;}
            for (int i = 0; i < n; i++)
            {
                if (party[i] / (double) t > 0.5)
                {
                    party[i]--;
                    t--;
                    cout<<(char)(i+'A');
                }
            }
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
