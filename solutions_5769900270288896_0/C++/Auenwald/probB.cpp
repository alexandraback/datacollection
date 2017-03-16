#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <math.h>

using namespace std;

#define INTMAX 0x7FFFFFFF
#define LONGMAX 0x7FFFFFFFFFFFFFFF

int main(){
	int T;
	cin>>T;
	for(int i=1; i<=T; i++){
		int R,C,N;
		cin>>R>>C>>N;
		int m = INTMAX;
		for(int mask=0; mask<(1<<(R*C)); mask++){
			int n=0;
			for(int l=0; l<(R*C); l++){
				if(mask&(1<<l))
					n++;
			}
			if(N!=n)
				continue;
			int count=0;
			for(int j=0; j<C; j++){
				for(int k=0; k<R-1; k++){
					int h=C*j+k;
					if((mask&(1<<h))&&(mask&(1<<(h+1))))
						count++;
				}
			}
			for(int k=0; k<R; k++){
				for(int j=0; j<C-1; j++){
					int h=C*j+k;
					if((mask&(1<<h))&&(mask&(1<<(h+C))))
						count++;
				}
			}
			m = min(m,count);
		}
		cout<<"Case #"<<i<<": "<<m;
		if(i!=T)
			cout<<"\n";
	}
}