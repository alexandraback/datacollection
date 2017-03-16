#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>


using namespace std;

int firstMe(const vector<int>& vec)
{
	int sum = 0;
	for (int i = 1; i < vec.size(); i++){
		if (vec[i] < vec[i-1]){
			sum += vec[i-1] - vec[i];
		}
	}
	return sum;
}

int secondMe(const vector<int>& vec)
{
	int sum = 0;
	int maxgap = 0;
	for (int i = 1; i< vec.size(); i++){
		if (vec[i] < vec[i-1]){
			if ((vec[i-1] - vec[i]) > maxgap){
				maxgap = (vec[i-1] - vec[i]);
			}
		}
	}
	if (maxgap == 0){
		return 0;
	}
	for (int i = 0; i+1 < vec.size(); i++){
		sum += vec[i] < maxgap ? vec[i] : maxgap;
	}
	return sum;
}
int main(int argc, char **argv)
{
	ifstream in(argv[1]);
	int nCase;
	in >> nCase;
	for (int i = 1; i <= nCase; i++){
		int nNum ;
		in >> nNum;
		vector<int> vecCnt;
		for (int j = 0; j < nNum; j++){
			int tmp;
			in >> tmp;
			vecCnt.push_back(tmp);
		}
		int first =  firstMe(vecCnt);
		int second = secondMe(vecCnt);
		cout<<"Case #"<<i<<": "<<first<<" "<<second<<endl;
	}
	return 0;
}
