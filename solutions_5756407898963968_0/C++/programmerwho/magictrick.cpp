#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int case_number;
	int row1;
	int row2;
	int card1[5][5];
	int card2[5][5];
	int flag= 0;
	int result = 0;
	ifstream ifs("A-small-attempt0.in");
	ofstream ofs("out.txt");
	ifs>>case_number;
	for(int cases = 1; cases <= case_number; cases ++)
	{
		ifs>> row1;
		for(int j = 1; j <= 4; j++)
		{
			for(int k = 1;k <= 4; k++)
			{
				ifs>>card1[j][k];
			}
		}
		ifs>> row2;
		for(int j = 1; j <= 4; j++)
		{
			for(int k = 1;k <= 4; k++)
			{
				ifs>>card2[j][k];
			}
		}
		flag= 0;
		result = 0;
		for(int j = 1;j<=4;j++)
		{
			for(int k = 1; k<=4;k++)
			{
				if(card1[row1][j] == card2[row2][k])
				{
					flag++;
					result = card1[row1][j];
				}
			}
		}
		ofs<<"Case #"<<cases<<": ";
		if(flag == 0)
			ofs<<"Volunteer cheated!"<<endl;
		if(flag == 1)
			ofs<<result<<endl;
		if(flag > 1)
			ofs<<"Bad magician!"<<endl;
	}
}