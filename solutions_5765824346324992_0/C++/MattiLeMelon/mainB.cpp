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

typedef struct barber{
	int index;
	int time;
} Barber;

bool operator<(const Barber& b1, const Barber& b2) {
		if (b1.time < b2.time)
			return true;
		if (b1.time == b2.time)
			return b1.index<b2.index;
		return false;
	}


void quicksort(Barber *BA, int left, int right) {
	int i = left, j = right;
    Barber tmp;
	
	Barber pivot = BA[(left+right)/2];
	
	// Put elements smaller than pivot on the left and those larger on the right
	while (i <= j) {
		// Find the left-most value that is larger than pivot
		while (BA[i] < pivot)
			i++;
		// Find the right-most value that is smaller than pivot
		while (pivot < BA[j])
			j--;

		// Swap arr[i] and arr[j]
		if (i <= j) {
			// Swap in BA
			tmp = BA[i];
			BA[i] = BA[j];
			BA[j] = tmp;

			i++;
			j--;
		} else
			break;
	}
 

	if (left < j)
		quicksort(BA, left, j);
	if (i < right)
		quicksort(BA, i, right);
}

//========================
// Main function
int main() {

	freopen("pbB/B-small-attempt2.in", "r", stdin);
	freopen("pbB/B-small-attempt2.out", "w", stdout);

	//freopen("pbB/testB.in", "r", stdin);



	int T=0, B=0, N=0;
	

	scanf("%d", &T);

	for (int t = 0; t < T; t++){
		
		
		scanf("%d %d", &B, &N);
		
		int *M = new int[B];
		

		for (int b=0; b<B; b++)
			scanf("%d", &M[b]);

		int res=0;
		int time=0;
		int *busy = new int[B];

		int n=0;
		bool found=false;

		// Remove the period and find the nb of customers per period
		int multi = 1;
		for (int b=0; b<B; b++) {
			multi *= M[b];
		}
		int customer_loop = 0;
		for (int b=0; b<B; b++) {
			customer_loop += multi/M[b];
		}

		// Remove the multi
		while (N>customer_loop) {
			N -= customer_loop;
		}

		if (N<=B) {
			res = N;		
		} else {
			for (int b=0; b<B; b++) {
				busy[b] = M[b];
				n++;
			}

			while(1) {
				// Find the min value
				int minn=200000000;
				for (int i=0; i<B; i++) {
					if (busy[i]<minn)
						minn=busy[i];
				}

				// Remove the min from the barbers time to get to the next customer
				for (int i=0; i<B; i++) {
					busy[i] -= minn;
					if (busy[i] == 0) {
						if (++n>=N) {
							res = i+1;
							found = true;
							break;
						}
						busy[i] = M[i];
					}
				}

				if (found)
					break;
			}
		}

		delete[] busy;
		/*int minn=200000000;
		for (int b=0; b<B; b++) {
			if (M[b]<minn)
				minn=M[b];
		}

		if (N<B)
			res = N;
		else {
			vector <Barber> times;
			Barber ba;
			for (int n=0; n<=N; n++) {
				for (int b=0; b<B; b++) {
					ba.index = b+1;
					ba.time = M[b]*n;
					if (ba.time<=minn*N)
						times.push_back(ba);
				}
			}
			sort(times.begin()+B, times.end());
			res = times.at(N-1).index;
		}*/


		printf("Case #%d: %d\n", t+1, res);
		

		delete[] M;
	}
	


	return 0;
}