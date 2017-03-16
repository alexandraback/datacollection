#include <algorithm>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

const int MAXN = 100 + 10;

ifstream input;
ofstream output;

int N;
string s[MAXN];
string tar;

void Read()
{
	input >> N;
	for (int i=0; i<N; i++)
	{
		input >> s[i];
	}
}

int Count[MAXN][MAXN];
bool GetTar()
{
	string tmp;
	for (int i=0; i<N; i++)
	{
		tmp = "";
		int pos = 0;
		int i_tmp = 0;
		while (pos<s[i].length())
		{
			tmp += s[i][pos];
			Count[i][i_tmp] = 0;
			while (pos+1<s[i].length() && s[i][pos]==s[i][pos+1])
			{
				pos++;
				Count[i][i_tmp]++;
			}
			if (pos+1>=s[i].length()) Count[i][i_tmp]++;
			i_tmp++;
			pos++;
		}

		//cout << tmp << endl;

		if (i==0) tar = tmp;
		else
			if (tar!=tmp) return false;
	}
	return true;
}

int a[MAXN];
int getTot()
{
	int tot = 0;
	for (int pos=0; pos<tar.length(); pos++)
	{
		for (int i=0; i<N; i++)
		{
			a[i] = Count[i][pos];
		}
		sort(a, a+N);
		int to = a[N/2];
		for (int i=0; i<N; i++)
			tot += abs(a[i]-to);
	}
	return tot;
}

void singleCase(int case_num)
{
	output << "Case #" << case_num << ": ";
	Read();
	if (!GetTar()) output << "Fegla Won" << endl;
	else
		output << getTot() << endl;
}

int main()
{
	int T, C = 0;
	input.open("A.in");
	output.open("A.out");

	input >> T;
	for (int i=0; i<T; i++)
	{
		C++;
		singleCase(C);
	}
	return 0;
}