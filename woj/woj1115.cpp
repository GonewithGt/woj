 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>
using namespace std;
 
 
void change(long long x)
 {
 	
 	char a[27]={'0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
 	int b[100];
 	
 	
 	
 	int i=0;
 	 for(i=0;;i++)
        {
                b[i]=x%26;
                if(b[i]==0)
                {
                	b[i]=26;
                	x=x-26;
                } 
                x=x/26;
                if(x==0)
        {
                   break;
         }
        }
        
      for(;i>-1;i--)
    {
           printf("%c",a[b[i]]);
    }
    printf("\0");


 }

int main()
{
	//char a[26]={'0','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	int r=-1,c=-1;
	char row;
	char colum;
	while(r!=0&&c!=0)
	{
		
	    //scanf("%c%lld%c%lld",&row,&r,&colum,&c)!=EOF
	   // scanf("%c",&row);
	    //scanf("%d",&r);
	    //scanf("%c",&colum);
	    //scanf("%d",&c);
	    
	     cin>>row>>r>>colum>>c;
	   // printf("r=%d c=%d\n",r,c);
	    
	   
		if(r==0&&c==0)
		{
			break;
		}
		else
		{
			change(c);
		    printf("%d\n",r);
		}
		
		
		
	}
	return 0;
}
