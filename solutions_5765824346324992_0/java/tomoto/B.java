import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.SortedSet;
import java.util.TreeSet;

public class B {
	public static void main(String[] args) throws FileNotFoundException {
		new B().run();
	}
	
	private static final String FILE = "../B-small-attempt1";
	
	private Scanner scanner;
	private PrintWriter out;
	
	void run() throws FileNotFoundException {
		scanner = new Scanner(new File(FILE + ".in"));
		out = new PrintWriter(new File(FILE + ".out"));
		
		int n = scanner.nextInt();
		for (int i = 1; i <= n; i++) {
			solve(i);
		}
		
		scanner.close();
		out.close();
	}
	
	void solve(int index) {
		int numberOfBarbers = scanner.nextInt();
		int myPosition = scanner.nextInt();
		
		TreeSet<Barber> barbers = new TreeSet<>();
		
		int cycleOfMinutesToTake = 1;
		for (int i = 1; i <= numberOfBarbers; i++) {
			int minutesToTake = scanner.nextInt();
			barbers.add(new Barber(i, minutesToTake, 0));
			cycleOfMinutesToTake *= minutesToTake;
		}
		
		int cycleOfCustomers = 0;
		for (Barber b : barbers) {
			cycleOfCustomers += cycleOfMinutesToTake / b.minutesToTake;
		}
		
		// System.err.println(cycleOfMinutesToTake);
		myPosition %= cycleOfCustomers;
		if (myPosition == 0) {
			myPosition = cycleOfCustomers;
		}
		
		// System.err.println(myPosition + ": " + barbers.toString());
		
		Barber myBarber = null;
		
		while (myPosition-- > 0) {
			// take the first barber
			myBarber = barbers.first();
			barbers.remove(myBarber);
			
			for (Barber b : barbers) {
				b.busyFor -= myBarber.busyFor; 
			}
			
			myBarber.busyFor = myBarber.minutesToTake;
			
			barbers.add(myBarber);
			
			// System.err.println(myBarber.index + " taken");
			// System.err.println(myPosition + ": " + barbers.toString());
		}
		
		out.println("Case #" + index + ": " + myBarber.index);
		out.flush();
	}
	
	public static class Barber implements Comparable<Barber> {
		public int index;
		public int minutesToTake;
		public int busyFor;
		
		public Barber(int index, int minutesToTake, int busyFor) {
			this.index = index;
			this.minutesToTake = minutesToTake;
			this.busyFor = busyFor;
		}

		@Override
		public int compareTo(Barber o) {
			if (busyFor == o.busyFor) {
				return Integer.compare(index, o.index);
			} else {
				return Integer.compare(busyFor, o.busyFor);
			}
		}
		
		@Override
		public String toString() {
			return "(" + index + " " + minutesToTake + " " + busyFor + ")"; 
		}
		
	}
	
	
}

