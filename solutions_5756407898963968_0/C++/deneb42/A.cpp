#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void readCards(ifstream &in, vector<int> &dest)
{
	int row, discard;

	in >> row;

	for(int j = 1; j < row; ++j)
	{
		in >> discard;
		in >> discard;
		in >> discard;
		in >> discard; // skipping the 4 uninteresting results
	}

	for(int j = 0; j < 4; ++j)
		in >> dest[j];
	// now we have the datas where we want

	for(int j = row+1; j <= 4; ++j)
	{
		in >> discard;
		in >> discard;
		in >> discard;
		in >> discard; // skipping the 4 uninteresting results
	}
}

int main()
{
	string name("A-small-attempt0");
	ifstream in;
	ofstream out;
	int nbCases = 0; // size of the sets loaded

	char bad[] = "Bad magician!";
	char cheat[] = "Volunteer cheated!";
	int card;
	vector<int> cards1, cards2;

	// Variables end -------------------------------------------------------------------------

	in.open((name + ".in").c_str());
	out.open((name + ".out").c_str()); // flux opening

	cards1.resize(4);
	cards2.resize(4);

	if(!(in.is_open() && out.is_open()))
	{
		cerr << "> one of the file could not be loaded" << endl;
	}

	in >> nbCases; // getting case number

	for(int i = 1; i <= nbCases; ++i)
	{
		readCards(in, cards1);
		readCards(in, cards2);
		card = 0;

		for(int j = 0; j < 4; ++j)
		{
			for(int k = 0; k < 4; ++k)
			{
				if(cards1[j] == cards2[k])
				{
					if(card == 0)
						card = cards1[j];
					else
						card = -1;
				}
			}
		}

		if(card == 0)
			out << "Case #" << i << ": " << cheat << endl;
		else if(card == -1)
			out << "Case #" << i << ": " << bad << endl;
		else
			out << "Case #" << i << ": " << card << endl;
	}

    in.close();
    out.close();
    cout << "Appuyez sur ENTER pour continuer" << endl;
    cin.get();
    return 0;
}
