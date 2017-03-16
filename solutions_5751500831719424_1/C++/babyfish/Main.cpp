#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct info
{
	char c;
	int n;
};

struct my_string
{
	string s;
	vector<info> inf;
};

unsigned long long exchange(int x, vector<int> &v)
{
	unsigned long long result = 0;
	for (int i = 0; i < v.size(); i++)
	{
		result += abs(v[i] - x);
	}
	return result;
}

void main()
{
	ifstream input;
	ofstream output;
	input.open("input.in");
	output.open("output.out");

	if (!input)
	{
		cout<<"No input file"<<endl;
	}
	if (!output)
	{
		cout<<"No output file"<<endl;
	}
	int cases = 0;
	input>>cases;

	for (int nn = 1; nn <= cases; nn++)
	{
		int n;
		
		input>>n;
		vector<my_string> ms(n);
		vector<info> infos(n);
		for (int i = 0; i < n; i++)
		{
			input>>ms[i].s;
		}

		for (int i = 0; i < n; i++)
		{
			int idx0, idx1;
			idx0 = idx1 = 0;
			for (;idx1 < ms[i].s.size(); idx1++)
			{
				if (ms[i].s[idx1] != ms[i].s[idx0])
				{
					info temp;
					temp.c = ms[i].s[idx0];
					temp.n = idx1 - idx0;
					ms[i].inf.push_back(temp);

					idx0 = idx1;
				}
			}
			info tempend;
			tempend.c = ms[i].s[idx0];
			tempend.n = idx1 - idx0;
			ms[i].inf.push_back(tempend);
		}


		bool possible = true;
		int sizes = ms[0].inf.size();
		unsigned long long changes = 0;

		for (int i = 1; i < n; i++)
		{
			if (ms[i].inf.size() != sizes)
			{
				possible = false;
				goto endprint;
			}
		}

		for (int i = 0; i < sizes; i++)
		{
			char now_char = ms[0].inf[i].c;
			vector<int> nums(n);

			for (int j = 0; j < n; j++)
			{
				if (ms[j].inf[i].c == now_char)
				{
					nums[j] = ms[j].inf[i].n;
				}
				else
				{
					possible = false;
					goto endprint;
				}
			}

			sort(nums.begin(), nums.end());

			unsigned long long plus = 0;
			int low = nums[0];
			int high = nums[nums.size() -1];
			plus= exchange(nums[0], nums);
			for (int i = low; i <= high; i++)
			{
				unsigned long long temp = exchange(i, nums);
				if (temp < plus)
				{
					plus = temp;
				}
			}

			changes += plus;
		}



endprint:
		output<<"Case #"<<nn<<": ";
		if (possible)
		{
			output<<changes<<endl;
		}
		else
		{
			output<<"Fegla Won"<<endl;
		}






		/*int n;
		string strs[2];
		input>>n;

		for (int i = 0; i < n; i++)
		{
			input>>strs[i];
			cout<<strs[i]<<endl;
		}

		int idx11, idx12;
		int idx21, idx22;
		bool possible = true;
		int changes = 0;
		bool meet_end = false;

		idx11 = idx12 = idx21 = idx22 = 0;
		possible = true;
		while (!meet_end)
		{
			if (strs[0][idx11] != strs[1][idx21])
			{
				possible = false;
				//cout<<"Differ:"<<idx11<<','<<idx21<<endl;
				break;
			}

			for (; true; idx12++) 
			{
				if (idx12 >= strs[0].size())
				{
					meet_end = true;
					break;
				}
				if (strs[0][idx12] != strs[0][idx11])
				{
					break;
				}
			}
			for (; true; idx22++)
			{
				if (idx22 >= strs[1].size())
				{
					meet_end = true;
					break;
				}
				if (strs[1][idx22] != strs[1][idx21])
				{
					break;
				}
			}

			int char1_num, char2_num;
			char1_num = idx12 - idx11;
			char2_num = idx22 - idx21;

			changes += abs(char1_num - char2_num);

			idx11 = idx12;
			idx21 = idx22;
		}



		if (meet_end)
		{
			if ((idx12 == strs[0].size()) && (idx22 == strs[1].size()))
			{
			}
			else
			{
				//cout<<"Not Same End"<<endl;
				possible = false;
			}
		}

		output<<"Case #"<<nn<<": ";
		if (possible)
		{
			output<<changes<<endl;
		}
		else
		{
			output<<"Fegla Won"<<endl;
		}*/
	}



	input.close();
	output.close();
	system("pause");
}