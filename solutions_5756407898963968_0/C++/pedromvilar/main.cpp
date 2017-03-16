#include <fstream>
//This standard library handles files
#include <sstream>
//This standard library handles stringstreams, useful generalisations of strings
using namespace std;

int match(int firstarr[4], int secondarr[4])
{
	/*
	This function is supposed to find the card picked by the volunteer.
	It returns 0 if the magician was a bad one, and -1 if the volunteer cheated.
	*/
	int card = -1;
	for (int i = 0; i < 4 && card != 0; i++)
	{
		for (int j = 0; j < 4 && card != 0; j++)
		{
			if (firstarr[i] == secondarr[j])		// compares each of the elements of the row of the first array with each of the elements of the second
			{
				if (card == -1)						//if no element has been matched yet
					card = firstarr[i];				//matches one element
				else
					card = 0;						//this means the magician was a bad one
			}
		}
	}
	return card;
}

int main()
{
	fstream filein("input.in", fstream::in), fileout("output.out", fstream::out);
	string s;
	int T, i, j, k, firstans, secondans, card;
	int firstarr[4][4], secondarr[4][4];
	filein >> T;									//gets number of cases
	for (i = 0; i < T; i++)
	{
		//loops for each case
		fileout << "Case #" << (i + 1) << ": ";		//starts building output file
		filein >> firstans;								//gets first answer
		for (j = 0; j < 4; j++)						//gets first arrangement
		{
			for (k = 0; k < 4; k++)
				filein >> firstarr[j][k];
		}

		filein >> secondans;								//gets second answer
		for (j = 0; j < 4; j++)							//gets second arrangement
		{
			for (k = 0; k < 4; k++)
				filein >> secondarr[j][k];
		}
		card = match(firstarr[firstans - 1], secondarr[secondans - 1]);	//matches answers with card
		switch (card)
		{
			case -1:
				fileout << "Volunteer cheated!";
				break;
			case 0:
				fileout << "Bad magician!";
				break;
			default:
				fileout << card;
		}
		fileout << endl;
	}
	fileout.close();
	return 0;
}
