// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
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
#include <utility>
#include <vector>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

int main(){
	int T;
	cin>>T;

	FOR(iteration,0,T){
		cout<<"Case #"<<(iteration+1)<<": ";

		long long N,B;
		cin>>B>>N;

		vector <long long> M;

		FOR(i,0,B){
			long long tmp;
			cin>>tmp;
			M.push_back(tmp);
		}

		if(N<=B){
			cout<<N<<endl;
			continue;
		}

		long long minutesmax=1;

		int flag=1;

		while(flag){
			long long already=0;
			FOR(i,0,B){
				already+=1+(minutesmax/M[i]);
			}

			if(already>=N){
				flag=0;
			}else{
				minutesmax*=2;
			}
		}

		long long minutesmin=minutesmax/2;

		while(minutesmin<minutesmax){
			long long mid=(minutesmin+minutesmax)/2;
			long long already=0;
			FOR(i,0,B){
				already+=1+(mid/M[i]);
			}

			if(already>=N){
				minutesmax=mid;
			}else{
				minutesmin=mid+1;
			}
		}

		long long elap=minutesmin;

		long long aminago=0;

		FOR(i,0,B){
			aminago+=1+((elap-1)/M[i]);
		}

		int sel=N-aminago;
		int ret=1;

		FOR(i,0,B){
			if(elap%M[i]==0){
				if((--sel)==0){
					ret=i+1;
					break;
				}
			}
		}

		cout<<ret;







		cout<<endl;
	}

}
