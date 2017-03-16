import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;


public class MainClass {
	
	public static void main(String[] args) throws IOException, InterruptedException {
		BufferedReader fr = new BufferedReader(new FileReader(new File("input.txt")));
		FileWriter fw = new FileWriter(new File("result.txt"));
		String firstLine = fr.readLine();
		int nbCases = Integer.parseInt(firstLine);
		for (int i =0; i<nbCases; i++){

			String line = fr.readLine();
			int R = Integer.parseInt(line.split(" ")[0]);
			int C = Integer.parseInt(line.split(" ")[1]);
			int N = Integer.parseInt(line.split(" ")[2]);
			
			
			int points=bruteforce(R,C,N);
			
			
			
			
			fw.write("Case #"+(i+1)+": "+points+"\n");
			
		}
		fw.close();
		System.out.println("finished");
	}

	private static int bruteforce(int r, int c, int n) {
		
		boolean[][] tenants = new boolean[r][c];
		
		return bruteforce( tenants, r,c,n,0);
		
		
	}

	private static int bruteforce(boolean[][] tenants, int r, int c, int n,
			int t) {

		if (t==r*c){
			int count =0;
			for (int i=0; i<r; i++){
				for (int j=0; j<c; j++){
					if (tenants[i][j]){
						count++;
					}
				}
			}
			if (count!=n){
				return 10*n;
			}
			else{
				int score =0;
				for (int i=0; i<r; i++){
					for (int j=0; j<c; j++){
						if (tenants[i][j]){
							if (i<r-1&&tenants[i+1][j]){
								score++;
							}
							if (j<c-1&&tenants[i][j+1]){
								score++;
							}
						}
					}
				}
				return score;
			}
		}

		int ti = t%r;
		int tj = t/r;
		tenants[ti][tj]=true;
		int s1 = bruteforce(tenants,r,c,n,t+1);
		tenants[ti][tj]=false;
		int s2 = bruteforce(tenants,r,c,n,t+1);
		return Math.min(s1, s2);
	}

}
