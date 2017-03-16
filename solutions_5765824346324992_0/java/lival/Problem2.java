
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Pivis
 */
public class Problem2 {
    public static class Barber implements Comparable {
        private long initial;
        private long current;
        private long index;
        
        public Barber(long i, long c, long ind) {
            initial = i;
            current = c;
            index = ind;
        }
        
        @Override
        public int compareTo(Object o) {
            Barber that = (Barber) o;
            if (this.current == that.current) {
                return (this.index - that.index > 0) ? 1 : -1 ;
            }
            return (this.current - that.current > 0) ? 1 : -1;
                    
        }
    }
    
    public static void main(String[] args) throws FileNotFoundException, IOException {
        File f = new File("C:\\Users\\Pivis\\Documents\\NetBeansProjects\\GCJ2\\src\\a.in");
        File out = new File("C:\\Users\\Pivis\\Documents\\NetBeansProjects\\GCJ2\\src\\a.out");
        Scanner in = new Scanner(new FileReader(f));
        BufferedWriter output = new BufferedWriter(new FileWriter(out));
        
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            int B = in.nextInt();
            int N = in.nextInt();
            long[] barbers = new long[B];
            for (int j = 0; j < B; j++) {
                barbers[j] = in.nextLong();
            }
         String text = "Case #" + (i+1) + ": " + find2(barbers, N) + "\n";
            output.write(text);
            
        }
        output.close();
    }
    
    public static long find2(long[] a, int N) {
        int B = a.length;
        if (N < B) return N;
        long lcm = lcm(a);
        
        int sum = 0;
        for (int i = 0; i < B; i++) {
            sum += lcm/a[i];
        }
        N = N%sum == 0 ? sum : N%sum;
        return find (a, N);
    }
    private static long gcd(long a, long b) {
        while (b > 0) {
            long temp = b;
            b = a % b; // % is remainder
            a = temp;
        }
        return a;
    }

    private static long gcd(long[] input) {
        long result = input[0];
        for (int i = 1; i < input.length; i++) {
            result = gcd(result, input[i]);
        }
        return result;
    }

    private static long lcm(long a, long b) {
        return a * (b / gcd(a, b));
    }

    private static long lcm(long[] input) {
        long result = input[0];
        for (int i = 1; i < input.length; i++) {
            result = lcm(result, input[i]);
        }
        return result;
    }

    
    public static long find (long[] a, int N) {
        
        int B = a.length;
        if (N <= B) return N;
        int counter = B; 
       
        PriorityQueue<Barber> pq = new PriorityQueue<>();
        for (int i = 0; i < B; i++) {
            Barber b = new Barber(a[i], a[i], i);
            pq.add(b);
        }
        while (counter < N - 1) {
            Barber b = pq.poll();
            counter++;
            b.current += b.initial;
            pq.add(b);
        }
        return pq.peek().index + 1;
    }
}
