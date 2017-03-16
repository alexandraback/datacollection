#include <iostream>
#include <string>

using namespace std;

int solve(int a1[4], int a2[4]);
void print(int result, int r);

int main()
{
    int n;
    int r1;
    int r2;
    int a1[4];
    int a2[4];
    int waste;
    int result;
    
    cin >> n;
    
    for(int r=0;r<n;r++)
    {
    	cin >> r1;
        for(int i=0;i<4;i++)
        {
        	for(int j=0;j<4;j++)
        	{
        		if(i==r1-1) cin >> a1[j];
            	else cin >> waste;
        	}
        }

		cin >> r2;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
        	{
        		if(i==r2-1) cin >> a2[j];
            	else cin >> waste;
        	}
        }        
        result = solve(a1,a2);
        print(result, r+1);
    }
    return 0;
}

int solve(int a1[4], int a2[4])
{
	int result = -1;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if(a1[i] == a2[j])
			{
				if(result==-1) result=a1[i];
				else return 0;
			}
		}
	}

    return result;
}

void print(int result, int r)
{
     cout << "Case #" << r;
     switch(result)
     {
           case 0:  cout << ": Bad magician!\n"; break;
           case -1:  cout << ": Volunteer cheated!\n"; break;
           default:  cout << ": " << result << endl; break;
     }
}
