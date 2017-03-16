#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool arr[20][20];

int cost(int r, int c, int R, int C){
	int s=0;
	if(r<R-1)if(arr[r+1][c])s+=1;
	if(r>0)if(arr[r-1][c])s+=1;
	if(c<C-1)if(arr[r][c+1])s+=1;
	if(c>0)if(arr[r][c-1])s+=1;
	return s;
}


int val(int r, int c){
	int s=0;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(arr[i][j])s+=cost(i,j,r,c);
		}
	}
	return s/2;
}

int main(){
	int T;
	cin>>T;
	for(int tc=1; tc<=T; tc++){
		int r,c,n;
		cin>>r>>c>>n;
		vector<bool> a(r*c);
		int min = 9999;
		int counter=0;
		for(int i=r*c-1; i>=0; i--){
			if(counter<n){
				a[i]=true;
				counter++;
			}
			else a[i]=false;
		}
		do{
			for(int i=0; i<r; i++)
				for(int j=0; j<c; j++)
					arr[i][j] = a[i*c+j];
			int p = val(r,c);
			if(p<min)min=p;
		}while(next_permutation(a.begin(),a.end()));
		cout<<"Case #"<<tc<<": "<<min<<endl;
	}
	return 0;
}

