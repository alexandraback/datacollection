import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class A {

	public static void main(String[] args) throws Exception {
		new A().run();
	}

	private void run() throws Exception {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(new File("src\\input.txt"));
		PrintWriter pw = new PrintWriter("output.txt");
		int tc = sc.nextInt();
		for (int t = 1; t <= tc; t++) {
			int[] was = new int[16];
			int r1 = sc.nextInt() - 1;
			
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++) {
					int x = sc.nextInt() - 1;
					if (i == r1)
						was[x]++;
				}
			r1 = sc.nextInt() - 1;
			
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++) {
					int x = sc.nextInt() - 1;
					if (i == r1)
						was[x]++;
				}
			int cnt = 0;
			int bi = -1;
			for (int i = 0; i < 16; i++)
				if (was[i] == 2) {
					bi = i + 1;
					cnt++;
				}
			if (cnt == 0)
				pw.printf("Case #%d: Volunteer cheated!\n", t);
			if (cnt == 1)
				pw.printf("Case #%d: %d\n", t, bi);
			if (cnt > 1)
				pw.printf("Case #%d: Bad magician!\n", t);
		}
		pw.close();
	}

}
