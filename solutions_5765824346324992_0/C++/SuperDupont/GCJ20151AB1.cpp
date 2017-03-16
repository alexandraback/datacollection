// GCJ20151AB1.cpp : définit le point d'entrée pour l'application console.
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
		int Res;
		bool possible;

		// Spécifique
		long long pl, nb, dt, tps, ptr, nplmax, n, ndt;
		vector <long long> mk, tpsk;

		// Début d'analyse
		// Init
		Res = 0;

		// Extraction
		// 
		*FicIn >> nb;
		*FicIn >> pl;

		for (i = 0; i < nb; i++)
		{
			*FicIn >> tmp;
			mk.push_back((long long)tmp);
		}

		//Exec
		if (pl <= nb) Res = pl;
		else
		{
			// Recherche du temps par dichotomie
			tps = 100000000000000;
			dt = tps / 2;
			while (dt > 5)
			{
				ptr = 0;
				for (i = 0; i < nb; i++) ptr += tps / mk[i]+1;
				if (ptr>=pl)tps -= dt;
				if (ptr < pl)tps += dt;
				dt /= 2;
			}
			for (;; tps--)
			{
				ptr = 0;
				for (i = 0; i < nb; i++) ptr += tps / mk[i] + 1;
				if (ptr < pl) break;
			}

			for (;; tps++)
			{
				ptr = 0;
				for (i = 0; i < nb; i++) ptr += tps / mk[i] + 1;
				if (ptr >= pl) break;
			}
			for (i = 0; i < nb; i++) if (tps%mk[i] == 0)break;
			Res =i+1;
		}



		// Formatage de la sortie

		// Sortie
		sprintf(LOut, "Case #%d: %d\n", Nt, Res);
		printf("%s", LOut);
		*FicOut << LOut;
	}

	void Perform()
	{
		// Ouverture des fichiers
		FicIn = new fstream("B-small-attempt0.in", fstream::in);
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

	printf("GCJ20151AB1\n");
	P.Perform();

	return 0;
}