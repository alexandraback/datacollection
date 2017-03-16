import java.io.File;
import java.util.Comparator;
import java.util.Scanner;
 
public class A {
    public static void main(String args[]) {
        new A().solve();
    }
     
    public void solve() {
        Scanner sc = new Scanner(System.in);
//        try {
//        	sc = new Scanner(new File("bin/i.txt"));
//        } catch(Exception e) {
//        	
//        }
        
        int testCases = sc.nextInt(); sc.nextLine();
         
        for(int i = 0; i < testCases; i++) {
        	int N = sc.nextInt();
        	sc.nextLine();
        	
        	int[] mush = new int[N];
        	
        	for(int j = 0; j < N; j++) {
        		mush[j] = sc.nextInt();
        	}
        	
        	System.out.println("Case #" + (i + 1) + ": " + solve(N, mush));
        }
    }
    
    private String solve(int N, int[] mush) {
    	int m1 = 0;
    	int last = mush[0];
    	for(int i = 1; i < N; i++) {
    		int current = mush[i];
    		if(current < last) m1 += last - current;
    		last = current;
    	}
    	
    	int m2 = 0;
    	
    	int maxrate = 0;
    	for(int i = 0; i < N - 1; i++) {
    		int rate = -(mush[i + 1] - mush[i]);
    		if(rate > maxrate) maxrate = rate;
    	}
    	
    	for(int i = 0; i < N - 1; i++) {
    		if(mush[i] < maxrate) {
				m2 += mush[i];
			} else {
				m2 += maxrate;
			}
    	}
    	
    	return m1 + " " + m2;
    }
}