#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>

#define SIZE			310  //一个大整数用个字节保存，最多表示位大整数
#define SIZE_10			2 * SIZE

typedef unsigned char	UCHAR;
typedef unsigned short	USHORT;

typedef struct BigNum  //大整数结构
{
	UCHAR data[SIZE];  //空间为(SIZE * sizeof(UCHAR))，就是SIZE个字节
}BigNum;


UCHAR atox(char ch)  //将一个十进制的字符转位数字，转换失败返回xff
{
	UCHAR res;
	if (ch >= '0' && ch <= '9')
	{
		res = ch - '0';
		
		printf("gt\n");
	}
	else
	{
		printf("change error!\n");
		return 0xff;
	}
	return res;
}

int GetByte(BigNum bignum)  //判断有多少个字节不为
{
	int ByteOfBigNum = SIZE;
	while ((bignum.data[ByteOfBigNum - 1] == 0) && (ByteOfBigNum > 0))
	{
		ByteOfBigNum--;
	}
	return ByteOfBigNum;
}



BigNum Init(char* str)  //初始化大整数，str为十六进制字符串
{
	BigNum bignum;
	int len = (int)strlen(str);
	int i;
	int j = 0;
//	if (len > 2 * SIZE)
//	{
//		len = 2 * SIZE;
//	}
	for (i = len - 1; i >=0; i -= 1)
	{
		bignum.data[j] = atox(str[i]);
		j++;
	}
	
	while (j < SIZE)
	{
		bignum.data[j] = 0;
		j++;
	}
	return bignum;
}

BigNum Initnum(int  num)  //初始化大整数，str为十六进制字符串
{
	BigNum bignum;
	int i;
	int j=0;
    while(num)
    {
    	bignum.data[j]=num%10;
    	num=num/10;
    	j++;
    }
	
	while (j < SIZE)
	{
		bignum.data[j] = 0;
		j++;
	}
	return bignum;
}



BigNum Add(BigNum bignum_a, BigNum bignum_b)  //大整数加法
{
	BigNum bignum_c;
	USHORT temp;
	UCHAR carry = 0;
	int i;
	for (i = 0; i < SIZE; i++)
	{
		temp = bignum_a.data[i] + bignum_b.data[i] + carry;
		bignum_c.data[i] = temp%10 ;
		carry = temp/10;
	}
	return bignum_c;
}







void Print_10(BigNum bignum)  //打印十进制大整数
{
	int n=GetByte(bignum);
	for(int i=n-1;i>=0;i--)
	printf("%d",bignum.data[i]);
	
	printf("\n");
}



int main()
{
	int n;
	BigNum *dp;
	dp=(BigNum *)malloc(1001*sizeof(BigNum));
	
    //unsigned long long dp[501];
    /*
    char a[1]={'0'};
    a[0]='0';
	dp[0]=Init(a);
	 a[0]='1';
	dp[1]=Init(a);
	 a[0]='2';
	dp[2]=Init(a);
	 a[0]='4';
	dp[3]=Init(a);
	//double ans;
	*/
	//dp[0].data[0]=1;
//	dp[1].data[0]=3;
	//dp[2].data[0]=2;
	//dp[3].data[0]=4;
	BigNum ans;
	BigNum one;
	one=Initnum(1);
	dp[0]=Initnum(1);
	dp[1]=Initnum(3);
	
	
	// Print_10(one); 
	
	while ( scanf("%d", &n)!=EOF)

{

      if(n>=2)
      {
      	for(int i=2;i<=n;i++)
        {
        
        
        	dp[i]=Add(Add(dp[i-1],dp[i-1]),one);
        }
      }
        
        
        ans=dp[n];

   

   Print_10(ans); //需要加上 \n ，每组处理完直接输出即可。

}

	
}

