#include <iostream>
#include <fstream>
using namespace std;

const int K = 120;

int x[K][K];
int tt[K];

int main()
{
	ifstream in("t.in");
	ofstream out("t.out");

	int q;          
	in >> q;
	for (int i = 1; i <= q; i++)
	{
		memset(tt, 0, sizeof(tt));                                 
	    int pos;
	    in >> pos;
	    for (int a = 0; a < 4; a++)
	    	for (int b = 0; b < 4; b++)
	    		in >> x[a][b];
		for (int a = 0; a < 4; a++)
			for (int b = 0; b < 4; b++)
				if (a == pos - 1)
					tt[x[a][b]]++;
		in >> pos;
	    for (int a = 0; a < 4; a++)
	    	for (int b = 0; b < 4; b++)
	    		in >> x[a][b];
		for (int a = 0; a < 4; a++)
			for (int b = 0; b < 4; b++)
				if (a == pos - 1)
					tt[x[a][b]]++;
		int var = 0;
		int magic = 0;
		for (int j = 1; j <= 16; j++)
		{
			if (tt[j] == 2)
			{
				var++;
				magic = j;
			}
		}

		if (var == 0)
			out << "Case #" << i << ": Volunteer cheated!\n";
		else if (var == 1)
			out << "Case #" << i << ": " << magic << endl;
		else
			out << "Case #" << i << ": Bad magician!\n"; 
	}

	return 0;
}