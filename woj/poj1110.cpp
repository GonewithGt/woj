#include <iostream> 
 #include <cstring>
 #include <iterator>
 #include <vector>
 #include <cstdio>
 using namespace std;

struct Fra
 {
     int x1, y1;
     int x2, y2;
     
     Fra()
     {
         x1 = y1 = 100;
         x2 = y2 = -100;
     }
 };

bool used[26];
int into[26];
int map[26][26];
char mat[32][32];
vector<char> ans; 
void buildMap(Fra fra[])
 {
     for (int i = 0; i < 26; ++i)
     {
         if (used[i])
         {
             for (int j = fra[i].x1; j <= fra[i].x2; ++j)
             {
                 if (mat[j][fra[i].y1] != i+'A')
                 {
                     if (map[i][mat[j][fra[i].y1]-'A'] == 0)
                     {
                         into[mat[j][fra[i].y1]-'A']++;
                         map[i][mat[j][fra[i].y1]-'A'] = 1;
                     }
                 }
                 if (mat[j][fra[i].y2] != i+'A')
                 {
                     if (map[i][mat[j][fra[i].y2]-'A'] == 0) 
                     {
                         into[mat[j][fra[i].y2]-'A']++;
                         map[i][mat[j][fra[i].y2]-'A'] = 1;
                     }
                 }
             }
             for (int j = fra[i].y1; j <= fra[i].y2; ++j)
             {
                 if (mat[fra[i].x1][j] != i+'A')
                 {
                     if (map[i][mat[fra[i].x1][j]-'A'] == 0)
                     {
                         into[mat[fra[i].x1][j]-'A']++;
                         map[i][mat[fra[i].x1][j]-'A'] = 1;
                     }
                 }
                 if (mat[fra[i].x2][j] != i+'A')
                 {
                     if (map[i][mat[fra[i].x2][j]-'A'] == 0)
                     {
                         into[mat[fra[i].x2][j]-'A']++;
                         map[i][mat[fra[i].x2][j]-'A'] = 1;
                     }
                 }
             }
         }
     }
 }    

void topo(int depth, int count)
 {
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

void p1110(int n,int m){
     while (scanf("%d",&n) != EOF)
     {
         cin >> m;
         memset(used, 0, sizeof(used));
         memset(into, 0, sizeof(into));
         memset(map, 0, sizeof(map));
         memset(mat, 0, sizeof(mat));
         Fra fra[26];
         ans.clear(); 
         string temp;
         
         for (int i = 0; i < n; ++i)
         {
             cin >> temp;
             for (int j = 0; j < m; ++j)
             {
                 mat[i][j] = temp[j];
                 
                 if (mat[i][j] != '.')
                 {
                     int toNum = mat[i][j]-'A';
                     used[toNum] = true;
                     if (fra[toNum].x1 > i) fra[toNum].x1 = i;
                     if (fra[toNum].y1 > j) fra[toNum].y1 = j;
                     if (fra[toNum].x2 < i) fra[toNum].x2 = i;
                     if (fra[toNum].y2 < j) fra[toNum].y2 = j;
                 }
             }
         }
         
         buildMap(fra);
         int count = 0;
         
         for (int i = 0; i < 26; ++i)
             if (used[i])
                 count++;
         topo(0, count); 
     }
 }

int main()
 {
     int n, m;
     p1110(n,m);
     return 0;
 }
