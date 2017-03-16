

#include"stdafx.h"
#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <queue>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,t;
	cin>>t;
	for (int t1=0; t1<t; t1++){
		cin>>n;
		vector<string>my;
		for (int i=0; i<n; i++){
			string temp;
			cin>>temp;
			my.push_back(temp);

		}
		char a=my[0][0];
		
	int g[125][125];
		for (int i=0; i<125; i++)
		for (int j=0; j<125; j++)
			g[i][j]=0;

		vector<char>cv;
		cv.push_back(a);

		int ans=0;
		for (int i=1; i<my[0].size(); i++)
			if (my[0][i]!=a) { 
				a=my[0][i];
				cv.push_back(a);
			}

		
		for (int i=0; i<n; i++){
			int u=0;
			for (int j=0; j<my[i].size(); j++){
			   /*  cout<<(int)cv[u]<<" VV"<<endl;*/
				if (my[i][j]==cv[u]) g[i][u]++;
				else { u++;	if (u>=cv.size()) { ans=-1; break;}
				if (my[i][j]==cv[u]) g[i][u]++;
				else ans=-1;
				}
				if (u>=cv.size()) { ans=-1; break;}
			}
			if (u!=cv.size()-1) ans=-1;
		}

		
		for (int j=0; j<n; j++)
			for (int i=0; i<cv.size(); i++)
				if (g[j][i]==0) ans=-1;
		if (ans==-1) {cout<<"Case #"<<t1+1<<": Fegla Won"<<endl; continue;}
	     
		/*for (int j=0; j<n; j++){
			for (int i=0; i<cv.size(); i++)
			
				cout<<g[j][i]<<" ";
			cout<<endl;
		
		}*/
		for (int i=0; i<cv.size(); i++){
			//cout<<cv[i]<<endl;
			vector<int> temp2;
		    int ans1=1111111111;
			for (int h=1; h<200; h++){
			int ans2=0;
			for (int j=0; j<n; j++){
				ans2+=abs(h-g[j][i]);
			}
			ans1=min(ans1,ans2);
			}
			/*cout<<cv[i]<<" "<<ans1<<" "<<endl;*/
			ans+=ans1;
		}
				cout<<"Case #"<<t1+1<<": "<<ans<<endl;
	}


	//system("pause");

	return 0;

}