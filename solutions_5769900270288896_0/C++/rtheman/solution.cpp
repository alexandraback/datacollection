#include<fstream>
#include<iostream>
#include <iomanip>

using namespace std;

int main()
{	

	ifstream input;
 	ofstream output;
 	input.open("cj1bb.txt");
 	output.open("answer.txt");
	int n,t,r,c,z,mask,vis[17][17],ct,ans;
	input>>t;
	int ss=t;
	while(t--){
		input>>r>>c>>n;
		z=r*c;
		
		mask=0;
		int mn=100000;
		while(mask<(1<<z)){
			
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++)
					vis[i][j]=0;
			}
			ct=0;
			
			for(int i=0;i<z;i++){
				if(mask&(1<<i)){
					ct++;
					vis[i/c][i%c]=1;
					if(ct>n){
						
						break;
					}
					
				}
			
			
				if(ct==n){
					ans=0;
					for(int i=0;i<r;i++){
						for(int j=0;j<c;j++){
							
							if(i>0&&vis[i][j]==1&&vis[i-1][j]==1){
								ans++;
							}
							if(i<r-1&&vis[i][j]==1&&vis[i+1][j]==1){
								ans++;
							}
							if(j>0&&vis[i][j]==1&&vis[i][j-1]==1){
								ans++;
							}
							if(j<c-1&&vis[i][j]==1&&vis[i][j+1]==1){
								ans++;
							}
						}
					}
					if(ans<mn){
						mn=ans;
					}
				}
				
			}
			mask++;
		}
		output<<"Case #"<<ss-t<<": "<<mn/2<<endl;
	}
	return 0;
}
