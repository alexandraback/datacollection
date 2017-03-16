import java.io.*;
import java.util.*;

public class BB {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner console = new Scanner(new File("B-small-attempt1.in"));
		PrintStream output = new PrintStream(new File("BBfinal.txt"));
		int caseNum = console.nextInt();
		for (int i = 1; i <= caseNum; i++) {
			int period = console.nextInt();
			int number = console.nextInt();
			int[] a=new int[period];
			for (int b = 0; b < period; b++) {
			a[b]=console.nextInt();
			}
			output.println("Case #"+i+": " + find(period, number,a) );
			System.out.println(find(period, number,a) );
		}
	}

	public static int find(int period,int number,int[] a) {
		int small=a[0];
		for (int b = 0; b < period; b++) {
			small=gongbei(small,a[b]);
		}
		
	int people=0;
	for (int c = 0; c < period; c++) {
		people=small/a[c]+people;
		}
	int real=number%people;
	if(real==0){
		real=people;
	}
	int start=0;
	int qwe[]=new int[period];
//	for (int qwa = 0; qwa < period; qwa++) {
//		qwe[qwa]=a[qwa];
//	}

	while(start!=real){
		for (int e = 0; e < period; e++) {
			if(qwe[e]==0){
				qwe[e]=a[e];
				start++;
               if(start==real){
            	   return e+1;
               }
			}
		 //    System.out.println(qwe[e]);
	           	qwe[e]=qwe[e]-1;
		}
	}
		
		return 1;
	}
	
	
	
	public static int gongyue(int min, int max) {
		  while(max%min!=0){
		   int temp=max%min;
		   max=min;
		   min=temp;
		  }
		  return min;
		 }

		 public static int gongbei(int min, int max) {
		  return min* max / gongyue(min, max);
		 }

}
