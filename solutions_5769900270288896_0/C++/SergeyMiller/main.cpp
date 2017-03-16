#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#define INF 1000*1000*1000
using namespace std;
typedef int ll;


ll getr(int j)
{
    ll ans =0;
    int prev = 0;
    while(j)
    {
        if(j%2 && prev)
        {
            ++ans;
        }
        prev = j%2;

        j/= 2;
    }
    return ans;
}

ll getb(int i)
{
    ll ans = 0;

    while(i)
    {
        if(i%2)
            ++ans;
        i /= 2;
    }
    return ans;
}

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    ll t;
    cin >> t;

    for(ll o = 0;o < t;++o)
    {
        ll n, a,b;
        cin >> a >> b >> n;

        if(n <= (a*b + 1)/2)
        {
            cout << "Case #" << o + 1 << ": " << 0 << endl;
            continue;
        }
        else
        {
            if(a > b) swap(a,b);
            ll pa = pow(2,a);
            ll dp[16][16];
            ll ansv[16][16][17];
           // vector < vector < vector <ll> > > ansv(b, vector <vector <ll> > (pa, vector <ll> (n+1)));
            for(int i = 0;i < pa; ++i)
            {
                for(int j = 0;j < pa;++j)
                {
                    ll ansj = getr(j);
                    ansj += getb(i & j);
                    dp[i][j] = ansj;
                }
            }

            ll total_ans = INF;

            for(int i = 0; i < b;++i)
            {
                for(int k = 0;k < pa; ++k)
                {
                    for(int j = 0;j <= n;++j)
                    {
                        ansv[i][k][j] = INF;
                        if(i == 0)
                        {
                            if(j == getb(k))
                                ansv[i][k][j] = dp[0][k];
                            continue;
                        }


                        for(int w = 0; w < pa; ++w)
                        {
                            if(j - getb(k) >= getb(w))
                            ansv[i][k][j] = min(ansv[i][k][j], ansv[i-1][w][j - getb(k)] + dp[w][k]);
                        }

                        if(i == b-1 && j == n)
                            total_ans = min(total_ans, ansv[i][k][j]);
                    }
                }
            }
            cout << "Case #" << o + 1 << ": " << total_ans << endl;
        }
    }
    return 0;
}

