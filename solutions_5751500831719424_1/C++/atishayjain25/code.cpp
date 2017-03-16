#include<iostream>
#include<string.h>
using namespace std;

struct str_prop
{
	int chars;
	char c_array[110];
	int c_count[110];
};

int main()
{
	int t;
	cin>>t;
	int n;
	str_prop properties[110];
	char str[120][120];
	int optimal[110];
	int toSort[110];
	for(int cases =1; cases <= t; cases ++)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>str[i];
		}
		//for(int i=0;i<n;i++)
			//cout<<str[i]<<" "<<strlen(str[i])<<endl;
		
		for(int i=0;i<n;i++)
		{
			char current='A';
			int count =-1;
			for(int j=0;j< strlen(str[i]); j++)
			{
				if(str[i][j] == current)
				{
					properties[i].c_count[count] ++;
				}
				else
				{
					count ++;
					properties[i].c_array[count] = str[i][j];
					properties[i].c_count[count] = 1;
					current = str[i][j];
				}
			}
			properties[i].chars = count+1;
		}
		
		int wins = 1;
		for(int i=1;i<n;i++)
		{
			if(properties[i].chars != properties[0].chars)
			{
				wins = 0;
				break;
			}
			for(int j=0;j<properties[i].chars;j++)
			{
				if(properties[i].c_array[j] != properties[0].c_array[j])
				{
					wins = 0;
					break;
				}
			}
			if(wins == 0)
				break;
		}
		
		int result = 0;
		
		/*for(int i=0; i< n;i++)
		{
			cout<<properties[i].chars<<endl;
			for(int j=0;j<properties[0].chars;j++)
			{
				cout<<properties[i].c_array[j]<<" :"<<properties[i].c_count[j]<<endl;
			}
			cout<<endl;
		}*/
		if(wins == 0)
			cout<<"Case #"<<cases<<": Fegla Won"<<endl;
		else
		{
			for(int j=0;j<properties[0].chars;j++)
			{
				for(int i=0;i<n;i++)				
				{
					toSort[i] = properties[i].c_count[j];
				}
				int tmp;
				for(int i=0;i<n;i++)
					for(int k = i+1; k<n; k++)
					{
						if(toSort[i] > toSort[k])
						{
							tmp = toSort[i];
							toSort[i] = toSort[k];
							toSort[k] = tmp;
						}
					}
				int median = toSort[n/2];
								
				/*for(int i=0;i<n;i++)
					cout<<toSort[i]<<" ";
				cout<<endl<<"Median: "<<median<<endl;*/		

				for(int i=0;i<n;i++)
				{
					if(toSort[i]> median)
						result += toSort[i]-median;
					else
						result += median - toSort[i];	
				}	
			}
			cout<<"Case #"<<cases<<": "<<result<<endl;			
		}	
	}
}
