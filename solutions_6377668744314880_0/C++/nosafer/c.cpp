#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>


using namespace std;


vector<int> cut(vector<pair<int, int> >& vecCor)
{
	vector<int> vec;
	if (vecCor.size() <= 1){
		vec.resize(vecCor.size(), 0);
		return vec;
	}
	for (int i = 0; i < vecCor.size(); i++){
		int mincut = 10000000;
		for (int j = 0; j < vecCor.size(); j++){
			if (i == j){
				continue;
			}
			int left = 0;
			int right = 0;
			for (int w = 0; w < vecCor.size(); w++){
				if (w == i || w == j){
					continue;
				}
				int x1 = vecCor[i].first;
				int y1 = vecCor[i].second;
				int x2 = vecCor[j].first;
				int y2 = vecCor[j].second;
				int x = vecCor[w].first;
				int y = vecCor[w].second;
				int result =  (y2-y1)*x-(x2-x1)*y-(y2-y1)*x1 + (x2-x1)*y1;
				if (result > 0){
					left ++;
				}
				else if (result < 0){
					right ++;
				}
			}
			left = min(left, right);
			mincut = min(left, mincut);
			if (mincut == 0){
				break;
			}
		}
		vec.push_back(mincut);
	}
	return vec;
}

int main(int argc, char **argv)
{
	ifstream in(argv[1]);
	int nCase;
	in >> nCase;
	for (int i = 1; i <= nCase; i++){
		int nNum ;
		in >> nNum;
		vector<pair<int, int> > vecCor;
		for (int j = 0; j < nNum; j++){
			int tmp1, tmp2;
			in >> tmp1;
			in >> tmp2;
			pair<int, int> pairtmp = make_pair(tmp1, tmp2);
			vecCor.push_back(pairtmp);
		}
		vector<int> result = cut(vecCor);
		cout<<"Case #"<<i<<":"<<endl;
		for (int j = 0; j < result.size(); j++){
			cout<<result[j]<<endl;
		}
	}
	return 0;
}
