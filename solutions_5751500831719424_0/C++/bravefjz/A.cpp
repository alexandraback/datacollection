#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;
int T;
int N;

void main()
{
	ifstream fin("A-small-attempt0.in");
	ofstream fout("out.txt");
	fin >> T;
	for (int i = 0; i != T; i++)
	{
		fin >> N;
		vector<string> strs(N,"");
		long long int y = 0;
		bool flag = true;
		fout << "Case #" << i+1 << ": ";
		string common = "";
		for (int j = 0; j != N; j++)
		{
			fin >> strs[j];
			string tmp = "";
			for (int k = 0; k != strs[j].size(); k++)
				if(k == 0 || strs[j][k] != tmp[tmp.size()-1])
					tmp = tmp + strs[j][k];
			if(j == 0)
				common = tmp;
			else if(common != tmp)
				flag = false;
		}
		if(!flag)
			fout << "Fegla Won" << endl;
		else
		{
			y = 0;
			vector<int> idxes(N,0);
			for (int j = 0; j != common.size(); j++)
			{
				vector<int> nums(N,0);
				long long int n = 0;
				for (int k = 0; k != N; k++)
				{
					while(idxes[k] <= strs[k].size()-1 && common[j] == strs[k][idxes[k]])
					{
						idxes[k]++;
						nums[k]++;
					}
					n += nums[k];
				}
				n /= N;
				long long int y1 = 0, y2 = 0;
				for (int k = 0; k != N; k++)
				{
					if(n >= nums[k])
						y1 += n-nums[k];
					else
						y1 += nums[k]-n;
					if(n+1 >= nums[k])
						y2 += n+1-nums[k];
					else
						y2 += nums[k]-n-1;
				}
				if(y1 < y2)
					y += y1;
				else
					y += y2;
			}
			fout << y << endl;
		}
	}
	fin.close();
	fout.close();
}
