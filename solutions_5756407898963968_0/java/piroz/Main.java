package qualificationA;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int test_case_num = sc.nextInt();
		for(int test_case=0;test_case<test_case_num;test_case++) {
			boolean[] ok = new boolean[16];
			Arrays.fill(ok, true);
			for(int i=0;i<2;i++) {
				int a = sc.nextInt()-1;
				int[][] m = new int[4][4];
				for(int y=0;y<4;y++) {
					for(int x=0;x<4;x++) {
						m[y][x] = sc.nextInt()-1;
						if (y!=a) {
							ok[m[y][x]] = false;
						}
					}
				}
			}
			int count = 0;
			int index = -1;
			for(int i=0;i<16;i++) {
				if (ok[i]) {
					count++;
					index = i;
				}
			}
			if (count == 1) {
				out(index+1);
			}else if(count == 0) {
				out("Volunteer cheated!");
			}else{
				out("Bad magician!");
			}
		}
	}
	
	public static int outnum = 0;
	public static void out(String s) {
		outnum++;
		System.out.println("Case #" + outnum + ": " + s);
	}
	public static void out(int i) {
		out(Integer.toString(i));
	}
}
