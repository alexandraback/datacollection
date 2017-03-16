/*
 * magician.cxx
 * 
 * Copyright 2014 albert <albert@APC5309>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
#include <iostream>
#include <string>
#include <map>
 
int main()
{
    std::map<std::string, int> wordcounts;
    int i, j, k, T, t, selection, guess, hits;
    int draw1[17];
    
	std::cin >> T ;
	
	for ( t=0; t<T; t++) {
		//clean arrays
		for (i=1;i<17;i++) {
			draw1[i]=0;
		}
		hits=0;
		guess=0;
		
		std::cin >> selection ;
		selection--;
		for (i=0; i<4 ; i++ ) {
			for (j=0 ; j<4 ; j++ ) {
				std::cin >> k ;		
				if (i==selection) {
					draw1[k]=1;
				}
			}
		}

		std::cin >> selection ;
		selection--;
		for (i=0; i<4 ; i++ ) {
			for (j=0 ; j<4 ; j++ ) {
				std::cin >> k ;		
				if (i==selection) {
					if (draw1[k]==1) {
						guess=k;
						hits++;
					};
				}
			}
		}
		
		std::cout << "Case #" << (t+1) << ": ";
		switch (hits)
		{
			case 0 :
				std::cout << "Volunteer cheated!";
				break;
			case 1 :
				std::cout << guess;
				break;
			default :
				std::cout << "Bad magician!";
		}
		std::cout << "\n";
	}
}
