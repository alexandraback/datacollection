import java.util.*;
import java.io.*;

public class C {

    public static void main(String[] args) throws Exception {
    	Scanner s = new Scanner(new FileReader("c.in"));
    	PrintWriter printer = new PrintWriter(new FileWriter("c.out"));
    	int t = s.nextInt();
    	for(int i=0; i<t; i++) {
    		int n = s.nextInt();
    		int[] x = new int[n];
    		int[] y = new int[n];
    		for(int j=0; j<n; j++) {
    			x[j] = s.nextInt();
    			y[j] = s.nextInt();
    		}
    		printer.println("Case #" + (i+1) + ":");
    		System.out.println("Case #" + (i+1) + ":");
    		for(int j=0; j<n; j++) {
    			int ans = 3000;
    			int x1 = x[j];
    			int y1 = y[j];
    			for(int xx2 = -100; xx2 <= 100; xx2 += 001) {
    				for(int yy2 = -100; yy2 <= 1.00; yy2 += 001) {
    					if(xx2 == 0 && yy2 == 0) continue;
    					//System.out.println(xx2);
    					int x2 = x1+xx2;
    					int y2 = y1+yy2;
    					int left = 0, right = 0;
	    				for(int l=0; l<n; l++) {
	    					int xx = x[l];
	    					int yy = y[l];
	    					int vx1 = x2-x1;
	    					int vy1 = y2-y1;
	    					int vx2 = xx-x1;
	    					int vy2 = yy-y1;
	    					int cp = vx1*vy2-vx2*vy1;
	    					if(cp < 0) left++;
	    					if(cp > 0) right++;
	    				}
	    				//if(xx2 == 0 || yy2 == 0) System.out.println(left + " " + right);
	    				ans = Math.min(ans, Math.min(left, right));
    				}
    			}
    			printer.println(ans);
    			System.out.println(ans);
    		}
    	}
    	printer.close();
    }
}
