#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

int nums[101],flags[MAX];

int main(){

	int countx,counta,count;
	
	int i,j,k,n,t;
	scanf("%d",&t);
	for(int gt=0;gt<t;gt++){
 	  scanf("%d",&n);
 	  if(n>1){
		for(i=0;i<MAX;i++)
 	         flags[i]=-1;
        j=0;
        countx=0;
        counta=0;
		for(i=0;i<n;i++){
		     scanf("%d",&nums[i]);			 
			 if(flags[nums[i]]!=-1){
		            count=0;
					for(k=flags[nums[i]];k<=i;k++)
		                 if(nums[k]!=-1)
		                       count++;
		  	        if(i%2!=0)
	        		     counta +=count;
					else
						 countx +=count;
					for(k=flags[nums[i]];k<=i;k++)
		                 nums[k]=-1;
					}
			 else
			 	 	flags[nums[i]]=i;			       					 
			 }
        if(countx>counta)
			 printf("xay\n");
	    else
	    	 printf("amr\n");
	   }
	}
	return 0;		   
	}

