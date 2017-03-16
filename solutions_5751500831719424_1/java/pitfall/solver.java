import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeMap;
 
public class solver implements Runnable {         
        BufferedReader in;
        PrintWriter out;
        StringTokenizer tok = new StringTokenizer("");
 
        void init() throws FileNotFoundException {
        	in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);   
            
            in=new BufferedReader(new FileReader("A-large.in"));
            //in=new BufferedReader(new FileReader("input.txt"));
            out=new PrintWriter("output.txt");
        }
 
        String readString() throws IOException {
                while (!tok.hasMoreTokens()) {
                        try {
                                tok = new StringTokenizer(in.readLine());
                        } catch (Exception e) {
                                return null;
                        }
                }
                return tok.nextToken();
        }
 
        int readInt() throws IOException {
                return Integer.parseInt(readString());
        }
 
        long readLong() throws IOException {
                return Long.parseLong(readString());
        }
 
        double readDouble() throws IOException {
                return Double.parseDouble(readString());
        }
 
        public static void main(String[] args) {
                new Thread(null, new solver(), "", 128 * (1L << 20)).start();
        }
 
        
 
        public void run() {
                try {
                        init();
                        solve();
                        out.close();                        
                } catch (IOException e) {
                	    System.err.println(e.getMessage());
                        System.exit(-1);
                }
        }
        
        
        
        
        
        
        void solve() throws IOException{        	
        	int t=readInt();
        	for (int test=1;test<=t;test++){
        		out.print("Case #"+test+": ");        		
        		
        		int n=readInt();
        		char[][] a=new char[n][];  		
        		for (int i=0;i<n;i++) a[i]=readString().toCharArray();
        		
        		
        		int[] pos=new int[n];
        		int[] k=new int[n];
        		int[] x=new int[n];
        		int ans=0;
        		boolean faik=false;
        		while (true){     
        			int sum=0;
        			for (int i=0;i<n;i++){
        				x[i]='$';        				
        				if (pos[i]==a[i].length) continue;
        				x[i]=a[i][pos[i]];            			      			
            			while (pos[i]<a[i].length && a[i][pos[i]]==x[i]) {
            				pos[i]++;
            				k[i]++;
            			}      
            			sum+=k[i];
        			}    
        			Arrays.sort(x);
        			if (x[0]!=x[n-1]){
        				faik=true;
        				break;
        			}
        			if (x[0]=='$') break;
        			
        			int sr=sum/n;
        			int min=Integer.MAX_VALUE;
        			int res=0;
        			for (int i=0;i<n;i++){
        				res+=Math.abs(sr-k[i]);        				
        			}
        			min=res;
        			res=0;
        			for (int i=0;i<n;i++){
        				res+=(Math.abs(sr+1-k[i]));
        			}
        			min=Math.min(min, res);
        			ans+=min;
        			for (int i=0;i<n;i++) k[i]=0;
        		}
        		if (faik){
        			out.println("Fegla Won");
        		}else{
        			out.println(ans);
        		}
        		
        	}
        	
        	
        		    	    	
        }
}