// Coder nyble
#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<string> vs;

#define fi          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define fr(i,n)     re(i,0,n)
#define tr(i,x)     for(__typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define pu          push_back
#define mp          make_pair
#define sz(x)       (int)(x.size())
#define nl          printf("\n")

int main()
{
    int t;
    cin>>t;
    for(int z=1; z<=t; z++)
    {
        int N;
        cin>>N;
        vector<string> vstr;
        string str = "abcdefghijklmnopqrstuvwxyz", dstr;
        map<char,vector<int> > grid;

        char c;
        int distinct=1,d=1;
        bool notPossible = false ;

        fr(i,N)
        {
            cin>>str;
            vstr.push_back(str);
            c=str[0];
            if(i==0)dstr.append(1u,c);
            d=1;

            map<char,int > grid1;

            fr(j,str.length())
            {
                if(c!=str[j])
                {
                    d++;
                    c=str[j];
                    if(i==0)dstr.append(1u,c);
                }
                grid1[str[j]]++;
            }
            if(i==0)distinct = d;

            if(d!=distinct)notPossible = true;

            tr(it,grid1)
            {
                grid[(*it).first].push_back((*it).second);
                //cout<<(*it).second<<" ";
            }
            //nl;
        }

        int median;

        int moves=0,cnt = 0;

        tr(it,grid)
        {
            sort( (*it).second.begin(),(*it).second.end() );

            median = (*it).second [ (*it).second.size()/2 ];

            tr(it1,(*it).second)
            {
                moves+= abs( (*it1) - median );
            }
            //cout<<median << endl;*/
            tr(it2,vstr)                    //check order
            {
                int i = 0;

                tr(it3,(*it2))
                {
                    if(dstr[i] != (*it3) )
                    {
                        i++;
                        if(dstr[i] != (*it3) )notPossible = true ;
                    }
                }
            }
        }


        if(notPossible)
            printf("Case #%d: Fegla Won\n",z);
        else
            printf("Case #%d: %d\n",z,moves);

    }
    return 0;
}
