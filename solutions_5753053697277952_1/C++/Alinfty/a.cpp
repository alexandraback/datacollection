#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		int a[26]={0,};
		int N;
		int P=0;
		cin>>N;
		for(int n=0;n<N;n++){
			cin>>a[n];
			P+=a[n];
		}
		int temp[3];
		int i;
		cout<<"Case #"<<t<<":";
		while(P>0){
			i=0;
			for(int n=0;n<N;n++){
				if(a[n]==P/2){
					temp[i]=n;
					i++;
				}
			}
			if(i==3||i==1){
				a[temp[0]]--;
				P--;
				cout<<" "<<(char)(temp[0]+'A');
			}
			else if(i==2){
				a[temp[1]]--;
				a[temp[0]]--;
				P-=2;
				cout<<" "<<(char)(temp[0]+'A')<<(char)(temp[1]+'A');
			}
			else{
				int n;
				for(n=0;n<N;n++){
					if(a[n]>0) break;
				}
				a[n]--;
				cout<<" "<<(char)(n+'A');
				P--;
			}
		}
		cout<<endl;
	}
	return 0;
}
