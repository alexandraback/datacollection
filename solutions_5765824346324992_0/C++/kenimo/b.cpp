#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <iomanip>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;

LL M[1000];
void run()
{
	LL B,N;
	cin >> B >> N;
	for(int i=0;i<B;i++){
		cin >> M[i];
	}

	LL low=-1;
	LL hi=10*N;
	while(low+1<hi){
		LL mid=(low+hi)/2;
		LL s=0;
		for(int i=0;i<B;i++){
			s+=mid/M[i]+1;
		}
		if(N<=s){
			hi=mid;
		}
		else{
			low=mid;
		}
	}
	//cout << hi << endl;
	{
		LL s=0;
		for(int i=0;i<B;i++){
			if(low>=0){
				s+=low/M[i]+1;
			}
		}
		int t=N-s;
		for(int i=0;i<B;i++){
			if(hi%M[i]==0){
				t--;
				if(t==0){
					cout << i+1 << endl;
					return;
				}
			}
		}

	}

}


int main() {
	int TotalCase;
	cin >> TotalCase;
	for (int Case=1;Case<=TotalCase;Case++) {
		cout << "Case #" << Case << ": ";
		run();
	}
}
