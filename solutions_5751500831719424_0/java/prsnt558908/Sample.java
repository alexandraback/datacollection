import java.io.*;
import java.util.*;
import static java.lang.Math.*;
//import java.util.logging.Level;
//import java.util.logging.Logger;
public class Sample

{
     BufferedReader read;
     BufferedWriter write;
    public static void main(String args[]) throws Exception
    {
        new Sample().init("A-small-attempt0");
    }
     void init(String name) throws Exception
    {
        
        read= rf(name+".in");
        write=wf(name+".out");
        String x="";
        x = read.readLine();
        int n = Integer.parseInt(x);
        for(int i=0;i<n;i++) result( i);
        write.flush(); write.close();read.close();
   }
int cnt[][],n,l,inf=1<<25;
String s[],common;
void result(int p) throws Exception
{
    n=i(read.readLine());
    s=new String[n];
    for(int i=0;i<n;i++)s[i]=read.readLine();
   common=get(s[0]);
   for(String ss:s)if(!get(ss).equals(common))
   {
       String s1="Fegla Won";
       System.out.println("Case #"+(p+1)+": "+s1);
       write.write("Case #"+(p+1)+": "+s1+"\n");
       return;
   }
   long ans=0;
   l=common.length();
   cnt=new int[n][l];
   //System.out.println(common+"  "+l);
   for(int i=0;i<n;i++)get(s[i],cnt[i]);
   //for(int i[]:cnt)System.out.println(" len "+i.length+"  array "+Arrays.toString(i));
   for(int i=0;i<l;i++)
   {
       int mn=inf;
       for(int j=1;j<105;j++)mn=min(mn,mn(j,i));
       ans+=mn;
   }
   
    String s1=""+ans;
    System.out.println("Case #"+(p+1)+": "+s1);
    write.write("Case #"+(p+1)+": "+s1+"\n");
}
int mn(int p,int j)
 {
    int ans=0;
    for(int i=0;i<n;i++)ans+=abs(cnt[i][j]-p);
    return ans;
}
String get(String s)
{
    String ans=""+s.charAt(0);
    for(int i=1;i<s.length();i++)if(s.charAt(i)!=s.charAt(i-1))ans+=s.charAt(i);
   // System.out.println(s+"   "+ans);
    return ans;
}
void get(String s,int a[])
{
    Arrays.fill(a,1);
    int i=0;
    for(int j=1;j<s.length();j++)if(s.charAt(j)==s.charAt(j-1))a[i]++;else i++;
}
boolean isPalindrome(long l)
{
   char c[]=(""+l).toCharArray();
   for(int i=0;i<c.length;i++)if(c[i]!=c[c.length-i-1])return false;
   return true;
}
int i(String s){return Integer.parseInt(s.trim());}
long l(String s){return Long.parseLong(s.trim());}
double d(String s){return Double.parseDouble(s.trim());}
 int[] ia(String s1){String s[]=s1.trim().split(" ");int p[]=new int[s.length];for(int i=0;i<s.length;i++)p[i]=Integer.parseInt(s[i]);return p;}
 long[] la(String s)
 {
     String s1[]=s.split(" ");
     long la[]=new long[s1.length];
     for(int i=0;i<s1.length;i++)la[i]=l(s1[i]);
     return la;
 }
 double [] ld(String s)
  {
    String s1[]=s.split(" ");
    int l=s1.length;
   double d[]=new double[l];
   for(int i=0;i<l;i++)d[i]=d(s1[i]);
   return d;
 }
static BufferedWriter wf(String s) throws Exception{return new BufferedWriter(new FileWriter(new File(s)));}
static BufferedReader rf(String s) throws Exception{return new BufferedReader(new FileReader(new File(s)));}
static BufferedReader ri() throws Exception{return new BufferedReader(new InputStreamReader(System.in));}
}
