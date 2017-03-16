import java.util.*;

public class B implements Comparable<B>{
public static void main(String [] args) {
	Scanner scanner = new Scanner(System.in);
	int nCase = scanner.nextInt();
	
	for (int nc = 1; nc <= nCase; nc++) {
		int B = scanner.nextInt();
		int N = scanner.nextInt();
		int[] M = new int[B];
		for (int i = 0; i < B; i++)
			M[i] = scanner.nextInt();
		PriorityQueue<B> pq = new PriorityQueue<B>();
		for (int i = 0; i < B; i++)
			pq.add(new B(0, i+1));
		
		int end = 1;
		for (int i = 0; i < B; i++)
			end = lcm(end, M[i]);
		
		LinkedList<Integer> list = new LinkedList<Integer>();
		while (pq.peek().time < end) {			
			B thisB = pq.poll();
			list.add(thisB.no);
			pq.add(new B(thisB.time + M[thisB.no-1], thisB.no));
		}
		
		int need = (N-1) % list.size();
		
		while (need-- > 0) {
			list.remove();
		}
		
		System.out.println("Case #" + nc + ": " + list.remove());
	}
}

static int gcd(int a, int b) {
	while (b != 0) {
		int t = b;
		b = a%b;
		a = t;
	}
	return a;
}
static int lcm(int a, int b) {
	return a/gcd(a,b) * b;
}

int time;
int no;
public  B(int a, int b) {
	time = a;
	no = b;
}
public int compareTo(B o) {
	int diff = time - o.time;
	if (diff != 0) return diff;
	else return no - o.no;
}
}