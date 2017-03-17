#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#define N  200010
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);

for (int i = 0; i < t; i++)

{
	
	char words[10000][15];
	char word[15];
	int j=0;
	while(scanf("%s",word)!=EOF)
	{
		printf("\n%s\n",word);
		if(j==0)
		{
			if(word[0]>='a'&&word[0]<='z')
		    word[0]=word[0]+26;
		}else
		{
			int k=1;
		while(word[k])
		{
			if(word[0]>='A'&&word[0]<='Z')
		    word[k]=word[k]-26;
		}
		}
		
		strcpy(words[j],word);
		
		j++;
	}
	
	for(int gt=0;gt<=j;gt++)
	printf("%s ",words[j]);
	

    //处理每一组数据并输出


}

}
