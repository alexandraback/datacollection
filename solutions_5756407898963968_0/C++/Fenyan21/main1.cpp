#include <fstream>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
	ifstream is("rp1.txt");
	//std::istream& is = std::cin;
	ofstream os("answer.txt");
	int testcase;
	is >> testcase;
	for ( int tc = 1; tc <= testcase; tc++){
		int a1,a2;
		vector<int> v1(4),v2(4);
		is >> a1;
		int tmp;
		for( int i = 0; i < 4; i++) if( i!=a1-1){
			is >>tmp >> tmp >> tmp >> tmp;
		} else {
			is >> v1[0] >> v1[1] >> v1[2] >> v1[3]; 
		}
		is >> a2;
		for( int i = 0; i < 4; i++) if( i!=a2-1){
			is >>tmp >> tmp >> tmp >> tmp;
		} else {
			is >> v2[0] >> v2[1] >> v2[2] >> v2[3]; 
		}

		vector<int> res;
		for( int i = 0; i < 4; i++){
			int now = v1[i];
			for( int j = 0; j < 4; j++) if( now == v2[j] )
				res.push_back(now);
		}
		

		os << "Case #"<<tc;
		os << ": ";
		if( res.size() == 0 ){
			os << "Volunteer cheated!" << endl;
		} else if ( res.size() > 1) {
			os << "Bad magician!" << endl;
		}else
			os << res[0] << endl;
	}
	is.close();
	os.close();
}