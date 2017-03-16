#include <iostream>
#include<memory.h>
#include <map>
#include <list>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
using namespace std;

int main()
{
	ifstream cin;
	cin.open("in.in");
	ofstream cout;
	cout.open("out.out");
	
	int T;
	cin>>T;
	for (int z = 1; z <= T; z++)
	{
		int n;
		cin>>n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin>>a[i];
		int mxDec = 0;
		int sm = 0;
		for (int i = 1; i < n; i++)
		{
			mxDec = max(mxDec, a[i-1]-a[i]);
			sm += max(0, a[i-1]-a[i]);
		}
		int sm2 =0;
		for (int i = 1; i < n; i++)
		{
			sm2 += min(mxDec, a[i-1]);
		}
		cout<<"Case #"<<z<<": "<<sm<<" "<<sm2<<endl;
	}
}