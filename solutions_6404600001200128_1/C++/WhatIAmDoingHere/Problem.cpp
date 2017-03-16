#include<iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <limits.h>

using namespace::std;
vector<int> p;

int method1(){
	int diff=0, result=0;

	for(int i=1; i<p.size(); i++){
		diff=p[i-1] - p[i];
		
		if(diff>0)
			result = result+diff;			
	}
	return result;
}

int method2(){
	int diff=0, result=0, maxDiff=0;
	
	for(int i=1; i<p.size(); i++){
		diff=p[i-1] - p[i];
		if(diff>=maxDiff)
			maxDiff = diff;			
	}
	//cout<<maxDiff<<endl;
	
	for(int i=0; i<p.size()-1; i++){
		if(p[i]>maxDiff)
			result = result + maxDiff;			
		else
			result = result + p[i];	
	}
	return result;
}

int main()
{
	int data=0, d=0, testcases=0, result=0;
	ifstream iFile("A-large.in");//("input.in");//
	ofstream oFile("output.text");
	
	//vector<int> p;
	
	
	if(iFile.is_open()){
		iFile>>testcases;		
		for(int i=1; i<=testcases; i++){
			oFile<<"Case #"<<i<<": ";
			iFile>>d;			
			for(int i=0; i<d; i++){
				iFile>>data;
				p.push_back(data);
				//cout<<data<<endl;
			}
			if(p.size()<=0) return 0;
			
			//method 1
			result = method1();
			oFile<<result;
			//method 2
			result = method2();
			oFile<<" "<<result<<endl;
			
			p.clear();
		}
		iFile.close();
	}
	else
		oFile<<"Can't open input file"<<endl;
	return 0;
}