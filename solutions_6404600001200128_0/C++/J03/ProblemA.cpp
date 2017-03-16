
#include<vector>
#include<fstream>
#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
	string inputfilename="input.txt";
	string outputfilename="output.txt";
	ifstream infile(inputfilename);
	ofstream OF(outputfilename);
	int T;
	infile>>T;

	for(int icase=0;icase<T;icase++){
		int answer1=0;
		int answer2=0;
		int N=0;
		vector<int> v;
		infile>>N;
		v.resize(N);
		for(int i=0;i<N;i++){
			infile>>v[i];
		}
		int max=0;
		for(int i=1;i<N;i++){
			if(v[i]<v[i-1]) {
				int buf=v[i-1]-v[i];
				answer1+=buf;
				if(buf>max) max=buf;
			}
		}
		for(int i=1;i<N;i++){
			
				int buf=v[i-1];
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

