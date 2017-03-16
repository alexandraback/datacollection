import java.util.*;
import java.io.*;
import java.lang.Math;
import java.math.*;

class Barber implements Comparable<Barber>{
	int minutes;
	int remainings;
	int index;
	Barber(int a, int i){
		minutes = a;
		remainings = a;
		index = i;
	}

	void decreaseTime(int m){
		remainings -= m;
	}

	@Override
	public int compareTo(Barber b){
		if(this.remainings > b.remainings){
			return 1;
		} else if(this.remainings == b.remainings){
			if(this.index < b.index){
				return -1;
			} else if (this.index > b.index){
				return 1;
			} else
				return 0;
		} else {
			return -1;
		}
	}
}


public class Q2{
	public static int commonDivisor(int n,int m){
		while(n % m != 0){
			int temp= n % m;
			n = m;
			m = temp;
		}
		return m;
	}

	public static int commonMultiple(int n, int m){
		return n * m / commonDivisor(n, m);
	}

	public static void main(String args[]){
		File f = new File(args[0]);
		try{
			Scanner s = new Scanner(f);
			int time = Integer.parseInt(s.next());
			PrintWriter writer = new PrintWriter("output.txt", "UTF-8");
			for(int in = 1; in <= time; in++) {
				int min = -1;
				int numB = Integer.parseInt(s.next());
				int n = Integer.parseInt(s.next());
				
					Barber[] barber = new Barber[numB];
					for(int i = 0; i < numB; i++){
						barber[i] = new Barber(Integer.parseInt(s.next()), i + 1);
					}

					if(n <= numB){
						min = n;
					} else {
						n = n - numB;
						int times = 1;
						for(Barber b : barber){
							times *= b.minutes;
						}
						// in a period how many people have gone:
						int people = 0;
						for(Barber b : barber){
							people += times / b.minutes;
						}
						n = n % people;
						if(n == 0){n = people;}
						for(int i = 0; i < n; i++){
							Arrays.sort(barber);
							int mi = barber[0].remainings;
							for(Barber b : barber){
								b.decreaseTime(mi);
							}
							barber[0].remainings = barber[0].minutes;
							
						}
						min = barber[0].index;
					}
				System.out.println("Finished: " + in + " result: " + min);
				writer.println("Case #" + in + ": " + min);
			}
			writer.close();
		}catch (Exception e){
			e.printStackTrace();
		}
	}
}
