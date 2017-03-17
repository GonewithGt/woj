#include<cstdio>
#include<cmath>
#include<algorithm>
//#include<iostream>
 
using namespace std;
 
#define MAX_N 300 + 16
 
typedef double p_type;
 
struct Point
{
	p_type x, y;
 	Point(){}
 
    Point(p_type x, p_type y) : x(x), y(y){}
} ps[MAX_N];
 
struct PolarAngle
{
	p_type angle;
	bool flag;	// 起点或终点
 
	const bool operator<(const PolarAngle &other)
	{
	return angle < other.angle;
	}
} as[MAX_N];
 
inline p_type distance_of(const Point &P, const Point &Q)
{
	return sqrt((P.x - Q.x) * (P.x - Q.x) + (P.y - Q.y) * (P.y - Q.y));
}
 
inline int solve(const int& n, const p_type& r)
{
	int result = 1;
	for (int i = 0; i < n; ++i)
	{
		int m = 0;
		double d;
		for (int j = 0; j < n; ++j)
		{
			if (i != j && (d = distance_of(ps[i], ps[j])) <= 2)
			{
				double phi = acos(d / 2);
				double theta = atan2(ps[j].y - ps[i].y, ps[j].x - ps[i].x);
				as[m].angle = theta - phi, as[m++].flag = 1;
				as[m].angle = theta + phi, as[m++].flag = 0;
			}
		}
		sort(as, as + m);
		for (int sum = 1, j = 0; j < m; ++j)
		{
			if (as[j].flag)
				++sum;
			else
				--sum;
			result = max(result, sum);
		}
	}
	return result;
}
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
	//#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int num,r;
	while(scanf("%d %d",&num,&r)!=EOF)
	{
		for (int i = 0; i < num; ++i)
		{
			scanf("%lf%lf", &ps[i].x, &ps[i].y);
			//cin>>ps[i].x>>ps[i].y;
		}
		int ans =solve(num, 1.0*r);
		printf("%d\n",ans);
	//	cout<<ans<<endl;
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif
	return 0;
}

