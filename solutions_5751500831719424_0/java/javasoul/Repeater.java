import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;
import java.awt.geom.*;
import java.io.*;
import java.awt.*;

public class Repeater{
    public static void main(String[] args){
        new Repeater();
    }

    String getToken(String s)
    {
      char[] all = s.toCharArray();
      String res=""+all[0];
      for(int i=1;i<all.length;i++)
         if(all[i]!=all[i-1])
           res+=""+all[i];
       return res;
    }
    boolean IsEqual(String s, String token)
    {
       return token.equals(getToken(s));
    }
    int[] getLength(String s, int tl)
    {
       int[] res=new int[tl];
       int index=0;
       char[] all=s.toCharArray();
       res[0]=1;
       for(int i=1;i<all.length;i++)
       {
         if(all[i]!=all[i-1])
            index++;
            res[index]++;
       }
       return res;
    }
    Repeater()
    {
        try{
            int TTC=0;
            int index=1;

            File inFile=new File("./A-small.in");
            File outFile=new File("./A-small.out");
            if(outFile.exists())
               outFile.delete();
            boolean bool=outFile.createNewFile();
            RandomAccessFile rac=new RandomAccessFile(inFile,"r");
            TTC=Integer.parseInt(rac.readLine());
            String res="";

            while(TTC>0)
            {
                res="";
                int n= Integer.parseInt(rac.readLine());
                String[] all = new String[n];
                for(int i=0;i<n;i++)
                  all[i]=rac.readLine();
                String token = getToken(all[0]);
                boolean fail=false;
                for(int i=1;i<n;i++)
                   if(!IsEqual(all[i],token))
                   {
                     fail=true;
                     break;
                   }
                if(fail)
                  res="Fegla Won";
                else
                {
                   int tl = token.length();
                   int[][] count = new int[n][tl];
                   for(int i=0;i<n;i++)
                       count[i]=getLength(all[i],tl);
                   int[] rest = new int[tl];
                   for(int i=0;i<tl;i++)
                   {
                     int[] alltl=new int[101];
                     int min=100;
                     int max=1;
                     for(int j=0;j<n;j++){
                        int no=count[j][i];
                        if(no>max) max=no;
                        if(no<min) min=no;
                        alltl[no]++;
                     }
                     if(min==max)
                       rest[i]=0;
                     else
                     {
                        int[] cost=new int[max-min+1];
                        for(int k=min;k<=max;k++)
                        {
                           for(int l=min;l<=max;l++)
                           {
                             if(l==k) continue;
                             if(alltl[l]==0) continue;
                             cost[k-min]+=Math.abs(l-k)*alltl[l];
                           }
                        }
                        Arrays.sort(cost);
                        rest[i]=cost[0];
                     }
                   }
                   for(int i=1;i<tl;i++)
                     rest[0]+=rest[i];
                   res=""+rest[0];
                }
                RandomAccessFile rac2=new RandomAccessFile(outFile,"rw");
                rac2.seek(rac2.length());
                rac2.writeBytes("Case #"+index+": "+res);
                rac2.writeBytes("\r\n");
                rac2.close();
                index++;
                TTC--;
            }
            rac.close();
        }catch(Exception e)
        {
            System.out.println("Error: "+e.getMessage());
            e.printStackTrace();
        }
 }
}