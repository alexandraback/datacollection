#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int CASES;
	int ROW;
	int MATRIX [4][4];
	int STORE [17];
	
	ifstream File ("Case1.txt");
	ofstream out ("Out.txt");
	File >> CASES;
	for (int i = 1; i <= CASES; i++)
	{
		for (int z = 0; z < 17; z++)
		STORE[z] = 0;
		int record = 0;
		for(int a = 0; a < 2; a++)
		{
		File >> ROW; 
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
				File >> MATRIX[j][k];
		}
		ROW--;
		for (int j = 0; j < 4; j++)
		{
			STORE[MATRIX[ROW][j]]++;
		}
		}
		out << "Case #" << i << ": ";
		int doubles = 0;
		for (int j = 1; j < 17; j++)
		{
			if (STORE[j] > 1)
			{
				doubles++;
				record = j;
			}
		}
		if (doubles == 0)
			out << "Volunteer cheated!\n";
		else if (doubles == 1)
			out << record << endl;
		else
			out << "Bad magician!\n";
				
	}

	out.close();
	system("pause");
	return 0;
}