#include<iostream>
#include<cstdio>

using namespace std;

double array[7][2];

int Calculate(double a,double b)

{

	int sum;
	double p=a*a+b*b;
	if(p<=9.0)
	sum=100;
	else if(p<=36.0)
	sum=80;
	else if(p<=81.0)
	sum=60;
	else if(p<=144.0)
	sum=40;
	else if(p<=225.0)
	sum=20;
	else
	sum=0;
	return sum;
}

 

int main()

{

	int i,s1,s2;
	while(1)
	{
	for(i=0;i<6;i++)
	{
	scanf("%lf%lf",&array[i][0],&array[i][1]);
	}
 
	if(array[0][0]==-100)
	break;
	s1=0;
	s2=0;
	for(i=0;i<3;i++)

	{

	s1+=Calculate(array[i][0],array[i][1]);

	}

 

	for(i=3;i<6;i++)

	{

	s2+=Calculate(array[i][0],array[i][1]);

	}
	printf("SCORE: %d to %d, ",s1,s2);

	if(s1>s2)

	printf("PLAYER 1 WINS.\n");

	else if(s1<s2)

	printf("PLAYER 2 WINS.\n");

	else

	printf("TIE.\n");

}

	return 0;

}

 

