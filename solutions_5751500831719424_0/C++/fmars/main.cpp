#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
#include<climits>
using namespace std;
struct En{
    char c;
    int n;
    En(char cc,int nn):c(cc),n(nn){}
};
void func_1(string str,vector<En> &v){
    v.push_back(En(str[0],0));
    for(int i=1;i<str.size();i++)
        if(str[i]==v.back().c)
            v.back().n++;
        else   {
            v.push_back(En(str[i],1));
        }
}
int func_3(vector<int>&arr){
    int min=INT_MAX;
    for(int i=0;i<arr.size();i++){
        int r=0;
        for(int j=0;j<arr.size();j++)
            if(j!=i)
                r+=abs(arr[j]-arr[i]);
        min=min<r?min:r;
    }
    return min;
}
int func_2(vector< vector<En> > &v,int k){
    vector<int> arr;
    for(int i=0;i<v.size();i++)
        arr.push_back(v[i][k].n);
    return func_3(arr);
}
int main()
{
	freopen("in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i,j, TC, T, N;
	scanf("%d", &TC);
	for (T = 1; T <= TC; T++){
		printf("Case #%d: ", T);
		cin>>N;
		vector< vector<En> > v;
		for(i=0;i<N;i++){
            string str;
            cin>>str;
            vector<En> vv;
            func_1(str,vv);
            v.push_back(vv);
		}
		int res=0;
		int f=0;
		for(i=1;i<N;i++)
            if(v[i].size()!=v[i-1].size()){
                printf("Fegla Won\n");
                f=1;
                break;
        }
        if(f)continue;

        for(i=0;i<v[0].size();i++)
            for(j=1;j<N && !f;j++){
                if(v[j][i].c!=v[j-1][i].c){
                    printf("Fegla Won\n");
                    f=1;
                    break;
                }
            if(f)break;
        }
        if(f)continue;

        for(i=0;i<v[0].size();i++)
            res+=func_2(v,i);
		printf("%d\n", res);
	}
	return 0;
}
