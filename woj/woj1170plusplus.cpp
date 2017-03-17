#include <stdio.h>
#include <stdlib.h> 
#define N 300000000

int comp(const void*a,const void*b)//用来做比较的函数。
{
    return *(int*)a-*(int*)b;
}
 
 int main()
 {
 	int *array=(int *)malloc(30000000*sizeof(int)); 
 	int gt=0,count=0;
 	while(scanf("%d",&gt)&&gt!=0)
	{
		array[count]=gt;
		count++;
	}
 	
 	qsort(array,count,sizeof(int),comp);//调用qsort排序
 	int prev=0;
 	
 	for(int i=0;i<count;i++)
 	{
 		if(array[i]==prev)
 		continue;
 		else
 		{
 			printf("%d ",array[i]);
 			prev=array[i];
 		}
 		
 	}
 	return 0;
 }
 

/*

int parent(int i)
{
	return i/2;
}

int LEFT(int i)
{
	return 2*i;
}

int RIGHT(int i)
{
	return 2*i+1;
}
 
void Heapify(int A[], int n, int t)
  
 {
  
   int left = LEFT(t);
  
   int right = RIGHT(t);
  
   int max = t;
  
   if(left <= n)     max = A[left] > A[max] ? left : max;
  
   if(right <= n)     max = A[right] > A[max] ? right : max;
  
   if(max != A[t])
  
   {
  
     swap(A, max, t);
  
     Heapify(A, n, max);
  
   }
  
 }
 
 void BuildHeap(int A[], int n)
  
 {
  
   int i;
  
   for(i = n/2; i<=n; i++)
  
   Heapify(A, n, i);
  
 }
 
 void GetMaximum(int A[], int n)
  
 {
  
   int max = A[1];
  
   A[1] = A[n];
  
   n--;
  
   Heapify(A, n, 1);
  
   return max;
  
 }
 
 void Insert(int A[], int n, int t)
  
 {
  
   n++;
  
   A[n] = t;
  
   int p = n;
  
   while(p >1 && A[PARENT(p)] < t)
  
   {
  
     A[p] = A[PARENT(p)];
  
     p = PARENT(p);
  
   }
  
   A[p] = t;
  
   return max;
  
 }
 
*/


 
 
