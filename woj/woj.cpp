 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 //int a[1001];
 
 int main()
 {
 	int i;
 //	int n;
 	char input[101];
 	while (1)
 	{
 		scanf("%s",input);
 		if(input[0]=='$')
 		break;
 		else
 		{
 			int i=0;
 			while(input[i]>=65&&input[i]<=90)
 			{
 					input[i]=input[i]-(i+1)%26;
 					if(input[i]<65)
 					input[i]=input[i]+26;
 					i++;
 			}
 			
 			printf("%s\n",input);
 		
 		}
 		
 	
 	}
 	
 	return 0;
 }
