#include <iostream>
#include <fstream>
using namespace std;

int mat1[5][5], mat2[5][5];
int ans1, ans2;

int main(int argc, char *argv[]) {
	ifstream fin("A-small-attempt0.in");
	ofstream fout("magic.out");
	
	int cases;
	fin >> cases;
	for(int cnt = 1; cnt <= cases; ++cnt)
	{
		int count = 0;
		int ans;
		fin >> ans1;
		fout << "Case #" << cnt << ": ";
		for(int i = 1; i <= 4; ++i)
			for(int j = 1; j <= 4; ++j)
			{
				fin >> mat1[i][j];
			}
		
		fin >> ans2;
		for(int i = 1; i <= 4; ++i)
			for(int j = 1; j <= 4; ++j)
			{
				fin >> mat2[i][j];
			}
		for(int i = 1; i <= 4; ++i)
			for(int j = 1; j <= 4; ++j)
			{
				if(mat1[ans1][i] == mat2[ans2][j])
				{
					count ++;
					ans = mat1[ans1][i];
				}
			}
		if(count == 1)
		{
			fout << ans << endl;
			
		}
		else if(count == 0)
		{
			fout << "Volunteer cheated!" << endl;
		}
		else
		{
			fout << "Bad magician!" << endl;
		} 
	}
}