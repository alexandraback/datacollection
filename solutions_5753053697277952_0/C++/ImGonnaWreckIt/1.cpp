#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(){
	int i,j,k,l;
	int N, T;
	cin>>T;
	int *P;
	for(l = 0 ; l < T ; l++)
	{
		cin>>N;
		P = new int[N];
		for(i = 0 ; i < N ; i++)
			cin>>P[i];
		cout<<"Case #"<<l+1<<": ";
		int total = 0;
		for(i = 0 ; i < N; i++)
			total = total + P[i];
		int maxA = 0;
		int maxB = 1;
		while(true)
		{
			if(total == 0)
				break;
			maxA = 0;
			maxB = 1;
			if(P[1] > P[0]	)
			{
				maxA = 1;
				maxB = 0;
			}
			for(i = 2 ; i < N ; i++){
				if(P[i] == 0)
					continue;
				if(P[i] >= P[maxA])
				{
						maxB = maxA;
						maxA = i;
				}
				else if(P[i] >= P[maxB] && P[i] < P[maxA]){
					maxB = i;
				}
			}
			if(P[maxA] > 0){
				cout<<(char)('A' + maxA);
				P[maxA]--;
				total--;
			}
			if(P[maxB] > total/2 && P[maxB] > 0)
			{
				cout<<(char)('A' + maxB);
				total--;
				P[maxB]--;
			}
			cout<<" ";		
		}
		cout<<"\n";
		delete[] P;
	}
}
