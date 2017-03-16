#include<iostream>
#include<stdio.h>
using namespace std;

int R,C,N;

int comp(int i){
	int ans = 0;
	for (int r = 0; r < R; r++){
		for (int c = 0; c < C; c++){
			if (c > 0 && (i & (1 << (r * C + c))) && (i & (1 << (r * C + c - 1))))
				ans++;
			if (r > 0 && (i & (1 << (r * C + c))) && (i & (1 << (r * C + c - C))))
				ans++;
		}
    }
	return ans;
}

int main(){

    freopen("input.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, ap[1 << 18];
	cin>>t;
	for (int tt=1;tt<=t;tt++){

		cin >>R>>C>>N;
		int b = R*C*N*100;
		for (int i=1;i<(1<<(R*C));++i){
			ap[i] = ap[i-(i&-i)]+1;
			if (ap[i]==N)
                b = min(b, comp(i));
		}
		cout<<"Case #"<<tt<<": "<<b<<endl;

	}

}
