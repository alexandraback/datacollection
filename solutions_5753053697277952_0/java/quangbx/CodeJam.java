
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

public class CodeJam {
    static Scanner scan;
    static PrintWriter out;
    public static void main(String[] arg) {
        try {
            File file = new File("E:\\A-small-attempt1 (1).in");
            scan = new Scanner(file);
            out = new PrintWriter("E:\\data.out");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        int c = scan.nextInt();
        for(int i = 0; i < c; i++) {
//            out.println("Case #" + (i+1) + ": " + testcase());
			out.print("Case #" + (i+1) + ": ");
			testcase();
			out.println();
        }
        scan.close();
        out.close();
    }

    static void testcase() {
        int n = scan.nextInt();
        int[] A = new int[n];
        for(int i=0;i<n;i++)
            A[i] = scan.nextInt();
        if(n == 2) {
        	if(A[0] > A[1]) {
        		for(int i=0;i<A[0]-A[1];i++)
        			out.print("A ");
        	} else if(A[0] < A[1]) {
        		for(int i=0;i<A[1]-A[0];i++)
        			out.print("B ");
        	}
        	int min = A[0] > A[1] ? A[1] : A[0];
        	for(int i=0;i<min;i++)
        		out.print("AB ");
        } else {
        while(true) {
            int max = 0;
            for (int i=1;i<n;i++) {
                if(A[max] < A[i])
                    max = i;
            }
            if(max == n-2 && A[n-2] == 1 && A[n-1] == 1) {
                out.print((char)(n-2+'A') + "" + (char)(n-1+'A'));
                break;
            }
            out.print((char)(max+'A') + " ");
            A[max]--;
        }
        }
    }
}
