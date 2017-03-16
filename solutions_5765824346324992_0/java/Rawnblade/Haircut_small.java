import java.io.File;
import java.io.PrintWriter;
import java.util.*;

public class Haircut_small{
	static PrintWriter out;
	public static void main(String[] args) throws Exception{
		Scanner reader = new Scanner(System.in);
		out = new PrintWriter(new File("a.out"));
		
		int times = reader.nextInt();
		for(int t = 1; t <= times; t++){
			int n = reader.nextInt();
			int x = reader.nextInt() - 1;
			
			int[] v = new int[n];
			for(int i = 0; i < n; i++)
				v[i] = reader.nextInt();
			
			//Sim until cycle
			int[] f = new int[n];
			HashMap<String, Integer> map = new HashMap<String, Integer>();
			ArrayList<Integer> barbs = new ArrayList<Integer>();
			int start = -1;
			
			String key = Arrays.toString(f);
			while(true){
//				System.out.println(key);
				map.put(key, barbs.size());
				
				boolean change = false;
				//Assign barbers
				for(int i = 0; i < n; i++){
					if(f[i] == 0){
						barbs.add(i);
						f[i] = v[i];
						change = true;
					}
				}
				
				if(change){
					key = Arrays.toString(f);
					if(map.containsKey(key)) break;
					map.put(key, barbs.size());
				}
				
				//Cut hair
				for(int i = 0; i < n; i++)
					if(f[i] > 0) f[i]--;
				
				key = Arrays.toString(f);
				if(map.containsKey(key)) break;
			}
			
//			print(barbs.size() + " " + barbs.toString());
			print("Case #"+t+": "+chooseBarber(x,map.get(key),barbs));
		}
		
		out.close();
	}
	
	public static int chooseBarber(int x, int r, ArrayList<Integer> b){
		if(x < b.size())
			return b.get(x)+1;
		return b.get((x - r) % b.size() + r) + 1;
	}
	
	public static void print(String msg){
		out.println(msg);
		System.out.println(msg);
	}
}
