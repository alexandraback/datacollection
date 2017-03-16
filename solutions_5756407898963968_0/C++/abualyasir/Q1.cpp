#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int search(int a[2][4])
{
	int count=0,flag=-1;
	int count1=0;
	int number;
	for(int i=0;i<4;i++)
    {
    	 count=0;
    	 for(int j=0;j<4;j++)
    	   if(a[0][i]==a[1][j])
    	   {
    	    count++;
    	      number=a[0][i];
    	    }
    	    if(count>0)
    	      count1++;
       
           if(count==1)
           {
           	number=a[0][i];
           	 
           }
    }
    
      if(count1==0)
           return -1;
           if(count1>=2)
            return -2;
            if(count1==1)
             return number;
}
int main()
{
	ifstream in;
	in.open("how.txt");
	  ofstream out;
	  out.open("output.txt");
	  int tc;
	  in>>tc;
	  for(int t=0;t<tc;t++)
	  {
	  	out<<"Case #"<<(t+1)<<": ";
	  	int row1,row2;
	  	    in>>row1;
	  	    
	  	    int a[4][4];
	  	     int b[4][4];
	  	      
	  	        for(int i=0;i<4;i++)
	  	          for(int j=0;j<4;j++)
	  	           in>> a[i][j];
	  	           in>>row2;
	  	          
	  	           for(int i=0;i<4;i++)
	  	          for(int j=0;j<4;j++)
	  	           in>> b[i][j];
					 int c[2][4];
	  	            for(int i=0;i<4;i++)
	  	             c[0][i]=a[row1-1][i];
	  	             for(int i=0;i<4;i++)
	  	             c[1][i]=b[row2-1][i];
	  	            
	  	          int f=search(c);
	  	         
					if(f==-1)
					 out<<"Volunteer cheated!"<<endl;
					 if(f==-2)
					  out<<"Bad magician!"<<endl;
					  if(f>0)
					   out<<f<<endl;   
	  }
}
