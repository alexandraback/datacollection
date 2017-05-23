#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

vector<char> decompose(string s) {
	vector<char> ret;
	for(int i=0;i<s.size();i++) if(i==0||s[i]!=s[i-1]) {
		//cout<<s[i]<<endl;
		ret.push_back(s[i]);
	}
	//cout<<endl;
	return ret;
}

vector<int> decompose2(string s) {
	cout<<s<<endl;
	vector<int> ret;
	int ct=0;
	for(int i=0;i<s.size();i++) {
		int ct=1;
		bool found=false;
		for(int j=i+1;j<s.size();j++) {
			if(s[j]!=s[i]) {
				i=j-1;
				found=true;
				break;
			}
			ct++;
		}
		if(!found)i=s.size();
		ret.push_back(ct);
		//cout<<ct<<" "<<i<<" ";
	}
	cout<<endl;
	return ret;
}

int doit(vector<string> v) {
	vector<char> first=decompose(v[0]);
	for(int i=1;i<v.size();i++) {
		vector<char> other=decompose(v[i]);
		if(first!=other) return -1;
	}
	vector<vector<int> > counts;
	for(int i=0;i<v.size();i++) {
		counts.push_back(decompose2(v[i]));
	}
	int ret=0;
	for(int i=0;i<counts[0].size();i++) {
		vector<int> cts;
		for(int j=0;j<v.size();j++) {
			cts.push_back(counts[j][i]);
		}
		sort(cts.begin(),cts.end());
		int med=cts[cts.size()/2];
		for(int j=0;j<cts.size();j++) ret+=abs(cts[j]-med);
	}
	return ret;
}

int main()
{
	ifstream infile;
	//string prefix = "B-large-practice";
	//string prefix = "practice";
	//string prefix = "A-large";
	string prefix = "A-small-attempt0";
	infile.open(prefix + ".in");
	ofstream outfile(prefix + ".out");
	int cases;
	if (infile.is_open()) {
		infile>>cases;
	}
	else {
		return 0;
	}
	for(int i=0;i<cases;i++) {
		int N;
		infile>>N;
		vector<string> v;
		for(int j=0;j<N;j++) {
			string s;
			infile>>s;
			v.push_back(s);
		}
		int ret=doit(v);
		if(ret==-1)
			outfile << "Case #" << (i+1) << ": " << "Fegla Won" << endl; 
		else
			outfile << "Case #" << (i+1) << ": " << ret << endl; 
	}
	cout<<"DONE"<<endl;
	string zzz;
	cin>>zzz;
	outfile.close();
	return 0;
}