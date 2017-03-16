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

		int N;


		cin>>N;

		vector <string> in;

		int tab[1000][1000];

		FOR(i,0,1000)
			FOR(j,0,1000)
			tab[i][j]=0;

		FOR(i,0,N){
			string tmp;
			cin>>tmp;
			in.push_back(tmp);
		}

		string seq="_";

		FOR(i,0,in[0].length()){
			if(seq[seq.length()-1]!=in[0][i])
				seq+=in[0][i];
		}

		int impossible=0;

		FOR(it,0,N){
			string nseq="_";
			FOR(i,0,in[it].length()){
				if(nseq[nseq.length()-1]!=in[it][i])
					nseq+=in[it][i];

				tab[it][nseq.length()-1]++;
			}

			if(seq!=nseq)
				impossible=1;

		}

		if(impossible){
			cout<<"Fegla Won\n";
			continue;
		}
		
		int ret=0;
		FOR(i,0,1000){
			int tmp=10000;

			FOR(dest,0,1000){
				int t=0;
				FOR(j,0,N){
					t+=abs(dest-tab[j][i]);
				}

				tmp=min(tmp,t);
			}

			ret+=tmp;
		}

		cout<<ret;

		cout<<endl;
	}

}
