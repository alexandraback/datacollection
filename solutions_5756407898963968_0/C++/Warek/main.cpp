#include <iostream>
#include <cstdio>
#include <fstream>

int main(int argc, char *argv[])
{
	std::ifstream read("A-small-attempt0.in");
	std::ofstream write("A-small-attempt0.out");
	int num=0;
	read >> num;
	int cards[2][4];
	int n;
	int row;
	for (int i=0;i<num;i++)
	{
		read >> row;
		std::cout << row << std::endl;
		for (int j=1;j<row;j++) read >>n>>n>>n>>n;
		read >> cards[0][0] >> cards[0][1] >> cards[0][2] >> cards[0][3];
		for (int j=row;j<4;j++) read >>n>>n>>n>>n;
		read >> row;
		for (int j=1;j<row;j++) read >>n>>n>>n>>n;
		read >> cards[1][0] >> cards[1][1] >> cards[1][2] >> cards[1][3];
		for (int j=row;j<4;j++) read >>n>>n>>n>>n;
		int count=0;
		int card;
		for (int j=0;j<4;j++)
		{
			int comp=cards[0][j];
			for (int k=0;k<4;k++)
			{
				if (comp==cards[1][k])
				{
					card=comp;
					count++;
				}
			}
		}
		if (count==0) write << "Case #" << i+1 << ": Volunteer cheated!" << std::endl;
		if (count==1) write << "Case #" << i+1 << ": " << card << std::endl;
		if (count>1) write << "Case #" << i+1 << ": Bad magician!" << std::endl;
	}
	return 0;
}

