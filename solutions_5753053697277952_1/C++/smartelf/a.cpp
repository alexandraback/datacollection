#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool valid(vector<int>& v){
	int t = 0;
	for(size_t i = 0; i < v.size(); ++i){
		t += v[i];
	}
	for(size_t i = 0; i < v.size(); ++i){
		if ( v[i] * 2  > t) return false;
	}
	return true;
}

size_t vmax(vector<int>& v){
	int m = 0;
	size_t mi = 0;
	for(size_t i = 0; i < v.size(); ++i){
		if(v[i] > m){
			m = v[i];
			mi = i;
		}
	}
	return mi;
}

int main(){
	//ifstream in("in.txt");
	ifstream in("A-large.in");
	//ifstream in("A-small-attempt0.in");
	ofstream out("out.txt");
	
	unsigned cases(0), size(0), n(0);
	in >> cases;
	for(int c = 1; c <= cases; ++c){
		int p;
		in >> p;
		vector<int> count(p,0);
		int total = 0;
		for(size_t i = 0; i < p; ++i){
			in >> count[i];
			total += count[i];
		}

		out << "Case #" << c << ":" ;

		while(total > 0){
			size_t m1 = vmax(count);
			count[m1]--;
			out << " " <<  static_cast<char>('A' + m1);
			size_t m2 = vmax(count);
			count[m2]--;
			total--;
			if(total && valid(count)){
				out << static_cast<char>('A' + m2);
				total--;
			}else{
				count[m2]++;
			}

		}

		
		
		out << "\n";
		out.flush();
	}
	out.flush();
	return 0;
}