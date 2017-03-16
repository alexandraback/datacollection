import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Repeater {
	private static int[][] chars;
	private static char[] carac;
	public static void main(String[] args) throws Exception{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T =Integer.parseInt(in.readLine());
		for (int caso = 1; caso <=T; caso++) {
			int N = Integer.parseInt(in.readLine());
			carac = new char[105];
			int ind=0;
			int idx=0;
			String prim = in.readLine();
			while(idx<prim.length())
			{
				char act = prim.charAt(idx);
				while(true)
				{
					if(idx+1<prim.length() && prim.charAt(idx+1)==act)
					{
						idx++;
					}
					else
						break;
				}
				carac[ind]=act;
				ind++;idx++;
			}
			boolean imp = false;
			chars = new int[N][ind];
			for (int i = 0; i < N; i++) {
				if(i!=0)
					prim = in.readLine();
				if(imp)
					continue;
				int indice=0;
				idx=0;
				int cnt=0;
				while(idx<prim.length())
				{
					char act = prim.charAt(idx);
					if(indice==ind)
					{
						imp=true;
						break;
					}
					if(act!=carac[indice])
					{
						imp=true;
						break;
					}
					cnt=1;
					while(true)
					{
						if(idx+1<prim.length() && prim.charAt(idx+1)==act)
						{
							idx++;cnt++;
						}
						else
							break;
						
					}
					chars[i][indice]=cnt;
					idx++;indice++;
				}
				if(indice!=ind)
					imp=true;
			}
			int camb = 0;
			for (int i = 0; i < ind && !imp; i++) {
				int min = Integer.MAX_VALUE;
				for (int j = 0; j < N && !imp; j++) {
					int act = 0;
					for (int k = 0; k < N; k++) {
						act+= Math.abs(chars[j][i] - chars[k][i]);
					}
					min = Math.min(act, min);
				}
				camb+=min;
			}
			System.out.print("Case #"+caso+": ");
			if(imp)
				System.out.println("Fegla Won");
			else
				System.out.println(camb);
		}
	}

}
