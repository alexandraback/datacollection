import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.Scanner;

public class Solution {
	static void solve(InputStream in) {
		Scanner scn = new Scanner(in);
		int numcases = scn.nextInt();
		for(int i = 1; i <= numcases; ++i) {
			solveCase(scn, i);
		}
	}

	static void solveCase(Scanner in, int casenumber) {
		int l0 = in.nextInt();
		int[] l0Cards = new int[4];
		for(int i = 1; i < l0; ++i) {
			for(int j = 0; j < 4; j++)
				in.nextInt();
		}
		for(int i = 0; i < 4; ++i) {
			l0Cards[i] = in.nextInt();
		}
		for(int i = l0; i < 4; ++i) {
			for(int j = 0; j < 4; j++)
				in.nextInt();			
		}

		int l1 = in.nextInt();
		int[] l1Cards = new int[4];
		for(int i = 1; i < l1; ++i) {
			for(int j = 0; j < 4; j++)
				in.nextInt();
		}
		for(int i = 0; i < 4; ++i) {
			l1Cards[i] = in.nextInt();
		}
		for(int i = l1; i < 4; ++i) {
			for(int j = 0; j < 4; j++)
				in.nextInt();			
		}

		int answer = -1;
		for(int i = 0; i < 4; ++i) {
			for(int j = 0; j < 4; ++j) {
				if(l0Cards[i] == l1Cards[j]) {
					if(answer == -1) {
						answer = l0Cards[i];
					} else {
						System.out.println("Case #" + casenumber + ": " + "Bad magician!");
						return;
					}
				}
			}
		}

		if(answer == -1) {
			System.out.println("Case #" + casenumber + ": " + "Volunteer cheated!");
		} else {
			System.out.println("Case #" + casenumber + ": " + answer);
		}
	}

	public static void main(String[] args) {
		String infile;
		if(args.length == 0) {
			Scanner scn = new Scanner(System.in);
			infile = scn.nextLine();
		} else {
			infile = args[0];
		}
		
		InputStream is;

		try {
			is = new FileInputStream(infile);
			
			solve(is);

			is.close(); 
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
