        #include <fstream>
        #include <iostream>
        #include <string>
        #include <stdio.h>
        
        using namespace std;
        
        int main()
        {
            ofstream fout ("2015gcj3out.txt");
            ifstream fin ("2015gcj3in.txt");
            
            int t;
            int n;
            int res;
            int aux1;
          
                        
            fin >> t;
           
            for(int i=0; i<t; i++)
            {
            
            fin >> n;
            
          //  fout << n << endl;
            
            long long x[n];
            long long y[n];
            
            fout << "Case #" << i+1 << ":" << endl;
            
            long long dx, dy;
           
            for(int j=0; j<n; j++)
            {
            fin >> x[j];
            fin >> y[j];
       //     fout << x[j] << " ";
      //      fout << y[j];
        //    fout << endl;
            }
            
            for(int j=0; j<n; j++)
            {
            res = 4000;
            
            
            for(int l=0; l<n;l++)
            {
            aux1 = 0;
            
            dx = y[l]-y[j];
            dy = x[j]-x[l];
            for(int k=0; k<n; k++)
            if(k != l && j != l && k != j)
            if( dx*(x[j]-x[k]) + dy*(y[j]-y[k]) < 0)
            {
            aux1++;
        //    fout << j << " " << l << " " << k << endl;
            }
            
            if(aux1 < res && l != j)
            res = aux1;
            }
            
            
            
            for(int l=0; l<n;l++)
            {
            aux1 = 0;
            dx = -y[l]+y[j];
            dy = -x[j]+x[l];
            for(int k=0; k<n; k++)
            if(k != l && j != l && k != j)
            if( dx*(x[j]-x[k]) + dy*(y[j]-y[k]) < 0)
            {
            aux1++;
        //    fout << j << " " << l << " " << k << endl;
            }
            
            if(aux1 < res && l!=j)
            res = aux1;
            }
            
           
            
            if(n > 3)
            fout << res << endl;
            else
            fout << 0 << endl;
            }
            
            
            } 
            return 0;
            
        }
        
        

