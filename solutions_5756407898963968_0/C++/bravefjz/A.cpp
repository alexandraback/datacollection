#include <fstream>
using namespace std;

ifstream fin;
ofstream fout;
int T;
int row_one, row_two;
int board_one[4][4];
int board_two[4][4];
int y;

void readonce(int &row, int board[4][4])
{
	fin >> row;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			fin >> board[i][j];
}

void solve()
{
	int count[16] = {0};
	for (int i = 0; i < 4; i++)
	{
		count[board_one[row_one-1][i]-1]++;
		count[board_two[row_two-1][i]-1]++;
	}
	int repeated = 0;
	int repeated_val = 0;
	for(int i = 0; i < 16; i++)
		if(count[i] == 2)
		{
			repeated++;
			repeated_val = i+1;
		}
	if (repeated == 1)
		y = repeated_val;
	else if(repeated == 0)
		y = -1;
	else
		y = 0;
}
void main()
{

	fin.open("in.txt");
	fout.open("out.txt");
	fin >> T;
	for(int i = 0; i < T; i++)
	{
		readonce(row_one,board_one);
		readonce(row_two,board_two);
		solve();
		if(y > 0)
			fout << "Case #" << i+1 << ": "<< y << endl;
		else if(y == 0)
			fout << "Case #" << i+1 << ": Bad magician!"<< endl;
		else
			fout << "Case #" << i+1 << ": Volunteer cheated!"<< endl;
	}
	fin.close();
	fout.close();
}