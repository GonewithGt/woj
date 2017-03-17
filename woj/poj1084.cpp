
#include <iostream>
 #include <functional>
 #include <algorithm>
 #include <fstream>
 #include <cstring>
 #include <cstdio>
 #include <bitset>
 #include <set>
 #include <vector>
 #include <cmath>
 #include <cstdlib>
 #include <queue>
 #include <stack>
 #include <map>
 
using namespace std;

const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
typedef pair <int, int> PLL;

int arr[1200];
int xis[1200];
int cnt;

int find(int val)
 {
     int l = 1, r = cnt, mid;
     while (l <= r)
     {
         mid = (l + r) >> 1;
         if (xis[mid] == val)
         {
             break;
         }
         else if (xis[mid] > val)
         {
             r = mid - 1;
         }
         else
         {
             l = mid + 1;
         }
     }
     return mid;
 }

class SufArr
 {
     public:
         static const int N = 1200;
         int init[N];
         int X[N];
         int Y[N];
         int Rank[N];
         int sa[N];
         int height[N];
         int buc[N];
         int LOG[N];
         int dp[N][20];
         int size;
         vector <int> task;

         void clear()
         {
             size = 0;
         }

         void insert(int n)
         {
             init[size++] = n;
         }

         bool cmp(int *r, int a, int b, int l)
         {
             return (r[a] == r[b] && r[a + l] == r[b + l]);
         }

         void get(int m = 256) //m一般为最大值+1
         {
             init[size] = 0;
             int l, p, *x = X, *y = Y, n = size + 1;
             for (int i = 0; i < m; ++i)
             {
                 buc[i] = 0;
             }
             for (int i = 0; i < n; ++i)
             {
                 ++buc[x[i] = init[i]];
             }
             for (int i = 1; i < m; ++i)
             {
                 buc[i] += buc[i - 1];
             }
             for (int i = n - 1; i >= 0; --i)
             {
                 sa[--buc[x[i]]] = i;
             }
             for (l = 1, p = 1; l <= n && p < n; m = p, l *= 2)
             {
                 p = 0;
                 for (int i = n - l; i < n; ++i)
                 {
                     y[p++] = i;
                 }
                 for (int i = 0; i < n; ++i)
                 {
                     if (sa[i] >= l)
                     {
                         y[p++] = sa[i] - l;
                     }
                 }
                 for (int i = 0; i < m; ++i)
                 {
                     buc[i] = 0;
                 }
                 for (int i = 0; i < n; ++i)
                 {
                     ++buc[x[y[i]]];
                 }
                 for (int i = 1; i < m; ++i)
                 {
                     buc[i] += buc[i - 1];
                 }
                 for (int i = n - 1; i >= 0; --i)
                 {
                     sa[--buc[x[y[i]]]] = y[i];
                 }
                 int i;

                 for (swap(x, y), x[sa[0]] = 0, p = 1, i = 1; i < n; ++i)
                 { 
                     x[sa[i]] = cmp(y, sa[i - 1], sa[i], l) ? p - 1 : p++; 
                 }
             }
         }

         void geth()
         {
             int h = 0, n = size;
             for (int i = 0; i <= n; ++i)
             {
                 Rank[sa[i]] = i;
             }
             height[0] = 0;
             for (int i = 0; i < n; ++i)
             {
                 if (h > 0)
                 {
                     --h;
                 }
                 int j =sa[Rank[i] - 1];
                 for (; i + h < n && j + h < n && init[i + h] == init[j + h]; ++h);
                 height[Rank[i] - 1] = h;
             }
         }  

         bool chk(int k)
         {
             int l = sa[1], r = sa[1];
             for (int i = 1; i < size; ++i)
             {
                 if (height[i] >= k)
                 {
                     l = min(l, sa[i + 1]);
                     r = max(r, sa[i + 1]);
                 }
                 else
                 {
                     if (r - l >= k)
                     {
                         return 1;
                     }
                     l = r = sa[i + 1];
                 }
             }
             return 0;
         }

         void slv()
         {
             int l = 1, r = size / 2, mid;
             int ans = -1;
             while (l <= r)
             {
                 mid = (l + r) >> 1;
                 if (chk(mid))
                 {
                     l = mid + 1;
                     ans = mid;
                 }
                 else
                 {
                     r = mid - 1;
                 }
             }
             if (ans == -1)
             {
                 printf("-1\n");
                 return;
             }
             task.clear();
             task.push_back(sa[1]);
             int ret = 0;
             for (int i = 1; i < size; ++i)
             {
                 if (height[i] >= ans)
                 {
                     task.push_back(sa[i + 1]);
                 }
                 else
                 {
                     sort(task.begin(), task.end());
                     int tmp1 = 1, tmp2 = 1, isize = task.size(), last = task[0];
                     for (int j = 1; j < isize; ++j)
                     {
                         if (task[j] - last >= ans)
                         {
                             ++tmp1;
                             last = task[j];
                         }
                     }
                     last = task[isize - 1];
                     for (int j = isize - 2; j >= 0; --j)
                     {
                         if (last - task[j] >= ans)
                         {
                             ++tmp2;
                             last = task[j];
                         }
                     }
                     ret = max(ret, max(tmp1, tmp2));
                     task.clear();
                     task.push_back(sa[i + 1]);
                 }
             }
             printf("%d %d\n", ans, ret);

         }
 }SA;

void p1084()
 {
     int n;
     while (~scanf("%d", &n))
     {
         SA.clear();
         cnt = 0;
         for (int i = 0; i < n; ++i)
         {
             scanf("%d", &arr[i]);
             xis[++cnt] = arr[i];
         }
         sort (xis + 1, xis + 1 + cnt);
         cnt = unique(xis + 1, xis + 1 + cnt) - xis - 1;
         for (int i = 0; i < n; ++i)
         {
             int val = find(arr[i]);
             SA.insert(val);
         }
         SA.get(cnt + 1);
         SA.geth();
         SA.slv();
     }
 }

int main()
 {
     p1084();
     return 0;
 }



