// GCJ20151AA0.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
// Ci-dessous pour ne plus être gêné par les erreur de compilation
// dûes à scanf, strcpy, etc...
// sans pour autant à chaque fois devoir redéfinir _CRT_SECURE_NO_WARNINGS
// dans la définition du préprocessseur (Projet>Propriétés>Conf>C/C++>Préprocesseur/Définitions)
#pragma warning(disable: 4996) /* Disable deprecation */

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <ctime>
#include <algorithm>
#include <string.h>

using namespace std;

class Perf
{
public:



	void PerformLoop()
	{
		int i, j, k, som, tmp;
		char in[10000];
		char LOut[10000];
		int Res1,Res2;
		bool possible;

		// Spécifique
		vector <int> mi;
		int n,vit;

		// Début d'analyse
		// Init
		Res1 = 0;
		Res2 = 0;

		// Extraction
		// 
		*FicIn >> n;
		for (i = 0; i < n; i++)
		{
			*FicIn >> tmp;
			mi.push_back(tmp);
		}

		//Exec
		// Pourt le 1:
		for (i = 1; i < n; i++)
		{
			if (mi[i] < mi[i - 1]) Res1 += mi[i-1] - mi[i];
		}

		// Pour le 2
		vit = 0;
		for (i = 1; i < n; i++)
		{
			if (mi[i] > mi[i - 1]) continue;
			if ((mi[i - 1] - mi[i]) > vit) vit = mi[i - 1] - mi[i];
		}
		for (i = 1; i < n; i++)
		{
			if (mi[i-1] > vit) Res2+=vit;
			else Res2 += mi[i - 1];
		}





		// Formatage de la sortie

		// Sortie
		sprintf(LOut, "Case #%d: %d %d\n", Nt, Res1,Res2);
		printf("%s", LOut);
		*FicOut << LOut;
	}

	void Perform()
	{
		// Ouverture des fichiers
		FicIn = new fstream("A-small-attempt0.in", fstream::in);
		FicOut = new fstream("Fichier.out", fstream::out);
		if (FicIn->fail()){ printf("Impossible d'ouvrir le fichier d'entree\n"); return; }
		if (FicOut->fail()){ printf("Impossible d'ouvrir le fichier de sortie\n"); return; }

		// Nombre de Tests
		*FicIn >> T;

		for (Nt = 1; Nt <= T; Nt++) PerformLoop();

		// Fermeture des fichiers
		FicIn->close();
		FicOut->close();
	}

	int T, Nt;
	fstream *FicIn;
	fstream *FicOut;


};

int main(int argc, char** argv)
{
	Perf P;

	printf("GCJ20151AA0\n");
	P.Perform();

	return 0;
}