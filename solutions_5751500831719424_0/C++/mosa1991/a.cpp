#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

int main()
{
	int N,r,cas=0;
	cin >> N;
	for(int tes=0;tes<N;tes++)
	{
	   cas++;
           cout << "Case #" <<cas << ": ";
	   cin >> r;
	   bool istrue = true;
	   vector<string> s(r);
	   for(int i=0;i<r;i++)
		cin >> s[i];
	   int a[r][100];
	   int b[r][100];
	   for(int j=0;j<r;j++)
	   for(int i=0;i<100;i++)
	   {
		a[j][i] = 0;
		b[j][i] = -1;
	   }
	   int k[r];
	   for(int j=0;j<r;j++)
	   {	 a[j][0] = 1;
	  	 b[j][0] = s[j][0]-'a';
		 k[j] = 0;
	  	 for(int i=1;i<s[j].length();i++)
	  	 {
			if(s[j][i] == s[j][i-1])
			  a[j][k[j]]++;
			else
			{
			 k[j]++;
		   	 b[j][k[j]] = s[j][i]-'a';
		   	 a[j][k[j]] = 1;
			}
	   	}
	   }
	   for(int i=0;i<r-1;i++)
	   {
		if(k[i]!=k[i+1])
		{
			istrue = false;
			break;
		}
           }
	   if(!istrue)
	   {
		cout << "Fegla Won" << endl;
		continue;
	   }
	   for(int i=0;i<r-1;i++)
	   {
		for(int j=0;j<=k[0];j++)
		{
		   if(b[i][j] != b[i+1][j])
		   {
			istrue = false;
			break;
		   }
		}
		if(!istrue)
			break;
	   }

	  if(!istrue)
	  {
		cout << "Fegla Won" << endl;
		continue;
	  }
	  int sum = 0;
	  for(int j=0;j<=k[0];j++)
	  {
		int ma=0;
		for(int i=0;i<r;i++)
		{
		    ma = max(ma,a[i][j]);
		}
		int cal,min1=1000000;
		for(int i=1;i<=ma;i++)
		{
		   cal = 0;
		   for(int p=0;p<r;p++)
		    cal += abs(a[p][j]-i);
		   min1 = min(min1,cal);
		}
		sum += min1;
	  }
		cout << sum << endl;
	
	}
return 0;
}
