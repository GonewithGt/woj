#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#define INF 10001



int main()
{
    int animals;
    while((scanf("%d" , &animals)) != EOF)
    {
          int a[8][animals];
          int i , j; 
          for(i = 0;i < 8;i++)
              {
                  for(j = 0; j < animals; j++)
                  { 
                    scanf("%d",&a[i][j]); 
                  }
              } 
          int min[10001];
          memset(min,10001,sizeof(min)); 
          int sum = 0;
          for(j = 0; j < animals; j++)
              {
                    for(i = 0;i < 8;i++)
                    {    
                          min[j] = min[j] < a[i][j] ? min[j] : a[i][j];
                    }  
              sum += min[j];
              }
          printf("%d\n",sum);
    }
    return 0; 
}  
