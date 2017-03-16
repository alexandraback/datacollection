#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

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
		}
	}



	input.close();
	output.close();
	system("pause");
}