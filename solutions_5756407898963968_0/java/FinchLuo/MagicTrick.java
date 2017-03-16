package qr2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class MagicTrick {

	/**
	 * @param args
	 */
	
	public static int caseCount;
	public static BufferedReader inbuf;
	public static BufferedWriter outbuf;
	public static String fileIn="data/qr2014/A-small-attempt0.in";
	public static String fileOut="data/qr2014/A-small-attempt0.out";
	
	public static ArrayList<Integer> commonNums(ArrayList<Integer> row1,ArrayList<Integer> row2){
		ArrayList<Integer> result=new ArrayList<Integer>();
		for(int i=0;i<4;i++){
			if(row1.contains(row2.get(i)))
				result.add(row2.get(i));
				
		}
		return result;
	}
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		//打开文件句柄
		long sTime=System.currentTimeMillis();
		inbuf=new BufferedReader(new FileReader(fileIn));
		outbuf=new BufferedWriter(new FileWriter(fileOut));	
		caseCount=Integer.valueOf(inbuf.readLine());
		String line="";	
		for(int i=1;i<=caseCount;i++){
			outbuf.append("Case #"+i+": ");//注意这里的空格
			line=inbuf.readLine();
			int firstRow=Integer.valueOf(line);
			ArrayList<Integer> row1=new ArrayList<Integer>();
			for(int row=0;row<4;row++){
				line=inbuf.readLine();
				if(row==firstRow-1){
					String[] numStrs=line.split(" ");
					for(int p=0;p<4;p++)
						row1.add(Integer.valueOf(numStrs[p]));
				}
					
			}
			line=inbuf.readLine();
			int secondRow=Integer.valueOf(line);
			ArrayList<Integer> row2=new ArrayList<Integer>();
			for(int row=0;row<4;row++){
				line=inbuf.readLine();
				if(row==secondRow-1){
					String[] numStrs=line.split(" ");
					for(int p=0;p<4;p++)
						row2.add(Integer.valueOf(numStrs[p]));
				}					
			}
			//下面执行判断
			ArrayList<Integer> result=commonNums(row1,row2);
			if(result.isEmpty()) 
				outbuf.write("Volunteer cheated!\r\n");
			else if(result.size()>1)
				outbuf.write("Bad magician!\r\n");
			else outbuf.write(result.get(0)+"\r\n");
			
			
		}
		
		
		
		//关闭文件句柄	
		inbuf.close();
		outbuf.close();
		System.out.println("time:"+(System.currentTimeMillis()-sTime)/1000.0+"s");
	}

}
