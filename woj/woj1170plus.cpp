#include <stdio.h>

#define N 300000000
#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F

//³¬Ê±¼ä£¬bitsort 

int arr[1+ N/BITSPERWORD];

void set(int i)
{
    arr[i>>SHIFT] |= (1<<(i&MASK));
}

int test(int i)
{
        return arr[i>>SHIFT] & (1<<(i&MASK));
}

int main()
{
    
   
	int gt=0,max=0;
	//int i=0,max=0;
	while(scanf("%d",&gt)&&gt!=0)
	{
		if(gt>max)
		max=gt;
		set(gt);
	}
	for(int j=1;j<max;j++)
	{
        if (test(j))
		printf("%d ",j);
	}
	printf("%d",max);
	return 0;
}


