import java.io.PrintWriter;
import java.util.ArrayList;

public class HairCut {
	public static void main(String[]args){
		new Reader();
		ArrayList<String> texte = Reader.getAllLines("/home/romain/Downloads/B-small-attempt1.in");
		
		
		PrintWriter writer = Reader.getWriter("/home/romain/Downloads/output.txt");
		int count =1;
		
		for(int i =1;i<texte.size();i=i+2){
			String [] tab1 = texte.get(i).split(" ");
			int result =proceed(Integer.parseInt(tab1[1]),texte.get(i+1));
			System.out.println("Case #"+count+": "+result);
			
			writer.println("Case #"+count+": "+result);
			count++;
		}
		
		
		writer.close();
			
	}
	public static int proceed(int position,String ligne){
		 String [] tab = ligne.split(" ");
		 int [] tr = new int[tab.length];
		 for(int i=0;i<tr.length;i++){
			 tr[i]=0;
		 }
		 int ppcm = Integer.parseInt(tab[0]);
		 for(int i =0;i<tab.length;i++){
			 ppcm = P(ppcm,Integer.parseInt(tab[i]));
		 
		 }
		 System.out.println("ppcm : "+ppcm);
		 int c=0;
		 for(int i=0;i<tab.length;i++){
			 c = c+ (int) (ppcm/Integer.parseInt(tab[i]));
		 
		 }
		 
		 position = (position%c)+c;
		 
		 while(position>0){
			 System.out.println(position);
			 for(int i=0;i<tr.length;i++){
				 if(tr[i]==0&&position!=1){
					 tr[i]= Integer.parseInt(tab[i]);
					 position--;
				 }
				 else if(tr[i]==0&&position==1){
					 position--;
					 return i+1;
					 
				 }
				 tr[i]--;
			 }
			 
		 }
		 return 0;
		
	}
	
	public static int P(int X,int Y)
	{
	  int A=X;
	  int B=Y;
	  while (A!=B)
	  {
	    while (A>B) B=B+Y;
	    while (A<B) A=A+X;
	  }
	  return A;
	}
	
}