import java.io.*;
import java.util.Scanner;


public class GCJAsmall {
	
	
	public static void main(String args[]) throws FileNotFoundException, UnsupportedEncodingException{
		GCJAsmall main = new GCJAsmall();
		main.answer();
	}
	
	
	public void answer()throws FileNotFoundException, UnsupportedEncodingException{
		Scanner scan = new Scanner(new File("A-small-attempt0.in"));
		//Scanner scan = new Scanner(System.in);
		int cases = Integer.parseInt(scan.nextLine()); 
		PrintWriter writer = new PrintWriter("Asmall.out", "UTF-8");
		for(int i=1; i<=cases; i++){
			//String[] size = scan.nextLine().split(" ");
			//Integer.parseInt(size[0]);
			//scan.nextInt();
			//1st time
			int row = Integer.parseInt(scan.nextLine());			
			int[] row1 = new int[4];
			String[] rowS = new String[4];
			for(int r=1; r<=4; r++){
				rowS = scan.nextLine().split(" ");
				if(r==row){
					for(int c=0; c<4; c++){
						row1[c]=Integer.parseInt(rowS[c]);
						//System.out.print(row1[c]+"\t'");
					}
					//System.out.println();
				}			
			}
			//2nd time
			row = Integer.parseInt(scan.nextLine()); 			
			int[] row2 = new int[4];
			for(int r=1; r<=4; r++){
				rowS = scan.nextLine().split(" ");
				if(r==row){
					for(int c=0; c<4; c++){
						row2[c]=Integer.parseInt(rowS[c]);
						//System.out.print(row2[c]+"\t");
					}
					//System.out.println();
				}			
			}
			int counter=0;
			int card=-1;
			for(int r1=0; r1<4; r1++){
				for(int r2=0; r2<4; r2++){
					if(row1[r1]==row2[r2]){
						counter++;
						card=row1[r1];
					}
				}
			}
			if(counter==0){
				writer.println("Case #"+i+": "+"Volunteer cheated!");
				System.out.println("Case #"+i+": "+"Volunteer cheated!");
			}else if(counter==1){
				writer.println("Case #"+i+": "+card);
				System.out.println("Case #"+i+": "+card);
			}else{
				writer.println("Case #"+i+": "+"Bad magician!");
				System.out.println("Case #"+i+": "+"Bad magician!");
			}
			
			
		}
		writer.close();
	}
	
}
