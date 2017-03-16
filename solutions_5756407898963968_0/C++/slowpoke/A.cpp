#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

static const int SZ = 4;

vector<int> readLine(ifstream &in){
	int line;
	in >> line;
	vector<int> v;
	for (int i = 0; i < SZ; ++i){
		for (int j = 0; j < SZ; ++j){
			int tmp;
			in >> tmp;
			if (line == i + 1){
				v.push_back(tmp);
			}
		}
	}
	return v;
}

void proc(int tc, ifstream &in, ofstream &out){
	vector<int> v1 = readLine(in);
	vector<int> v2 = readLine(in);
	vector<int> v(SZ);

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	auto it = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v.begin());
	
	int common = it - v.begin();

	out << "Case #" << tc << ": ";
	if (common == 0){
		out << "Volunteer cheated!" << endl;
	}
	else if (common == 1){
		out << v[0] << endl; 
	}
	else{
		out << "Bad magician!" << endl;
	}

}

int main(){
	ifstream in("A-small-attempt0.in");
	ofstream out("A-small-attempt0.out");

	int T;
	in >> T;
	for (int i = 1; i <= T; ++i){
		proc(i, in, out);
	}
}