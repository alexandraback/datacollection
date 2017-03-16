#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

struct Data
{
	char lettre;
	int nb;
};

int trouveMin(vector <int> tab)
{
	int meilleurValeur = 1000*1000;
	
	for (int iTest = 0; iTest <= 100; iTest++)
	{
		int somme = 0;
		for (int iVal = 0; iVal < tab.size(); iVal++)
			somme += abs(tab[iVal]-iTest);
		
		meilleurValeur = min(meilleurValeur, somme);
	}	
	
}

int output ()
{
	string mots[100];
	
	int nbMots;
	cin >> nbMots;
	for (int i = 0; i < nbMots; i++)
		cin >> mots[i];
	
	vector <Data> listeIntervalles[100];
	
	int longueurIntervalle = -1;
	
	for (int i = 0; i < nbMots; i++)
	{
		int curPos = 0;
		while (curPos < mots[i].size())
		{
			int nbOccurences = 0;
			int curChar = mots[i][curPos];
			
			while (curChar == mots[i][curPos])
			{
				nbOccurences++;
				curPos++;
				
				if (curPos == mots[i].size())
					break;
			}
			
			Data toAdd;
			toAdd.nb = nbOccurences;
			toAdd.lettre = curChar;
			listeIntervalles[i].push_back(toAdd);
		}
		
		//printf("%c - %d\n", listeIntervalles[i][1].lettre, listeIntervalles[i][1].nb);
		
		if (longueurIntervalle == -1)
			longueurIntervalle = listeIntervalles[i].size();
		else if (longueurIntervalle != listeIntervalles[i].size())
			return -1;
	}
	
	int somme = 0;
	
	for (int i = 0; i < longueurIntervalle; i++)
	{
		vector <int> tab;
		char curChar = listeIntervalles[0][i].lettre;
		tab.push_back(listeIntervalles[0][i].nb);
		for (int j = 1; j < nbMots; j++)
		{
			if (curChar != listeIntervalles[j][i].lettre)
				return -1;
			
			tab.push_back(listeIntervalles[j][i].nb);
		}
		
		somme += trouveMin(tab);
	}
	
	return somme;

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
