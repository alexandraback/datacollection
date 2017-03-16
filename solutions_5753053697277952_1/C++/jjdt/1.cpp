#include <vector>
#include <queue>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream fin("A-large (1).in");
	ofstream fout("testrespuesta.txt");
	long int t;
	fin>>t;
	for(long int j=0; j<t; j++){
		int n;
		fin>>n;
		vector<int> partido;
		vector<int> aevaluar;
		long int mmax;
		fin>>mmax;
		partido.push_back(mmax);
		for(int i=1; i<n;i++){
			long int m;
			fin>>m;
			partido.push_back(m);
			if(m>mmax){
				mmax=m;
			}
		}
		for(int i=0; i<n; i++){
			if(partido.at(i)==mmax) {
			partido.at(i)=0;
			aevaluar.push_back(i);}
		}
		
		
		fout<<"Case #"<<j+1<<":";
		while(mmax>0){
			//cout<<mmax;
			int y=0;
			if(aevaluar.size()%2){
				fout<<" "<<(char)(aevaluar.at(y)+'A');
				y++;
			}
			while(y<aevaluar.size()){
				fout<<" "<<(char)(aevaluar.at(y)+'A')<<(char)(aevaluar.at(y+1)+'A');
				y+=2;
				//cout<<"hey"<<y<<"T";
			}
			mmax--;
			for(int i=0; i<n; i++){
				if(partido.at(i)==mmax) {
				partido.at(i)=0;
				aevaluar.push_back(i);}
			}
			//cout<<"hey";
		}
		//cout<<"terminado\n";
		fout<<"\n";
		

	}
}









// int('a');
// string.at(i);
/*

long long int myPow(long long int x, long long int p)
{
  if (p == 0) return 1;
  if (p == 1) return x;

  long long int tmp = myPow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}
*/
