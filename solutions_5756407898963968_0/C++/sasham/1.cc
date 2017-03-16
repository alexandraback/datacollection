#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

#include <vector>

using namespace std;

int main(void)
{
   int T;
   string str; 
   
   int r;
   
   int v1[4];
   int v2[4];

   vector<int>::iterator it;
      

   cin >> T; getline(cin, str);
//	 cout << "[[[[[[" << str << "]]]]]]" << endl;
   for (int t = 1; t <= T; t++ )
   {
      cout << "Case #" << t << ": ";
      
      cin >> r; getline(cin, str);
//	 cout << "[[[[[[" << str << "]]]]]]" << endl;
      for (int i = 1; i <=4; i++ )
      {
	 if ( r == i ) 
   	   cin >> v1[0] >> v1[1] >> v1[2] >> v1[3];

	 getline(cin, str);
//	 cout << "[[[[[[" << str << "]]]]]]" << endl;
      }
//      cout << "v1: " << v1[0] << "  " << v1[1] << "  "<< v1[2] << "  "<< v1[3] << endl;
      sort (v1,v1+4);
//      cout << "v1': " << v1[0] << "  " << v1[1] << "  "<< v1[2] << "  "<< v1[3] << endl;
      
      cin >> r; getline(cin, str);
//	 cout << "[[[[[[" << str << "]]]]]]" << endl;
      for (int i = 1; i <=4; i++ )
      {
	 if ( r == i ) 
  	   cin >> v2[0] >> v2[1] >> v2[2] >> v2[3];
	 getline(cin, str);
//         cout << "[[[[[[" << str << "]]]]]]" << endl;
      }
      
//      cout << "v2: " << v2[0] << "  " << v2[1] << "  "<< v2[2] << "  "<< v2[3] << endl;
      sort (v2,v2+4);
//      cout << "v2': " << v2[0] << "  " << v2[1] << "  "<< v2[2] << "  "<< v2[3] << endl;
      
      vector<int> v(4); 
      it = set_intersection (v1, v1+4, v2, v2+4, v.begin());
      v.resize(it-v.begin());
      
      if ( v.size() == 1)
        cout << v[0];
      else 
      {	
	if ( v.size() > 1)
	{   
	  cout << "Bad magician!";
	   
//	  for (it=v.begin(); it!=v.end(); ++it)
//	    cout << "               " << *it;
	}
	  
	else
	  cout << "Volunteer cheated!";
      }
      
      cout << endl;
   }
   
   return 0;
}



