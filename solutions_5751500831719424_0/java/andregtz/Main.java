import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;


public class Main {

	public static void main(String[] args) throws IOException {
		Scanner in=new Scanner(System.in);
		StringTokenizer st;
		//BufferedReader b=new BufferedReader(new InputStreamReader(System.in));
		BufferedReader b=new BufferedReader(new FileReader("c:/A-small-attempt0.in"));
		st=new StringTokenizer(b.readLine());
		FileWriter fw=new FileWriter("A.out");
		PrintWriter pw= new PrintWriter(fw);
		int T= Integer.parseInt(st.nextToken());
		int t=0;
		
		while(t++<T){
			pw.print("Case #"+t+": ");
			boolean win=true;
			String comparator="";
			st=new StringTokenizer(b.readLine());
			int n= Integer.parseInt(st.nextToken());
			String[] cadena=new String[n];
			
			for(int i=0;i<n;i++){
				st=new StringTokenizer(b.readLine());
				cadena[i]=st.nextToken();
			}
			String regex="";
			char last=cadena[0].charAt(0);
			comparator+=last;
			regex+=last+"+";
			for(int i=0;i<cadena[0].length();i++){
				if(cadena[0].charAt(i)!=last){
					comparator+=cadena[0].charAt(i);
					regex+=cadena[0].charAt(i)+"+";
					last=cadena[0].charAt(i);
				}
				
			}
			//System.out.println("regex:"+regex);
			for(int i=0;i<n;i++){
				if(!cadena[i].matches(regex)){
					win=false;
					break;
				}
			}
			if(win){
			int[][] counter=new int[comparator.length()][n];
			int diferencia=0;
			//System.out.println("counter: "+counter.length+" "+comparator);
			for(int i=0;i<n;i++){
				int k=0;
				for(int j=0;j<cadena[i].length();j++)
					if (k>=comparator.length()) break;
					else if(comparator.charAt(k)==cadena[i].charAt(j))
						counter[k][i]++; 
					else{
						k++;
						j--;
					}
			}
			/*for(int i=0;i<counter.length;i++){
				for(int j=0;j<counter[i].length;j++)
					System.out.print(counter[i][j]+" ");
				System.out.println();
			}*/
			for(int i=0;i<counter.length;i++){
				Arrays.sort(counter[i]);
				for(int j=0;j<counter[i].length;j++)
					diferencia+=Math.abs(counter[i][j]-counter[i][(counter[i].length/2)]);
			}
			pw.println(diferencia);
			}else
				pw.println("Fegla Won");
		}			
		pw.close();
	}

}
