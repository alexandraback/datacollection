#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t, n;
	vector<int> m;
	
	int res1, res2;
	int maxDif;
	
	cin >> t;
	
	for (int casenum = 1; casenum <= t; casenum++)
	{
		res1 = res2 = 0;
		maxDif = -1;
		
		cin >> n;
		m.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> m[i];
			
			//first method
			if (i > 0 && m[i] < m[i-1])
				res1 += (m[i-1] - m[i]);
				
			//second method: find max negative dif
			if (i > 0 && m[i] < m[i-1])
			{
				if (m[i-1] - m[i] > maxDif || maxDif == -1)
					maxDif = m[i-1] - m[i];
			}
		}
		
		//second method: max dif is number of mushrooms eaten in 10 seconds
		if (maxDif != -1)
		{
			for (int i = 0; i < n-1; i++)
			{
				if (m[i] > maxDif)
					res2 += maxDif;
				else
					res2 += m[i];
			}
		}
		
		//print results
		cout << "Case #" << casenum << ": ";
		cout << res1 << " " << res2 << endl;
		
		m.clear();
	}
}
