#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdint.h>
#include <map>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <string.h>

const char text2cards[] = "Bad magician!";
const char text0cards[] = "Volunteer cheated!";

int main(int argc, char** argv)
{
	uint32_t cT, T, i, j;
	
	std::ifstream finp;
	std::ofstream fout;
	finp.open("0.in");
	fout.open("1.out", std::ios::trunc);
	if(!finp.is_open() || !fout.is_open())
	{
		std::cout << "can't open files" << std::endl;
		return -1;
	}
	
	finp >> cT;
	finp.ignore();
	for(T=1; T<=cT; T++)
	{
		int32_t row1, row2;
		int32_t count;
		int32_t last;
		int32_t arr1[4][4];
		int32_t arr2[4][4];	
		row1 = 0;
		row2 = 0;	
		memset(arr1, 0, sizeof(arr1));
		memset(arr2, 0, sizeof(arr2));
		
		finp >> row1;
		for(i=0; i<4; i++)
			for(j=0; j<4; j++)
				finp >> arr1[i][j];
		finp >> row2;
		for(i=0; i<4; i++)
			for(j=0; j<4; j++)
				finp >> arr2[i][j];
				
		row1--;
		row2--;
		count = 0;
		last = 0;
		for(i=0; i<4; i++)
			for(j=0; j<4; j++)
			{
				if(arr1[row1][i] == arr2[row2][j])
				{
					last = arr1[row1][i];
					count++;
				}
			}
			
		fout << "Case #" << T << ": ";
		if(count==0)
		{
			fout << text0cards;
		} else 
		if(count>=2)
		{
			fout << text2cards;
		} else
		{
			fout << last;
		}
		
		fout << std::endl;
	}
	
	finp.close();
	fout.close();
	std::cout << "done" << std::endl;
	return 0;
}
