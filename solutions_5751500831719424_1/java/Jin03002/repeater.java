import java.io.*;
import java.util.*;
public class repeater{
   public static void main(String[] args) throws IOException{
      BufferedReader f = new BufferedReader(new FileReader("A-large.in"));
      PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("gjc.out")));
      int T=Integer.parseInt(f.readLine());
      for(int c=0;c<T;c++){
         boolean bool=true;
         int number=0;
         int N=Integer.parseInt(f.readLine());
         String[] ar=new String[N];
         for(int x=0;x<N;x++)
            ar[x]=f.readLine();
         String cur=ar[0].substring(0,1);
         int curind=0;
         int[] ind=new int[N];
         int[] num=new int[N];
         if(c==74) System.out.println(ar[0]+"   "+ar[1]);
         while(curind<ar[0].length()){
            cur=ar[0].substring(curind,curind+1);
            for(int y=0;y<N;y++){
               if(ind[y]>=ar[y].length()) bool=false;
               else if(ar[y].substring(ind[y],ind[y]+1).compareTo(cur)!=0) bool=false;
               else{
                  num[y]=0;
                  while(ar[y].substring(ind[y],ind[y]+1).compareTo(cur)==0){
                     ind[y]++;
                     if(ind[y]>=ar[y].length()) break;
                     num[y]++;
                  }
               }
            }
            number+=find(num);
            curind=ind[0];
         }
         for(int x=0;x<N;x++)
            if(ar[x].length()!=ind[x]) bool=false;
         if(!bool)
            out.println("Case #"+(c+1)+": Fegla Won");
         else
            out.println("Case #"+(c+1)+": "+number);
      }
      out.close();
   }
   
   public static int find(int[] ar){
      int min=Integer.MAX_VALUE;
      for(int x=1;x<ar.length;x++){
         int temp=0;
         for(int y=0;y<ar.length;y++)
            temp+=Math.abs(ar[x]-ar[y]);
         min=Math.min(temp,min);
      }
      return min;
   }
}