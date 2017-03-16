import java.util.*;
import java.lang.*;

public class MagicTrick{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int num_problems = Integer.parseInt(scan.nextLine());
		for(int i = 1; i <= num_problems; i++) {
			int[] row0 = new int[4];
			int[] row1 = new int[4];
			
			for (int j = 0; j < 2; j++) {
				int loc = Integer.parseInt(scan.nextLine());
				for(int k = 0; k < 4; k++) {
					String row = scan.nextLine();
					if ( k + 1 == loc ) {
						String[] row_s = row.split(" ");						
						for(int l = 0; l < 4; l++){
							(j == 0 ? row0 : row1)[l] = Integer.parseInt(row_s[l]);
						}
					}
				}
			}			
			inspect(row0, row1, i);
		}
		scan.close();
		
	}
	
	public static void inspect(int[] row0, int[] row1, int i){
		int sol = -1;
		for(int j = 0; j < 4; j++) {
			for(int k = 0; k < 4; k++) {
				if(row0[j] == row1[k]) {
					if(sol == -1)
						sol = row0[j];
					else {
						System.out.println("Case #" + i + ": Bad magician!");
						return;
					}
				}
			}
		}
		if (sol == -1)
			System.out.println("Case #" + i + ": Volunteer cheated!");
		else
			System.out.println("Case #" + i + ": " + sol);
	}
}