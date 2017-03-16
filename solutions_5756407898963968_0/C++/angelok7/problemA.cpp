#include <iostream>
#include <fstream>

using namespace std;


int main()
{
	int n,N;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	fin>>N;

	for(n=0;n<N;n++){
		int a,b;
		int map1[5][5];
		int map2[5][5];
		int i,j;
		fin>>a;
		for(i=1;i<5;i++)
			for(j=1;j<5;j++)
				fin>>map1[i][j];
		fin>>b;
		for(i=1;i<5;i++)
			for(j=1;j<5;j++)
				fin>>map2[i][j];

		int count = 0;
		int res = 0;
		for(i=1;i<5;i++){
			for(j=1;j<5;j++){
				if(map1[a][i] == map2[b][j]){
					count++;
					res = map1[a][i];
				}
			}
		}
		if(count == 1)
			fout<<"Case #"<<n+1<<": "<<res<<endl;
		else if(count == 0)
			fout<<"Case #"<<n+1<<": Volunteer cheated!"<<endl;
		else
			fout<<"Case #"<<n+1<<": Bad magician!"<<endl;

	}


	return 0;
}
