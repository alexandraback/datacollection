#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <stack>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int num;
    ifstream fin;
    ofstream fout;
    string input;
    fin.open("repeatsmall.in", std::ifstream::in);
    fout.open("repeatsmall.out", std::ofstream::out);
    fin>>num;
    for(int i = 0; i < num; i++)
    {
	int n;
	fin>>n;
	vector<string> x(n);
	vector<string> y(n);
	vector<vector<int> > z(n);
	bool flag = true;
	for(int j = 0; j < n; j++)
	{
	    fin>>x[j];
	    string p, q;
	    p = x[j][0];
	    y[j].append(p);
	    int count = 0;
	    for(int k = 1; k < x[j].size(); k++)
	    {
		q = x[j][k];
		count++;
		if(q != p)
		{
		    z[j].push_back(count);
		    count = 0;
		    y[j].append(q);
		    p = q;
		}
		if(k == x[j].size() - 1)
		{
		    z[j].push_back(count+1);
		}
	    }
	    if(x[j].size() == 1)
		z[j].push_back(count+1);
	    cout<<y[j]<<endl;
	}
	for(int j = 1; j < n; j++)
	{
	    if(y[j] != y[0])
	    {
		fout<<"Case #"<<i+1<<": Fegla Won"<<endl;
		flag = false;
	    }
	}
	for(int j = 0; j < n; j++)
	{
	    for(int xx = 0; xx < z[j].size(); xx++)
		cout<<z[j][xx];
	    cout<<endl;
	}
	if(!flag)
	{
	    continue;
	}
	int ans = 0;
	for(int j = 0; j < z[0].size(); j++)
	{
	    int save = 100000000;
	    for(int p = 0; p < n; p++)
	    {
		int count = 0;
		for(int q = 0; q < n; q++)
		{
		    count += z[p][j] - z[q][j] > 0? z[p][j]-z[q][j]: z[q][j] - z[p][j];
		}
		if(count < save)
		    save = count;
	    }
	    ans+=save;
	}
	fout<<"Case #"<<i+1<<": "<<ans<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
