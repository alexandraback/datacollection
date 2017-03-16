import java.util.*;
import java.io.*;
public class B{
public static long res = 0;
public static boolean mat[][];
public static void main(String args[]) throws IOException{
BufferedReader lector = new BufferedReader(new InputStreamReader(System.in));
int cases = Integer.parseInt(lector.readLine());
for(int c =1;c<=cases;c++){
String t[] = lector.readLine().split(" ");
int a = Integer.parseInt(t[0]);
int b = Integer.parseInt(t[1]);
int d = Integer.parseInt(t[2]);
mat = new boolean[a][b];
res = (a-1)*b+(b-1)*a;
hagale(0,0,d,0);
System.out.println("Case #"+c+": "+res);
}
}
public static void hagale(int a,int b,int c,int d){
if(c==0 && a*mat[0].length+b==mat.length*mat[0].length && d<res){
res = d;
return;
}
if(a*mat[0].length+b==mat.length*mat[0].length)return;
if(c<0 || d>res)return;
mat[a][b] = true;
int p = 0;
if(a-1>-1 && mat[a-1][b])p++;
if(b-1>-1 && mat[a][b-1])p++;
hagale((b==mat[0].length-1?a+1:a),(b==mat[0].length-1?0:b+1),c-1,d+p);
mat[a][b] = false;
hagale((b==mat[0].length-1?a+1:a),(b==mat[0].length-1?0:b+1),c,d);
}
}
