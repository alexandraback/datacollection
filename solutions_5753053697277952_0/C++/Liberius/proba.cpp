#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

bool is_empty(const vector<size_t>& list){
	for (size_t i = 0; i < list.size(); ++i)
		if (list[i] != 0) return false;
	return true;
}

bool check_violence(const vector<size_t>& list) {
	size_t sum=0;
	for (size_t i = 0; i < list.size(); ++i)
		sum += list[i];
	for (size_t i = 0; i < list.size(); ++i)
		if (list[i] * 2 > sum) return true;
	return false;
}

string process (vector<size_t> input){
	string result;
	size_t temp;
	while(1){
		if (is_empty(input)) return result;
		temp = distance(input.begin(), max_element(input.begin(), input.end()));
		result.push_back('A' + temp);
		--(input[temp]);
		if (is_empty(input)) return result;
		temp = distance(input.begin(), max_element(input.begin(), input.end()));
		--(input[temp]);
		if (check_violence(input)) ++(input[temp]);
		else result.push_back('A' + temp);
		result.push_back(' ');
	}
}


int main(int argc, char** argv){
	string filename;
	cout << "input filename: ";
	cin >> filename;
	ifstream ip(filename.c_str());
	ofstream op("output.txt");
	if (!(ip.is_open())) {
		op << "File not exist.";
		op.close();
		return 1;
	}
	size_t T;
	ip >> T;
	string input;
	for (size_t i = 1; i <= T; ++i){
		size_t N;
		ip >> N;
		vector<size_t> list(N);
		for (size_t j = 0; j < N; ++j)
			ip >> list[j];
		op << "Case #" << i << ": ";
		op << process(list);
		op << endl; 
	}
	op.close();
	ip.close();
	return 0;
}