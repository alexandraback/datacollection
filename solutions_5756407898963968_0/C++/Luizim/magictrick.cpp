#include <iostream>
#include <set>

using namespace std;
int main ()
{
	int t;
	cin>>t;

	for(int i=0;i<t;i++){
		int n, resp =0, respid;
		cin>>n;

		set<int> myset;

		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){

				int aux;
				cin>>aux;

				if(j+1==n){
					myset.insert(aux);
				}
			}
		}

		cin>>n;

		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				int aux;
				cin>>aux;

				if(j+1==n){
					if(myset.count(aux)!=0){
						resp++;
						respid=aux;
					}
				}
			}
		}

		cout<<"Case #"<<i+1<<": ";
		if(resp==0){
			cout<<"Volunteer cheated!";
		}else if(resp==1){
			cout<<respid;
		}else{
			cout<<"Bad magician!";

		}
		cout<<endl;
	}

return 0;
}