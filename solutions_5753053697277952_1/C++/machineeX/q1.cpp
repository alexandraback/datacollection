#include<iostream>
#include<fstream>
using namespace std;


int arr[2][26];


int main()
{
	
	fstream fin,fout;
	fin.open("input.txt",ios::in);
	fout.open("output.txt",ios::out);
	
	int i,t;
	fin>>t;
	for(i=1;i<=t;i++)
	{

		int n,j,k,l;
		fin>>n;
		
		for(j=0;j<n;j++)
		{
			arr[0][j]=j;
			fin>>arr[1][j];
		}

/*
for(j=0;j<n;j++)
		{
			cout<<arr[0][j]<<" ";
			cout<<arr[1][j]<<"@ ";
		}
*/

		
		string str="";
		int sum=0;

		for(j=0;j<n;j++)
		{
			sum+=arr[1][j];
		}
				
		for(j=sum;j>0;j--)
		{
			int swap=0;
			for (k = 0 ; k < ( n - 1 ); k++)
  			{
    			for (l = 0 ; l < n - k - 1; l++)
    			{
      				if (arr[1][l] < arr[1][l+1])
      				{
        				swap       = arr[1][l];
        				arr[1][l]   = arr[1][l+1];
        				arr[1][l+1] = swap;
        				
        				swap       = arr[0][l];
        				arr[0][l]   = arr[0][l+1];
        				arr[0][l+1] = swap;
      				}
    			}
  			}
/*
cout<<endl;  			
  		
for(int z=0;z<n;z++)
		{
			cout<<arr[0][z]<<" ";
			cout<<arr[1][z]<<"@ ";
		}
		  e
		  	
 cout<<endl;*/
  			
			if(arr[1][0]!=arr[1][1])  
			{
				str+=65+arr[0][0];
  				arr[1][0]--;
  				str+=" ";
  		    }
  		    else if(j==3)
  		    {
  		    	str+=65+arr[0][0];
  				arr[1][0]--;
  				str+=" ";
  		    }
			else
			{
				str+=65+arr[0][0];
  				arr[1][0]--;
  				str+=65+arr[0][1];
  				arr[1][1]--;
  				str+=" ";
  				j--;
			}  	
		}
		
//cout<<str<<endl;






		fout<<"Case #"<<i<<": "<<str<<endl;
	}
	
	cout<<"done";
	return 0;
}
