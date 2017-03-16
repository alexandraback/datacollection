package y2015.round1a;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Haircut {

	private static final String FILES_PATH = "E:\\DL\\gcj\\2015\\round1A\\";
	private static final String IN_EXT = ".in";
	private static final String OUT_EXT = ".out";
	
	private static final String FILE_NAME = "B-small-attempt0";

	public static void main(String[] args) throws IOException {
		 Scanner in = new Scanner(new File(FILES_PATH + FILE_NAME + IN_EXT));
		 FileWriter fw = new FileWriter(new File(FILES_PATH + FILE_NAME + OUT_EXT));
		 
		 int nbTests = in.nextInt();
		 in.nextLine();
		 
		 int nbBarbers, myPlace;
		 long ppcm;
		 Barber b = null;
		 
		 PriorityQueue<Barber> queue;
		 List<Barber> rotation;
		 for(int i = 0; i < nbTests; i++) {
			 nbBarbers = in.nextInt();
			 myPlace = in.nextInt();
			 in.nextLine();
			 
			 ppcm = 1;
			 queue = new PriorityQueue<Barber>();
			 
			 for(int j = 0; j < nbBarbers; j++) {
				 b = new Barber(j + 1, in.nextInt());
				 queue.add(b);
				 ppcm = calc_PPCM(ppcm, b.cuteTime);
			 }
			 
			 rotation = new ArrayList<Barber>();
			 
			 b = queue.poll();
			 while(b.nextCut < ppcm) {
				 rotation.add(b);
				 b.nextCut += b.cuteTime;
				 queue.add(b);
				 b = queue.poll();
			 }
			 
			 fw.write("Case #" + (i+1) + ": " + rotation.get((myPlace - 1) % rotation.size()).num + "\n");
			 in.nextLine();
			 
		 }
		
		 fw.close();
		 in.close();
	}
	
	private static class Barber implements Comparable<Barber> {
		public int num;
		public int cuteTime;
		public long nextCut;
		public Barber(int num, int cuteTime) {
			this.num = num;
			this.cuteTime = cuteTime;
			this.nextCut = 0L;
		}
		@Override
		public int compareTo(Barber b) {
			if(this.nextCut == b.nextCut) {
				return this.num - b.num;
			}
			return Long.valueOf(this.nextCut).compareTo(b.nextCut);
		}
		public String toString() {
			return "b" + num + "/" + nextCut;
		}
	}
	
	private static long calc_PPCM(long Nb1, long Nb2) {
		long Produit, Reste;
			
		Produit = Nb1 * Nb2;
		Reste = Nb1 % Nb2;
		while(Reste != 0) {
		    Nb1 = Nb2;
		    Nb2 = Reste;
		    Reste = Nb1 % Nb2;
	    }
		return Produit/Nb2;
    }
	
}
