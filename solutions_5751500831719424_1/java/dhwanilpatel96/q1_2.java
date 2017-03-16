package r1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
public class q1_2
{
    Scanner file;
    int[][] coun;
    int n;
    int t;
    String[] str;
    char[][] charector;
    int[] num;
    int min;
    
    public static void main(String[] args)
    {
new q1_2().start();
    }
    public void openFile()
    {
try
{
file=new Scanner(new File("C:/Users/Dhwanil/Desktop/A.in"));
} 
catch (FileNotFoundException e)
{
System.out.println("file can not open");
System.exit(0);
}
    }
    
    public void closeFile()
    {
file.close();
    }
    
    public void start()
    {
this.openFile();
t=file.nextInt();
file.nextLine();
char temp;
int c1;
for(int i=1;i<=t;i++)
{
n=file.nextInt();
file.nextLine();
temp=0;
min=0;
this.str=new String[n];
this.coun=new int[n][1000];
this.charector=new char[n][1000];
num=new int[n];
for(int j=0;j<n;j++)
{
c1=0;
this.str[j]=file.nextLine();
for(int k=0;k<this.str[j].length();k++)
{
if(k==0)
{
temp=this.str[j].charAt(k);
this.charector[j][c1]=this.str[j].charAt(k);
this.coun[j][c1]++;
}
else if(temp==this.str[j].charAt(k))
{
this.coun[j][c1]++;
}
else
{
temp=this.str[j].charAt(k);
c1++;
this.charector[j][c1]=this.str[j].charAt(k);
this.coun[j][c1]++;
}
}
num[j]=c1;
}


if(!this.isItPossible())
{
System.out.printf("Case #%d: Fegla Won\n",i);
continue;
}

this.getanswer();
System.out.printf("Case #%d: %d\n",i,min);
}

    }
    
    public boolean isItPossible()
    {
char t;
int c=num[0];
for(int i=1;i<n;i++)
{
if(c!=num[i])
{
return false;
}
}
for(int i=0;i<=num[0];i++)
{
t=this.charector[0][i];
for(int j=1;j<n;j++)
{
if(this.charector[j][i]!=t)
{
return false;
}
}
}
return true;
    }
    
    public void getanswer()
    {
int m;
int z;
min=0;
for(int j=0;j<=num[0];j++)
{
m=0;
//System.out.println("for ch== "+j);
for(int k=0;k<n;k++)
{
z=0;
for(int i=0;i<n;i++)
{
z+=Math.abs(this.coun[k][j]-this.coun[i][j]);
}
if(k==0)
{
m=z;
}
else if(z<m)
{
m=z;
}
}
min+=m;
}

    }
    
}