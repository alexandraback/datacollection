#include <bits/stdc++.h>

using namespace std;
#define LL long long
#define FORI(A,B,C) for(int I=(A);I<=(B); I++)
#define FORLL(A,B,C) for(LL I=(A);I<=(B); I++)
#define VLL vector<LL>
#define VVLL vector<vector<LL>>
#define VI vector<int>
#define VVI vector<vector<int>>

#define showv(A) for(auto &x:A){cout<<x<<" ";}cout<<endl;


int findMax(vector<int> nums){
	int res = 0;
	for (int i=1;i<nums.size();i++){
		if (nums[i]>=nums[res]) res=i;
	}
	return res;
}

string funv(vector<int> nums){
	string res;
	int sum=0;
	for (auto &x:nums) sum+=x;
	int idx;
	while (sum>=4){
		idx=findMax(nums);nums[idx]--;sum--;
	    res+=('A'+idx);
	    idx=findMax(nums);nums[idx]--;sum--;
	    res+=('A'+idx);
	    res+=" ";
	}
	if (sum==3){
	    idx=findMax(nums);nums[idx]--;sum--;
	    res+=('A'+idx);
	    res+=" ";
	}
	idx=findMax(nums);nums[idx]--;sum--;
	res+=('A'+idx);
	idx=findMax(nums);nums[idx]--;sum--;
	res+=('A'+idx);
	res+=" ";


	return res;
}

int main() {
    ifstream ifile;
    ofstream ofile;
    ifile.open("Input.txt");
    ofile.open("Output.txt");

    int CaseIdx,TotalCase;
    string line;
    getline(ifile,line);
    stringstream ss(line);
    ss>>TotalCase;

    for (CaseIdx = 1; CaseIdx<=TotalCase; CaseIdx++)
    {
//  begin of code
  //  1. prepare data for current test case
    	LL N;
    	vector<int> nums;

		string line;
		{getline(ifile,line);stringstream ss(line);ss>>N;}
		{
			getline(ifile,line);stringstream ss(line);
			for (int i=0;i<N;i++)
			{int temp;ss>>temp;nums.push_back(temp);}
		}

  //  2. data_pre_processing if possible. (significantly reduced time/space complextity

  //  3. data_processing to get the result
		//int res = fun(A,B,C);
		string res = funv(nums);

  //  4. Output results;
		string caseResult="";
	    caseResult += res;

    	cout<<"Case #"<<CaseIdx<<": "<<caseResult<<endl;
    	ofile<<"Case #"<<CaseIdx<<": "<<caseResult<<endl;

// end of code
    }


    ifile.close();
    ofile.close();
	return 0;
}

