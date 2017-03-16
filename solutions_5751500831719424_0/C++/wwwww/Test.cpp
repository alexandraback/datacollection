#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct LC
{
	char letter;
	int count;
};

int main()
{
	int ncases;
	cin >> ncases;
	for (int i = 1; i <= ncases; i++)
	{
		int nstr;
		string str;
		cin >> nstr;
		cin.ignore(1000, '\n');
		vector<vector<LC> > words;
		for (int j = 0; j < nstr; j++)
		{
			getline(cin, str);
			int ind = 1;
			vector<LC> cur;
			LC temp;
			temp.count = 1;
			temp.letter = str[0];
			while (ind < str.length())
			{
				if (str[ind] != temp.letter)
				{
					cur.push_back(temp);
					temp.count = 1;
					temp.letter = str[ind];
				}
				else
				{
					temp.count++;
				}
				ind++;
			}
			cur.push_back(temp);
			words.push_back(cur);
		}

		int len = words[0].size();
		bool eqlen = true;
		for (int k = 1; k < nstr; k++)
		{
			if (words[k].size() != len)
			{
				eqlen = false;
				break;
			}
		}

		cout << "Case #" << i << ": ";

		if (!eqlen)
		{
			cout << "Fegla Won\n";
		}
		else
		{
			int ops = 0;
			bool valid = true;
			for (int z = 0; z < len; z++)
			{
				char ch = words[0][z].letter;
				int minops = INT_MAX;
				for (int k = 0; k < nstr; k++)
				{
					if (words[k][z].letter != ch)
					{
						valid = false;
						break;
					}
					int tmp = 0;
					for (int kk = 0; kk < nstr; kk++)
					{
						tmp = tmp + abs(words[kk][z].count - words[k][z].count);
					}
					if (abs(tmp) < minops)
						minops = abs(tmp);
				}
				if (!valid)
					break;
				else
					ops = ops + minops;
			}
			if (valid)
			{
				cout << ops << "\n";
			}
			else
			{
				cout << "Fegla Won\n";
			}
		}
	}
	return 0;
}