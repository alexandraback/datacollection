#include<iostream>
#include<fstream>

using namespace std;

int main(){
	ofstream fout;
	fout.open("d:\\ans.txt");
	cout.rdbuf(fout.rdbuf());

	ifstream fin;
	fin.open("d:\\1.in");
	cin.rdbuf(fin.rdbuf());
	int t,a[4][4],b[4][4];
	int r1,r2;
	int i,j,k;
	cin>>t;
	for(i=1;i<=t;i++){
		cin>>r1;
		r1--;
		for(j=0;j<4;j++)
			for(k=0;k<4;k++)
				cin>>a[j][k];
		cin>>r2;
		r2--;
		for(j=0;j<4;j++)
			for(k=0;k<4;k++)
				cin>>b[j][k];
		int ans=-1;
		int num=0;
		for(j=0;j<4;j++){
			for(k=0;k<4;k++){
				if(a[r1][j]==b[r2][k]){
					ans=a[r1][j];
					num++;
				}
			}
		}
		cout<<"Case #"<<i<<": ";
		if(num==0)
			cout<<"Volunteer cheated!";
		else if(num==1)
			cout<<ans;
		else 
			cout<<"Bad magician!";
		cout<<endl;

		
	}
	return 0;
}