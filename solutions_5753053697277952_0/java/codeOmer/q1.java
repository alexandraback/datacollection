import java.util.*;
import java.io.*;

public class q1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int t = in.nextInt();
		for (int i=1; i<=t; i++) {
			System.out.print("Case #" + i + ":");
			int parties=in.nextInt();
			int[] members = new int[parties];
			for (int k=0; k<parties; k++) {
				members[k]=in.nextInt();
			}
			while (!emptyarray(members)) {
				System.out.print(" ");
				int max = maxArray(members);
				int count=0;
				for (int j=0; j<parties; j++) {
					if (members[j]==max && count<2) {
						if (count!=1 || numberLeft(members)!=2) {
							System.out.print((char)('A'+j));
							members[j]--;
							count++;
						}
					}
				}
			}
			if (i<t) System.out.println();

		}


	}

	public static int numberLeft(int[] arr) {
		int count=0;
		for (int i=0; i<arr.length; i++) {
			count+=arr[i];
		}
		return count;
	}

	public static boolean emptyarray(int[] arr) {
		for (int i=0; i<arr.length; i++) {
			if (arr[i]>0) return false;
		}
		return true;
	}

	public static int maxArray(int[] arr) {
		int max=-1;
		for (int i=0; i<arr.length; i++) {
			if (arr[i]>max) max=arr[i];
		}
		return max;
	}

}
