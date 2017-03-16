import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class NoisyNeighbours {

	
	boolean[][] ocupied;
	
	int getMin(int sp, int r, int c, int n, int min) {
		if(n == 0)
			return min;
		
		int m = Integer.MAX_VALUE;
		
		for(int i=sp; i<=r*c-n;++i) {
			int tr = i / c;
			int tc = i % c;
			
			ocupied[tr][tc] = true;
			
			int tmin = min;
			if(tr-1 >=0 && ocupied[tr-1][tc])
				++tmin;
			if(tc-1>=0 && ocupied[tr][tc-1])
				++tmin;
			
			tmin = getMin(i+1, r,c,n-1,tmin);
			if(tmin < m)
				m = tmin;
			
			ocupied[tr][tc] = false;
		}
		
		return m;
	}
	
	void process() throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("in.txt"));
		PrintWriter writer = new PrintWriter("out.txt", "UTF-8");
		
		
	    try {
	        String line = br.readLine();
	        
	        int t = Integer.parseInt(line);
	        
	        for(int i=1;i<=t;++i) {
	        	StringTokenizer st = new StringTokenizer(br.readLine());
	        	
	        	int r = Integer.parseInt(st.nextToken());
	        	int c = Integer.parseInt(st.nextToken());
	        	int n = Integer.parseInt(st.nextToken());
	        	ocupied = new boolean[r][c];
	        	
	        	int min = getMin(0,r,c,n,0);
	        	writer.print("Case #" + new Integer(i).toString() + ": " + min);
	        	
	        	if(i<t)
	        		writer.println();
	        }
	    } finally {
	        br.close();
	        writer.close();
	    }
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		NoisyNeighbours instance = new NoisyNeighbours();
		instance.process();
	}

}
