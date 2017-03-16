import java.util.*;
import java.io.*;
public class aa{
public static PrintWriter out = new PrintWriter(System.out);//HACER FLUSHHHH
public static void main(String args[]) throws IOException{
BufferedReader lector = new BufferedReader(new InputStreamReader(System.in));
int a =Integer.parseInt(lector.readLine());
for(int aa = 1;aa<=a;aa++){
int res = 0;
boolean pude = true;
int b = Integer.parseInt(lector.readLine());
String p = "";
int mat[][] = new int[2][2];
for(int bb = 0;bb<b;bb++){
String tal = lector.readLine();
Vector<Integer> joder = new Vector<Integer>();
for(int pj = 0,c=0;pj<tal.length();c++){
if(bb==0)p+=tal.charAt(pj);
int pp = pj;
if(bb!=0 && c>=p.length())pude=false;
if(pude && bb!=0 && p.charAt(c)!=tal.charAt(pj))pude = false;

while(pp<tal.length() && tal.charAt(pj)==tal.charAt(pp))pp++;
joder.add(pp-pj);
if(bb!=0 && pude)
mat[bb][c]=pp-pj;
pj=pp;
}
if(bb==0){
mat = new int[b][p.length()];
for(int x = 0;x<mat[0].length;x++)mat[0][x]=joder.get(x);
//System.out.println(p+" "+joder);
}
}
//for(int n =  0;n<mat.length;n++,System.out.println())
//for(int m = 0;m<mat[n].length;m++)
//System.out.print(mat[n][m]+" ");
for(int n = 0;n<mat[0].length && pude;n++){
Vector<Integer> mi = new Vector<Integer>();
for(int m = 0;m<mat.length && pude;m++){
if(mat[m][n]==0)pude=false;
mi.add(mat[m][n]);
}
Collections.sort(mi);
for(int m = 0;m<mi.size() && pude;m++)
res+=Math.abs(mi.get(m)-mi.get(mi.size()/2));
}

System.out.println("Case #"+aa+": "+((!pude)?"Fegla Won":res));
}
}

}
