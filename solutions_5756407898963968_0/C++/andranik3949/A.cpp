#include <fstream>
#include <vector>
using namespace std;

vector <int> check( 4, 0 );

int checkFor( const int& num )
{
	for ( int i = 0; i < 4; i++ )
		if ( check[i] == num )
			return num;
	return -1;
}

int main()
{
	ifstream cin("A-small-attempt0.in");
	ofstream cout("A-small-attempt0.out");
	int num;
	cin >> num;
	for ( int i = 0; i < num; i++ )
	{
		int row, curr, answer = -1;
		cin >> row;
		for ( int j = 0; j < 16; j++ )
		{
			cin >> curr;
			if ( j / 4 == row - 1 )
				check[j % 4] = curr;
		}
		cin >> row;
		for ( int j = 0; j < 16; j++ )
		{
			cin >> curr;
			if ( j / 4 == row - 1 && answer != -2 )
			{
				if ( answer == -1 )
					answer = checkFor(curr);
				else
					if ( checkFor( curr ) != -1 )
						answer = -2;
			}
		}
		cout << "Case #" << i + 1 << ": ";
		switch ( answer )
		{
			case -2:
				cout << "Bad Magician!";
				break;
			case -1:
				cout << "Volunteer cheated!";
				break;
			default:
				cout << answer;
		}
		cout << endl;
	}
	return 0;
}