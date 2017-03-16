#include<cstdio>
#include<cmath>
#include<iostream>
#include<string>

using namespace std;

#define MAXB 1024

int M[MAXB];

int main(){
	int T;
	cin >> T;
	for(int k=0; k<T; k++){
		int B,N;
		cin >> B >> N;
		
		for(int i=0; i<B; i++)
			cin >> M[i];

		int y;
		for(int i=0; i<B; i++){
			int lo = 0, hi=N, mid;
			long long num, t;
			while(lo <= hi){
				mid = lo+(hi-lo)/2;
				t = (long long)(mid) * (long long)(M[i]);
				num=0;
				for(int j=0; j<=i; j++)
					num+=t/M[j]+1;
				for(int j=i+1; j<B; j++)
					num+=(t+(long long)(M[j])-1)/M[j];

				if(num==N)
					break;
				else if(num<N)
					lo = mid+1;
				else
					hi = mid-1;
			}
			y=-1;
			if(num==N){
				y=i+1;
				break;
			}
		}

		cout << "Case #" << (k+1) << ": " << y << "\n";
	}
}
