import java.io.*;
import java.util.*;

public class AA {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner console = new Scanner(new File("A-large1.in"));
		PrintStream output = new PrintStream(new File("AAfinal.txt"));
		int caseNum = console.nextInt();
		for (int i = 1; i <= caseNum; i++) {
			int period = console.nextInt();
			int[] a=new int[period];
			for (int b = 0; b < period; b++) {
			a[b]=console.nextInt();
			}
			output.println("Case #"+i+": " + find(period, a)+" "+find2(period, a) );
		}
	}

	public static int find(int period,int[] a) {
		int count=0;
		for (int b = 0; b < period-1; b++) {
			if(a[b]>a[b+1]){
				count=count+a[b]-a[b+1];
			}
			}
		return count;
	}
	public static int find2(int period,int[] a) {
		int max=0;
		for (int b = 0; b < period-1; b++) {
			if(a[b+1]-a[b]<max){
				max=a[b+1]-a[b];
			}
			}
		max=max*(-1);
		int count=0;
		for (int c = 0; c < period-1; c++) {
			if(a[c]<max){
				count=count+a[c];
			}else{
				count=count+max;
				}
			}
	
		return count;
	}
}
