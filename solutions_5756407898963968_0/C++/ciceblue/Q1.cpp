#include <iostream>
#include <fstream>
#define REP(i,s,n) for(int i=s;i<n;i++)
using namespace std;
ifstream fin("A-small-attempt0.in");
ofstream fout("out.txt");
int main()
{
	int T;
	fin >> T;
	int row1, row2;
	int temp;
	int cc;
	int res;
	int count[17];
	REP(caseNumber, 1, T + 1)
	{
		REP(i, 1, 17) count[i] = 0;
		fin >> row1;
		REP(i, 1, 5)
		{
			REP(j, 0, 4)
			{
				fin >> temp;
				if (i == row1)count[temp] = 1;
			}
		}
		fin >> row2;
		cc = 0;
		REP(i, 1, 5)
		{
			REP(j, 0, 4)
			{
				fin >> temp;
				if (i == row2&&count[temp]){
					cc++; res = temp;
				}
			}
		}
		if (cc == 0)
		{
			fout << "Case #"<<caseNumber<<": Volunteer cheated!\n";
		}
		else if (cc == 1)
		{
			fout << "Case #"<<caseNumber<<": "<<res<<'\n';
		}
		else
		{
			fout << "Case #"<<caseNumber<<": Bad magician!\n";
		}
	}
	return 0;
}