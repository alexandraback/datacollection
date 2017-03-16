import java.io.*;
import java.util.*;
 
public class Main {
    /**
     * author geshpaniec
     * 23.10.2014
     */
 
    StringTokenizer in;
    BufferedReader inb;
    PrintWriter out;
    static boolean local;
    final String problemname = "success";
    final static String _localArg="geshpaniec";
    final static byte IO=3;
        /* IO:
         * 1 - standard I/O
         * 2 - input.txt/output.txt
         * 3 - problemname.in/problemname.out
         */
 
    int[][] neighbors;
    int R,C,N;
    
    class Pair{
    	int x;
    	int y;
    	int neighbors;
    	Pair(int x,int y,int neighbors){
    		this.x =x;
    		this.y = y;
    		this.neighbors = neighbors;
    	}
    	@Override
    	public String toString() {
    		return "("+x+","+y+")";
    	}
    	    	
    }
    
    int getNei(int x, int y){
    	int res = 0;
    	
    	if (x-1>=0)
    		res+=neighbors[x-1][y];
    	if (x+1<R)
    		res+=neighbors[x+1][y];
    	if (y-1>=0)
    		res+=neighbors[x][y-1];
    	if (y+1<C)
    		res+=neighbors[x][y+1];
    	return res;
    }
    
    int getAns(int x, int y){
    	int res = 0;
    	if (x+1<R)
    		res+=neighbors[x+1][y];
    	if (y+1<C)
    		res+=neighbors[x][y+1];
    	return res;
    }
    
    boolean perem(Pair a1,Pair a2){
    	int ans = getNei(a1.x, a1.y) - getNei(a2.x, a2.y);
    	if (a1.x-1 == a2.x && a1.y==a2.y)
    		ans++;
    	if (a1.x+1 == a2.x && a1.y==a2.y)
    		ans++;
    	if (a1.x == a2.x && a1.y-1==a2.y)
    		ans++;
    	if (a1.x == a2.x && a1.y+1==a2.y)
    		ans++;
    	return ans >0;
    }
    
    
    long funct(){
    	neighbors = new int[R][C];
    	
    	int minCount = 0;
    	minCount = ((R+1)/2)*((C+1)/2)+(R/2)*(C/2);
    	
    	if (N<=minCount){
    		return 0;
    	} 	
    	
    	ArrayList<Pair> free = new ArrayList<Pair>();
    	
    	ArrayList<Pair> notFree = new ArrayList<Pair>();
    	
    	for (int i = 0;i<R;i++){
    		for (int j = 0 ; j<C;j++){
    			if ((i+j)%2 == 0){
    				notFree.add(new Pair(i,j,0));
    				neighbors[i][j]=1;
    			}
    			else{
    				free.add(new Pair(i,j,0));
    			}
    		}
    	}
    	
    	for (int i = minCount+1; i<=N;i++){
    		Pair p = free.get(free.size()-1);
    		free.remove(free.size()-1);
    		p.neighbors = getNei(p.x, p.y);
    		notFree.add(p);
    		neighbors[p.x][p.y] = 1;
    	}
    	
    	boolean K = true;
    	
    	A:while (K){
    		K = false;
    		for (Pair a1:notFree){
    			for (Pair a2:free){
    				if (perem(a1,a2)){
    					K = true;
    					neighbors[a1.x][a1.y] = 0;
    					neighbors[a2.x][a2.y] = 1;
    					
    					a1.neighbors = getNei(a1.x, a1.y);
    					a2.neighbors = getNei(a2.x, a2.y);
    					
    					notFree.remove(a1);
    					notFree.add(a2);
    					
    					free.remove(a2);
    					free.add(a1);
    					
    					continue A;
    				}
    			}
    		}
    	}
    	
    	long ans = 0;
    	
    	for (Pair a:notFree){
    		ans+=getAns(a.x, a.y);
    	}
    	return ans;
    }
    
    public void solve() throws Exception {
    	int T = nextInt();
    	for (int q = 1;q<=T;q++){
    		R = nextInt();
    		C = nextInt();
    		N = nextInt();
    		System.out.println(q);
    		out.println("Case #"+q+": "+funct());
    		
    	}
    }
 
    public static void main(String[] args) throws Exception {
        local = false;
        if (args.length == 1 && args[0].equals(_localArg))
            local = true;
        new Main().run();
 
    }
 
    public void run() throws Exception {
        if (local) {
            inb = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter(new OutputStreamWriter(System.out));
        } else {
            switch (IO){
                case 1:
                    inb = new BufferedReader(new InputStreamReader(System.in));
                    out = new PrintWriter(new OutputStreamWriter(System.out));
                    break;
                case 2:
                    inb = new BufferedReader(new FileReader("input.txt"));
                    out = new PrintWriter(new FileWriter("output.txt"));
                    break;
                case 3:
                    inb = new BufferedReader(new FileReader(problemname+".in"));
                    out = new PrintWriter(new FileWriter(problemname+".out"));
                    break;
            }
        }
        in = new StringTokenizer("");
        double Time=System.nanoTime();
        solve();
        if (local){
            Time=System.nanoTime()-Time;
            out.println();
            out.println(" Time work: "+Time/(1e9)+" seconds");
        }
        out.flush();
    }
 
    int nextInt() throws Exception {
        return Integer.parseInt(next());
    }
 
    long nextLong() throws Exception{
        return Long.parseLong(next());
    }
 
    double nextDouble() throws Exception {
        return Double.parseDouble(next());
    }
 
    String next() throws Exception {
        if (!in.hasMoreTokens())
            in=new StringTokenizer(inb.readLine());
        return in.nextToken();
    }
 
    int[] nextArray(int n) throws Exception{
        int[] a=new int[n];
        for (int i=0;i<n;i++)
            a[i]=nextInt();
        return a;
    }
 
    long[] nextLArray(int n) throws Exception{
        long[] a=new long[n];
        for (int i=0;i<n;i++)
            a[i]=nextLong();
        return a;
    }
 
    double[] nextDArray(int n) throws Exception{
        double[] a=new double[n];
        for (int i=0;i<n;i++)
            a[i]=nextDouble();
        return a;
    }
 
    String[] nextSArray(int n) throws Exception{
        String[] a=new String[n];
        for (int i=0;i<n;i++)
            a[i]=next();
        return a;
    }

}