#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <numeric>
using namespace std;
ifstream in("in.in");
ofstream out("out.out");
int main()
{
	vector<string> v;
	vector<string> final_v;	
	int pos[100];
	int T;
	int N;
	in >> T;
	int loop = 0;
	while (T--)
	{
		loop++;
		v.clear();
		final_v.clear();
		string s;
		in >> N;
		int nn = N;
		//cout << "*******************" << endl;
		while (nn--)
		{
			in >> s;
			v.push_back(s);
			//cout << s << endl;
		}
		//getchar();
		for (int i = 0; i < 100; i++)
			pos[i] = 0;
		string saved;
		int flag = 0;
		for (int i = 0; i < N; i++)
		{
			string s = "";
			char prechar = '0';
			for (int j = 0; j < v[i].size(); j++)
			if (prechar != v[i][j])
			{
				s += v[i][j];
				prechar = v[i][j];
			}
			final_v.push_back(s);
			if (i == 0)
				saved = s;
			else if (saved != s)
				flag = 1;
		}
		if (!flag)//能够成立
		{
			flag = 1;
			int count = 0;
			int gg = 0;
			while (flag)
			{
				int same = 0;
				int diff = 0;
				for (int i = 0; i < N; i++)//对每个字符串
				{
					if (pos[i] == v[i].size() - 1)
						diff++;
					else if (v[i][pos[i]] == v[i][pos[i] + 1])//跟后一个一样
						same++;
					else diff++;
				}

				//cout << "same " << same << endl;
				//cout << "diff " << diff << endl;
				//for (int i = 0; i < N; i++)
				//	cout << pos[i] << " ";
				//cout << endl;
				if (diff == 0 || same == 0)//都是相同元或者不同元
				{
					for (int i = 0; i < N; i++)
					if (pos[i] != v[i].size() - 1)
						pos[i]++;
				}
				else if (same > diff)//相同比较多,不同的要增加
				{
					for (int i = 0; i < N; i++)//对每个字符串
					{
						if (pos[i] == v[i].size() - 1)
						{
						}
						else if (v[i][pos[i]] == v[i][pos[i] + 1])//跟后一个一样
						{
							if (pos[i] != v[i].size() - 1)
								pos[i]++;
						}
						else {}
					}
					count += diff;
				}
				else
				{
					for (int i = 0; i < N; i++)//对每个字符串
					{
						if (pos[i] == v[i].size() - 1)
						{
						}
						else if (v[i][pos[i]] == v[i][pos[i] + 1])//跟后一个一样
						{
							if (pos[i] != v[i].size() - 1)
								pos[i]++;
						}
					}
					count += same;
				}
				//////////////////////////////////////////
				int ccount = 0;
				for (int i = 0; i < N; i++)
				if (pos[i] == v[i].size() - 1)
					ccount++;
				if (ccount == N)
					gg++;
				if (ccount == N && gg == 2)
					flag = 0;
			}
			out << "Case #" << loop << ": " << count << endl;
		}
		else
		{
			out << "Case #" << loop << ": " << "Fegla Won" << endl;
		}
		//cout << loop << endl;

	}
	//getchar();
}