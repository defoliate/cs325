#include<iostream>
#include<cmath>
#include<iomanip>
#include<fstream>
#define MAX 10000
using namespace std;

// point class
class Point{
private:
 int x;
 int y;
public:
// constructor
 Point(){
   x=-1;
   y=-1;
 }

 Point(int a,int b){
   x=a;
   y=b;

 }
// setterand getter functions
 void setX(int a){
   x=a;
 }

 void setY(int a){
   y=a;
 }

 int getX(){
   return(x);
 }

 int getY(){
   return(y);
 }
};

// Node class
class Node{
private:
       int n;// node name
       Point *p;// corresponding point
     public:
       // constructor
       Node(){
         n=-1;
         p=NULL;
       }
       // constructor with parameter
       Node(int _n,Point *_p){
         n=_n;
         p=_p;
       }

       // setter and getter methods
       void setN(int _n){
         n=_n;
       }
       void setPoint(Point *_p){
         p=_p;
       }

       int getN(){
         return(n);
       }

       Point *getPoint(){
         return(p);
       }

       // ostream operator
       friend ostream& operator<<(ostream &out,Node &n){
         out<<"("<<n.p->getX()<<","<<n.p->getY()<<")";
         return(out);
       }
     };

// graph class
     class GRAPH{
     private:
       int size;// node size
       int **ary;// distance d array
       Node *node;// node list
       int ind;// current index
       // calculate distance
       int distance(Point *a,Point *b){
         double d=sqrt(pow(a->getX()-b->getX(),2)+pow(a->getY()-b->getY(),2));
         int d1=(int)d;
         // to get nearest round value
         // cout<<d1<<"======"<<d<<endl;
         double r=d-d1;
         // cout<<r<<endl;
         if(r>=.5){
         	// cout<<d1<<endl;
           return(d1+1);
         }
         else{
           return(d1);
         }
       }

     public:
       // constructor
       GRAPH(int _s){
         ind=-1;
         size=_s;
           // for 2D array
         ary=new int*[size];
           // node create
         node=new Node[size];
           // create 2D array
         for(int i=0;i<size;i++){
           ary[i]=new int[size];
         }
       }

       // add node
       void addNode(Node n){
         ind++;
         // cout<<"xx"<<ind;
         node[ind]=n;
       }

       // get node
       Node getNodeAtIndex(int a){
         return(node[a]);
       }

       // calculate distance and store in corresponding 2d array
       bool setup(){
        // cout<<ind<<"xxxxxx"<<size<<endl;
         if(ind<=size){
           for(int i=0;i<size;i++)   {
             Node na=node[i];
             for(int j=0;j<size;j++)   {
               Node nb=node[j];
               ary[i][j]=distance(na.getPoint(),nb.getPoint());
             }
           }

         // store maximum value in diagonal
           for(int i=0;i<size;i++){
             ary[i][i]=-1;
           }
           return true;
         }
         else{
           return false;
         }
       }


       // get minimum indexing value
       int minKey(int key[],bool mSet[]){
         int _min=MAX,m_index;

           // calculate minimum index value
         for(int i=0;i<size;i++){
           if(mSet[i]==false && key[i]<_min){
             _min=key[i];
             m_index=i;
           }
         }
         return (m_index);
       }

       // print mst
       void printmst(int *p){
         int total=0;
         cout<<"Edges in MST"<<endl;
         cout<<"Point (x,y)\t"<<"    Distance"<<endl;
         for(int i=1;i<size;i++){

           cout<<node[p[i]]<<" - "<< node[i];
           // cout<<right;
           cout<<setw(4)<<"\t"<<ary[i][p[i]]<<endl;
           total+=ary[i][p[i]];
         }
         cout<<"\tTotal distance\t"<<total<<endl;
       }


       // get mst with distance
       void primMST(){
         int *p=new int[size];
         int *key=new int[size];
         bool *mSet=new bool[size];

         for(int i=0;i<size;i++){
           key[i]=MAX;
           mSet[i]=false;
         }

         key[0]=0;
         p[0]=-1;
         for(int i=0;i<size-1;i++){
          // get next minimum key index
           int u=minKey(key,mSet);
           mSet[u]=true;
           for(int j=0;j<size;j++){
            // find minimum key and corresponding parent
             if(ary[u][j] && mSet[j]==false && ary[u][j]<key[j]){               
               p[j]=u;
               key[j]=ary[u][j];
             }
           }
         }
         printmst(p);
       }
       // print 2d sarray
       void print(){
         for(int i=0;i<size;i++){
           for(int j=0;j<size;j++){
             cout<<ary[i][j];
           }
           cout<<endl;
         }

       }

     };

int main(int argc,char **argv){
       Point **p;
       ifstream in;
  // cout<<argv[1];
       in.open("graph.txt");
       if(in.bad()){
         cout<<"File not found.";
       }
       else{
         int size;
         in>>size;
         p=new Point*[size];
         GRAPH graph(size);
         int x,y;
         int i=0;
         while(!in.eof()){
           in>>x;
           in>>y;
           p[i]=new Point(x,y);
           Node n(i+1,p[i]);
           graph.addNode(n);
         }
         in.close();  
         bool r=graph.setup();
         graph.primMST();  
       }
     }
