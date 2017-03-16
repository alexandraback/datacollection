/**
   __      __            ______             _________     __     ______
  |  |    |  |          /  __  \           /   _____ \   |  |   |   __  \
  |  |    |  |         /  /  \  \          |  |     \/   |  |   |  |  \  \
  |  |    |  |        /  /    \  \         |  |          |  |   |  |   \  \
  |  |____|  |       /  /######\  \        |  |______    |  |   |  |___*  /
  |   ____   |      /              \       |______   |   |  |   |   ___  X
  |  |    |  |     /  /##########\  \             |  |   |  |   |  |   *  \
  |  |    |  |    /  /            \  \            |  |   |  |   |  |   /  /
  |  |    |  |   /  /              \  \   /\______|  |   |  |   |  |__/  /
  |__|    |__|   \_/                \_/   \__________|   |__|   |_______/


**/



#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<utility>
#include<set>


#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define sf scanf
#define pf printf
#define pb push_back
#define MP make_pair
#define fr first
#define sc second
#define ll long long
#define dd double
#define all(v) v.begin(), v.end()
#define PI acos(-1.0)
#define mem(ara, value) memset(ara, value, sizeof(ara))
#define paii pair<int, int>
#define pall pair<ll, ll>
#define SZ(a) int(a.size())
#define read(nm) freopen(nm, "r", stdin)
#define write(nm) freopen(nm, "w", stdout)
#define dump(x) cout<<#x<<" = "<<x<<endl

using namespace std;

#define take(args...) asdf,args

struct ASDF{
    ASDF& operator,(int &a) {
        sf("%d", &a);
        return *this;
    }
    ASDF& operator,(long int &a){
        sf("%ld", &a);
        return *this;
    }
    ASDF& operator,(long long int &a){
        sf("%lld", &a);
        return *this;
    }
    ASDF& operator,(char &c){
        sf("%c", &c);
        return *this;
    }
    ASDF& operator,(double &d){
        sf("%lf", &d);
        return *this;
    }

    template<typename T>
    ASDF& operator,(T &a){
        cin>>a;
        return *this;
    }
}asdf;


template<typename T>
ostream& operator<<(ostream& output, vector<T>&v)
{
    output<<"[ ";
    if(SZ(v))
    {
        output<<v[0];
    }
    FOR(i, 1, SZ(v))
    {
        output<<", "<<v[i];
    }
    output<<" ]";
    return output;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& output, pair<T1, T2>&p)
{
    output<<"( "<<p.fr<<", "<<p.sc<<" )";
    return output;
}


//Header ends here

#define MAXX 107


vector<string>v;
string s;

vector<pair<char, int> > ara[MAXX];


int main()
{
    read("asmall.in"); write("asmall.out");

    int kases, kaseno = 0;

    int N;

    cin>>kases;

    while(kases--)
    {
        cin>>N;
        v.clear();

        for(int i=0; i<N; i++) ara[i].clear();

        loop(i, N)
        {
            cin>>s;
            v.pb(s);
        }


        for(int i=0; i<N; i++)
        {
            ara[i].pb(MP(v[i][0], 1 ));

            int pos = 0;

            for(int j=1; j<SZ(v[i]); j++)
            {
                if(v[i][j] == v[i][j-1])
                {
                    ara[i][pos].sc++;
                }
                else
                {
                    ara[i].pb(MP(v[i][j], 1));
                    pos++;
                }
            }
        }


        bool possible = true;

        for(int i=1; i<N; i++)
        {
            if(SZ(ara[i]) != SZ(ara[i-1]))
            {
                possible = false;
                break;
            }
        }




        int len = SZ(ara[0]);

        ll cnt = 0;

        int counter[102];



        for(int i=0; i<len; i++)
        {
            char ch = ara[0][i].fr;


            mem(counter, 0);

            for(int j=0; j<N; j++)
            {
                if(ara[j][i].fr != ch)
                {
                    possible = false;
                }
                else
                {
                    counter[ ara[j][i].sc ]++;
                }
            }


            ll mn = 1<<29;
            ll tmp;

            for(int i=1; i<102; i++)
            {
                tmp = 0;
                for(int j=1; j<102; j++)
                {
                    tmp += abs(i-j)*(ll)counter[j];
                }
                mn = min(tmp, mn);
            }

            cnt += mn;
        }

        if(possible)
        {
            pf("Case #%d: %lld\n", ++kaseno, cnt);
        }
        else
        {
            pf("Case #%d: Fegla Won\n", ++kaseno);
        }

    }




}
