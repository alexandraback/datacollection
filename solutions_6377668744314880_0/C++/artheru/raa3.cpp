#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main(){
	ifstream inf("in.txt");
	ofstream of("out.txt");
	int qN;
	inf>>qN;

	for(int q=0; q<qN; ++q){
		int n; inf>>n;
		long long x[3010], y[3010];
		for (int i=0; i<n; ++i)
			inf>>x[i]>>y[i];

		of<<"Case #"<<q+1<<":"<<endl;

		for (int i=0; i<n; ++i){
			int mini=100000;
			for (int j=0; j<n; ++j) if (i!=j)
			{
				int neg=0, pos=0;
				long long tx=x[i]-x[j];
				long long ty=y[i]-y[j];
				for (int k=0; k<n; ++k){
					long long cross=tx*(y[i]-y[k])-(x[i]-x[k])*ty;
					if (cross>0) pos++;
					else if (cross<0) neg++;
				}
				int tm=min(neg,pos);
				if (tm<mini) mini=tm;
			}
			if (mini==100000)
				of<<0<<endl;
			else
				of<<mini<<endl;
		}
	}
}