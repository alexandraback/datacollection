import java.io.*;
import java.util.*;
public class senateevac{
   private static String fileName = "A-small";
   public static void main(String[] args) throws IOException{
      BufferedReader f = new BufferedReader(new FileReader(fileName+".in"));
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(fileName+".out")));
      String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      int Num=Integer.parseInt(f.readLine());
      for(int ind=0;ind<Num;ind++){
         int i = Integer.parseInt(f.readLine());
         String[] inar=f.readLine().split(" ");
         Pair[] ar = new Pair[inar.length];
         for(int x=0;x<i;x++)
            ar[x]=new Pair(Integer.parseInt(inar[x]), x);
         Arrays.sort(ar);
         int sum=0;
         for(int x=0;x<i;x++)
            sum+=ar[x].a;
         String o="";
         if(sum%2==1){
            o+=alphabet.substring(ar[i-1].b,ar[i-1].b+1);
            o+=" ";
            ar[i-1].a-=1;
            Arrays.sort(ar);
            sum-=1;
         }
         while(sum>0){
            o+=alphabet.substring(ar[i-1].b,ar[i-1].b+1);
            ar[i-1].a-=1;
            o+=alphabet.substring(ar[i-2].b,ar[i-2].b+1);
            ar[i-2].a-=1;
            o+=" ";
            Arrays.sort(ar);
            sum-=2;
         }
         
         
         out.println("Case #"+(ind+1)+": "+o);
      }
      out.close();
   }
   
   private static class Pair implements Comparable<Pair>{
      int a;
      int b;
   
      public Pair(int ma, int mb){
         a = ma;
         b = mb;
      }
   
      public int compareTo(Pair o){
         if(a == o.a){
            if(b==o.b) 
               return 0;
            return b<o.b?-1:1;
         }
         return a<o.a?-1:1;
      }
   }
}
