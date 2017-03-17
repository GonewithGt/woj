
 #include <cstdio>
 #include <cstring>
 #include <algorithm>

#define SIZE			1001  //一个大整数用个字节保存，最多表示位大整数
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
		
	//	printf("gt\n");
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
	if(n==0)
	{
		printf("0\n");
	return;
	}
	 
	for(int i=n-1;i>=0;i--)
	printf("%d",bignum.data[i]);
	
	printf("\n");
}



int main()
{
	int n;
	int gt=0;
	BigNum ans;
	BigNum num1,num2;
	char *s1;
	char *s2;
	//char *s3;
	s1=(char *)malloc(1001*sizeof(char));
	s2=(char *)malloc(1001*sizeof(char));
	//s2=(char *)malloc(1001*sizeof(char));
	
	while ( scanf("%d", &n)!=EOF)

{
	for(int j=0;j<n;j++)
	{
		scanf("%s",s1);
		scanf("%s",s2);
	//	if(strcmp(s1,s3)==0&&strcmp(s2,s3)==0)
	//	{
	//		printf("%d\n",gt);
	//		continue;
	//	}
		
		num1=Init(s1);
		num2=Init(s2);
		ans=Add(num1,num2);
		Print_10(ans); //需要加上 \n ，每组处理完直接输出即可。
	} 

      
   

   

}

return 1;

	
}

