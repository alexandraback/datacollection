#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <cstdio>
using namespace std;
	
int tablero[17][17];
void llenoTablero (int r, int c, int bitmask) {
	for (int a = 0; a < r; a++) {
		for (int b = 0; b < c; b++) {
			tablero[a][b] = bitmask%2;
			bitmask /= 2; 
		}
	}
}

int puntaje (int r, int c) {
	int ret = 0;
	for (int a = 0; a < r; a++) {
		for (int b = 0; b < c; b++) {
			if (a+1 < r && tablero[a][b] + tablero[a+1][b] == 2) {
				ret++;
			}
			if (b+1 < c && tablero[a][b] + tablero[a][b+1] == 2) {
				ret++;
			}
		}
	}
	return ret;
}

int main () {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	
	int t, r, c, n;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> r >> c >> n;
		
		int minActual = 25;
		for (int i = 0; i < (1 << (r*c)); i++) {
			//cout << i << " " << __builtin_popcount(i) << endl;
			if (__builtin_popcount(i) == n) {
				llenoTablero(r, c, i);
				/*
				for (int a = 0; a < r; a++) {
					for (int b = 0; b < c; b++) {
						cout << tablero[a][b] << " ";
					}
					cout << endl;
				}
				cout << endl;
				*/
				minActual = min(puntaje(r, c), minActual);
			} 
		}
		cout << "Case #" << tc << ": " << minActual << endl;
	}
	return 0;
}
