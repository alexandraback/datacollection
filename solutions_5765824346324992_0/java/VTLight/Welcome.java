package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Welcome {
	public static void main(String[] args) throws Exception {
		FileInputStream fis = null;
		BufferedReader reader = null;
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("/home/luong/Downloads/"+args[0]+".out", true)));

		String s;
		fis = new FileInputStream("/home/luong/Downloads/"+args[0]+".in");
		reader = new BufferedReader(new InputStreamReader(fis));
		s = reader.readLine();
		int nbLoop = Integer.parseInt(s);
		for (int i = 1; i <= nbLoop; i++){
			String ch ="";
			StringTokenizer st = new StringTokenizer(reader.readLine());
			int b = Integer.parseInt(st.nextToken());
			int n = Integer.parseInt(st.nextToken());
			int[] m = new int[b];
			int[] c = new int[b];
			st = new StringTokenizer(reader.readLine());
			for(int j=0; j<b; j++){
				m[j] = Integer.parseInt(st.nextToken());
				c[j] = m[j];
			}
			int bc = m[0];
			for(int j=1; j<b; j++){
				bc = bcnn(bc, m[j]);
			}
			int t=0;
			for(int j=0; j<b; j++){
				t += bc/m[j];
			}
			n=n%t;
			if(n == 0){
				n=t;
			}
			if(n<=b){
				writeToFile(bw, "Case #"+i+": "+n);
			}else{
				for(int j=b+1; j<=n; j++){
					int min = 0;
					for(int k=1; k<b; k++){
						if(c[min] > c[k]){
							min = k;
						}
					}
					c[min] += m[min];
					if(j == n){
						writeToFile(bw, "Case #"+i+": "+(min+1));
					}
				}
			}
			
		}
		reader.close();
		fis.close();
		bw.close();
	}
	
	public static int bcnn(int a, int b){
		int c = a;
		while(c % b != 0){
			c += a;
		}
		return c;
	}
	
	public static void writeToFile(BufferedWriter bw, String text) throws Exception {
			bw.write(text);
			bw.newLine();
	}
}