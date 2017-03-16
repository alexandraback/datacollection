#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<map>

using namespace std;
int M[1001];
int A[1001];
int main(){
	int kases; cin>>kases;
	for(int kase = 1; kase <= kases; kase++){
		int ry = 0, rz = 0;
		int N, T = 0; cin>>N; 
		int maxi = 0;
		for(int i=0;i<N;i++){
			cin>>M[i]; T += M[i];
			if(i == 0) A[i] = M[i];
			else A[i] = A[i-1] + M[i];
			//maxi = max(maxi, M[i]);
		}
		for(int i=1;i<N;i++){
			if(M[i] < M[i-1]){
				ry += (M[i-1]-M[i]);
				maxi = max(maxi, M[i-1]-M[i]);
			}
		} //cout<<maxi<<endl;
		/*for(int rate = 0;rate <= maxi; rate++){
			int st = M[0]; rz = 0;
			bool ok = true;
			for(int j=1;j<N;j++){
				if(rate*10 > st){  rz+=st; st = 0;}
				else{ st -= rate*10; rz+=rate*10;}
				cout<<"Rate: "<<rate<<" st: "<<st<<" rz: "<<rz<<" M[j]: "<<M[j]<<endl;
				if(st > M[j]){ok=false; break;}
				st = M[j];
			}
			if(ok)break;
		}*/
		int st = 0; rz = 0;
		for(int i=0;i+1<N;i++){
			st = M[i];
			if(maxi > st){ rz += st; st = 0;}
			else{ st -= maxi; rz+=maxi;}
			//st += M[i];
		}
		cout<<"Case #"<<kase<<": "<<ry<<" "<<rz<<endl;	
	}
}
