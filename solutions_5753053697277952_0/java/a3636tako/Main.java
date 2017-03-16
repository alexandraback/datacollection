import java.io.*;
import java.util.*;

public class Main{
	public void solve(){
		int T = nextInt();
		for(int cnt = 1; cnt <= T; cnt++){
			int N = nextInt();
			int[] P = new int[N];
			int sum = 0;
			for(int i = 0; i < N; i++){
				P[i] = nextInt();
				sum += P[i];
			}
			out.printf("Case #%d:", cnt);
			while(sum > 0){
				int mv1 = -1;
				int mi1 = -1;
				int mv2 = -1;
				int mi2 = -1;
				for(int i = 0; i < N; i++){
					if(mv1 < P[i]){
						mv2 = mv1;
						mi2 = mi1;
						mv1 = P[i];
						mi1 = i;
					}else if(mv2 < P[i]){
						mv2 = P[i];
						mi2 = i;
					}
				}
				if(mv1 - mv2 >= 2){
					mi2 = mi1;
				}
				if(sum >= 2){
					sum -= 2;
					P[mi1] -= 1;
					P[mi2] -= 1;
					int mm = -1;
					for(int i = 0; i < N; i++){
						mm = Math.max(mm, P[i]);
					}
					if(mm * 2 > sum){
						out.print(" ");
						out.print((char)(mi1 + 'A'));
						sum += 1;
						P[mi2] += 1;
					}else{
						out.print(" ");
						out.print((char)(mi1 + 'A'));
						out.print((char)(mi2 + 'A'));
						
					}
					
				}else{
					out.print(" ");
					out.print((char)(mi1 + 'A'));
				}
			}
			out.println();
			
		}
	}
	
	private static PrintWriter out;
	public static void main(String[] args){
		out = new PrintWriter(System.out);
		new Main().solve();
		out.flush();
	}
	
	
	
	public static int nextInt(){
		int num = 0;
		String str = next();
		boolean minus = false;
		int i = 0;
		if(str.charAt(0) == '-'){
			minus = true;
			i++;
		}
		int len = str.length();
		for(;i < len; i++){
			char c = str.charAt(i);
			if(!('0' <= c && c <= '9')) throw new RuntimeException();
			num = num * 10 + (c - '0');
		}
		return minus ? -num : num;
	}
	
	public static long nextLong(){
		long num = 0;
		String str = next();
		boolean minus = false;
		int i = 0;
		if(str.charAt(0) == '-'){
			minus = true;
			i++;
		}
		int len = str.length();
		for(;i < len; i++){
			char c = str.charAt(i);
			if(!('0' <= c && c <= '9')) throw new RuntimeException();
			num = num * 10l + (c - '0');
		}
		return minus ? -num : num;
	}
	public static String next(){
		int c;
		while(!isAlNum(c = read())){}
		StringBuilder build = new StringBuilder();
		build.append((char)c);
		while(isAlNum(c = read())){
			build.append((char)c);
		}
		return build.toString();
	}
	
	
	private static byte[] inputBuffer = new byte[1024];
	private static int bufferLength = 0;
	private static int bufferIndex = 0;
	private static int read(){
		if(bufferLength < 0) throw new RuntimeException();
		if(bufferIndex >= bufferLength){
			try{
				bufferLength = System.in.read(inputBuffer);
				bufferIndex = 0;
			}catch(IOException e){
				throw new RuntimeException(e);
			}
			if(bufferLength <= 0) return (bufferLength = -1);
		}
		return inputBuffer[bufferIndex++];
	}
	
	private static boolean isAlNum(int c){
		return '!' <= c && c <= '~';
	}
}