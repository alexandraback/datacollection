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

		vector <int> m;

		int N;
		cin>>N;

		FOR(i,0,N){
			int tmp;
			cin>>tmp;
			m.push_back(tmp);
		}

		int y,z;

		y=0;
		
		FOR(i,1,N){
			if(m[i]<m[i-1])
				y+=m[i-1]-m[i];
		}

		z=0;

		int eatrate=0;

		FOR(i,1,N){
			if(m[i-1]-m[i]>eatrate)
				eatrate=m[i-1]-m[i];
		}

		FOR(i,0,N-1){
			z+=min(eatrate,m[i]);
		}

		cout<<y<<' '<<z;




		cout<<endl;
	}

}
