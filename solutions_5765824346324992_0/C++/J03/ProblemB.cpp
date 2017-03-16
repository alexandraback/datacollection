
#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>
#include "boost/math/common_factor.hpp"
using namespace std;

using namespace boost::math;

long int main(long int argc, char* argv[])
{
	string inputfilename="input.txt";
	string outputfilename="output.txt";
	ifstream infile(inputfilename);
	ofstream OF(outputfilename);
	long int T;
	infile>>T;

	for(long int icase=0;icase<T;icase++){
		cout<<icase<<endl;
		long int answer;
		long int B;
		long int N;

		infile>>B>>N;
		vector<long int> v;  //times
		vector<long int> status;
		status.resize(B);
		v.resize(B);
		status.resize(B);


		long  int prod=1;
		long int LCm=1;
		for(long int i=0;i<B;i++){
			status[i]=0;
			infile>>v[i];
			//prod*=v[i];
			LCm=lcm(LCm,v[i]);
		}
		long int tot=0;
		
		for(long int i=0;i<B;i++){
			tot+=LCm/v[i];
		}

		


		if(!(N%tot)){
			//N=N%tot;
			//answer=min_element(v.begin(),v.end())-v.begin();
			N=tot;
		}else{
			N=N%tot;
		}

					//if(N==0) N=prod;


		long int itime=0;
		int iflag=0;
		while(N>=0){
		
			for(long int i=0;i<B;i++){
				if(status[i]<=itime){
					status[i]+=v[i];
					
					if(N==1) {
						answer=i;
						iflag=1;
						break;
					}
					N--;
				}
				
			}
			if(iflag==1) break;
			itime++;
		}	
	


		



	
		OF<<"Case #"<<icase+1<<": "<<answer+1<<endl;
	}

		

	infile.close();
	OF.close();
	return 0;
}

