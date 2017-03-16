import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class R1A_B {
public static void main(String[] args) {
		String prblm="B"; boolean fl=true;
		String filein=prblm+"-"+((fl)?"large":"small")+".in.txt";
		String fileout=prblm+"-"+((fl)?"large":"small")+".out.txt";
		try {
			BufferedReader fr= new BufferedReader(new FileReader(filein));
			BufferedWriter fw= new BufferedWriter(new FileWriter(fileout));
			String s=fr.readLine();
			int T=Integer.parseInt(s);
			for (int i = 1; i <= T; i++) {
				s=fr.readLine();
				String[] tok=s.split(" ");
				int B=Integer.parseInt(tok[0]);
				int N=Integer.parseInt(tok[1]);
				s=fr.readLine();
				tok=s.split(" ");
				int[] mk=new int[B];
				int mn=Integer.MAX_VALUE;
				for (int j = 0; j < B; j++){
					mk[j]=Integer.parseInt(tok[j]);
					mn=Math.min(mn, mk[j]);
				}
				long ul=((long)mn)*N,ll=0;
				while (ul!=ll){
					long t=(ul+ll)/2;
					long rnk=0;
					for (int j = 0; j < B && rnk<=N; j++) 
						rnk+=t/mk[j]+1;
					if (rnk>=N) ul=t;
					else ll=Math.max(t, ll+1);
				}
				long rnk=0,b=0;
				for (int j = 0; j < B; j++) rnk+=(ul-1)/mk[j]+1;
				for (int j = 0; j < B; j++){
					if (ul%mk[j]==0) rnk++;
					if (rnk==N) {b=j+1; break;}
				}
				System.out.println((rnk==N)+" "+b);
				fw.write("Case #"+i+": "+ b  +"\n");
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}