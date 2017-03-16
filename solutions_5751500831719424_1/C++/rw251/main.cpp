#define __STDC_LIMIT_MACROS
#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <vector>
#include <cstring>
#include <map>
#include <list>
#include <time.h>
#include <bitset>
#include <algorithm>
#include <stdint.h>
#include <limits.h>
#include <iomanip>
#include <set>
#include <deque>

#define rep(i,a,b) for(int i = a; i < b; ++i)
#define REP(i,n) rep(i,0,n)
#define getInt(i) int i;scanf("%d",&i)
#define getDouble(i) double i;scanf("%lf",&i)
#define getUll(i) ull i;scanf("%llu",&i)
#define getLl(i) ll i;scanf("%lld",&i)
#define getChar(c) char c; scanf("%c", &c);
#define getString(s) std::string s;std::getline(cin, s);
#define getWord(w) char w[100]; scanf("%s",w);
#define newLine(tmp) std::getline(cin, tmp);
#define sq(x) ((x)*(x))
#define mset(x,v) memset(x,v,sizeof(x))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))
#define __STDC_LIMIT_MACROS

using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;


int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    getInt(T);
    REP(tt,T){
        getInt(N);
        getString(ttt);
        vector<string> ss;
        vector<int> idx;
        REP(i,N){
            getString(s);
            ss.push_back(s);
            idx.push_back(0);
        }
        bool isposs = true;
        int total =0;
        while(true){
            char first = ss[0][idx[0]];
            vector<int> ans;
            ans.push_back(0);
            while(idx[0] < ss[0].length() && ss[0][idx[0]]==first){
                idx[0]++;
                ans[0]++;
            }
            rep(j,1,N){
                ans.push_back(0);
                if(ss[j][idx[j]]!=first) {
                    isposs = false;
                    break;
                }
                while(idx[j] < ss[j].length() && ss[j][idx[j]]==first){
                    idx[j]++;
                    ans[j]++;
                }
            }
            if(!isposs) break;
            bool alldone = true;
            REP(j,N){
                if(idx[j]<ss[j].length()) alldone = false;
            }
            double tot = 0;
            REP(j,N){
                tot+=ans[j];
            }
            double avg = round(tot/N);

            int actot=100000;
            REP(k,102){
                int mintot=0;
                REP(j,N){
                    mintot += abs(k-ans[j]);
                }
                actot = min(actot, mintot);
            }
            total+=actot;

            if(alldone) break;
        }
        if(isposs){
            cout << "Case #" << (tt+1) << ": " << total << '\n';
        }
        else{
            cout << "Case #" << (tt+1) << ": Fegla won\n";
        }
    }

    return 0;
}
