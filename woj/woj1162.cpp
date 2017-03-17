
 #include <cstdio>
 #include <cstring>
 #include <algorithm>

#define SIZE			1001  //һ���������ø��ֽڱ��棬����ʾλ������
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
		
	//	printf("gt\n");
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
		Print_10(ans); //��Ҫ���� \n ��ÿ�鴦����ֱ��������ɡ�
	} 

      
   

   

}

return 1;

	
}

