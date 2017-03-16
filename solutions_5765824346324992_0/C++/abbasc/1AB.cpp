#include <bits/stdc++.h>
//#define DEBUG
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b)
{
    if(b == 0)  return a;
    return gcd(b,a%b);
}

ll lcm(ll a,ll b)
{
    ll g = gcd(a,b);
    return a*b/g;
}

int main()
{
    #ifndef DEBUG

    ifstream in("1ab_s1.in");
    cin.rdbuf(in.rdbuf());
    ofstream out("1ab_s1.out");
    cout.rdbuf(out.rdbuf());

    #endif

    int T;
    cin>>T;
    for(int X = 1; X <= T; X++)
    {
        int B,N,ans;
        cin>>B>>N;
        vector<int> M(B);
        for(int i = 0; i < B; i++)
            cin>>M[i];
        ll lm = 1,md = 0;
        for(int i = 0; i < B; i++)
        {
            lm = lcm(lm,M[i]);
        }
        for(int i = 0; i < B; i++)
        {
            md += lm/M[i];
        }
        if(N <= B)
            ans = N;
        else
        {
            //N -= B;
            N %= md;
            if(N == 0)  N += md;
            int last = 1;
            vector<int> M1(B,0);
            while(N > 0)
            {
                int mn = 0;
                for(int i = 0; i < B; i++)
                {
                    if(M1[mn] > M1[i]) mn = i;
                }
                N--;
                last = mn+1;
                M1[mn] += M[mn];
                //cout<<N<<" "<<last<<endl;
            }
            ans = last;
        }


        cout<<"Case #"<<X<<": "<<ans<<endl;



    }
    return 0;
}

