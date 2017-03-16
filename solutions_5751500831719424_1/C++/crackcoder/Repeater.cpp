#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    
    int t;
     cin>>t;
	 for(int i=0;i<t;i++)
     {
     	int n;
     	cin>>n;
     	     	
     	vector<char> ch [n];
     	vector<int> count [n];
     	for(int j=0;j<n;j++){
     		string temp;
     		cin>>temp;
     		char cur;
     		int curct = 0;
     		for(int k=0;k<temp.length();k++){
     			if(temp[k]!=cur){
     				if(k!=0) 
					{
     					ch[j].push_back(cur);
     					count[j].push_back(curct);
     				}
     				
     				cur = temp[k];
     				curct = 1;
     			}
     			else{
     				curct ++;
     			}
     		}
     		ch[j].push_back(cur);
     		count[j].push_back(curct);
     	}
     	
     	int siz = -1;
     	bool possible = true;
     	for(int j=0;j<n;j++)
		{
     		if((siz!=-1)&&(siz != ch[j].size()))	{
     			possible = false; 
     			break;
     		}
     		else siz = ch[j].size();
     	}
     	
     	if(possible)
     	{
     		int change = 0;
     		
     		for(int j=0;j<siz;j++)
     		{
     			int nu[n];
     			char curchar;
     			bool charset = false;
     			for(int k=0;k<n;k++)
     			{
     				if(charset)
					{
						if(ch[k][j]!= curchar){						
     					possible = false;
     					break;
     					}
					}
     				nu[k] = count[k][j];
     				curchar = ch[k][j];
     				charset = true;
     			}
     			if(!possible) break;
     			sort(nu, nu + n);
     			
     			int first = 0;
     			int last = n-1;
     			int tempchange =0;
     			while(first<=last)
     			{
     				tempchange += (nu[last]-nu[first]);
     				first ++;
     				last --;
     			}
     			change += tempchange;
     		}
     		if(possible)
     		cout<<"Case #"<<i+1<<": "<<change<<endl;
     		else 
     		cout<<"Case #"<<i+1<<": Fegla Won"<<endl;
     	}
     	else
		{
     		cout<<"Case #"<<i+1<<": Fegla Won"<<endl;
     	}	
      }
	 return 0;     
}
