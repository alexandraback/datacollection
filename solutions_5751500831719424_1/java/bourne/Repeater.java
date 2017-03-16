import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;


public class Repeater {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader reader = new BufferedReader(new FileReader(new File("Al.in")));
		PrintWriter writer = new PrintWriter(new File("opt_6.txt"));
		int t = Integer.parseInt(reader.readLine());
		for(int i=0; i<t; i++) {
			int n = Integer.parseInt(reader.readLine());
			List<String> strs = new ArrayList<>();
			for(int j=0; j<n; j++) {
				strs.add(reader.readLine());
			}
			int res = go(strs);
			if(res == -1) 
				writer.write("Case #"+(i+1) + ": Fegla Won\n" );
			else 
				writer.write("Case #"+(i+1) + ": " + res + "\n");		
		}
		reader.close();
		writer.close();
	}
	
	public static int go(List<String> strs) {
		int n = strs.size();
		List<Integer> ptrs = new ArrayList<Integer>();
		String fS = strs.get(0);
        String un = fS.substring(0, 1);
        for(int i=1; i<fS.length(); i++) {
        	if(fS.charAt(i) != un.charAt(un.length() - 1)) {
        		un += fS.charAt(i);
        	}
        }
        for(int i=1; i<strs.size(); i++) {
        	String u = getUniqs(strs.get(i));
        	if(!un.equals(u)) {
        		return -1;
        	}
        }
        int m = 0;
        int cK = 0;
        int[] lp = new int[n];
        for(int i=0; i<un.length(); i++) {
        	char curC = un.charAt(i);
        	ptrs = new ArrayList<Integer>();
        	for(int j=0; j<n; j++) {
        		String cur = strs.get(j);
        		int k = lp[j];
        		while(k<cur.length() && cur.charAt(k) == curC) {
        			k++;
        		}
        		if(k == lp[j]) {
        			return -1;
        		}
        		ptrs.add(k - lp[j]);
        		lp[j] = k;
        	}
        	int minM = Integer.MAX_VALUE;
        	int min = ptrs.get(0);
        	int max = ptrs.get(0);
        	for(int d=1; d<ptrs.size(); d++) {
        		min = Math.min(min, ptrs.get(d));
        		max = Math.max(max, ptrs.get(d));
        	}
        	for(int j=min; j<=max; j++) {
        		int moves = 0;
        		for(int k=0; k<ptrs.size(); k++) {
        			
        				moves += Math.abs(ptrs.get(k) - j);
        			
        		}
        		minM = Math.min(moves, minM);
        	}
        	m += minM;
        }
        return m;
	}
	
	public static String getUniqs(String fS) {
        String un = fS.substring(0, 1);
        for(int i=1; i<fS.length(); i++) {
        	if(fS.charAt(i) != un.charAt(un.length() - 1)) {
        		un += fS.charAt(i);
        	}
        }
        return un;
	}
}
