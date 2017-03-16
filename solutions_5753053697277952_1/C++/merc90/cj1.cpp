#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

int main() {
    //freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-large.in", "r", stdin);
    freopen("out1.txt", "w", stdout);
	int t,tt,n,p[27],cnt,cn;
	cin>>t;
	tt=t;
	while(tt--)
	{
        cin>>n;
        cnt=0;
        std::vector<std::pair <int,int> > v;
        REP(q,n)
        {
            cin>>p[q];
            cnt+=p[q];
            v.push_back(std::make_pair (p[q],q));
        }
        cn=cnt;
        cout<<"Case #"<<t-tt<<": ";
        //sort(v.rbegin(),v.rend());
        while(cn)
        {
          sort(v.rbegin(),v.rend());
            v[0].first--;cn--;
			char c='A'+v[0].second;
            cout<<c;
            sort(v.rbegin(),v.rend());
            if((float)v[1].first*100/(cn-1)<=50.00 || v[1].first==0)
            {
                v[0].first--;cn--;
                char c='A'+v[0].second;
            cout<<c;
            }
            cout<<" ";
        }
		//cout<<"Case #"<<t-tt<<": "<<ret<<endl;
		cout<<endl;
	}
	return 0;
}
