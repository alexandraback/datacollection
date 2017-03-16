import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class R1A_C {
public static void main(String[] args) {
		String prblm="C"; boolean fl=!true;
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
				int[] xi=new int[N];
				int[] yi=new int[N];
				for (int j = 0; j < N; j++) {
					s=fr.readLine();
					String[] tok=s.split(" ");
					xi[j]=Integer.parseInt(tok[0]);
					yi[j]=Integer.parseInt(tok[1]);
				}
				s="";
				for (int j = 0; j < N; j++) {
					int mn=Integer.MAX_VALUE;
					if (N<=3) mn=0;
					else {
						for (int k = 0; k < yi.length; k++) {
							if (k==j) continue;
							int l=0,r=0;
							long dx=xi[j]-xi[k],dy=yi[j]-yi[k];						
							for (int h = 0; h < yi.length; h++) {
								if (h==j || h==k) continue;
								int ndx=xi[j]-xi[h],ndy=yi[j]-yi[h];
								long v=-dx*ndy+dy*ndx;
								if (v>0) l++;
								else if (v<0) r++;
							}
							mn=Math.min(mn, Math.min(l, r));
						}
					}
					s+="\n"+mn;
				}
				System.out.println(s);
				fw.write("Case #"+i+":"+ s  +"\n");
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}