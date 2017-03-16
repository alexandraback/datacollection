#ifdef VX_PRECOMPILED
    #include "precomp.h"
    typedef mpz_class big;
    // I use 4 cores :)
    #define MAX_THREADS 4
#else
    #include <bits/stdc++.h>
    #include<sys/stat.h>
    #include<unistd.h>
    // http://gmplib.org/ (uncomment if solution uses big nums)
    // most likely you'll get an error about mpz_class not being declared...
    //#include "gmpxx.h"
    #define big mpz_class
    // I figure that when other people want to test my solutions they shouldn't
    // get the whole multi-threaded mess that requires and deletes folders and files...
    #define MAX_THREADS 1
#endif

#define for_each(q,s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
typedef long long int64;
#define long int64

using namespace std;

//=========================================================
// program:
//
long dabs(const long &a)
{
    return (a<0)?-a:a;
}

struct point
{
    long x,y;
};


#define EPSILON 0.00001

struct leftbottomer
{
    bool operator ()(const point &i , const point &j)
    {
        if (i.x==j.x)
        {
            return (i.y<j.y);
        }
        return (i.x<j.x);
    }
};

long signedAreaTwice( const point &a,const point &b,const point &c)
{
    return ( a.x*b.y + b.x*c.y + a.y*c.x - b.y*c.x - c.y*a.x - a.y * b.x);
}

long distanceBetweenPoints(const point &a, const point &b)
{
    long dx=(a.x-b.x);
    long dy=(a.y-b.y);
    return dx*dx + dy*dy;
}

struct anglesort
{
    point hullfirst;
    
    bool operator ()(const point &i , const point &j)
    {
        long sarea=signedAreaTwice(hullfirst,i,j);

        if ( sarea == 0 ) //colinear
        {
            return ( distanceBetweenPoints(hullfirst,i) < distanceBetweenPoints(hullfirst,j));
        }

        return atan2(i.y - hullfirst.y, i.x - hullfirst.x) < atan2(j.y - hullfirst.y, j.x - hullfirst.x);
    }
};



bool SegmentsIntersect(const long&x1, const long&y1, const long&x2,const long&y2,const long&x3,const long&y3,const long&x4,const long&y4)
{
    long dx1=x2-x1;
    long dx2=y2-y1;
    
    long dy1=x3-x4;
    long dy2=y3-y4;
    
    long dz1=x3-x1;
    long dz2=y3-y1;
    
    long D=/*determinante*/ dx1*dy2-dy1*dx2;
    long E=/*determinante*/ dz1*dy2-dy1*dz2;
    long F=/*determinante*/ dx1*dz2-dz1*dx2;
    
    if(D==0) return false; //pararel
    if(D<0) { D*=-1; E*=-1; F*=-1; }
    if (E<0) return false;
    if (F<0) return false;
    if (E>D) return false;
    if (F>D) return false;
    return true;
    
    //return (x2 >= x3 && x1 <= x4 && y2 >=y3 && y1 <= y4);
}


struct solver
{
    // This convex hull solver is ANCIENT, apologies for all the terrible code
    // style.
    //
    // To be fair, GCJ are asking for Convex Hull, so this is on them.
    //
    // No really, could they have thought of a more boring problem?
    //
    // Also, Input allows colinear points and that's just mean.
    
    point hullfirst;    
    void convexhull( point* pts, int &n, bool allowcolinear=false)
    {
   
        std::sort(pts,pts+n,leftbottomer());
    
    
        //delete duplicates!
        int k=1;
        for (int i=1;i<n;i++)
        {
            if ( (pts[i].x!=pts[i-1].x) || (pts[i].y!=pts[i-1].y))
            {
                pts[k++]=pts[i];
            }
        }
        n=k;
    
        hullfirst=pts[0];
    
    
        int top=0;
    
        anglesort as;
        as.hullfirst = hullfirst;
        std::sort(pts+1,pts+n, as);
        //return;
    
        //return;
    
        //Add points to hull!
        int j=2;
    
        top=2;
        while (j<n)
        {
            long sarea;
    
            sarea = signedAreaTwice(pts[top-2],pts[top-1],pts[j]);
    
            if ( sarea == 0) //colinear
            {
                //for this problem we must keep colinears
    
                //
                if (allowcolinear)
                    pts[top++]=pts[j++];
                else
                    pts[top-1]=pts[j++];
            }
            else if ( sarea > 0) //good one
            {
                //printf(" [%lf] ",sarea);
                pts[top++]=pts[j];
                j++;
            }
            else if(top>2) //replace
            {
                //pts[top-1]=pts[j];
                top--;
            }
            else
            {
                pts[top-1]=pts[j++];
            }
    
        }
    
        // verify last point and first point
        long sarea = signedAreaTwice(pts[top-2],pts[top-1],pts[0]);
        while ( (top>2) && (sarea<=0))
        {
            top--;
            sarea = signedAreaTwice(pts[top-2],pts[top-1],pts[0]);
        }
        n=top; //the array now contains the convex hull!
    
    
        /*printf("--\n");
        for (int i=0;i<n;i++)
            printf(" (%0.1lf,%0.1lf)" ,pts[i].x,pts[i].y);
        printf("\n\n");*/
    
    
    
    }
    
