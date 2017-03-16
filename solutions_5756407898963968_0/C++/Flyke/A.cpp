#include <iostream.h>
#include <fstream.h>

// Code Jam 2014
// Qualification round
// Problem A. Magic Trick


int main(int argc, char *argv[])
{
	int T;
	int t;
	int i;
	int j;
	int answer;
	
	int cards[16];
	int row;
	
	int possibles[4];
	
	ifstream inFile;
	
	//inFile.open("test.in");
	if ( argc < 2 )
	{
		cout << "No input file given!" << endl;
		exit(1);
	}
	inFile.open(argv[1]);
	if ( !inFile )
	{
		cout << "Error opening file!" << endl;
		exit(1);
	}
	
	inFile >> T;
	
	for (t=0;t<T;t++)
	{
		answer = -1;
		inFile >> row;
		for (i=0;i<16;i++)
		{
			inFile >> cards[i];
		}
		
		for (i=0;i<4;i++)
		{
			possibles[i] = cards[(row-1)*4+i];
			//cout << "possible: " << possibles[i] << endl;
		}
		
		
		inFile >> row;
		for (i=0;i<16;i++)
		{
			inFile >> cards[i];
		}
		for (i=0;i<4;i++)
		{
			for ( j=0;j<4;j++ )
			{
				if ( possibles[i] == cards[(row-1)*4+j] )
				{
					if ( answer > 0 )
					{
						answer = 0;
					}
					else if ( answer < 0 )
					{
						answer = possibles[i];
					}
					// answer == 0
					//cout << "match: " << possibles[i] << endl;
				}
			}
		}
		
		cout << "Case #" << t+1 << ": ";
		switch ( answer )
		{
			case -1:
				cout << "Volunteer cheated!";
				break;
			case 0:
				cout << "Bad magician!";
				break;
			default:
				cout << answer;
				break;
		}
		cout << endl;
		
	}
		
		
	
	inFile.close();
	return 0;
}