package round_one_B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class B {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("C:\\Users\\Valentin\\workspace_luna\\CodeJam\\src\\B-small-attempt5.in"));
		System.setOut(new PrintStream(new File("C:\\Users\\Valentin\\workspace_luna\\CodeJam\\src\\test.out")));

		int t = sc.nextInt();
		for (int k = 0; k < t; k++) {
			int r = sc.nextInt();
			int c = sc.nextInt();
			int nTenants = sc.nextInt();
			long counter = 0;
			boolean[][] tenants = new boolean[r][c];
			
			if (r % 2 == 1 && c % 2 == 1 && nTenants <= (int)Math.ceil((r*c)/2.0) + 1 && nTenants >= (int)Math.ceil((r*c)/2.0)) {
				if (r == 1 && c == 1) {
					System.out.println("Case #" + (k+1) + ": 0");
				}
				else if (nTenants == (int)Math.ceil((r*c)/2.0) + 1) {
					System.out.println("Case #" + (k+1) + ": 3");
				}
				else System.out.println("Case #" + (k+1) + ": 0");
				continue;
			}
			for (int i = 0; i < c && nTenants > 0; i++) {
				for (int j = (i+1) % 2; j < r && nTenants > 0; j = j+2, nTenants--) {
					tenants[j][i] = true;
				}
			}
			if (nTenants != 0) {
				if (r == 1) {
					if (c % 2 == 0) {
						counter++;
						nTenants--;
					}
					else {
						if (nTenants > 1) {
							counter += 2;
							nTenants -= 2;
						}
						else {
							counter++;
							nTenants--;
						}
					}
				}
				else if (c == 1) {
					if (r % 2 == 0) {
						counter++;
						nTenants--;
					}
					else {
						if (nTenants > 1) {
							counter += 2;
							nTenants -= 2;
						}
						else {
							counter++;
							nTenants--;
						}
					}
				}
				//coins
				if (r % 2 == 0 && c % 2 == 0) {
					if (nTenants >= 2) {
						counter += 4;
						nTenants -= 2;
					}
					else {
						counter += nTenants*2;
						nTenants = 0;
					}
				}
				else if (r % 2 == 0 && c % 2 == 1) {
					if (nTenants >= 2) {
						counter += 4;
						nTenants -= 2;
					}
					else {
						counter += nTenants*2;
						nTenants = 0;
					}
				}
				else if (r % 2 == 1 && c % 2 == 0) {
					if (nTenants >= 2) {
						counter += 4;
						nTenants -= 2;
					}
					else {
						counter += nTenants*2;
						nTenants = 0;
					}
				}
				else {
					if (nTenants >= 4) {
						counter += 8;
						nTenants -= 4;
					}
					else {
						counter += nTenants*2;
						nTenants = 0;
					}
				}
			}
			
			if (nTenants > 0) {
				
				if (r == 1 || c == 1) {
					counter = counter + 2*nTenants;
					System.out.println("Case #" + (k+1) + ": " + counter);
					continue;
				}
				
				//murs
				if (r % 2 == 0 && c % 2 == 0) {
					int haut = (int)Math.ceil(c/2.0) - 1;
					int bas = (int)Math.ceil(c/2.0) - 1 - 0;
					int gauche = (int)Math.ceil(r/2.0) - 1;
					int droite = (int)Math.ceil(r/2.0) - 1 - 0;
					int total = haut + bas + droite + gauche;
					if (nTenants >= total) {
						counter += 3*total;
						nTenants -= total;
					}
					else {
						counter += nTenants*3;
						nTenants = 0;
					}
				}
				else if (r % 2 == 0 && c % 2 == 1) {
					int haut = (int)Math.ceil(c/2.0) - 2;
					int bas = (int)Math.ceil(c/2.0) - 1 - 0;
					int gauche = (int)Math.ceil(r/2.0) - 1;
					int droite = (int)Math.ceil(r/2.0) - 0 - 1;
					int total = haut + bas + droite + gauche;
					if (nTenants >= total) {
						counter += 3*total;
						nTenants -= total;
					}
					else {
						counter += nTenants*3;
						nTenants = 0;
					}
				}
				else if (r % 2 == 1 && c % 2 == 0) {
					int haut = (int)Math.ceil(c/2.0) - 1;
					int bas = (int)Math.ceil(c/2.0) - 0 - 1;
					int gauche = (int)Math.ceil(r/2.0) - 2;
					int droite = (int)Math.ceil(r/2.0) - 1 - 0;
					int total = haut + bas + droite + gauche;
					if (nTenants >= total) {
						counter += 3*total;
						nTenants -= total;
					}
					else {
						counter += nTenants*3;
						nTenants = 0;
					}
				}
				else {
					int haut = (int)Math.ceil(c/2.0) - 2;
					int bas = (int)Math.ceil(c/2.0) - 0 - 2;
					int gauche = (int)Math.ceil(r/2.0) - 2;
					int droite = (int)Math.ceil(r/2.0) - 0 - 2;
					int total = haut + bas + droite + gauche;
					if (nTenants >= total) {
						counter += 3*total;
						nTenants -= total;
					}
					else {
						counter += nTenants*3;
						nTenants = 0;
					}
				}
			}
			counter = counter + 4*nTenants;
			System.out.println("Case #" + (k+1) + ": " + counter);
		}
	}

}
