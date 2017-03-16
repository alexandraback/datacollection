#include<iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <limits.h>

using namespace::std;
vector<int> p;
int myNumber=0;

int method1(){
	int min=0, max=0, result=0, noInOneRound=0;
	bool d=true;

	for(int i=0; i<p.size(); i++){
		
		if(p[i]>max)
			max=p[i];
	}
	//cout<<max;
	min = max;
	for(int j=0; ; j++){
		d=true;
		for(int i=0; i<p.size(); i++){
			if(0 != max%p[i])
				d=false;
		}
		if(d)
			break;
		max = max+min;	
	}
	
	for(int i=0; i<p.size(); i++){
			noInOneRound = noInOneRound + max/p[i]; 
	}
		
		
	
	//cout<<max;
	int count=1;
	for(;noInOneRound*count<myNumber;count++){
		
	}
	count--;
	myNumber = myNumber - noInOneRound*count;
	for(int j=0; ;j++){
		d=false;
		for(int i=0; i<p.size(); i++){
			if(0 == j%p[i])
				myNumber--;
			if(0 == myNumber){
				d=true;
				result = i+1;
				break;
			}	
		}
		if(d) 
			break;
	}
	
	return result;
}


int main()
{
	int data=0, d=0, testcases=0, result=0;
	ifstream iFile("B-small-attempt0.in");//("input.in");//
	ofstream oFile("output.text");
	
	if(iFile.is_open()){
		iFile>>testcases;		
		for(int i=1; i<=testcases; i++){
			oFile<<"Case #"<<i<<": ";
			iFile>>d>>myNumber;			
			for(int i=0; i<d; i++){
				iFile>>data;
				p.push_back(data);
				//cout<<data<<endl;
			}
			if(p.size()<=0) return 0;
			
			//method 1
			result = method1();
			oFile<<result<<endl;
			
			p.clear();
		}
		iFile.close();
	}
	else
		oFile<<"Can't open input file"<<endl;
	return 0;
}