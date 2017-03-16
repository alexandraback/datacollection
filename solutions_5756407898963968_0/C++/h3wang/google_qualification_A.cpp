#include <iostream>
#include <vector>
using namespace std;
#define DEBUG
#include <fstream>
#ifdef DEBUG
ifstream fin("A.in");
ofstream fout("A.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
int a[4][4],T,tmp,a1,a2;
int aa[4],bb[4];
vector<int> rv;
int main(){
	redirect();
	cin>>T;
	for(int i=0;i<T;i++){
		cout<<"Case #"<<i+1<<": ";
		rv.clear();
		cin>>a1;
		for(int j=0;j<4;j++)
			for(int k=0;k<4;k++)
				cin>>a[j][k];
		for(int j=0;j<4;j++)
			aa[j]=a[a1-1][j];
		cin>>a2;
		for(int j=0;j<4;j++)
			for(int k=0;k<4;k++)
				cin>>a[j][k];
		for(int j=0;j<4;j++)
			bb[j]=a[a2-1][j];

		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++)
				if(aa[j]==bb[k])
					rv.push_back(aa[j]);
		}
		if(rv.size()==0)
			cout<<"Volunteer cheated!"<<endl;
		else if(rv.size()==1)
			cout<<rv[0]<<endl;
		else
			cout<<"Bad magician!"<<endl;
	}
	return 0;
}