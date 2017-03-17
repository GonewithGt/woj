/*
【题目来源】http://acm.whu.edu.cn/land/problem/detail?problem_id=1110

【题目分析】
几张图片叠在一起，给出堆叠后的情况，要求出所有可能的从下到上的堆叠顺序。

【思路分析】 
1.题目已经很明确的告诉每个边框的每条边，至少会有一个字母露在外面
所以遍历整张图，确定每个边框的范围。 只需确定左上角和右下角即可。
2.根据每个边框的范围再遍历，若应该出现A的位置出现了B，那么B一定在A上面。这样各个边框的上下顺序就求出来。
若B在A上面，那么记录A->B。
3.拓扑排序
4.要求输出所有能情况且按字母顺序输出。那么只要按照字母顺序使用DFS（递归）来解决，注意处理完入度为0的点（删边更新入度）
递归进去后要还原回来（删去的边弄回来，入度更新回来）。从而保证可以下次使用 

【小小心得】
参考了网上代码;拓扑排序的递归用法
*/ 
#include <iostream> 
#include <cstring>
#include <iterator>
#include <vector>
#include <cstdio>
using namespace std;

struct Frame
{
    int x1, y1;//左上角 
    
    int x2, y2;//右下角 
    
    //左上角必须初始化大一点，右下角必须初始化小一点 
    Frame()
    {
        x1 = y1 = 100;
        
        x2 = y2 = -100;
    }
};

//记录26个字母使用了哪些 
bool used[26];

//入度 
int into[26];

//存储拓扑排序的图 
int map[26][26];

//输入的原始图 
char matrix[32][32];

vector<char> ans;

//建立拓扑排序的图 即更新into数组 
void buildMap(Frame frame[])
{
    for (int i = 0; i < 26; ++i)
    {
        //若此字母用过 
        if (used[i])
        {
            //遍历frame第一列和最后一列 
            for (int j = frame[i].x1; j <= frame[i].x2; ++j)
            {
                if (matrix[j][frame[i].y1] != i+'A')
                {
                    //要加这个判断条件，不然入度会被多算 如CBBC 则B的入度被算成了2其实是1 
                    if (map[i][matrix[j][frame[i].y1]-'A'] == 0)
                    {
                        //记录入度 
                        into[matrix[j][frame[i].y1]-'A']++;
                        //建图 
                        map[i][matrix[j][frame[i].y1]-'A'] = 1;
                    }
                }
                if (matrix[j][frame[i].y2] != i+'A')
                {
                    if (map[i][matrix[j][frame[i].y2]-'A'] == 0) 
                    {
                        into[matrix[j][frame[i].y2]-'A']++;
                    
                        map[i][matrix[j][frame[i].y2]-'A'] = 1;
                    }
                }
            }
            //遍历frame第一行和最后一行 
            for (int j = frame[i].y1; j <= frame[i].y2; ++j)
            {
                if (matrix[frame[i].x1][j] != i+'A')
                {
                    if (map[i][matrix[frame[i].x1][j]-'A'] == 0)
                    {
                        into[matrix[frame[i].x1][j]-'A']++;
                    
                        map[i][matrix[frame[i].x1][j]-'A'] = 1;
                    }
                }
                if (matrix[frame[i].x2][j] != i+'A')
                {
                    if (map[i][matrix[frame[i].x2][j]-'A'] == 0)
                    {
                        into[matrix[frame[i].x2][j]-'A']++;
                    
                        map[i][matrix[frame[i].x2][j]-'A'] = 1;
                    }
                }
            }
        }
    }
}    

//depth用于判断递归了多少次 
void topo(int depth, int count)
{
    //若递归的次数大于或等于所用字母的次数则可以结束
    if (depth >= count)
    {
        copy(ans.begin(), ans.end(), ostream_iterator<char>(cout));
        
        cout << endl;
        
        return;
    }
    
    for (int i = 0; i < 26; ++i)
    {
        if (used[i])
        {
            if (into[i] == 0)    
            {
                //删除入度为0的点所发出的边 
                ans.push_back(i+'A');
            
                into[i] = -1;
                
                for (int k = 0; k < 26; ++k)
                {
                    if (map[i][k] == 1)
                    {    
                        into[k]--;
                    }
                }
                
                topo(depth+1, count);
                
                //还原 
                ans.pop_back();
                
                into[i] = 0;
                
                for (int k = 0; k < 26; ++k)
                {
                    if (map[i][k] == 1)
                    {    
                        into[k]++;
                    }
                }                
            }
        }
    }
}

int main()
{
    int n, m;
    
    while (scanf("%d",&n) != EOF)
    {
        cin >> m;
        
        memset(used, 0, sizeof(used));
        
        memset(into, 0, sizeof(into));
        
        memset(map, 0, sizeof(map));
        
        memset(matrix, 0, sizeof(matrix));
        
        Frame frame[26];
        
        ans.clear(); 
        
        string temp;
         
        for (int i = 0; i < n; ++i)
        {
            cin >> temp;
            for (int j = 0; j < m; ++j)
            {
                matrix[i][j] = temp[j];
                
                if (matrix[i][j] != '.')
                {
                    int toNum = matrix[i][j]-'A';
                    
                    used[toNum] = true;
                    //更新左上角和右下角 
                    if (frame[toNum].x1 > i) frame[toNum].x1 = i;
                    if (frame[toNum].y1 > j) frame[toNum].y1 = j;
                    if (frame[toNum].x2 < i) frame[toNum].x2 = i;
                    if (frame[toNum].y2 < j) frame[toNum].y2 = j;
                }
            }
        }
        
        buildMap(frame);

        //一共用了多少个字母 
        int count = 0;
        
        for (int i = 0; i < 26; ++i)
            if (used[i])
                count++;
        
        topo(0, count); 
    }
}
