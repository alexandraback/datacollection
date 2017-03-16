package codejam2015;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;

public class NoisyNeightbors {
	private static BufferedWriter bw;
	private static int R;
	private static int C;

	public static void main(String[] args) throws IOException {

		Scanner sc = new Scanner(new File("in.txt"));
		File fout = new File("out.txt");
		FileOutputStream fos = new FileOutputStream(fout);
		bw = new BufferedWriter(new OutputStreamWriter(fos));

		int T = sc.nextInt();

		for (int t = 0; t < T; t++) {
			R = sc.nextInt();
			C = sc.nextInt();
			int N = sc.nextInt();

			boolean[][] array = new boolean[R][C];
			// start at full
			int full = R * C;
//			for (int i = 0; i < R; i++) {
//				for (int j = 0; j < C; j++) {
//					array[i][j] = true;
//				}
//
//			}

			System.out.println("-------------------------");
			if (full==N){
				for (int i = 0; i < R; i++) {
					for (int j = 0; j < C; j++) {
						array[i][j] = true;
					}
	
				}
				out(t,happiness(array)+"");
				continue;
			}
			
			int x8 = -1, y8 = -1, x9 = -1, y9 = -1;


			// System.out.println("first:"+first);
//			boolean[][] copy = new boolean[R][C];
//			top: for (int k = 0; k < R; k++) {
//				for (int l = 0; l < C; l++) {
//					copy[k][l] = array[k][l];
//				}
//			}
			int min = Integer.MAX_VALUE;
			;
			for (int hh = 0; hh < 100; hh++) {
				//System.out.println(hh);
				array=new boolean[R][C];
				for (int mm=0;mm<N;mm++){
//					for (int j = 0; j < C; j++) {
//						for (int i = 0; i < R; i++) {
//							if (array[i][j])
//								System.out.print("X");
//							else
//								System.out.print(".");
//						}
//						System.out.println();
//					}
					do{
						
						//System.out.println(mm+" "+N+" "+hh+" "+R+" "+C);
					x8 = (int) (Math.random() * R);
					y8 = (int) (Math.random() * C);
					//System.out.println(x8+" "+y8+" "+array[x8][y8]);
					}while(array[x8][y8]);
					array[x8][y8]=true;
					
					
					
				}
				
					int first = happiness(array);
					for (int jj = 0; jj < 10000; jj++) {
						x8 = (int) (Math.random() * R);
						x9 = (int) (Math.random() * R);
						y8 = (int) (Math.random() * C);
						y9 = (int) (Math.random() * C);
						array = swap(x8, y8, x9, y9, array);
						int hap = happiness(array);
						if (hap < first) {
							first = hap;
						} else
							array = swap(x8, y8, x9, y9, array);
						// swap(x4, y4, x5, y5, array);
					}
				
				int hap = happiness(array);
				if (hap < min){
					min = hap;
					//System.out.println("new min :"+min);

					
				}
					
			}

			for (int j = 0; j < C; j++) {
				for (int i = 0; i < R; i++) {
					if (array[i][j])
						System.out.print("X");
					else
						System.out.print(".");
				}
				System.out.println();
			}
			// int total = happiness(array);
			out(t, min + "");

		}

		bw.close();

	}

	private static boolean[][] swap(int x4, int y4, int x5, int y5,
			boolean[][] array) {
		// System.out.println(x4+" "+y4+" "+x5+" "+y5);
		boolean temp = array[x4][y4];
		array[x4][y4] = array[x5][y5];
		array[x5][y5] = temp;
		return array;

	}

	public static int neighbor(int x, int y, boolean[][] array) {
		int cnt = 0;
		if (x - 1 >= 0 && array[x - 1][y])
			cnt++;
		if (y - 1 >= 0 && array[x][y - 1])
			cnt++;
		if (x + 1 < R && array[x + 1][y])
			cnt++;
		if (y + 1 < C && array[x][y + 1])
			cnt++;

		return cnt;
	}

	public static int happiness(boolean[][] array) {
		int total = 0;
		for (int k = 0; k < R; k++) {
			for (int l = 0; l < C; l++) {
				if (array[k][l]) {
					if (k - 1 >= 0 && array[k - 1][l])
						total++;
					if (l - 1 >= 0 && array[k][l - 1])
						total++;
					if (k + 1 < R && array[k + 1][l])
						total++;
					if (l + 1 < C && array[k][l + 1])
						total++;
				}
			}

		}

		return total / 2;

	}

	public static void out(int t, String out) throws IOException {
		String s = "Case #" + (t + 1) + ": " + out;
		System.out.println(s);
		bw.write(s + "\n");
	}
}
