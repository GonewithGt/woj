 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>



int main()
{
	int n;
	
	while (1)

{

    scanf("%d", &n);

    if (n == 0) //输入结束标志，n=0时不需要被处理

        break;

    int ans = (n+1)/2; //这里计算得到结果

    printf("%d\n", ans); //需要加上 \n ，每组处理完直接输出即可。

}

	
}

