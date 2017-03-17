// 使用 字符串 进行操作
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char in[101];
    while(scanf("%s",in)!= EOF){
        int len = strlen(in);
        // char out[101][101];
        // 动态申请二维数组 
        char **out = (char**)malloc(len*sizeof(char*));
        for(int t=0; t<len; t++) out[t] = (char*)malloc((len+1)*sizeof(char));
         
        for(int i=0; i<len; i++){
            for(int j=0; j<len; j++){
                out[i][j] = in[(j + i)%len];
            }
            out[i][len] = '\0';
        }
        // 冒泡排序 
        for(int i=0; i<len-1; i++){
            for(int j=0; j<(len-i-1); j++){
                if(strcmp(out[j],out[j+1]) > 0)
                {
                    char tmp[len];
                    strcpy(tmp, out[j]);
                    strcpy(out[j], out[j+1]);
                    strcpy(out[j+1], tmp);
                }
            }
        }
        printf("%s\n",out[0]);
    }
    return 0;
}
