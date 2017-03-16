        #include <fstream>
        #include <iostream>
        #include <string>
        #include <stdio.h>
        #include <math.h>
        #include <limits>
        
        
        using namespace std;
        
        
        int main()
        {
            ofstream fout ("2015gcj1out.txt");
            ifstream fin ("2015gcj1in.txt");
            
            int t;
            int n;
            int max;
            
            int res1, res2;     
          
            fin >> t;      
            
            for(int i=0; i<t; i++)
            {
            
            fin >> n;
            
            int m[n];
            
            res1 = 0;
            res2 = 0;
            
            for(int j=0; j<n; j++)
            fin >> m[j];
            
            for(int j=0; j<n-1; j++)
            if(m[j+1]<m[j])
            res1 = res1+m[j]-m[j+1];
            
            max = 0;
            
            for(int j=0; j<n-1; j++)
            if( max < m[j]-m[j+1])
            max = m[j]-m[j+1];
            
            for(int j=0; j<n-1; j++)
            if(m[j] > max)
            res2 = res2+max;
            else
            res2 = res2 + m[j];         
            
            
            
            fout << "Case #" << i+1 << ": " << res1 << " " << res2 << endl;
            }
            
       
            
            return 0;
              
        }
        
        
