
#include<vector>
#include<fstream>
#include<iostream>
using namespace std;

long int main(long int argc, char* argv[])
{
	string inputfilename="input.txt";
	string outputfilename="output.txt";
	ifstream infile(inputfilename);
	ofstream OF(outputfilename);
	long int T;
	infile>>T;

	for(long int icase=0;icase<T;icase++){
		long int answer1=0;
		long int answer2=0;
		long int N=0;
		vector<long int> v;
		infile>>N;
		v.resize(N);
		for(long int i=0;i<N;i++){
			infile>>v[i];
		}
		long int max=0;
		for(long int i=1;i<N;i++){
			if(v[i]<v[i-1]) {
				long int buf=v[i-1]-v[i];
				answer1+=buf;
				if(buf>max) max=buf;
			}
		}
		for(long int i=1;i<N;i++){
			
				long int buf=v[i-1];
				if(max>buf){
					answer2+=buf;
				}else{
					answer2+=max;
				}
			
		}
	
	
	
	
	
		OF<<"Case #"<<icase+1<<": "<<answer1<<" "<<answer2<<endl;
		cout<<"Case #"<<icase+1<<": "<<answer1<<" "<<answer2<<"	"<<max<<endl;
	}

		

	infile.close();
	OF.close();
	return 0;
}

