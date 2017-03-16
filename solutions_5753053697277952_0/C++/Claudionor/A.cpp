#include <bits/stdc++.h>

using namespace std;

vector<int> sen;

bool bizu(const int a, const int b){
	return sen[a]>sen[b];
}

int main(){
	int t;
	int n;
	vector<int> index;
	int sum;
	int cont=1;
	cin>>t;
	while(t--){
		cout<<"Case #"<<cont<<":";
		cont++;
		cin>>n;
		sum=0;
		sen=vector<int>(n);
		index=vector<int>(n);
		for(int i=0;i<n;i++){
			cin>>sen[i];
			index[i]=i;
			sum+=sen[i];
		}
		while(sum>0){
			sort(index.begin(), index.end(),bizu);
			if(sen.size()==2){
				for(int i=0;i<sum/2;i++)
					cout<<" AB";
				sum=0;
			}
			else{
				if(sen[index[1]]>sum/2-1){
					if(sen[index[2]]>sum/2-1 || sen[index[0]]-1>sum/2-1|| sen[index[1]]-1>sum/2-1|| sum==1){
						cout<<" "<<(char)('A'+index[0]);
						sen[index[0]]--;
						sum--;

					}
					else{
						cout<<" "<<(char)('A'+index[0])<<(char)('A'+index[1]);
						sen[index[0]]--;
						sen[index[1]]--;
						sum-=2;
					}
				}
				else{
					cout<<" "<<(char)('A'+index[0])<<(char)('A'+index[0]);
					sen[index[0]]-=2;
					sum-=2;
				}
			}
		}
		cout<<"\n";
	}
	return 0;
}