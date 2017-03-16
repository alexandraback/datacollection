//Carlo Piovesan - carlop

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>
#include <string>
#include <math.h>
#include <map>
#include <set>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <bitset>
#include <ctime>
#include <algorithm>
#include <sys/time.h>
#include <assert.h>

using namespace std;

int main(void){
	int test_case_number;
	cin>>test_case_number;
		
	for (int test_case=1; test_case<=test_case_number; test_case++) {
		
		int N;
		cin>>N;
		
		vector <int> C(N);
		for (int i=0; i<N; i++) cin >> C[i];
		
		vector <pair<int,char> > V;
		for (int i=0; i<N; i++) V.push_back(make_pair(C[i], (char)((int)'A'+i)));
		
		sort(V.begin(), V.end(), std::greater<pair<int,char> >());
		
		int count = accumulate(C.begin(), C.end(), 0);
		
		string RES = "";
		
		if (count%2) {
			RES += V.front().second;
			RES += " ";
			V.front().first--;
			count--;
		}
		
		while (count>0) {
			sort(V.begin(), V.end(), std::greater<pair<int,char> >());
			RES += V[0].second;
			V[0].first--;

			RES += V[1].second;
			RES += " ";
			V[1].first--;
			
			count-=2;
		}
		
		cout<<"Case #"<<test_case<<": "<<RES.substr(0, (int)RES.size()-1)<<"\n";
	}
	
	return 0;
}



/*
10
10

1 -> 19 -> 91 -> 100
19	1		9
29
*/
