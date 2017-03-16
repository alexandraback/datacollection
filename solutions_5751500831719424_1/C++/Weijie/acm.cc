#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<iostream>

using namespace std;

FILE *fin;
FILE *fout;

int n;
string s[110];
char buff[1100];

string turn(string s){
	string ret = "";
	ret += s[0];
	for(int i = 1;i < s.length();++i)
		if(s[i] != s[i - 1])
			ret += s[i];
	return ret;
}

bool check(){
	string now = turn(s[1]);
	for(int i = 2;i <= n;++i)
		if(now != turn(s[i]))
			return false;
	return true;
}

int same[110][110];

int mabs(int a){
	if(a < 0)
		return -a;
	return a;	
}

int common(){
	int ret = 0;
	string uni = turn(s[1]);
	memset(same,0,sizeof(same));
	for(int i = 1;i <= n;++i){
		int p = 0;
		same[i][p] = 1;
		for(int j = 1;j < s[i].length();++j){
			if(s[i][j] != s[i][j - 1])
				++p;
			++same[i][p];
		}
	}
	for(int i = 0;i < uni.length();++i){
		int minn = 0x3f3f3f3f;
		for(int j = 1;j <= 100;++j){
			int tmp = 0;
			for(int k = 1;k <= n;++k)
				tmp += mabs(same[k][i] - j);
			minn = min(minn,tmp);
		}
		ret += minn;
	}
	return ret;
}

int main(){
	fin = fopen("A-large.in","r");
	fout = fopen("out.txt","w");
	int T;
	fscanf(fin,"%d",&T);
	for(int cas = 1;cas <= T;++cas){
		fscanf(fin,"%d",&n);
		for(int i = 1;i <= n;++i){
			fscanf(fin,"%s",buff);
			s[i] = string(buff);
		}
		fprintf(fout,"Case #%d: ",cas);
		if(check() == false){
			fprintf(fout,"Fegla Won\n");
			continue;
		}
		int t = common();
		int ans = 0;
		/*for(int i = 1;i <= n;++i){
			ans += (s[i].length() - t);
		}*/
		fprintf(fout,"%d\n",t);
	}
	fclose(fin);
	fclose(fout);
	system("pause");
	return 0;
}

