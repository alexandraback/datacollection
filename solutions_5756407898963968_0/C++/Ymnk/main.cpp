#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	fstream output_file;
	output_file.open("output.txt");

	int T;
	cin >> T;
	for(int i=0; i<T;i++)
	{
		int a1;
		int possible_cards[4];
		int answer = 0;

		cin>>a1;
		for(int j=0;j<4;j++)
		{
			if(j == a1-1)
			{
				cin >> possible_cards[0] >> possible_cards[1] >> possible_cards[2] >> possible_cards[3];
			}
			else
			{
				string line;
				cin.ignore();
				getline(cin, line);
			}
		}

		cin>>a1;
		for(int j=0;j<4;j++)
		{
			if(j == a1-1)
			{
				for(int k=0;k<4;k++)
				{
					int val;
					cin>>val;
					
					if(val == possible_cards[0] || val == possible_cards[1] || val == possible_cards[2] || val == possible_cards[3])
					{
						if(answer == 0)
							answer = val;
						else if(answer > 0)
							answer = -1;
					}
				}
			}
			else
			{
				string line;
				cin.ignore();
				getline(cin, line);
			}
		}

		output_file << "Case #" << i+1 << ": ";
		switch(answer)
		{
		case -1:
			output_file << "Bad magician!\n"; break;
		case 0:
			output_file << "Volunteer cheated!\n"; break;
		default:
			output_file << answer << endl; break;
		}

	}

	output_file.close();
	return 0;
}