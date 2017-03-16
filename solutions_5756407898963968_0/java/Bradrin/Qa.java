import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class Qa {
	
	public void populate(Scanner scan, int[] array) {
		int row = scan.nextInt();
		scan.nextLine();
		for (int i = 1; i < row; i++) {
			scan.nextLine();
		}
		for (int i = 0; i < 4; i++) {
			array[i] = scan.nextInt();
		}
		scan.nextLine();
		for (int i = row; i < 4; i++) {
			scan.nextLine();
		}
	}
	
	public void solve(Scanner scan, PrintWriter out) {
		int[] array1 = new int[4];
		int[] array2 = new int[4];
		populate(scan, array1);
		populate(scan, array2);
		int result = -1;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (array1[i] == array2[j]) {
					if (result == -1) {
						result = array1[i];
					} else {
						System.out.println("Bad magician!");
						out.println("Bad magician!");
						return;
					}
				}
			}
		}
		if (result == -1) {
			System.out.println("Volunteer cheated!");
			out.println("Volunteer cheated!");
			return;
		}
		System.out.println(result);
		out.println(result);
	}
	
	public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(new FileReader("inputqa.in"));
        PrintWriter out = new PrintWriter("outputqa.txt");
        int problems = scan.nextInt();
        for (int count = 0; count < problems; count++) {
            System.out.print("Case #" + (count+1) + ": ");
            out.print("Case #" + (count+1) + ": ");
            new Qa().solve(scan, out);
        }
        out.flush();
        out.close();
        scan.close();
    }
	
}