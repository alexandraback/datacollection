#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

const int MAX_CHAINES = 100;
const int MAX_TAILLE = 102;
const int IMPOSSIBLE = -1;

int nbTests;
int nbChaines;
string chaines[MAX_CHAINES];
int curPos[MAX_CHAINES];
char curChaine[MAX_TAILLE];

void computeAnswer()
{
	for(int iTest = 1; iTest <= nbTests; ++iTest)
	{
		scanf("%d", &nbChaines);
		for(int iChaine = 0; iChaine < nbChaines; ++iChaine)
		{
			scanf(" %s", curChaine);
			chaines[iChaine] = curChaine;
			curPos[iChaine] = 0;
		}
		int nbModif = 0;
		char prevCar = '#';
		bool continuer = true;
		while(continuer)
		{
			int extra;
			/*for(int iChaine = 0; iChaine < nbChaines; ++iChaine)
				printf("%d ", curPos[iChaine]);
			printf("\n%c\n", prevCar);*/
			do
			{
				extra = 0;
				for(int iChaine = 0; iChaine < nbChaines; ++iChaine)
				{
					//printf(" %d", curPos[iChaine]);
					if(chaines[iChaine][curPos[iChaine]] == prevCar && prevCar != ' ')
						++extra;
				}
				//printf("\n");
				if(extra < nbChaines)
				{
					if(extra <= nbChaines/2)
					{
						//printf("COIN\n");
						for(int iChaine = 0; iChaine < nbChaines; ++iChaine)
							if(chaines[iChaine][curPos[iChaine]] == prevCar)
							{
								++curPos[iChaine];
								++nbModif;
							}
					}
					else
					{
						for(int iChaine = 0; iChaine < nbChaines; ++iChaine)
							if(curPos[iChaine] >= (int)chaines[iChaine].size() || chaines[iChaine][curPos[iChaine]] != prevCar)
							{
								--curPos[iChaine];
								++nbModif;
							}
					}
				}
			} while(extra < nbChaines && extra);
			bool identique = true;
			for(int iChaine = 1; iChaine < nbChaines; ++iChaine)
				if(chaines[iChaine][curPos[iChaine]] != chaines[0][curPos[0]])
					identique = false;
			//printf("  %d\n", (int)identique);
			prevCar = chaines[0][curPos[0]];
			for(int iChaine = 0; iChaine < nbChaines; ++iChaine)
				++curPos[iChaine];
			if(!identique)
			{
				nbModif = -1;
				goto end;
			}
			/*for(int iChaine = 0; iChaine < nbChaines; ++iChaine)
				printf("%d ", curPos[iChaine]);
			printf("\n%d\n\n", nbModif);*/
			continuer = false;
			for(int iChaine = 0; iChaine < nbChaines; ++iChaine)
				if(curPos[iChaine] < (int)chaines[iChaine].size())
					continuer = true;
		}
		end:
		printf("Case #%d: ", iTest);
		if(nbModif != IMPOSSIBLE)
			printf("%d", nbModif);
		else
			printf("Fegla Won");
		printf("\n");
	}
}

void displayAnswer()
{

}

void readInput()
{
	/*
	freopen("test.in", "r", stdin);
	/*/
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	//*/
	scanf("%d", &nbTests);
}

int main()
{
	readInput();
	computeAnswer();
	displayAnswer();
	return 0;
}
