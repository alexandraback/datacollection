#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>

using namespace std;

int p[100];
int n;

int main(){
	ifstream in("A-large.in");
	ofstream out("A-large.out");
	int Test,cnt;
	in>>Test;
	for (cnt=1;cnt<=Test;cnt++){
		in>>n;
		for (int i=0;i<n;i++)
			in>>p[i];
		out<<"Case #"<<cnt<<": ";
		while (1){
			int now=-1;
			int pre;
			int max=1;
			int cnt=0;
			for (int i=0;i<n;i++){
				if (p[i]>=max){
					max=p[i];
					pre=now;
					now=i;
				}
				if (p[i])
					cnt++;
			}
			if (cnt==0)
				break;
			if (cnt>2){
				out<<(char)(now+'A')<<" ";
				p[now]--;
			}else{
				out<<(char)(pre+'A')<<(char)(now+'A');
				p[now]--;
				p[pre]--;
				if (p[now])
					out<<" ";
			}
		}
		out<<endl;
	}
}
