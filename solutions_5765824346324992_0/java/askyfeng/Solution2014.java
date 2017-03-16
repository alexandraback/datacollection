package GoogleJam;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class Solution2014 {
	private Solution2014(){}
	
	public static void main(String[] args) throws IOException{
		String file = "C:/zfeng/B-small-attempt0.in";
		String output = "C:/zfeng/output.out";
//		String file = "C:/zfeng/B-small-practice.in";
//		String output = "C:/zfeng/output.txt";
		BufferedReader content =  new BufferedReader(new FileReader(file));	
		PrintWriter outputFile = new PrintWriter(new FileWriter(output));
		
		int num_cases = Integer.parseInt( content.readLine() );
		
		for( int i = 1; i<=num_cases; i++ ){
//			int D = Integer.parseInt( content.readLine() );
			String dataRow = content.readLine();
			String[] data = dataRow.split(" ");
			int B = Integer.parseInt( data[0] );
			int N = Integer.parseInt( data[1] );
			dataRow = content.readLine();
			
			String num = Haircut( B, N, dataRow );
			
			System.out.println("Case #"+i+": "+num);
			outputFile.println("Case #"+i+": "+num);			
		}
		
		content.close();
		outputFile.close();		
	}
	
	public static String Haircut(int B, int N, String str){
		if( B==1 )
			return "1";
		if( B>=N )
			return Integer.toString(N);
		
		String[] M = str.split(" ");
		int[] Mk = new int[B];
		for( int i=0;i<B;i++ ){
			Mk[i] = Integer.parseInt(M[i]);
		}
		int scm = commonMultiple(Mk[0], Mk[1]);
		for(int i=2;i<B;i++){
			scm = commonMultiple(scm, Mk[i]);
		}		
		
		int num = 0;
		for( int i=0;i<B;i++ ){
			num += scm/Mk[i];
		}
		N = (N-1)%num+1;
		
		int[] score = new int[B];
		int minX = 0;
		while(N>0){
			int minVal = score[0];
			minX = 0;
			for( int i=1;i<B;i++ ){
				if( score[i]<minVal ){
					minVal = score[i];
					minX = i;
				}
			}
			if( score[minX]>Integer.MAX_VALUE-Mk[minX] ){
				for( int i=0;i<B;i++ ){
					score[minX] -= minVal;
				}
			}
			score[minX] += Mk[minX];
			N--;
		}
		return Integer.toString(minX+1);
	}
	
	
	public static int commonDivisor(int n,int m){
		while(n%m!=0){
			int temp=n%m;
			n=m;
			m=temp;
		}
		return m;
	}

	public static int commonMultiple(int n,int m){
		return n*m/commonDivisor(n,m);
	}
		
	public static String OminousOmino(String str){
		String[] data = str.split(" ");
		int X = Integer.parseInt( data[0] );
		int R = Integer.parseInt( data[1] );
		int C = Integer.parseInt( data[2] );
		if( (R*C)%X != 0  )
			return "RICHARD";
		if( X>6 )
			return "RICHARD";
		if( X>Math.max(R, C))
			return "RICHARD";
		if( X<3 )
			return "GABRIEL";		
		if( (X+1)/2 > Math.min(R, C))
			return "RICHARD";
		if( X==3 )
			return "GABRIEL";
		if( X==4 )
			return Math.min(R, C)==2?"RICHARD":"GABRIEL";
		if( X==5 ){
			int V = Math.min(R, C);
			if( 3==Math.min(R, C) && V>5 && V%5==0 )
				return "RICHARD";
		}
		if( X==6 ){
			if(3==Math.min(R, C))
				return "RICHARD";
		}
		
		return "GABRIEL";
	}
	
	public static String Dijkstra(int L, int X, String str){
		if( L*X<3 || str.length()==1) return "NO";
		
		boolean allEqual = true;
		for(int i= 1; i<L; i++){
			if( str.charAt(i) != str.charAt(0) ){
				allEqual = false;
				break;
			}
		}		
		if(allEqual) return "NO";
		
		boolean sign = true;
		int left = 1;
		char leftCh = str.charAt(0);
		char[] res = new char[2];
		while('i'!=leftCh && left<L*X){	
			mapDijkstra(leftCh, str.charAt(left), res);
			if( res[0] == '-')
				sign = !sign;
			if( res[1] == '1' ){
				left++;
				if( left==L ){
					left = 0;
					X--;
				}
				leftCh = str.charAt(left);
			}else
				leftCh = res[1];
			left++;
			if( left==L ){
				left = 0;
				X--;
			}
		}
		
		if( left==L*X )
			return "NO";
		leftCh = str.charAt(left);
		left++;
		if( left==L ){
			left = 0;
			X--;
		}
		while('j'!=leftCh && left<L*X){	
			mapDijkstra(leftCh, str.charAt(left), res);
			if( res[0] == '-')
				sign = !sign;
			if( res[1] == '1' ){
				left++;
				if( left==L ){
					left = 0;
					X--;
				}
				leftCh = str.charAt(left);
			}else
				leftCh = res[1];
			left++;
			if( left==L ){
				left = 0;
				X--;
			}
		}
		if( left==L*X )
			return "NO";
		
		leftCh = str.charAt(left);
		left++;
		if( left==L ){
			left = 0;
			X--;
		}
		while('k'!=leftCh && left<L*X){	
			mapDijkstra(leftCh, str.charAt(left), res);
			if( res[0] == '-')
				sign = !sign;
			if( res[1] == '1' ){
				left++;
				if( left==L ){
					left = 0;
					X--;
				}
				leftCh = str.charAt(left);
			}else
				leftCh = res[1];
			left++;
			if( left==L ){
				left = 0;
				X--;
			}
		}
		
		if( left==L*X )
			return 'k'==leftCh?"YES":"NO";
		
		leftCh = str.charAt(left);
		X = (X-1)%4+1;
		left++;
		if( left==L ){
			left = 0;
			X--;
		}		
		while(left<L*X){	
			mapDijkstra(leftCh, str.charAt(left), res);
			if( res[0] == '-')
				sign = !sign;
			if( res[1] == '1' ){
				left++;
				if( left==L ){
					left = 0;
					X--;
				}
				if( left<L*X )
					leftCh = str.charAt(left);
				else{
					leftCh = res[1];
					break;
				}
			}else
				leftCh = res[1];
			left++;
			if( left==L ){
				left = 0;
				X--;
			}
		}
		
		if( leftCh=='1' && sign )
			return "YES";
		else
			return "NO";
				
	}
	
	public static void mapDijkstra( char x, char y, char[] res){
		if( x==y ){
			res[0] = '-';res[1] = '1';
			return;
		}
		if( x=='i'){
			if( y=='j'){
				res[0] = ' ';res[1] = 'k';
			}else{
				res[0] = '-';res[1] = 'j';
			}			
		}else if( x=='j'){
			if( y=='i'){
				res[0] = '-';res[1] = 'k';
			}else{
				res[0] = ' ';res[1] = 'i';
			}			
		}else{
			if( y=='i'){
				res[0] = ' ';res[1] = 'j';
			}else{
				res[0] = '-';res[1] = 'i';
			}			
		}
	}
	
	public static int InfiniteHouseofPancakes(int D, String str){
		String[] ch = str.split(" ");
		int[] A = new int[D];
		int sum = 0, max = 0;
		for(int i=0;i<D;i++){
			A[i] = Integer.parseInt( ch[i] );
			sum += A[i];
			max = Math.max(A[i], max);
		}
		int x = (int) Math.sqrt( sum );
		
		int num = minSqrtArr(A, x);
		for(int i=1;i<=100;i++){
			if( x+i>max )
				break;
			int num_test = minSqrtArr(A, x+i);
			num = Math.min(num, num_test);
		}		
		for(int i=1;i<=100;i++){
			if( x-i<1 )
				break;
			int num_test = minSqrtArr(A, x-i);
			num = Math.min(num, num_test);
		}	
		return num;
	}
	
	public static int minSqrtArr(int[] A, int x){
		int num = x;
		for(int a:A){
			num += (int)Math.ceil(1.0*a/x)-1;
		}
		return num;
	}
	
	
	public static int StandingOvation( String str){
		String[] data = str.split(" ");
		int smax = Integer.parseInt( data[0] );
		
		int friend = 0, stands = 0;;
		for( int i=0; i<=smax; i++){
			int audi = data[1].charAt(i)-'0';
			if( stands<i ){
				int newInvite = i-stands;
				friend += newInvite;
				stands += newInvite;
			}
			stands += audi;
		}
		
		return friend;
	}

}
