        #include <fstream>
        #include <iostream>
        #include <string>
        #include <stdio.h>
        #include <math.h>
        
        
        
        using namespace std;
        
        int main()
        {
            ofstream fout ("2015gcj2out.txt");
            ifstream fin ("2015gcj2in.txt");
            
            
            int t;
            
            int b, n;
            
            int posaux;
            long long mintime;
            double s;
            double aux2;
            long long aux3;
            double n2;
            long long max;
           
            
           fin >> t;
                      
                      
            for(int i=0; i<t; i++)
            {
            fin >> b;
            fin >> n;
            
     //     fout << n << endl;
            
            long long m[b];
            double m2[b];
            
            long long aux[b];
            
            s = 0.0000000000;
            
            max = 0;
            
            for(int j=0; j<b; j++)
            {
            fin >> m[j];
            if(m[j] > max)
            max= m[j];
        //   fout << m[j] << " ";
            m2[j] = (double)m[j];
            s = s + 1/m2[j];
            
            }
            
       //     fout << endl;
            
            n2 = (double)n;
            
            s = n2/s;
            
            s = s-max;
            
            if(s < 0)
            s = 0.000000;
            
           
            
        
            
            for(int j=0; j<b; j++)
            {
            aux2 = s/m[j];
            aux3 = (int)aux2;
            if(aux3 < 0)
            aux3 =0;
            aux[j]= m[j]*aux3;
        //  fout << aux[j] << " ";
            n = n - aux3;
            }
            
         //   fout << endl;
         //   fout << n << endl;
            
            for(int l=0; l<n; l++)
            {
            posaux = 1;
            mintime = aux[0];
            
            for(int j=0; j<b; j++)
            if( aux[j] < mintime)
            {
            posaux = j+1;
            mintime = aux[j];
            }
            
            aux[posaux-1] = aux[posaux-1] + m[posaux-1];
            }
            
            
            fout << "Case #" << i+1 << ": " << posaux << endl;
            }            
                                   
            
            return 0;
            
        }
        
        