    int N;
    point points[15];
    
    int solve(int i)
    {
        int res = N + 1;
        for (int mask = 0; mask < (1<<N); mask++) {
            point thepoints[15];
            int n = 0;
            int rem = 0;
            for (int j = 0; j < N; j++) {
                if ( (j==i) || (mask & (1<<j)) ) {
                    thepoints[n++] = points[j];
                    //cout << thepoints[n-1].x << endl;
                } else {
                    rem++;
                }
            }
            
            convexhull(thepoints, n, false);
            //cout << "Convex hull has " << n << endl;
            for (int j = 0; j < n; j++) {
                point &a = thepoints[j];
                point &b = thepoints[(j+1)% n];
                point &c = points[i];
                
                if (SegmentsIntersect(a.x*1000,a.y*1000, b.x*1000,b.y*1000, c.x*1000,c.y*1000, c.x*1000+1,c.y*1000+1)) {
                    res = std::min(res, rem);
                }
            }
        }
        return res;
    }
    void init() { }
    void read() {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> points[i].x >> points[i].y;
        }
    }
    #if MAX_THREADS > 1
        ofstream cout;
    #endif
    void write(int cn) {
        cout << "Case #"<<cn<<":" << endl;
        for (int i = 0; i < N; i++) {
            cout << solve(i)  << endl;
        }
    }
    
};

//=========================================================
// I/O:
//
#if MAX_THREADS > 1
    void run(const char* x)
    {
        int r = system(x);
        cerr<<x<<" "<<"("<<r<<")"<<endl;
    }
#endif

int main(int argc, const char* argv[])
{
    int TestCases, mode;
    #if MAX_THREADS == 1
        // Simple and straight forward. 
        cin >> TestCases;
        solver * theSolver = new solver;
        theSolver->init();
        for (int i=1; i<= TestCases; i++) {
            theSolver->read();
            theSolver->write(i);
        }
        delete theSolver;    
    #else
        cin>>TestCases;
        //-------------------------------------------
        // Copy the whole input to a file...
        ofstream f;
        f.open("tests/.input");
        f << cin.rdbuf();
        f.close();
        // Yeah...wipe that folder... Cause we will need its files to be empty
        run("rm ./tests/.t*");
        int k = 0;
        mode = 0;
        // We create some extra threads...
        while (k < MAX_THREADS) {
            if ( fork() == 0 ) {
                mode = k + 1;
                break;
            }
            k++;
        }
        // Reopen the input, this happens for each of the threads...
        if (mode != 0) {
            assert( freopen( "tests/.input","r",stdin) );
        }
    
        solver * theSolver = new solver;
        theSolver->init();
        for (int i=1; i<= TestCases; i++) {
            // Yeah, I don't like this much either
            ofstream f;
            char fn1[200], fn2[200];
            sprintf(fn1, "tests/.test.%d", i);
            sprintf(fn2, "tests/.test.%d.done", i);
            if (mode == 0) {
                // main thread shall just join stuff together as it becomes ready
                struct stat stFileInfo;
                // When a thread finishes a test case, it writes the .done file
                // Wait for that...
                while ( stat(fn2, &stFileInfo) !=0 ) {
                    sleep(1);
                }
                // Now copy the output file...
                ifstream f(fn1);
                cout << f.rdbuf();
            } else {
                // The trick is to make each thread read all the inputs, whether
                // it will process it or not...
                theSolver->read();
                // If fn1 exists, it is being processed already. Else process it
                f.open(fn1, ios_base::out | ios_base::in);
                if ( !f ) {
                    theSolver->cout.open(fn1, ios_base::out);
                    cerr << "[" << i << "/"<<TestCases<<"] "<<mode << endl;
                    theSolver->write(i);
                    theSolver->cout.close();
                    f.open(fn2);
                    f << "1" << endl;
                }
            }
        }
        delete theSolver;
    #endif

    
    return 0;
}
