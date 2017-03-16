import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;

public class Rnd1A {
public static void main(String[] args) {
		String prblm="A"; boolean fl=!true;
		String filein=prblm+"-"+((fl)?"large":"small")+".in.txt";
		String fileout=prblm+"-"+((fl)?"large":"small")+".out.txt";
		try {
			BufferedReader fr= new BufferedReader(new FileReader(filein));
			BufferedWriter fw= new BufferedWriter(new FileWriter(fileout));
			String s=fr.readLine();
			int T=Integer.parseInt(s);
			for (int i = 1; i <= T; i++) {
				s=fr.readLine();
				int N=Integer.parseInt(s);
				String[] wds=new String[N];
				ArrayList<Integer> chs=new ArrayList<Integer>();
				for (int j = 0; j < N; j++) 
					wds[j]=fr.readLine();
				int lch=-1;
				for (int j = 0; j < wds[0].length(); j++) {
					int ch=wds[0].charAt(j)-'a';
					if (ch==lch) continue;
					chs.add(ch); lch=ch;
				}
				int[][] rep=new int[chs.size()][N];
				int j,k=0;
				boolean fg=true;
				for (j = 0; j < N && fg; j++){
					lch=-1;
					int ind=0;
					for (k = 0; k < wds[j].length() && fg; k++) {
						int ch=wds[j].charAt(k)-'a';
						if (ch==lch) { rep[ind-1][j]++; continue;}
						if (ind<chs.size() && chs.get(ind)==ch){
							rep[ind][j]++;
							lch=ch; ind++;
						}
						else fg=false;
					}
					if (ind<chs.size()) fg=false;
				}
				//System.out.println(j+" "+k+" "+chs);
				int tt=0;
				if (fg) {
					for (j = 0; j < chs.size(); j++) {					
						Arrays.sort(rep[j]);
						int md=rep[j][(N-1)/2];
						for (k = 0; k < N; k++) {
							tt+=Math.abs(rep[j][k]-md);
						}
					}
					s=""+tt;
				}
				else s="Fegla Won";
				System.out.println(s);
				fw.write("Case #"+i+": "+ s  +"\n");
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}