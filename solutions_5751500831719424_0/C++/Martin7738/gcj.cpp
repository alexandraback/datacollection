#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

int output ()
{
//printf("iiin\n");
	string mot1, mot2;
	int nbStrings;
	cin >> nbStrings;
	
	cin >> mot1 >> mot2;
		
	if (mot1[0] != mot2[0])
		return -1;
	
	int pos1 = 0, pos2 = 0;
	
	int somme = 0;
	int decalage1 = 0, decalage2 = 0;
	
	while (pos1 < mot1.size() && pos2 < mot2.size())
	{
		if (mot1[pos1] != mot2[pos2])
		{
			//printf("in");
			return -1;
		}
		
		char curCar = mot1[pos1];
		
		while (pos1 < mot1.size() && mot1[pos1] == curCar)
			pos1++;
		
		while (pos2 < mot2.size() && mot2[pos2] == curCar)
			pos2++;
		//cout << pos1 << " - " << pos2 << "\n";
			
		somme += abs((pos2 - decalage2) - (pos1 - decalage1));
		decalage2 += (pos2 - decalage2) - (pos1 - decalage1);
	}
	//printf("\n");
	if (pos1 == mot1.size() && pos2 == mot2.size())
		return somme;
	else
	{
		//printf("in1");
		return -1;
	}

}

int main ()
{
	int nbCases;
	cin >> nbCases;
	
	for (int i = 1; i <= nbCases; i++)
	{
		int result = output();
		if (result != -1)
			printf("Case #%d: %d\n", i ,result);
		else
			printf("Case #%d: Fegla Won\n", i);
	}
	
	return 0;
}
