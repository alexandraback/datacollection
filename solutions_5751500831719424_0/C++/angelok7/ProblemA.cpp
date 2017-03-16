#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	int n,N;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	
	fin>>N;

	for(n=0;n<N;n++){
		int num;
		string arr[100];
		fin>>num;
		int i,j;
		for(i=0;i<num;i++)
			fin>>arr[i];
		int res = 0;
		int check = 0;
		while(1){
			int nu[100];
			int max = 0;
			if(arr[0].size() == 0)
				break;
			for(i=0;i<num;i++){
				for(j=0;j<arr[i].size();j++){
					if(arr[0][0] != arr[i][j])
						break;
				}
				nu[i] = j;
				if(nu[i] == 0)
					break;
				if(j > max)
					max = j;
			}
			if(i != num){
				check = 1;
				break;
			}
			int min = 1000000000;
			int sum = 0;
			for(i=1;i<=max;i++){
				sum = 0;
				for(j=0;j<num;j++){
					if(i > nu[j])
						sum += i - nu[j];
					else
						sum += nu[j] - i;
				}
				if(sum < min)
					min = sum;
			}
			res += min;
			for(i=0;i<num;i++)
				arr[i] = arr[i].substr(nu[i],arr[i].size());
		}
		for(i=0;i<num;i++)
			if(arr[i].size() != 0)
				check = 1;
		if(check == 1)
			fout<<"Case #"<<n+1<<": Fegla Won"<<endl;
		else
			fout<<"Case #"<<n+1<<": "<<res<<endl;
	}
	return 0;
}
