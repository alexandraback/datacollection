#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int ta=1;ta<=t;++ta)
	{
		cout << "Case #" << ta << ": ";
		int n;
		cin >> n;
		vector<int> inp(n);
		for(int i=0;i<n;++i)
			cin >> inp[i];
		int rate=0;
		for(int i=1;i<n;++i)
			rate=max(rate,inp[i-1]-inp[i]);
		int resp1=0;
		for(int i=1;i<n;++i)
			if(inp[i-1]-inp[i]>0)
				resp1+=inp[i-1]-inp[i];
		int resp2=0;
		for(int i=1;i<n;++i)
			if(inp[i-1] < rate)
				resp2+=inp[i-1];
			else
				resp2+=rate;
		cout << resp1 << ' ' << resp2 << endl;
	}
}
