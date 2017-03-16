#include <iostream>
#include <fstream>
using namespace std;

int T;
int R, C;
int N;

int DP[17][17][66000];

int countOnes(int bitmask) {
	int res = 0;
	while(bitmask) {
		if (bitmask%2)
			res++;
		bitmask/=2;
	}
	return res;
}

int countAdj(int newbitmask) {
	int res = 0;

	int prev = newbitmask%2;
	newbitmask/=2;
	while (newbitmask) {
		int curr = newbitmask%2;
		if (prev && curr)
			res++;
		prev = curr;
		newbitmask/=2;
	}
	return res;
}

int countUpAdj(int bitmask, int newbitmask) {
	int res= 0;

	while (bitmask || newbitmask) 
	{
		if (bitmask%2 && newbitmask%2)
			res++;
		bitmask/=2;
		newbitmask/=2;
	}
	return res;
}

int happy(int i, int n, int bitmask)
{
	if (n==0)
		return 0;
	if (n<0)
		return 1e9;
	if (i==R)
		return 1e9;

	if (DP[i][n][bitmask]>-1) {
		return DP[i][n][bitmask];
	}

	int bestSub = 1e9;

	for (int newbitmask = 0; newbitmask < (1<<C); newbitmask++) {

		int numAdded = countOnes(newbitmask);
		if (numAdded <=n) {
			int unhappniessAdded = countAdj(newbitmask) + countUpAdj(bitmask, newbitmask);

			int val = happy(i+1, n-numAdded, newbitmask) + unhappniessAdded;
			bestSub = min(bestSub, val);
		}
	}

	DP[i][n][bitmask] = bestSub;
	return bestSub;
}

int main () 
{
	ifstream cin;
	cin.open("B-small-attempt0.in");

	ofstream cout;
	cout.open("Noisy_Sevag_Small.out");


	cin>>T;

	for (int t=1; t<=T; t++ ) 
	{
		cin>>R>>C>>N;
		
		fill(&DP[0][0][0], &DP[0][0][0]+17*17*66000, -1);
		int ans = happy(0,N, 0);


		cout<<"Case #"<<t<<": "<<ans <<endl;
	}

	return 0;
}