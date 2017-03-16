#include<cstdio>
#include<cmath>
#include<iostream>
#include<string>

using namespace std;

#define MAXN 3024

long long X[MAXN], Y[MAXN];
int n[MAXN];

int main(){
	int T;
	cin >> T;
	for(int k=0; k<T; k++){
		int N;
		cin >> N;
		
		for(int i=0; i<N; i++){
			cin >> X[i] >> Y[i]; 
			n[i]=N;
		}

		for(int i=0; i<N; i++){
			for(int j=i+1; j<N; j++){
				long long u = Y[i]-Y[j];
				long long v = X[j]-X[i];

				int a = 0, b = 0;
				for(int l=0; l<N; l++){
					if( u * X[l] + v * Y[l] > u * X[i] + v* Y[i] )
						a++;
					if( u * X[l] + v * Y[l] < u * X[i] + v* Y[i] )
						b++;
				}

				n[i] = min(n[i], min(a,b));
				n[j] = min(n[j], min(a,b));
			}
		}

		if(N==1)
			n[0]=0;

		cout << "Case #" << (k+1) << ":\n";
		for(int i=0; i<N; i++)
			cout << n[i] << "\n";
	}
}
