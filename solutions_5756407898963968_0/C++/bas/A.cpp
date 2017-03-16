#include<iostream>
#include<vector>
#include<string>

using namespace std;
	int C, A1, A2;
         vector<int> v;
int main(){
	vector<vector<int> > a,b;
	a=vector<vector<int> >(4, vector<int>(4,0));
	b=vector<vector<int> >(4, vector<int>(4,0));
	
	cin>>C; 
	for(int j=0; j<C; j++){
		cin>>A1;
		for(int i=0; i<4; i++)
			for(int j=0; j<4; j++)
			    {cin>>a[i][j];}
		cin>>A2;
		for(int i=0; i<4; i++)
			for(int j=0; j<4; j++)
			    {cin>>b[i][j];}
		vector<int> m = vector<int>(17,0);
		for(int i=0; i<4; i++) m[a[A1-1][i]]=1;
		int num=0; int res=-1;
		for(int i=0; i<4; i++) if (m[b[A2-1][i]]==1){
//		    cout<<b[A2-1][i]<<" ";
		    num++; res = b[A2-1][i];
		}
		cout<<"Case #"<<j+1<<": " ;
//	cout<<A1<<" "<<A2<<" "<<num;
		switch(num){
		    case 0:
			cout<< "Volunteer cheated!\n";
		    break;
		    case 1:
			cout<<res<<"\n";
		    break;
		    default:
			cout<<"Bad magician!\n";
			    break;
		}
	}
	
}
