#include <stdio.h>

#define N 10000000
#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
/*
bitsort 
*/

int arr[1+ N/BITSPERWORD];

voidset(int i)
{
    arr[i>>SHIFT] |= (1<<(i&MASK));
}

int test(int i)
{
        return arr[i>>SHIFT] & (1<<(i&MASK));
}

int main()
{
        ////先在文本文件中生成N个数
    //FILE* file = freopen("in", "w", stdout);
        //if (file != NULL)
        //{
        //    for (int i = 0; i < N; i++)
        //    {
        //         printf("%d\n", N - 1 -i);
        //    }
        //    fclose(file);
        //}

    FILE* in_file = freopen("in", "r", stdin);
    FILE* out_file = freopen("out", "w", stdout);

        if (in_file != NULL)
    {
                int d;
                while(scanf("%d", &d) != EOF)
                    set(d);
        fclose(in_file);
    }

        if (out_file != NULL)
    {
                for (int i =0; i < N; i++)
                        if (test(i))
                printf("%d\n", i);
    }

    fclose(out_file);
        return 0;
}
