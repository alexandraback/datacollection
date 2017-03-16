#include <algorithm>
#include <iostream>

int main( )
{
   int t;
   std::cin >> t;
   
   for (int ti = 0; ti < t; ++ti) {
      int f1, c1[4][4];
      std::cin >> f1;
      
      for (int i = 0; i < 4; ++i) {
         for (int j = 0; j < 4; ++j) {
            std::cin >> c1[i][j];     
         }
      }
      
      int f2, c2[4][4];
      std::cin >> f2;
      
      for (int i = 0; i < 4; ++i) {
         for (int j = 0; j < 4; ++j) {
            std::cin >> c2[i][j];     
         }
      }
      
      auto fila1 = c1[f1 - 1];
      auto fila2 = c2[f2 - 1];

      int interseccion[4];
      
      std::sort(fila1, fila1 + 4);
      std::sort(fila2, fila2 + 4);

      std::cout << "Case #" << ti + 1 << ": ";
      
      switch (std::set_intersection(fila1, fila1 + 4, fila2, fila2 + 4, interseccion) - interseccion) {
      case 0:
         std::cout << "Volunteer cheated!";
         break; 
      case 1:
         std::cout << interseccion[0];
         break;   
      default:
         std::cout << "Bad magician!";     
      }
      
      std::cout << '\n';
   }
}
