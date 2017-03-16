#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <omp.h>  
using namespace std;

int main(){
	ifstream inf("in.txt");
	ofstream of("out.txt");
	int qN;
	inf>>qN;

	int outf[100];
	omp_set_num_threads(24);  

	int b[100], n[100];
	int m[100][1000];
	for(int q=0; q<qN; ++q){
		inf>>b[q]>>n[q];
		for (int i=0; i<b[q]; ++i)
			inf>>m[q][i];
	}

#pragma omp parallel for
	for(int q=0; q<qN; ++q){
		int arr[1001]={0};
		int seat=0;
		for (int i=0; i<n[q]; ++i){
			int minPtr=0;
			for (minPtr=0; minPtr<b[q]; ++minPtr) {
				if (arr[minPtr]==0) break;
			};
			arr[minPtr]+=m[q][minPtr];
			seat=minPtr;
			for (int j=0; j<b[q]; ++j) {
				if (arr[minPtr]>arr[j]) minPtr=j;
				if (arr[minPtr]==0) break;
			};
			int mini=arr[minPtr];
			if (mini>0)
				for (int j=0; j<b[q]; ++j)
					arr[j]-=mini;
		};
		cout<<q<<endl;
		outf[q]=seat+1;
	}
	
	for(int i=0; i<qN; ++i)
		of<<"Case #"<<i+1<<": "<<outf[i]<<endl;
}