import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Scanner;

public class P1 {

    static int T;
    static int N;
    static Node[] nodes;
    
    public static void main(String[] args) {
        Scanner scan;

        try {
            FileWriter fstream = new FileWriter("out.txt");
            BufferedWriter out = new BufferedWriter(fstream);
            scan = new Scanner(new File("input.txt"));
            
            T = scan.nextInt();
            int total;
            for (int t=0; t<T; t++) {
                total = 0;
                N = scan.nextInt();
                nodes = new Node[N];
                
                for (int i=0;i<N;i++) {
                    nodes[i] = new Node(i, scan.nextInt());
                    //nodes[i].p = i;
                    //nodes[i].n = scan.nextInt();
                    total += nodes[i].n;
                }
                Arrays.sort(nodes);
                StringBuilder result = new StringBuilder();
                String space = "";
                while(total > 0) {
                    result.append(space);
                    result.append((char)('A'+nodes[0].p));
                    nodes[0].n--;
                    total--;
                    if (nodes[1].n>total/2) {
                        result.append((char)('A'+nodes[1].p));
                        nodes[1].n--;
                        total--;
                    }
                    space = " ";
                    Arrays.sort(nodes);
                }
                    
                out.write("Case #" + (t+1) + ": " + result + "\n");
                out.flush();
                //out.close();
            }
            

        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
    
    
    
   
}

class Node implements Comparable<Node>{
    int n,p;
    public  Node(int p, int n) {
        this.p=p;
        this.n=n;
    }
    @Override
    public int compareTo(Node arg0) {
        // TODO Auto-generated method stub
        return arg0.n-this.n;
    }
}
