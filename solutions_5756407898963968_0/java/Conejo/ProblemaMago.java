import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;


public class ProblemaMago {
	public static void main(String[] args) throws IOException{
		BufferedReader bf = new BufferedReader(new FileReader("input_mago.txt"));
		int nTest = Integer.parseInt(bf.readLine());
		for(int t = 1;t<=nTest;t++){
			Set<Integer> set1 = new HashSet<>();
			Set<Integer> set2 = new HashSet<>();
			int answer1 = Integer.parseInt(bf.readLine());
			for(int i = 1;i<=4;i++){
				//4 filas
				String[] fila = bf.readLine().split(" ");
				if(answer1 != i)
					continue;
				for(String numero: fila)
					set1.add(Integer.parseInt(numero));
			}
			int answer2 = Integer.parseInt(bf.readLine());
			for(int i = 1;i<=4;i++){
				//4 filas
				String[] fila = bf.readLine().split(" ");
				if(answer2 != i)
					continue;
				for(String numero: fila)
					if(set1.contains(Integer.parseInt(numero)))
						set2.add(Integer.parseInt(numero));
			}
			System.out.print("Case #"+t+": ");
			if(set2.size()>1)
				System.out.println("Bad magician!");
			if(set2.size()==1)
				System.out.println(set2.iterator().next());
			if(set2.size()==0)
				System.out.println("Volunteer cheated!");
		}
	}
}
