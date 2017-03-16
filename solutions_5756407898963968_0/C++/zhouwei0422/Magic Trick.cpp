#include <algorithm>  
#include <bitset>  
#include <cctype>  
#include <cmath>  
#include <complex>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <ctime>  
#include <deque>  
#include <functional>  
#include <iomanip>  
#include <iostream>  
#include <fstream>
#include <list>  
#include <map>  
#include <numeric>  
#include <queue>  
#include <set>  
#include <sstream>  
#include <stack>  
#include <string>  
#include <utility>  
#include <vector>   
using namespace std;

ifstream ifile;
ofstream ofile;
int T;
int row1,row2;

void solve(int cases)
{
	set<int> s;
	vector<int> res;
	ifile>>row1;
	for(int i = 0; i < 16; i++)
	{
		int tmp;
		ifile>>tmp;
		if(i==(row1-1)*4 || i==(row1-1)*4+1 || i==(row1-1)*4+2 || i==(row1-1)*4+3)
		{
			s.insert(tmp);
		}
	}
	ifile>>row2;
	for(int i = 0; i < 16; i++)
	{
		int tmp;
		ifile>>tmp;
		if(i==(row2-1)*4 || i==(row2-1)*4+1 || i==(row2-1)*4+2 || i==(row2-1)*4+3)
		{
			if(s.find(tmp)!=s.end())
				res.push_back(tmp);
		}
	}
	if(res.size()==0)
		ofile<<"Case #"<<cases+1<<": Volunteer cheated!"<<endl;
	else if(res.size()>1)
		ofile<<"Case #"<<cases+1<<": Bad magician!"<<endl;
	else
		ofile<<"Case #"<<cases+1<<": "<<res[0]<<endl;
}

int main(void)
{
	ifile.open("input.txt");
	ofile.open("output.txt");
	ifile>>T;
	
	for (int cases = 0; cases < T; cases++)
	{
		solve(cases);
	}

	ifile.close();
	ofile.close();
	return 0;
}