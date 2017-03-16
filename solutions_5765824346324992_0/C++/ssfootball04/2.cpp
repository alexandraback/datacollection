#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <vector>
#include <algorithm>    // std::sort

using namespace std;


int main(int argc,char* argv[]){
	freopen(argv[1],"r",stdin);
	fstream output("output");
	string line;
	getline(cin,line);
	int T=(atoi(line.c_str()));
	int i,N; string X;
	for(i=0;i<T;i++){
		getline(cin,line);int j;
		for(j=0;j<line.length();j++){
			if(line[j]==' ')
				break;
		}
		int B=atoi(line.substr(0,j).c_str());
		N=atoi(line.substr(j+1).c_str());	
		getline(cin,line);
		int k=0;int p=0;vector<int> sizes;		
		for(j=0;j<line.length();j++){
			// if(line[j]==' ')
			// 	break;

			if(k==B-1){
				sizes.push_back(atoi(line.substr(p).c_str()));break;
				}			
			if(line[j]==' '){
				sizes.push_back(atoi(line.substr(p,j-p).c_str()));
				p=j+1;k=k+1;
				}
			}


		long int start=1;long int end=1000000000000;
		long int T=0;
		while(start<=end){
			T=(start+end)/2;
			long int sum=0;
			for(j=0;j<B;j++)
				sum+=T/sizes[j];
			if(sum==N-B-1)
				break;
			else if(sum>N-B-1)
				end=(start+end)/2-1;
			else
				start=(start+end)/2+1;
		}

		// cout << T << endl;

		while(1>0){
			long int sum=0;
			for(j=0;j<B;j++)
				sum+=T/sizes[j];
			if(sum<N-B-1)
				break;
			else
				T--;
		}

		// T++;
		// cout << T <<endl;

		int queue [B];
		for(j=0;j<B;j++) queue[j]=0;


		int cust=0;

		for(j=0;j<B;j++){
			cust+=T/sizes[j];
			if(T%sizes[j]==0)
				queue[j]=0;
			else{ 
				queue[j]=sizes[j]-T%sizes[j];
				cust++;
			}
		}
			// cout << "dsf" << endl;

		int barb=0,min=1000001,ind=-1;
		for(j=cust+1;j<=N;j++){
			min=1000001;ind=-1;
			for(k=0;k<B;k++){
				if(queue[k]<min){
					min=queue[k];
					ind=k;
				}
			}

			for(k=0;k<B;k++){
				if(k==ind)
					queue[k]=sizes[k];
				else
					queue[k]-=min;
			}

		}

		// int ans=solve(N,X);
		printf("Case #%d: %d\n",i+1,ind+1);
		output << "Case #" << i+1 <<": " << ind+1 << "\n" ;
	}
	output.close();
	return 0;
}

