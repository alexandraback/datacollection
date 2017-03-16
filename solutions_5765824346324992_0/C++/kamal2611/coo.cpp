/*
ID: k.kamal1
PROG: test
LANG: C++     
*/
#include <bits/stdc++.h>

using namespace std;

int arr[7];

int gcd(int a,int b)
{
    if(b>a)
    return gcd(b,a);
    if(b==0)
    return a;
    return gcd(b,a%b);
}

int lcm(int a,int b)
{
    int k=gcd(a,b);
    a/=k;
    return a*b;
}

vector<pair<int,int> > vec;

int main() {
    ofstream fout ("o.out");
    ifstream fin ("in.in");
    int tetC;
    fin >> tetC;
    for(int cnt = 0; cnt < tetC; cnt++)
    {
    	int num , cur;
    	fin >> num >> cur;
    	vec.clear();
    	int lm = 1;
    	for(int ct = 0; ct < num; ct++)
    	{
    		fin >> arr[ct];
    		lm = lcm(lm , arr[ct]);
    	}

		int fc = 0;
		for(int ct = 0; ct < num; ct++)
		fc += (lm/arr[ct]);
		
		cur %= fc;
		if(cur == 0)
		cur = fc;
		
		
		for(int ct = 0; ct < num; ct++)
		{
			int curv = 0;
			while(curv <= lm)
			{
				curv += arr[ct];
				vec.push_back( make_pair( curv,ct+1) );
			}
		}
		sort(vec.begin(), vec.end());		

		int ret = 0;
		if(cur <= num)
		ret = cur;
		else
		{
			cur -= num;
			ret = vec[cur-1].second;
		}
		
		

    	
    	fout << "Case #" << cnt+1 << ": " << ret << endl; 
     }
    return 0;
}

