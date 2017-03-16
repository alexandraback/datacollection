#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>

using namespace std;

int main()
{
	ifstream ifs("A-small-attempt0 (10).in");
    ofstream ofs("answer_A_small");
	int T;
	ifs >> T; cout << "T= " << T <<endl;
   
   for(int t=0;t<T;t++){  // test cases
	int N;
    ifs >> N; cout << "N= " << N << endl; 

	int tmp;
	vector<int>m;
	for(int i=0;i<N;i++){
     ifs>>tmp;  m.push_back(tmp); //cout <<tmp<<"  ";
	}
	//cout<<endl;

	long long int ans1=0;
	for(int i=0;i<N-1;i++){
		if(m[i+1]<m[i]){ans1+=m[i]-m[i+1];}
	}

	long long int ans2=0;
	int Rate=0;
	for(int i=0;i<N-1;i++){
		if(Rate<m[i]-m[i+1]){Rate=m[i]-m[i+1];}
	}

	for(int i=0;i<N-1;i++){
          ans2 += min(m[i],Rate);
	}



	cout << "Case #" <<t+1<<": " << ans1 <<" " <<ans2<<endl;
    ofs << "Case #" <<t+1<<": " << ans1 <<" " <<ans2<<endl;

   } // end of test cases

 return 0;
}