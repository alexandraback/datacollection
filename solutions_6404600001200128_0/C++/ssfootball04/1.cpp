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
		N=(atoi(line.c_str()));	
		getline(cin,line);
		int k=0;int p=0;vector<int> sizes;		
		for(j=0;j<line.length();j++){
			// if(line[j]==' ')
			// 	break;

			if(k==N-1){
				sizes.push_back(atoi(line.substr(p).c_str()));break;
				}			
			if(line[j]==' '){
				sizes.push_back(atoi(line.substr(p,j-p).c_str()));
				p=j+1;k=k+1;
				}
			}

		int comp1=0,comp2=0,max=0;
		for(j=1;j<N;j++){
			if(sizes[j]<sizes[j-1]){
				comp1+=-(sizes[j]-sizes[j-1]);
				if(sizes[j-1]-sizes[j]>max)
					max=sizes[j-1]-sizes[j];
			}
		}

		for(j=1;j<N;j++){
			comp2+=min(sizes[j-1],max);
		}

		// int ans=solve(N,X);
		printf("Case #%d: %d %d\n",i+1,comp1,comp2);
		output << "Case #" << i+1 <<": " << comp1 << " " <<comp2 << "\n" ;
	}
	output.close();
	return 0;
}

