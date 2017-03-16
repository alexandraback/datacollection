#include <iostream>
#include <fstream>
#include <vector>

using namespace std;



int unhappiness1(int r, int c, int n){
	int n0, n2, n3;
	if(((r*c)%2)==0){
		n0=(r*c)/2; n2=2; n3=r+c-4;
	}else{
		n0=(r*c+1)/2; n2=0; n3=r+c-2;
	}
	if(n<=n0)
		return 0;
	if(n<=n0+n2)
		return (2*(n-n0));
	if(n<=n0+n2+n3)
		return (2*n2+3*(n-n0-n2));
	return 2*n2+3*n3+4*(n-n0-n2-n3);
}

int unhappiness2(int r, int c, int n){
	int n0, n2, n3;
	if(((r*c)%2)==0){
		n0=(r*c)/2; n2=2; n3=r+c-4;
	}else{
		n0=(r*c-1)/2; n2=4; n3=max(0,r-4)+max(0,c-4);
	}
	if(n<=n0)
		return 0;
	if(n<=n0+n2)
		return (2*(n-n0));
	if(n<=n0+n2+n3)
		return (2*n2+3*(n-n0-n2));
	return 2*n2+3*n3+4*(n-n0-n2-n3);
}

int unhappiness(int r, int c, int n){
	if(r<1)
		return 0;
	if(n<=((r*c+1)/2))
		return 0;
	if(r==1)
		return (2*n-c-1);
	return min(unhappiness1(r,c,n),unhappiness2(r,c,n));
}

int main(){
	cout<<"launching function main"<<endl;
	ifstream file("B-small-attempt0.in");
//	ifstream file("verySmallInput");
	ofstream outputfile("myoutput.txt");
	int T, R, C, N;
	file>>T;
	for(int t=0;t<T;t++){
		//read input
		file>>R>>C>>N;
		//write output
		outputfile<<"Case #"<<(t+1)<<": "<<unhappiness(min(R,C),max(R,C),N)<<endl;
	}
	file.close();
	outputfile.close();
}

