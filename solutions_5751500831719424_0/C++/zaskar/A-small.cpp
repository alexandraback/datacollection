#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
	ifstream fin("A-small-attempt0.in");
	ofstream fout("A-small-attempt0.out");
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		int n;
		fin>>n;
		string w[100]; int l[100];
		for(int i=0;i<n;i++) { 
			fin>>w[i]; l[i]=w[i].size();
		}
		
		bool factible=true;
		int i=0, c[100], N=0, s[100];
		while (true) {
			
			bool alguna_cero=false, alguna_algo=false;
			for(int i=0;i<n;i++) {  
				if (l[i]>0) alguna_algo=true; else alguna_cero=true;
			} 
			if (alguna_algo&&alguna_cero) { factible=false; break; }
			if (!alguna_algo) break;
			
			char one=w[0][0]; 
			for(int i=0;i<n;i++) { 
				c[i]=0; while (c[i]<l[i] && w[i][c[i]]==one) c[i]++;
				if (c[i]==0) { factible=false; break; }
				s[i]=c[i];
			}
			if (!factible) break;
			sort(s,s+n); int x=s[n/2];
			
			for(int i=0;i<n;i++) { 
				if (c[i]<x) {
					N+=x-c[i];
				} else if (c[i]>x) {
					N+=c[i]-x;
				}
				w[i].erase(0,c[i]); l[i]-=c[i];
			}
			
		}
		
		if (factible)
			fout<<"Case #"<<I+1<<": "<<N<<endl;
		else 
			fout<<"Case #"<<I+1<<": "<<"Fegla Won"<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

