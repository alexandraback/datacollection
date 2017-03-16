//#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <string>
using namespace std;

const int D = 4;
int first[D][D];
int second[D][D];
int first_row, second_row;

const int bad = -1;
const int cheat = -2;

int solve(void)
{
	int count = 0;
	int ans;
	for (int i = 0; i < D; i++)
	{
		for (int j = 0; j < D; j++)
		{
			if (first[first_row][i] == second[second_row][j])
			{
				ans = first[first_row][i];
				count++;
				break;
			}
		}
	}

	if (count == 0) return cheat;
	else if (count > 1) return bad;
	else return ans;
}

const string str_bad = "Bad magician!";
const string str_cheat = "Volunteer cheated!";

void solve_A(void)
{
	ifstream in("input.txt");
	//ifstream in("A-small-attempt0.in");
	ofstream out("output.txt");

	int T;
	in >> T;

	for (int t = 1; t <= T; t++)
	{
		in >> first_row;
		for (int i = 0; i < D; i++)
		{
			for (int j = 0; j < D; j++)
			{
				in >> first[i][j];
			}
		}

		in >> second_row;
		for (int i = 0; i < D; i++)
		{
			for (int j = 0; j < D; j++)
			{
				in >> second[i][j];
			}
		}

		first_row--;
		second_row--;

		int temp = solve();
		out << "Case #" << t << ": ";
		if (temp>0) out << temp;
		else if (temp == bad) out << str_bad;
		else out << str_cheat;

		out << '\n';
	}

	in.close();
	out.close();
}

int main()
{
	solve_A();
	return 0;
}