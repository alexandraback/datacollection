import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class A {
	public static void main (String [] args) throws IOException {new A().run();}
	public void run() throws IOException{
		Scanner file = new Scanner(new File("A-small-attempt0.in.txt"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A.out")));
		int T = file.nextInt();
        for(int asdf = 0; asdf<T; asdf++){
            out.printf("Case #%d: ",asdf+1);
            TreeSet<Integer> set = new TreeSet<Integer>(), set2 = new TreeSet<Integer>();
            for(int k = 0, row = file.nextInt(); k<2; k++){
                for(int i = 0; i<4; i++)
                    for(int j = 0; j<4; j++)
                        if( i == row-1){
                            if( k == 0) set.add(file.nextInt());
                            else set2.add(file.nextInt());
                        }else file.nextInt();
                if( k == 0)
                    row = file.nextInt();
            }
            set.retainAll(set2);
            if( set.isEmpty())out.println("Volunteer cheated!");
            else if( set.size() > 1 )out.println("Bad magician!");
            else out.println(set.iterator().next());
        }
		out.close();
	}
}