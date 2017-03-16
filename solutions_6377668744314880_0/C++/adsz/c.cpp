#include <bits/stdc++.h>
using namespace std;

struct Coords { int x; int y; };

struct AngleRelativeTo
{
	const vector<Coords>& data;
	int relative;
	
	bool operator()(int lhs, int rhs)
	{
		int x1 = data[lhs].x - data[relative].x;
		int y1 = data[lhs].y - data[relative].y;
		int x2 = data[rhs].x - data[relative].x;
		int y2 = data[rhs].y - data[relative].y;
		
		return x1*y2 - x2*y1 > 0;
	}
};

void test()
{
	int n;
	cin >> n;
	
	
	vector<Coords> data(n);
	for (size_t i = 0; i<n; i++)
	{
		cin >> data[i].x >> data[i].y;
	}
	
		if (n <= 3)
	{
		for(int i=0;i<n;i++) cout << "0" << endl;
		return;
	}
	
	for (size_t i = 0; i<n; i++)
	{
		int result = n;
		
		vector<int> angle_sorted;
		for (size_t j=0;j<n;j++)
		{
			if (i!=j)
				angle_sorted.push_back(j);
		}
		
		AngleRelativeTo cmp{data, i};
		bool sorted = false;
		while (!sorted)
		{
			sorted = true;
			for (int p=1; p<n-1; p++)
			{
				if(cmp(angle_sorted[p], angle_sorted[p-1]))
				{
					swap(angle_sorted[p-1], angle_sorted[p]);
					sorted = false;
				}
			}
		}
		//sort(angle_sorted.begin(), angle_sorted.end(), ;
		
		/*cerr << "Sorting for " << i << endl;
		for (int j : angle_sorted)
			cerr << j << " ";
		cerr << endl;*/
		
		for (size_t j = 0; j<n && result>0; j++)
		{
			if (i==j) continue;
			
			for (size_t k = 0; k<n && result>0; k++)
			{
				if (k==i || k==j) continue;
								
				
				int xj = data[j].x - data[i].x;
				int yj = data[j].y - data[i].y;
				int xk = data[k].x - data[i].x;
				int yk = data[k].y - data[i].y;
				
				int det = xj*yk - xk*yj;
				
				
				if (det == 0 && xj*xk+yj*yk>0)
				{
					result = min(result, n-3);
				}
				else if (det>=0)
				{					
					//cerr << " Relative " << i << "->" << j << "->" << k << endl;
					//cerr << "det = " << det << endl;
					
					
					
					int to_remove = -1;
					for( int q = 0; ; q = (q+1)%(n-1))
					{
						if (to_remove == -1 && angle_sorted[q]==k)
							to_remove = 0;
						else if (to_remove >=0 && angle_sorted[q]==j)
							break;
						else if (to_remove >=0)
							to_remove++;
					}
					
					//cerr << "to_remove="<<to_remove<<endl;
					if (to_remove < result)
						result = to_remove;
				}
			}
		}
		
		cout << result << endl;
	}
}

int main()
{
	size_t c;
	std::cin >> c;
	for (size_t i = 1; i<=c; ++i)
	{
		std::cout << "Case #" << i << ":" << endl;
		test();
	}
}
