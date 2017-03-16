#include<fstream>
#include<bitset>
#include<vector>
using namespace std;
int main()
{
	ifstream fin("A-small-attempt0.in");
	ofstream fout("Magic Trick.out");
	int n;
	fin>>n;
	for (int k=0;k<n;++k)
	{
		int round1,round2;
		fin>>round1;
		vector<vector<int>> numbers(4,vector<int>(4)),numbers2(4,vector<int>(4));
		for (int i=0;i<4;++i)
			for (int j=0;j<4;++j)
				fin>>numbers[i][j];
		fin>>round2;
		int count = 0;
		for (int i=0;i<4;++i)
			for (int j=0;j<4;++j)
				fin>>numbers2[i][j];
		round1--;
		round2--;
		int sign;
		for (int i=0;i<4;++i)
			for (int j=0;j<4;++j)
				if (numbers[round1][i] == numbers2[round2][j])
				{
					count++;
					sign = numbers[round1][i];
				}
		if (count == 0)
			fout<<"Case #" << k+1 <<": Volunteer cheated!"<<endl;
		if (count == 1)
			fout<<"Case #" << k+1 <<": "<<sign<<endl;
		if (count > 1)
			fout<<"Case #"<< k+1<<": "<< "Bad magician!"<<endl;
	}
	return 0;
}