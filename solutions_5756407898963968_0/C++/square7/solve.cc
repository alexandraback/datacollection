#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int tot;
  cin >> tot;
  for(int i = 0; i < tot; ++i)
    {
      cout << "Case #" << i+1 << ": ";
      int first, second;
      vector<int> vec;
      cin >> first;
      for(int j = 0; j < 4; ++j)
	{
	  for(int k = 0; k < 4; ++k)
	    {
	      int val;
	      cin >> val;
	      if (first==j+1)
		{
		  vec.push_back(val);
		}
	    }
	}
      cin >> second;
      int result=-1;
      int cnt=0;
      for(int j = 0; j < 4; ++j)
	{
	  for(int k = 0; k < 4; ++k)
	    {
	      int val;
	      cin >> val;
	      if(second==j+1)
		{
		  for(auto ele:vec)
		    {
		      if(val==ele)
			{++cnt; result=ele;}
		    }
		}
	    }
	}
      if(cnt==1)
	{cout << result << endl;}
      else if(cnt>1)
	{cout << "Bad magician!" << endl;}
      else
	{cout << "Volunteer cheated!" << endl;}
    }
}
