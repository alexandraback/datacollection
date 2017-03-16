import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
 
public class Main {
 
	public static void main(String[] args) {
 
		BufferedReader br = null;
 
		try {
 
			br = new BufferedReader(new FileReader("A-small-attempt0.in"));

			
			int t = Integer.parseInt(br.readLine());
			
			for (int i = 0; i < t; i++) {
				int ans1 = Integer.parseInt(br.readLine()) - 1;
				
				int arr1[][] = new int[4][4];
				for (int j = 0; j < 4; j++) {
					String[] line = br.readLine().split(" "); 
					for (int k = 0; k < 4; k++) {
						arr1[j][k] = Integer.parseInt(line[k]);
					}
				}
				
				int ans2 = Integer.parseInt(br.readLine()) - 1;
				
				int arr2[][] = new int[4][4];
				for (int j = 0; j < 4; j++) {
					String[] line = br.readLine().split(" "); 
					for (int k = 0; k < 4; k++) {
						arr2[j][k] = Integer.parseInt(line[k]);
					}
				}
				
				
				int numOfMatches = 0;
				int match = 0;
				for (int j = 0; j < 4; j++) {
					for (int k = 0; k < 4; k++) {
						if (arr1[ans1][j] == arr2[ans2][k]) {
							numOfMatches++;
							match = arr1[ans1][j];
						}
					}
				}
				
				if (numOfMatches == 0) {
					System.out.println("Case #" + (i+1) + ": Volunteer cheated!");
				}
				else if (numOfMatches == 1) {
					System.out.println("Case #" + (i+1) + ": " + match);
				}
				else {
					System.out.println("Case #" + (i+1) + ": Bad magician!");
				}
			}
 
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)br.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		}
	}
}