// ConsoleApplication2.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#pragma warning(disable:4996)

#include <vector>
#include <iostream>
#include <fstream>


#include<stdio.h>
#include<string.h>
#include<algorithm>


using namespace std;

#define MIN(a,b) ( (a)<(b) ? (a) : (b) )
#define MAX(a,b) ( (a)>(b) ? (a) : (b) )

//========================
// Main function
int main() {

	freopen("pbA/A-large.in", "r", stdin);
	freopen("pbA/A-large.out", "w", stdout);

	//freopen("pbA/testA.in", "r", stdin);



	int T=0, N=0;
	//int *mushrooms;

	scanf("%d", &T);

	for (int t = 0; t < T; t++){
		
		
		scanf("%d", &N);
		
		int *mushrooms = new int[N];
		

		for (int n=0; n<N; n++)
			scanf("%d", &mushrooms[n]);

		int res1=0, res2=0;

		int speed2=mushrooms[0];

		int maxx=0;

		if (N==2) {
			res1 = mushrooms[0]-mushrooms[1]; 
			res2 = mushrooms[0]-mushrooms[1];
		} else {
			for (int i=0; i<N-1; i++) {
				res1 += MAX(mushrooms[i]-mushrooms[i+1], 0);

				if ( mushrooms[i]-mushrooms[i+1] > maxx)
					maxx = mushrooms[i]-mushrooms[i+1];
			}

			for (int i=0; i<N-1; i++) {
				res2 += MIN(mushrooms[i],maxx);
			}
		}
		//res2 += mushrooms[N-1];
		//res1 += MAX(mushrooms[N-2]-mushrooms[N-1], 0);

		printf("Case #%d: %d %d\n", t+1, res1, res2);
		

		delete[] mushrooms;
	}
	


	return 0;
}