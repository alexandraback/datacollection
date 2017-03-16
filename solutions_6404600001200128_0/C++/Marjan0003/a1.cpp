#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<map>


using namespace std;

int main(){
	ifstream in("in");
	ofstream out("out");
	int casenum=0;
	in>>casenum;
	int m[100];
	for (int c=0;c<casenum;c++){
		int n;
		in>>n;
		int case1=0;
		int mcase2=0;
		int case2=0;
		for(int i=0;i<n;i++){
			in>>m[i];
			//out<<m[i]<<endl;
			
			if(i>0 && m[i]<m[i-1]){
				//out<<"def"<<m[i-1]-m[i]<<endl;
				case1+=(m[i-1]-m[i]);
				if(mcase2<(m[i-1]-m[i]))
					mcase2=m[i-1]-m[i];
			}
		}
		//cout<<"m:"<<mcase2<<endl;
			
		for(int i=1;i<n;i++){
			if(m[i-1]<mcase2)
				case2+=m[i-1];
			else
				case2+=mcase2;
		
		}
		
		out<<"Case #"<<c+1<<": "<<case1<<" "<<case2<<endl;	
	
		
	}
	
	return 0;
	
}
