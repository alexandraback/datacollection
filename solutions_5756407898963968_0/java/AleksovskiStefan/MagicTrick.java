import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class MagicTrick {
	
	public static void main(String[] args) {
        String base = "/home/stefan/";
        String input = base + "A-small-attempt0.in";
        String output = base + "A-small-attempt0.out";
        
        try {
			Scanner scan = new Scanner(new FileReader(input));
			PrintWriter write = new PrintWriter(output);
			
			int n = scan.nextInt();
			scan.nextLine();
			
			for (int i = 1; i <= n; i++) {
				write.write("Case #" + i + ": ");
				test(scan, write);
			}
			
			scan.close();
			write.close();
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
        
	}

	private static void test(Scanner scan, PrintWriter write) {
		int s1, s2;
		int[][] m1 = new int[4][4];
		int[][] m2 = new int[4][4];
		
		s1 = scan.nextInt();
		s1--;
		scan.nextLine();
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++)
				m1[i][j] = scan.nextInt();
			scan.nextLine();
		}
		
		s2 = scan.nextInt();
		s2--;
		scan.nextLine();
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++)
				m2[i][j] = scan.nextInt();
			scan.nextLine();
		}
		
		int k = 0;
		int c = -1;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(m1[s1][i] == m2[s2][j]){
					k++;
					c = m1[s1][i];
				}
			}
		}
		
		if(k == 1)
			write.print(c + "\n");	
		else if(k == 0)
			write.print("Volunteer cheated!\n");
		else
			write.print("Bad magician!\n");
		
	}
	
}
