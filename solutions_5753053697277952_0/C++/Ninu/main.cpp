#include <fstream>
#include <vector>
#include <utility>
#include <queue>
#include <string>
#include <cassert>

using namespace std;

priority_queue<pair<int, char>> q;

int main()
{
	ifstream f("input.txt");
	ofstream g("output.txt");
	int testCount, n, sum, x;
	f >> testCount;
	for(int testNr = 1; testNr <= testCount; testNr++)
	{
		vector<string> res;
		//read
		sum = 0;
		f >> n;
		for(int i = 0; i < n; i++)
		{
			f >> x;
			sum += x;
			q.push(make_pair(x, 'A' + i));
		}
		//solve
		while(!q.empty())
		{
			pair<int, char> p = q.top();
			q.pop();
			p.first--;
			string ans;
			ans.push_back(p.second);
			sum--;
			if(p.first > 0)
			{
				q.push(p);
			}
			if(sum > 0 && q.top().first > sum / 2)
			{
				p = q.top();
				q.pop();
				p.first--;
				ans.push_back(p.second);
				sum--;
				if(p.first > 0)
				{
					q.push(p);
				}
				assert(sum == 0 || !(q.top().first > sum / 2));
			}
			res.push_back(ans);
		}
		//print
		g << "Case #" << testNr << ":";
		for(int i = 0; i < res.size(); i++)
		{
			g << ' ' << res[i];
		}
		g << '\n';
	}
	f.close();
	g.close();
	return 0;
}