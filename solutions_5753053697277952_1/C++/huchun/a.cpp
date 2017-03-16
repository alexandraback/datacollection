#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

struct comp{
	bool operator () (pair<char, int>& a, pair<char, int>& b){
		return a.second < b.second;
	}
};

int main(){
	ofstream myfile;
  	myfile.open ("outputa.txt");
  	int t;
	scanf("%d",&t);
	for (int i=1;i<=t;++i){
		int n;
		cin>>n;
		int arr[n];
		int count = 0;
		for (int j = 0; j < n; ++j){
			cin>>arr[j];
			count += arr[j];
		}
		priority_queue<pair<char, int>, vector<pair<char, int>>, comp> pq;
		for (int j = 0; j < n; ++j){
			pq.push(make_pair(j+'A', arr[j]));
		}
		myfile<<"Case #"<<i<<": ";
		while(!pq.empty()){
			myfile<<pq.top().first;
			pair<char, int> cur = pq.top();
			pq.pop();
			cur.second--;
			count--;
			if (cur.second > 0) pq.push(cur);
			if (count != 2){
				myfile<<pq.top().first;
				pair<char, int> cur = pq.top();
				pq.pop();
				cur.second--;
				if (cur.second > 0) pq.push(cur);
				count--;
			}
			myfile<<' ';
		}
		myfile<<endl;
	}
  	myfile.close();
  	return 0;
}
