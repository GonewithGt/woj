 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>

#define SIZE			200  //һ���������ø��ֽڱ��棬����ʾλ������
#define SIZE_10			2 * SIZE

typedef unsigned char	UCHAR;
typedef unsigned short	USHORT;

typedef struct BigNum  //�������ṹ
{
	UCHAR data[SIZE];  //�ռ�Ϊ(SIZE * sizeof(UCHAR))������SIZE���ֽ�
}BigNum;


UCHAR atox(char ch)  //��һ��ʮ���Ƶ��ַ�תλ���֣�ת��ʧ�ܷ���xff
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

int GetByte(BigNum bignum)  //�ж��ж��ٸ��ֽڲ�Ϊ
{
	int ByteOfBigNum = SIZE;
	while ((bignum.data[ByteOfBigNum - 1] == 0) && (ByteOfBigNum > 0))
	{
		ByteOfBigNum--;
	}
	return ByteOfBigNum;
}



BigNum Init(char* str)  //��ʼ����������strΪʮ�������ַ���
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



BigNum Add(BigNum bignum_a, BigNum bignum_b)  //�������ӷ�
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







void Print_10(BigNum bignum)  //��ӡʮ���ƴ�����
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
	dp=(BigNum *)malloc(501*sizeof(BigNum));
	
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
	dp[0].data[0]=0;
	dp[1].data[0]=1;
	dp[2].data[0]=2;
	dp[3].data[0]=4;
	BigNum ans;
	while (1)

{

    scanf("%d", &n);

    if (n == 0) //���������־��n=0ʱ����Ҫ������

        break;
        
        if(n<=3)
        {
        	ans=dp[n];
        }
        else
        {
        	for(int i=4;i<=n;i++)
        	{
        	//	dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        	dp[i]=Add(Add(dp[i-1],dp[i-2]),dp[i-3]);
        	}
        	ans=dp[n];
        }

   

   Print_10(ans); //��Ҫ���� \n ��ÿ�鴦����ֱ��������ɡ�

}

	
}


