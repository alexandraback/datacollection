import java.io.File;
import java.util.Comparator;
import java.util.Scanner;
 
public class B {
    public static void main(String args[]) {
        new B().solve();
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
        	int B = sc.nextInt();
        	int N = sc.nextInt();
        	sc.nextLine();
        	
        	int[] time = new int[B];
        	
        	for(int j = 0; j < B; j++) {
        		time[j] = sc.nextInt();
        	}
        	
        	System.out.println("Case #" + (i + 1) + ": " + solve(B, N, time));
        }
    }
    
    private int solve(int B, int N, int[] time) {
    	if(N == 0) return 1;
    	
    	int[] pending = new int[B];
    	for(int i = 0; i < B; i++) pending[i] = 0;
    	
    	int pos = -1;
    	int modulo = 0;
    	boolean moduloFound = false;
    	while(!moduloFound) {
    		pos = 0;
    		int min = pending[0];
    		for(int j = 1; j < B; j++) {
    			if(pending[j] < min) {
    				pos = j;
    				min = pending[j];
    			}
    		}
    		
    		for(int j = 0; j < B; j++) {
    			pending[j] -= min;
    		}
    		
    		boolean allZero = true;
    		for(int j = 0; allZero && j < B; j++) {
    			allZero = pending[j] == 0;
    		}
    		
    		if(allZero && modulo != 0) {
    			moduloFound = true;
    		} else {
	    		pending[pos] += time[pos];
	    		modulo++;
    		}
    	}
    	    	
    	N = (N % modulo);
    	if(N == 0) N = modulo;
    	
    	int i = 0;
    	while(i < N) {
    		pos = 0;
    		int min = pending[0];
    		for(int j = 1; j < B; j++) {
    			if(pending[j] < min) {
    				pos = j;
    				min = pending[j];
    			}
    		}

    		for(int j = 0; j < B; j++) {
    			pending[j] -= min;
    		}
    		
    		pending[pos] += time[pos];
    		i++;
    	}
    	return pos + 1;
    }
}