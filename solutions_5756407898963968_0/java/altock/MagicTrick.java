package Qualification;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.lang.reflect.Field;
import java.util.ArrayList;


public class MagicTrick{
	public MagicTrick(){	
	}
	public void MagicTrick(String filename) throws NumberFormatException, NoSuchFieldException, SecurityException, IllegalArgumentException, IllegalAccessException, IOException{
		BufferedReader greyparse = new BufferedReader(new FileReader(filename));
		greyparse.readLine();
		PrintWriter writer = new PrintWriter("src/Qualification/output", "UTF-8");
		int thiscase = 1;
		String thisString;
		int guess1;
		int guess2;
	
		
		while(greyparse.ready()){
			thisString = "Case #" + thiscase + ": ";
			Integer[][] square1 = new Integer[4][4];
			Integer[][] square2 = new Integer[4][4];
			guess1 =  Integer.valueOf(greyparse.readLine());
			for(int i = 0; i < 4; i++){
				Integer[] currow = new Integer[4];
				String rowlist = greyparse.readLine();
				String[] current = rowlist.split(" ");
				for(int j = 0; j < 4; j++){
					currow[j] = Integer.valueOf(current[j]);				
				}
				square1[i] = currow;
			}
			guess2 = Integer.valueOf(greyparse.readLine());
			for(int i = 0; i < 4; i++){
				Integer[] currow = new Integer[4];
				String rowlist = greyparse.readLine();
				String[] current = rowlist.split(" ");
				for(int j = 0; j < 4; j++){
					currow[j] = Integer.valueOf(current[j]);				
				}
				square2[i] = currow;
			}
			Integer [] firstrow = square1[guess1-1];
			Integer [] secondrow = square2[guess2-1];
			Integer same = 0;
			Integer answer =0;
			for(Integer i:firstrow){
				for(Integer j:secondrow){
					if(i == j){
						same++;
						answer = i;
					}
				}
			}
			if(same == 0){
				thisString += "Volunteer cheated!";
			}
			if(same == 1){
				thisString += answer;
			}
			if(same >1){
				thisString += "Bad magician!";
			}
			thiscase++;
			writer.println(thisString);
		}
		writer.close();
	}
	
	public static void main(String[] args) throws NumberFormatException, NoSuchFieldException, SecurityException, IllegalArgumentException, IllegalAccessException, IOException{
		MagicTrick c = new MagicTrick();
		c.MagicTrick("src/Qualification/A-small-attempt0.in");
	}
}