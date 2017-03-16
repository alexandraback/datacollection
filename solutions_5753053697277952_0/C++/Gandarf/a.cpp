#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;

int testn;
int a[26];
int temp, n;

int main()
{
	ifstream in("A-small-attempt0.in");
	//ifstream in("input.txt");
	ofstream out("output.txt");

	in >> testn;
	for (int test = 1; test <= testn; ++test) 
	{
		// init
		for (int i = 0; i < 26; ++i)
			a[i] = 0;

		// input
		in >> n;
		int total = 0;
		for (int i = 0; i < n; ++i)
		{
			in >> temp;
			a[i] = temp;
			total += temp;
		}

		out << "Case #" << test << ":";
		while (total > 0)
		{
			int cnt = 0;
			for (int i = 0; i < 26; ++i)
				if (a[i] > 0)
					cnt++;

			if (cnt == 2)
			{
				out << " ";
				for (int i = 0; i < 26; ++i)
				{
					if (a[i] > 0)
					{
						a[i]--;
						total--;
						char s = i + 'A';
						out << s;
					}
				}
				continue;
			}

			/*if (total == 2)
			{
				out << " ";
				for (int i = 0; i < 26; ++i)
				{
					if (a[i] > 0)
					{
						char s = i + 'A';
						out << s;
					}
				}
				break;
			}
			*/
			int pos = -1;
			int mn = -999;
			for (int i = 0; i < 26; ++i)
			{
				if (a[i] > mn)
				{
					mn = a[i];
					pos = i;
				}
			}

			char s = pos + 'A';
			out << " " << s;
			a[pos]--;
			total--;
		}
		out << endl;
	}

	in.close();
	out.close();
	return 0;
}