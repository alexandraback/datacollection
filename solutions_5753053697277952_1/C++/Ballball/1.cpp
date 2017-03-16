#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
const int MAXN = 26;
int a[MAXN];
int N;
int count[10];

int chooseOne()
{
	int ans = -1;
	int max = 0;
	for (int i = 0;i<N;i++)
		if (a[i]>max)
		{
			max = a[i];
			ans = i;
		}
	return ans;
}

bool valid(int total, int ans)
{
	for (int i = 0;i<N;i++)
	{
		if (i==ans)
		{
			if (a[i]*2-2>total-1)
				return false;
		}
		else if (a[i]*2>total-1)
			return false;
	}
	return true;
}

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("A-large.in");
	fout.open("A-large.out");
	int T;
	fin>>T;
	for (int i = 1;i<=T;i++)
	{
		fin>>N;
		int total = 0;
		for (int j = 0;j<N;j++)
		{
			int temp;
			fin>>temp;
			a[j] = temp;
			total+=temp;
		}
		fout<<"Case #"<<i<<": ";
		while (total>0)
		{
			int tempAns = chooseOne();
			if (valid(total,tempAns))
			{
				if (total>1)
					fout<<char(tempAns+'A')<<" ";
				else fout<<char(tempAns+'A')<<endl;
				a[tempAns]--;
				total--;
			}
			else
			{
				fout<<char(tempAns+'A');
				total--;
				a[tempAns]--;
				tempAns = chooseOne();
				if (total>1)
					fout<<char(tempAns+'A')<<" ";
				else fout<<char(tempAns+'A')<<endl;
				a[tempAns]--;
				total--;
			}
		}
	}
	fin.close();
	fout.close();
	return 0;
}