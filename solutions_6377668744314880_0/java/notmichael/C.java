import java.util.*;

public class C {

	public static void main(String[] args) {
		C c = new C();
		c.run();
	}

	public void run() {
		Scanner in = new Scanner(System.in);
		int cases = Integer.parseInt(in.nextLine());
		for (int a=0; a<cases; a++) {
			int numT = Integer.parseInt(in.nextLine());
			int[][] trees = new int[numT][2];
			int[] minV = new int[2];
			int[] maxV = new int[2];
			for (int i=0; i<numT; i++) {
				String[] split = in.nextLine().split(" ");
				for (int j=0; j<2; j++) {
					trees[i][j] = Integer.parseInt(split[j]);
					minV[j] = Math.min(minV[j],trees[i][j]);
					maxV[j] = Math.max(maxV[j],trees[i][j]);
				}
			}
			int[][] dom = new int[numT][4];
			int[][] dom2 = new int[numT][4];
			for (int i=0; i<numT; i++) {
				for (int j=i+1; j<numT; j++) {
					if (trees[i][0] <= trees[j][0]) {
						if (trees[i][1] <= trees[j][1]) {
							dom[i][0]++;
							dom[j][2]++;
						}
						if (trees[i][1] >= trees[j][1]) {
							dom[i][1]++;
							dom[j][3]++;
						}
					}
					if (trees[i][0] >= trees[j][0]){
						if (trees[i][1] <= trees[j][1]) {
							dom[i][3]++;
							dom[j][1]++;
						}
						if (trees[i][1] >= trees[j][1]) {
							dom[i][2]++;
							dom[j][0]++;
						}
					}
					if (trees[i][0] < trees[j][0]) {
						dom2[i][0]++;
						dom2[j][2]++;
					}
					else if (trees[i][0] < trees[j][0]) {
						dom2[i][2]++;
						dom2[j][0]++;
					}
					if (trees[i][1] < trees[j][1]) {
						dom2[i][3]++;
						dom2[j][1]++;
					}
					else if (trees[i][1] < trees[j][1]) {
						dom2[i][1]++;
						dom2[j][3]++;
					}
				}
			}
			System.out.println("Case #" + (a+1) + ":");
			for (int i=0; i<numT; i++) {
				if (trees[i][0]==minV[0] || trees[i][0]==maxV[0] || trees[i][1]==minV[1] || trees[i][1]==maxV[1]) {
					System.out.println("0");
				}
				else {
					int min = numT;
					for (int j=0; j<4; j++) {
						min = Math.min(min,dom[i][j]);
						min = Math.min(min,dom2[i][j]);
					}
					System.out.println(min);
				}
			}
		}
	}

}