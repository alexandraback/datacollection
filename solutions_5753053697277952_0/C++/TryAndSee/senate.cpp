#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

static char letters[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
static int P[26];

int main(){
	cout<<"launching function main"<<endl;
	ifstream file("A-small-attempt0.in");
	ofstream outputfile("myoutput.txt");
	int T, N, tot;
	//local
	int pos_max1, max1, pos_max2, max2;
	file>>T;
	for(int t=0;t<T;t++){
		//read input
		file>>N;
		tot=0;
		for(int i=0;i<N;i++){
			file>>P[i];
			tot+=P[i];
		}
		//solve & write
		outputfile<<"Case #"<<(t+1)<<":";
		if(tot%2==1){
			tot--;
			pos_max1=0; max1=P[0];
			for(int i=1; i<N; i++)
				if(P[i]>max1){
					pos_max1=i; max1=P[i];
				}
			P[pos_max1]--;
			outputfile<<" "<<letters[pos_max1];
		}
		tot/=2;
		for(int k=0; k<tot; k++){
			pos_max1=0; max1=P[0];
			for(int i=1; i<N; i++)
				if(P[i]>max1){
					pos_max1=i; max1=P[i];
				}
			P[pos_max1]--;
			pos_max2=0; max2=P[0];
			for(int i=1; i<N; i++)
				if(P[i]>max2){
					pos_max2=i; max2=P[i];
				}
			P[pos_max2]--;
			outputfile<<" "<<letters[pos_max1]<<letters[pos_max2];
		}
		outputfile<<endl;
		
	}
	file.close();
	outputfile.close();
}

