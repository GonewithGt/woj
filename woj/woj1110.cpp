/*
����Ŀ��Դ��http://acm.whu.edu.cn/land/problem/detail?problem_id=1110

����Ŀ������
����ͼƬ����һ�𣬸����ѵ���������Ҫ������п��ܵĴ��µ��ϵĶѵ�˳��

��˼·������ 
1.��Ŀ�Ѿ�����ȷ�ĸ���ÿ���߿��ÿ���ߣ����ٻ���һ����ĸ¶������
���Ա�������ͼ��ȷ��ÿ���߿�ķ�Χ�� ֻ��ȷ�����ϽǺ����½Ǽ��ɡ�
2.����ÿ���߿�ķ�Χ�ٱ�������Ӧ�ó���A��λ�ó�����B����ôBһ����A���档���������߿������˳����������
��B��A���棬��ô��¼A->B��
3.��������
4.Ҫ���������������Ұ���ĸ˳���������ôֻҪ������ĸ˳��ʹ��DFS���ݹ飩�������ע�⴦�������Ϊ0�ĵ㣨ɾ�߸�����ȣ�
�ݹ��ȥ��Ҫ��ԭ������ɾȥ�ı�Ū��������ȸ��»��������Ӷ���֤�����´�ʹ�� 

��СС�ĵá�
�ο������ϴ���;��������ĵݹ��÷�
*/ 
#include <iostream> 
#include <cstring>
#include <iterator>
#include <vector>
#include <cstdio>
using namespace std;

struct Frame
{
    int x1, y1;//���Ͻ� 
    
    int x2, y2;//���½� 
    
    //���ϽǱ����ʼ����һ�㣬���½Ǳ����ʼ��Сһ�� 
    Frame()
    {
        x1 = y1 = 100;
        
        x2 = y2 = -100;
    }
};

//��¼26����ĸʹ������Щ 
bool used[26];

//��� 
int into[26];

//�洢���������ͼ 
int map[26][26];

//�����ԭʼͼ 
char matrix[32][32];

vector<char> ans;

//�������������ͼ ������into���� 
void buildMap(Frame frame[])
{
    for (int i = 0; i < 26; ++i)
    {
        //������ĸ�ù� 
        if (used[i])
        {
            //����frame��һ�к����һ�� 
            for (int j = frame[i].x1; j <= frame[i].x2; ++j)
            {
                if (matrix[j][frame[i].y1] != i+'A')
                {
                    //Ҫ������ж���������Ȼ��Ȼᱻ���� ��CBBC ��B����ȱ������2��ʵ��1 
                    if (map[i][matrix[j][frame[i].y1]-'A'] == 0)
                    {
                        //��¼��� 
                        into[matrix[j][frame[i].y1]-'A']++;
                        //��ͼ 
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
            //����frame��һ�к����һ�� 
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

//depth�����жϵݹ��˶��ٴ� 
void topo(int depth, int count)
{
    //���ݹ�Ĵ������ڻ����������ĸ�Ĵ�������Խ���
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
                //ɾ�����Ϊ0�ĵ��������ı� 
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
                
                //��ԭ 
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
                    //�������ϽǺ����½� 
                    if (frame[toNum].x1 > i) frame[toNum].x1 = i;
                    if (frame[toNum].y1 > j) frame[toNum].y1 = j;
                    if (frame[toNum].x2 < i) frame[toNum].x2 = i;
                    if (frame[toNum].y2 < j) frame[toNum].y2 = j;
                }
            }
        }
        
        buildMap(frame);

        //һ�����˶��ٸ���ĸ 
        int count = 0;
        
        for (int i = 0; i < 26; ++i)
            if (used[i])
                count++;
        
        topo(0, count); 
    }
}
