#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool IsEqual(const vector<int>& bt)
{
	if(bt.size() == 0)
		return false;
	int e = bt[0];
	for(int i = 0 ; i < bt.size(); i ++)
	{
		if(bt[i] != e)
			return false;
	}
	return true;
}
int CalBn(int bn, const vector<int>& bt, int num)
{
	if(IsEqual(bt)){
		return ((num-1)%bn) + 1;
	}
	int seq = 1;
	vector<int> bn_ok;
	vector<int> bn_cycle;
	for(int i = 0; i < bn; i ++){
		bn_ok.push_back(bt[i]);
		bn_cycle.push_back(i);
	}
	int min_index;
	int min_time;
	for(int i = bn ; i < num; i ++)
	{
		min_index = 0;
		min_time = bn_ok[0];
		for(int j = 1 ; j < bn; j ++)
		{
			if(min_time > bn_ok[j])
			{
				min_index = j;
				min_time = bn_ok[j];
			}
		}
		bn_ok[min_index] += bt[min_index];
		bn_cycle.push_back(min_index);
		if(IsEqual(bn_ok))
		{
			break;
		}
	}
	seq = (num - 1)%bn_cycle.size();
	seq = bn_cycle[seq] + 1;
	return seq;
}
int main(int argc, char** argv)
{
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);
	int tn;
	fin >> tn;
	int cn = 1;
	while(cn <= tn)
	{
		int bn, num;
		fin >> bn >> num;
		vector<int> bt;
		if(bn == 0)
		{
			cout << "bn = 0 " << endl;
			continue;
		}
		bt.resize(bn);
		for(int i = 0 ; i < bn; i ++)
		{
			fin >> bt[i];	
		}
		fout << "Case #" << cn << ": " << CalBn(bn, bt, num) << endl;
		cn ++;
	}
	return 0;
}
