package gcj;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class question2 {
	
	static ArrayList<Integer> os;
	
	public static void main(String[] args) throws FileNotFoundException, IOException {	
		String file = "small2.in";
		
		try (BufferedReader br = new BufferedReader(new FileReader(file))) {
		    String line;
		    Integer N = Integer.parseInt(br.readLine());
		    for (int n = 0; n < N; n++) {

		    	int K = Integer.parseInt(br.readLine());
		    	
		    	os = new ArrayList<Integer>();
		    	for (String s : br.readLine().split(" ")) {
		    		os.add(Integer.parseInt(s));
		    	}
		    	
	

				System.out.println("Case #" + (n+1) + ": " + calc1(K) + " " + calc2(K));
		    }
		}
		


	}
	
	public static int calc1(int K) {
		int eaten = 0;
		for (int i = 1; i<K; i++) {
			if (os.get(i)<os.get(i-1)) {
				eaten += os.get(i-1)-os.get(i);
			}
		}
		return eaten;
	}
	public static int calc2(int K) {
		int eaten = 0;
		int interval = 0;
		for (int i = 1; i < K; i++) {
			interval = Math.max(interval, os.get(i-1)-os.get(i));
		}
		//System.out.println(interval);
		for (int i=0; i <K-1; i++) {
			eaten += Math.min(os.get(i), interval);
		}
		return eaten;
	}
}
