#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int t;

int check(int a){
	int count = 0;
	for(int i=0;i<t;i++){
		if(a & (1<<i))
			++count;
	}
	return count;
}

int main()
{
	int n,N;
	ifstream fin("B-small-attempt0.in");
	//ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	fin>>N;

	for(n=0;n<N;n++){
		int R,C,N;		
		fin>>R>>C>>N;
		t = R*C;
		int size = 1<<(R*C);
		int min = 10000000;
		for(int i=0;i<size;i++){
			if(check(i) == N){
				int count = 0;
				for(int j=0;j<t;j++){
					if(i & (1<<j)){
						if( j % C < (j+1)%C && (i & (1<<(j+1))))
							count++;
						if( j+C < t && (i & (1<<(j+C))))
							count++;
					}
				}
				if(min > count)
					min = count;
			}
		}
		
		fout<<"Case #"<<n+1<<": "<<min<<endl;
	}


	return 0;
}


//fout.setf(ios::fixed);
//fout.precision(6);