#include <fstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

ifstream input;
ofstream output;

const int delta[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int R, C, N;
bool board[20][20];

int person[20][2];

int ans;

int eval()
{
	int cnt = 0;
	for (int i=0; i<N; i++)
	{
		int x = person[i][0];
		int y = person[i][1];
		for (int d=0; d<4; d++)
		{
			int nx = x + delta[d][0];
			int ny = y + delta[d][1];
			if (board[nx][ny]) cnt++;
		}
	}
	return cnt / 2;
}

bool nextLoc(int & x, int & y)
{
	y++;
	if (y == C + 1)
	{
		x++; y = 1;
		if (x == R + 1)
			return false;
	}
	return true;
}

void gen(int pos)
{
	if (pos==N)
	{
		ans = min(ans, eval());
		return;
	}
	int x = 1, y = 0;
	if (pos > 0)
	{
		x = person[pos-1][0]; y = person[pos-1][1];
	}
	while (nextLoc(x, y))
	{
		board[x][y] = true;
		person[pos][0] = x;
		person[pos][1] = y;
		gen(pos + 1);
		board[x][y] = false;
	}
}

void singleCase(int case_num)
{
	input >> R >> C >> N;
	ans = 10000000;
	gen(0);
	output << "Case #" << case_num << ": " << ans << endl;
}

int main()
{
	input.open("B-small.in");
	output.open("B.out");
	int T;
	input >> T;
	for (int i=0; i<T; i++)
		singleCase(i + 1);

	return 0;
}