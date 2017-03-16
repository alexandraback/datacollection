#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;
#define forn(i,start,Max) for(int i=start;i<Max;i++)
ifstream in("in.txt");
ofstream out("out.txt");

char str1[110][110];
char str2[110][110];
int site[110][110];
int len[110];

int pro(int n)
{
	int j, k,sum,tem,max,sumall=0;
	char ch;
	forn(i, 0, n)
	{
		j = 0; k = 0;
		str2[i][k] = str1[i][j++];
		site[i][k] = 1;
		while (str1[i][j] != '\0')
		{
			if (str1[i][j] == str2[i][k])
				site[i][k]++;
			else
			{
				k++;
				str2[i][k] = str1[i][j];
				site[i][k] = 1;
			}
			j++;
		}
		len[i] = k;
	}
	forn(i, 0, n)
	{
		if (len[i] != k)
			return -1;
	}
	
	forn(i, 0, len[0]+1)
	{
		sum = 1000000000;
		max = site[0][i];
		ch = str2[0][i];
		forn(j, 1, n)
		{
			if (str2[j][i] != ch)
				return -1;
			if (site[j][i] > max)
				max = site[j][i];
		}
		forn (j, 1, max+1)
		{
			tem = 0;
			forn(z, 0, n)
			{
				tem += (j - site[z][i]) > 0 ? j - site[z][i] : -j + site[z][i];
			}
			if (tem < sum)
				sum = tem;
		}
		if (max == 1)
			sum = 0;
		sumall += sum;
	}
	return sumall;
}

int main()
{
	int T,N,da;
	in >> T;
	forn(i, 0, T)
	{
		out << "Case #" << i + 1<<": ";
		in >> N;
		forn(j, 0, N)
		{
			in >> str1[j];
		}
		da = pro(N);
		if (da >= 0)
			out << da << endl;
		else
			out << "Fegla Won" << endl;
	}
	return 0;
}
//out << setiosflags(ios::fixed);
//out << setprecision(8) ;