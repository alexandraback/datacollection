#include <stdio.h>
#include <vector>
#include <algorithm>

int main()
{
   FILE * pFile = fopen("A-small-attempt1.in", "r");
	int T;
	fscanf(pFile, "%d", &T);
	for(int t = 0; t < T; t++)
	{
		int row1, row2, temp;
		std::vector<int> arrange1, arrange2, output(4);
		fscanf(pFile, "%d", &row1);
		for(int i = 0; i < 16; i++)
		{
			fscanf(pFile, "%d", &temp);
			if(i >= (row1-1) *4 && i < row1 * 4)
				arrange1.push_back(temp);
		}
		fscanf(pFile, "%d", &row2);
		for(int i = 0; i < 16; i++)
		{
			fscanf(pFile, "%d", &temp);
			if(i >= (row2-1) *4 && i < row2 * 4)
				arrange2.push_back(temp);
		}
		std::sort(arrange1.begin(), arrange1.end());
		std::sort(arrange2.begin(), arrange2.end());
		std::vector<int>::iterator it = std::set_intersection(arrange1.begin(), arrange1.end(), arrange2.begin(), arrange2.end(), output.begin());
		if(it - output.begin() > 1)
			printf("Case #%d: Bad magician!\n", t+1);
		else if(it - output.begin() == 1)
			printf("Case #%d: %d\n", t+1, output[0]);
		else
			printf("Case #%d: Volunteer cheated!\n", t+1);
	}
	return 0;
}