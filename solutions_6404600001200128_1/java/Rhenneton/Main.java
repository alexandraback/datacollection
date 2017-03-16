import java.io.PrintWriter;
import java.util.ArrayList;


public class Main {
	public static void main(String[]args){
		new Reader();
		ArrayList<String> texte = Reader.getAllLines("/home/romain/Downloads/A-large.in");
		
		
		PrintWriter writer = Reader.getWriter("/home/romain/Downloads/output.txt");
		int count =1;
		
		for(int i =2;i<texte.size();i=i+2){
			writer.println("Case #"+count+": "+count1(texte.get(i))+" "+count2(texte.get(i))); 
			count++;
		}
		
		
		writer.close();
		
		
	}
	
	public static int count1(String ligne){
		String[] tab = ligne.split(" ");
		int count = 0;
		for(int i =0;i<tab.length-1;i++){
			count = count+Math.max(0,Integer.parseInt(tab[i])-Integer.parseInt(tab[i+1]));
		
		}
		
		return count;
		
	}
	
	public static int count2(String ligne){
		int maxrate = getMax(ligne);
		String [] tab = ligne.split(" ");
		int count = 0;
		for(int i=0;i<tab.length-1;i++){
			count = count + Math.min(maxrate,Integer.parseInt(tab[i]));
		}
		
		return count;
		
	}
	public static int getMax(String ligne){
		String [] tab = ligne.split(" ");
		int max = 0;
		for(int i =0;i<tab.length-1;i++){
			max = Math.max(max,Integer.parseInt(tab[i])-Integer.parseInt(tab[i+1]));
		}
		return max;
	}
}
