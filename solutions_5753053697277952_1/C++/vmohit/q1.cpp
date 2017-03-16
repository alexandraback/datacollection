#include <iostream>
#include <vector>
using namespace std;

#define ll long long
#define vll vector<ll>

int main(){
	int Te;
	char ch;
	cin>>Te;
	for(int te=1;te<=Te;te++){
		int n;
		cin>>n;
		vector<int> P(n);
		int s=0,mx=-1;
		for(int i=0;i<n;i++){
			cin>>P[i];
			s+=P[i];
			mx=max(mx,P[i]);
		}
		cout<<"Case #"<<te<<": ";
		if(n==2){
			if(P[0]>P[1]){
				for(int i=0;i<P[0]-P[1];i++){
					ch='A';
					cout<<ch<<" ";
				}
			}
			else{
				for(int i=0;i<P[1]-P[0];i++){
					ch='B';
					cout<<ch<<" ";
				}	
			}
			for(int i=0;i<min(P[0],P[1]);i++){
				cout<<"AB ";
			}
			cout<<endl;
		}
		else{
			while(mx!=1){
				int id=-1,ma=-1;
				for(int i=0;i<n;i++){
					if(P[i]>ma){
						ma=P[i];
						id=i;
					}
				}
				ch='A'+id;
				cout<<ch<<" ";
				P[id]--;
				id=-1;ma=-1;
				for(int i=0;i<n;i++){
					if(P[i]>ma){
						ma=P[i];
						id=i;
					}
				}
				mx=ma;
			}
			int num=n;
			int i=0;
			while(num!=2){
				ch='A'+i;
				cout<<ch<<" ";
				i++;
				num--;
			}
			ch='A'+i;
			char ch2=ch+1;
			cout<<ch<<ch2<<endl;
		}

	}
	return 0;
}