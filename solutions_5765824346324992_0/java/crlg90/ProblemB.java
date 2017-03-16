import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class ProblemB {
	
	public static int MAX_TIME = 100000;

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(br.readLine().trim());
		String linea;
		long posLine;
		int barbers;
		int barberTimes[];
		for(int c=1; c<=cases; c++){
			linea = br.readLine();
			StringTokenizer st = new StringTokenizer(linea);
			barbers = Integer.parseInt(st.nextToken());
			posLine = Long.parseLong(st.nextToken());
			linea = br.readLine();
			barberTimes = new int[barbers+1];
			st = new StringTokenizer(linea);
			for(int i=1; i<=barbers; i++)
				barberTimes[i] = Integer.parseInt(st.nextToken());
			long mcm = mcm(barberTimes);
			ArrayList<Integer> seq = new ArrayList<Integer>();
			for(int i=0;i<mcm;i++){
				for(int j = 1; j<barberTimes.length; j++){
					if (i % barberTimes[j] == 0)seq.add(j);
				}
			}
			//System.out.println(Arrays.toString(barberTimes));
			//System.out.println("MCM: " + mcm);
			
			/*System.out.println("SEQ: ");
			for(int i=0; i<seq.size();i++){
				System.out.print(seq.get(i) + " ");
			}*/
			System.out.println("Case #" + c + ": " + seq.get((int)((posLine-1) % seq.size())));
			
			
		}
	}
	public static long mcm (int[] barbers){
		int count1 = 0;
		int mcm = 1;
		int copy[] = new int[barbers.length-1];
		for(int i=1; i<barbers.length; i++){
			copy[i-1] = barbers[i];
			if(copy[i-1] == 1) count1++;
		}
		int divisor = 2;
		while(divisor <= MAX_TIME && count1 != barbers.length){
			int division = 0;
			for(int i=0; i<copy.length; i++){
				if(copy[i]%divisor == 0){
					copy[i]/= divisor;
					division++;
					if(copy[i] == 1)count1++;
				}
			}
			if (division > 0){
				mcm *= divisor;
			}else{
				divisor++;
			}
		}
		return mcm;
	}
}
