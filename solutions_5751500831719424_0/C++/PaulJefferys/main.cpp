#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <map>
#include <ctime>
#include <cassert>

using namespace std;

ofstream fout("../../../output.txt");
ifstream fin("../../../input.txt");



string concat;
vector<int> val;


int eval(vector<int> det)
{
    sort(det.begin(),det.end());
    if(det.size()==1)
        return 0;
    int k = (det.size()+1)/2-1;
    
    int ans = 0;
    
    for(int i=0; i<det.size(); i++)
        ans+=abs(det[i]-det[k]);
    return ans;
    
}

void parse(string s)
{
    char cur = 'X';
    vector<int> ret;
    string ret1;
    int len = 0;
    
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]==cur)
        {
            len++;
        }
        else{
            if(len>0)
                ret.push_back(len);
            len = 1;
            ret1+=s[i];
            cur = s[i];
        }
    }
    ret.push_back(len);
    val=ret;
    concat=ret1;
    return;
}


int main(void)
{
	int ttt;
	fin >> ttt;
	int ct = 0;
	string s;
	
	cout.precision(9);
	fout.precision(9);
    
    cout << "HELLO" <<  " " << ttt << endl;
    
    
	
	while(ttt>0)
	{
		ct++;
		ttt--;
        
		double c,f,x;
        
        
        int m;
        
        string ret;
        
        vector<string> lis;
        
        int i,j,k;
        int n;
        fin >> n;
        
        vector<vector<int> > vals;
        vector<string> shorts;

        
        for(i=0; i<n; i++)
        {
            string s;
            fin >> s;
            lis.push_back(s);
            parse(s);
            vals.push_back(val);
            shorts.push_back(concat);
        }
        
        bool isok = true;
        
        for(i=1; i<n; i++)
        {
            if(shorts[i]!=shorts[0])
                isok=false;
        }
        
        int ans = 0;
        
        if(isok)
        {
            for(i=0; i<vals[0].size(); i++)
            {
                vector<int> det;
                for(j=0; j<vals.size(); j++)
                    det.push_back(vals[j][i]);
                ans+=eval(det);
            }
        }
        
        
        string fail = "Fegla Won";
        
		
		cout << "Case #" << ct << ": ";
		fout << "Case #" << ct << ": ";
		
        if(isok)
        {
            cout << ans;
            fout << ans;
        }
        
        else{
            cout << fail;
            fout << fail;
        }
		
		
		
		fout << endl;
		cout << endl;
		
	}
	
	
	return 0;
}

