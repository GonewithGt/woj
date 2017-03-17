#include<iostream>  
#include<cmath>  
 using namespace std;  
#define eps 1e-8  
 int r,N;  
   
struct Point  
 {  
     double x,y;  
     Point(){}  
     Point(double tx,double ty){x=tx;y=ty;}  
 }points[200];  
   
double get_dist(Point p1,Point p2)  
 {  
     return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));  
 }  
   
 Point get_centerpoint(Point p1,Point p2)  
 {  
     Point mid = Point((p1.x+p2.x)/2,(p1.y+p2.y)/2); 
     double d = sqrt(r*r-pow(get_dist(p1,mid),2));  
     double angle = atan2(p1.x-p2.x,p2.y-p1.y);  
     return Point(mid.x+d*cos(angle),mid.y+d*sin(angle));  
 }  
   
int max(int a,int b)  
 {  
     if(a>b)  
         return a;  
     return b;  
 }  

void solve(int n,int r){
         int i,j;  
        
         int res = 0;  
         for(i=0;i<N;i++)  
         {  
             for(j=0;j<N;j++)  
             {  
                 if(get_dist(points[i],points[j]) > 2.0*r) continue;  
                 Point c = get_centerpoint(points[i],points[j]);  
                 int count = 0;  
                 for(int k=0;k<N;k++)  
                     if(get_dist(c,points[k]) < 1.0*r+eps) count++;  
                 res = max(res,count);  
             }  
         }  
         cout<<res<<endl;   
 }

int main(){  

     while(cin>>N>>r){ 
      for(int i=0;i<N;i++)  
             cin>>points[i].x>>points[i].y;  
     
     solve(N,r);
	 
	 }
     return 0;  
 }  
