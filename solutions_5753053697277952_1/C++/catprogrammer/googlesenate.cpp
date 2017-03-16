#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<char,int>i,pair<char,int> j){
	return i.second>j.second;
}
int main (){
	ifstream cin("Asmall.in");
	ofstream cout("AE.txt");
	int x;
	cin>>x;
	int y;
	int count=0;
		int check=0;
	for(int i=1;i<=x;i++){
		cin>>y;
		pair<char,int> array[y];
		count=0;check=0;
		for(int j=0;j<y;j++){
			cin>>array[j].second;
			count+=array[j].second;
			array[j].first=(char)(j+65);
		}
		cout<<"Case #"<<i<<":";
		while(count!=0){
			
				cout<<" ";
			
			sort(array,array+y,cmp);
			cout<<array[0].first;
			array[0].second--;
			count--;
			if(count%2!=0){
				sort(array,array+y,cmp);
				cout<<array[0].first;
			array[0].second--;
			count--;
			}
			
		}
		cout<<endl;
	}
}
