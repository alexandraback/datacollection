#include<cstdio>
#include<cmath>
#include<iostream>
#include<string>

using namespace std;

#define MAXD 1024

int m[MAXD];

int main(){
	int T;
	cin >> T;
	for(int k=0; k<T; k++){
		int N;
		cin >> N;
		
		int y=0, slope=0;
		for(int i=0; i<N; i++){
			cin >> m[i];
			if(i){
				slope=max(slope, m[i-1]-m[i]);
				y+=max(m[i-1]-m[i],0);
			}
		}
		
		int z=0;
		for(int i=0; i<N-1; i++)
			z+=min(m[i],slope);

		cout << "Case #" << (k+1) << ": " << y << " " << z << "\n";
	}
}
