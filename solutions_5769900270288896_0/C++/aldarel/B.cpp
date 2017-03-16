/*
 * B.cpp
 *
 *  Created on: 2 maj 2015
 *      Author: KAMIL
 */

#include <iostream>
#include <cstdlib>
#include <list>
#include <algorithm>
#include <cstddef>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
using namespace std;

int solveOneTimesC(int c, int n){
	int temp, result;
	if(c%2==0){
		temp=c/2;
		if(temp<n){
			result = (n-temp)*2 - 1;
			return result;
		}else
			return 0;
	}
	else{
		temp=c/2+1;
		if(temp<n){
			result = (n-temp)*2;
			return result;
		}else
			return 0;
	}
}

int solveTwoTimesC(int c, int n){
	int temp, result;
	temp=c;
	if(temp<n){
			result = (n-temp)*3;
			if(n-temp==1){
				result--;
			}
			if(n-temp>1)
				result-=2;
			return result;
	}else
		return 0;
}

int solveThreeTimesC(int c, int n){
	if(c==3){
		if(n<6)
			return 0;
		if(n==6)
			return 3;
		if(n==7)
			return 6;
		if(n==8)
			return 8;
		if(n==9)
			return 12;
	}
	if(c==4){
		if(n<7)
			return 0;
		if(n==7)
			return 2;
		if(n==8)
			return 4;
		if(n==9)
			return 7;
		if(n==10)
			return 10;
		if(n==11)//without one
			return 13;
		if(n==12)
			return 17;
	}
	if(c==5){
		if(n<9)
			return 0;
		if(n==9)
			return 3;
		if(n==10)
			return 6;
		if(n==11)
			return 8;
		if(n==12)
			return 11;
		if(n==13)
			return 14;
		if(n==14)
			return 18;
		if(n==15)
			return 22;
	}
	return -1;
}

int solveFourTimesC(int c, int n){//Max-24
	if(n<9)
		return 0;
	if(n==9)
		return 2;
	if(n==10)
		return 4;
	if(n==11)
		return 7;
	if(n==12)
		return 10;
	if(n==13)
		return 13;
	if(n==14)
		return 16;
	if(n==15)
		return 20;
	if(n==16)
		return 24;
	return -1;
}


int main(){
	int tests;
	cin>>tests;
	int *r=new int[tests], *c= new int[tests], *n= new int[tests];
	for(int i=0;i<tests;i++)
		cin>>r[i]>>c[i]>>n[i];
	for(int i=0;i<tests;i++){
		int rr = min(r[i],c[i]);
		int cc = max(r[i],c[i]);
		int nn = n[i];
		int result;
		switch(rr){
			case 1:
				result = solveOneTimesC(cc,nn);
				break;
			case 2:
				result = solveTwoTimesC(cc,nn);
				break;
			case 3:
				result = solveThreeTimesC(cc,nn);
				break;
			case 4:
				result = solveFourTimesC(cc,nn);
				break;
			default:
				result = -1;
				break;
		}
		cout<<"Case #"<<i+1<<": "<<result<<endl;
	}
	return 0;
}
