#include <cstdio>
 #include <cmath>
 #include <vector>
 #include <map>
 #include <algorithm>

using namespace std;

const double eps = 1e-8;
 const int n_max = 10 + 2;

int sgn(double d) {
     if (d > eps)
         return 1;
     if (d < -eps)
         return -1;
     return 0;
 }

struct point {
     double x, y;
     point(double _x = 0, double _y = 0): x(_x), y(_y) {
     }
     double len() const {
         return sqrt(x * x + y * y);
     }
     point turn_left() const {
         return point(-y, x);
     }
     point turn_right() const {
         return point(y, -x);
     }
     point trunc(double _len) const {
         double radio = _len / len();
         return point(x * radio, y * radio);
     }
 };

bool operator==(const point& p1, const point& p2) {
     return sgn(p1.x - p2.x) == 0 && sgn(p1.y - p2.y) == 0;
 }

bool operator<(const point& p1, const point& p2) {
     return sgn(p1.x - p2.x) == 0 ? sgn(p1.y - p2.y) < 0 : p1.x < p2.x;
 }

point operator+(const point& p1, const point& p2) {
     return point(p1.x + p2.x, p1.y + p2.y);
 }

point operator-(const point& p1, const point& p2) {
     return point(p1.x - p2.x, p1.y - p2.y);
 }

double operator^(const point& p1, const point& p2) {
     return p1.x * p2.x + p1.y * p2.y;
 }

double operator*(const point& p1, const point& p2) {
     return p1.x * p2.y - p1.y * p2.x;
 }

struct line_segment {
     point p1, p2;
     line_segment(const point& _p1 = point(), const point& _p2 = point()): p1(_p1), p2(_p2) {
     }
     bool intersect(const line_segment& seg) const {
         int s1 = sgn((p2 - p1) * (seg.p1 - p1)), s2 = sgn((p2 - p1) * (seg.p2 - p1));
         int s3 = sgn((seg.p2 - seg.p1) * (p1 - seg.p1)), s4 = sgn((seg.p2 - seg.p1) * (p2 - seg.p1));
         return s1 * s2 < 0 && s3 * s4 < 0;
     }
 };

struct rectangle {
     double x1, y1, x2, y2;
     rectangle(double _x1 = 0, double _y1 = 0, double _x2 = 0, double _y2 = 0): x1(_x1), y1(_y1), x2(_x2), y2(_y2) {
     }
     bool contain(const point& p) const {
         return sgn(p.x - x1) > 0 && sgn(p.x - x2) < 0 && sgn(p.y - y1) > 0 && sgn(p.y - y2) < 0;
     }
     bool intersect(const line_segment& seg) const {
         line_segment s1(point(x1, y1), point(x1, y2)), s2(point(x1, y1), point(x2, y1));
         line_segment s3(point(x2, y2), point(x1, y2)), s4(point(x2, y2), point(x2, y1));
         return s1.intersect(seg) || s2.intersect(seg) || s3.intersect(seg) || s4.intersect(seg);
     }
 };

struct circle {
     point c;
     double r;
     circle(const point& _c = point(), double _r = 0): c(_c), r(_r) {
     }
     bool contain(const point& p) const {
         return sgn((p - c).len() - r) < 0;
     }
     vector<line_segment> get_tangent(const point& p) const {
         vector<line_segment> res;
         double dis = (p - c).len();
         if (sgn(dis - r) <= 0)
             return res;
         point pp = c + (p - c).trunc(r * r / dis);
         double h = sqrt(abs(r * r - (r * r * r * r) / (dis * dis)));
         res.push_back(line_segment(p, pp + (p - c).turn_left().trunc(h)));
         res.push_back(line_segment(p, pp + (p - c).turn_right().trunc(h)));
         return res;
     }
     vector<line_segment> get_tangent(const circle& _cir) const {
         vector<line_segment> res;
         double dis = (_cir.c - c).len();
         if (sgn(dis - abs(_cir.r - r)) <= 0)
             return res;
         double len = sqrt(abs(dis * dis - (_cir.r - r) * (_cir.r - r)));
         double h1 = r * len / dis, h2 = _cir.r * len / dis;
         point p = r > _cir.r ? _cir.c - c : c - _cir.c;
         point pp1 = c + p.trunc(sqrt(abs(r * r - h1 * h1))), pp2 = _cir.c + p.trunc(sqrt(abs(_cir.r * _cir.r - h2 * h2)));
         res.push_back(line_segment(pp1 + p.turn_left().trunc(h1), pp2 + p.turn_left().trunc(h2)));
         res.push_back(line_segment(pp1 + p.turn_right().trunc(h1), pp2 + p.turn_right().trunc(h2)));
         if (sgn(dis - (r + _cir.r)) <= 0)
             return res;
         double d1 = dis * r / (r + _cir.r), d2 = dis * _cir.r / (r + _cir.r);
         point pp3 = c + (_cir.c - c).trunc(r * r / d1), pp4 = _cir.c + (c - _cir.c).trunc(_cir.r * _cir.r / d2);
         double h3 = sqrt(abs(r * r - (r * r * r * r) / (d1 * d1))), h4 = sqrt(abs(_cir.r * _cir.r - (_cir.r * _cir.r * _cir.r * _cir.r) / (d2 * d2)));
         res.push_back(line_segment(pp3 + (_cir.c - c).turn_left().trunc(h3), pp4 + (c - _cir.c).turn_left().trunc(h4)));
         res.push_back(line_segment(pp3 + (_cir.c - c).turn_right().trunc(h3), pp4 + (c - _cir.c).turn_right().trunc(h4)));
         return res;
     }
     bool intersect(const line_segment& seg) const {
         double dis = (seg.p1 - c) * (seg.p2 - c) / (seg.p2 - seg.p1).len();
         point pp = c + (seg.p2 - seg.p1).turn_right().trunc(dis);
         if (sgn((pp - seg.p1) ^ (pp - seg.p2)) <= 0)
             return sgn(abs(dis) - r) < 0;
         return sgn(min((seg.p1 - c).len(), (seg.p2 - c).len()) - r) < 0;
     }
     vector<point> get_cross(const line_segment& seg) const {
         vector<point> res;
         double dis = (seg.p1 - c) * (seg.p2 - c) / (seg.p1 - seg.p2).len();
         if (sgn(abs(dis) - r) >= 0)
             return res;
         point pp = c + (seg.p2 - seg.p1).turn_right().trunc(dis);
         double len = sqrt(r * r - dis * dis);
         point cro1 = pp + (seg.p1 - seg.p2).trunc(len), cro2 = pp + (seg.p2 - seg.p1).trunc(len);
         if (sgn((seg.p1 - cro1) ^ (seg.p2 - cro1)) <= 0)
             res.push_back(cro1);
         if (sgn((seg.p1 - cro2) ^ (seg.p2 - cro2)) <= 0)
             res.push_back(cro2);
         return res;
     }
     vector<point> get_cross(const circle& _cir) const {
         vector<point> res;
         double dis = (_cir.c - c).len();
         if (sgn(dis - (r + _cir.r)) >= 0 || sgn(dis - abs(_cir.r - r)) <= 0)
             return res;
         double p = (dis + r + _cir.r) / 2.0;
         double h = sqrt(abs(p * (p - dis) * (p - r) * (p - _cir.r))) * 2.0 / dis;
         point pp = c + (_cir.c - c).trunc(sqrt(abs(r * r - h * h)));
         res.push_back(pp + (_cir.c - c).turn_left().trunc(h));
         res.push_back(pp + (_cir.c - c).turn_right().trunc(h));
         return res;
     }
 };

struct arc {
     circle c;
     point p1, p2;
     arc(const circle& _c = circle(), const point& _p1 = point(), const point& _p2 = point()): c(_c), p1(_p1), p2(_p2) {
     }
     bool intersect(const line_segment& seg) const {
         double x_low = min(p1.x, p2.x), x_up = max(p1.x, p2.x), y_low = min(p1.y, p2.y), y_up = max(p1.y, p2.y);
         vector<point> cro = c.get_cross(seg);
         for (vector<point>::iterator i = cro.begin(); i != cro.end(); ++i)
             if (sgn(i->x - x_low) > 0 && sgn(i->x - x_up) < 0 && sgn(i->y - y_low) > 0 && sgn(i->y - y_up) < 0)
                 return true;
         return false;
     }
     bool intersect(const rectangle& _rect) const {
         line_segment s1(point(_rect.x1, _rect.y1), point(_rect.x1, _rect.y2)), s2(point(_rect.x1, _rect.y1), point(_rect.x2, _rect.y1));
         line_segment s3(point(_rect.x2, _rect.y2), point(_rect.x1, _rect.y2)), s4(point(_rect.x2, _rect.y2), point(_rect.x2, _rect.y1));
         return intersect(s1) || intersect(s2) || intersect(s3) || intersect(s4);
     }
     bool intersect(const circle& _cir) const {
         double x_low = min(p1.x, p2.x), x_up = max(p1.x, p2.x), y_low = min(p1.y, p2.y), y_up = max(p1.y, p2.y);
         vector<point> cro = c.get_cross(_cir);
         for (vector<point>::iterator i = cro.begin(); i != cro.end(); ++i)
             if (sgn(i->x - x_low) > 0 && sgn(i->x - x_up) < 0 && sgn(i->y - y_low) > 0 && sgn(i->y - y_up) < 0)
                 return true;
         return false;
     }
 };

struct disjoint_set {
     int p[(n_max * 4) * (n_max * 4) * 4];
     void clear() {
         for (int i = 0; i < (n_max * 4) * (n_max * 4) * 4; ++i)
             p[i] = i;
     }
     int get_parent(int k) {
         return p[k] == k ? k : p[k] = get_parent(p[k]);
     }
     void union_set(int a, int b) {
         int p_a = get_parent(a), p_b = get_parent(b);
         p[p_b] = p_a;
     }
 };

struct obstacle {
     double x, y, l, w, h;
 };

int n;
 double length, width, height;
 obstacle obs[n_max];
 point p_s, p_t;
 vector<rectangle> rect;
 vector<circle> cir;
 vector<point> arc_point[n_max * 4];
 disjoint_set ds;
 map<point, int> hash;

void solve();
 double get_max_radius();
 double get_dis(double, double);
 int get_id(const point&);
 bool check(double);
 void make_graph();
 void make_graph_s_t();
 void make_graph_circle_circle();
 void make_graph_circle();
 bool is_valid(const point&);
 bool is_valid(const line_segment&);
 bool is_valid(const arc&);

int main() {
     int t;
     scanf("%d", &t);
     for (int i = 0; i < t; ++i)
         solve();
     return 0;
 }

void solve() {
     scanf("%d%lf%lf%lf", &n, &length, &width, &height);
     for (int i = 0; i < n; ++i)
         scanf("%lf%lf%lf%lf%lf", &obs[i].x, &obs[i].y, &obs[i].l, &obs[i].w, &obs[i].h);
     scanf("%lf%lf%lf%lf", &p_s.x, &p_s.y, &p_t.x, &p_t.y);
     printf("%.2lf\n", get_max_radius());
 }

double get_max_radius() {
     double low = 0, up = 1e10;
     while (low - up < -1e-4) {
         double mid = (low + up) / 2.0;
         if (check(mid))
             low = mid;
         else
             up = mid;
     }
     return low;
 }

double get_dis(double r, double h) {
     if (sgn(h - r) >= 0)
         return r;
     return sqrt(r * r - (r - h) * (r - h));
 }

int get_id(const point& p) {
     if (hash.find(p) == hash.end())
         return hash[p] = hash.size();
     return hash[p];
 }

bool check(double r) {
     rect.clear();
     cir.clear();
     for (int i = 0; i < n; ++i) {
         double d = get_dis(r, obs[i].h);
         rect.push_back(rectangle(obs[i].x, obs[i].y - d, obs[i].x + obs[i].l, obs[i].y + obs[i].w + d));
         rect.push_back(rectangle(obs[i].x - d, obs[i].y, obs[i].x + obs[i].l + d, obs[i].y + obs[i].w));
         cir.push_back(circle(point(obs[i].x, obs[i].y), d));
         cir.push_back(circle(point(obs[i].x, obs[i].y + obs[i].w), d));
         cir.push_back(circle(point(obs[i].x + obs[i].l, obs[i].y), d));
         cir.push_back(circle(point(obs[i].x + obs[i].l, obs[i].y + obs[i].w), d));
     }
     double d = get_dis(r, height);
     rect.push_back(rectangle(0, 0, length, d));
     rect.push_back(rectangle(0, width - d, length, width));
     rect.push_back(rectangle(0, 0, d, width));
     rect.push_back(rectangle(length - d, 0, length, width));
     if (!is_valid(p_s) || !is_valid(p_t))
         return false;
     make_graph();
     return ds.get_parent(get_id(p_s)) == ds.get_parent(get_id(p_t));
 }

void make_graph() {
     for (int i = 0; i < cir.size(); ++i)
         arc_point[i].clear();
     ds.clear();
     hash.clear();
     make_graph_s_t();
     make_graph_circle_circle();
     make_graph_circle();
 }

void make_graph_s_t() {
     if (is_valid(line_segment(p_s, p_t)))
         ds.union_set(get_id(p_s), get_id(p_t));
     for (vector<circle>::iterator i = cir.begin(); i != cir.end(); ++i) {
         vector<line_segment> tang1 = i->get_tangent(p_s);
         vector<line_segment> tang2 = i->get_tangent(p_t);
         for (vector<line_segment>::iterator j = tang1.begin(); j != tang1.end(); ++j) {
             if (is_valid(*j)) {
                 arc_point[i - cir.begin()].push_back(j->p2);
                 ds.union_set(get_id(j->p1), get_id(j->p2));
             }
         }
         for (vector<line_segment>::iterator j = tang2.begin(); j != tang2.end(); ++j) {
             if (is_valid(*j)) {
                 arc_point[i - cir.begin()].push_back(j->p2);
                 ds.union_set(get_id(j->p1), get_id(j->p2));
             }
         }
     }
 }

void make_graph_circle_circle() {
     for (vector<circle>::iterator i = cir.begin(); i != cir.end(); ++i) {
         for (vector<circle>::iterator j = cir.begin(); j != cir.end(); ++j) {
             vector<line_segment> tang = i->get_tangent(*j);
             for (vector<line_segment>::iterator k = tang.begin(); k != tang.end(); ++k) {
                 if (is_valid(*k)) {
                     arc_point[i - cir.begin()].push_back(k->p1);
                     arc_point[j - cir.begin()].push_back(k->p2);
                     ds.union_set(get_id(k->p1), get_id(k->p2));
                 }
             }
         }
     }
 }

void make_graph_circle() {
     for (vector<circle>::iterator i = cir.begin(); i != cir.end(); ++i) {
         int cur = i - cir.begin();
         sort(arc_point[cur].begin(), arc_point[cur].end());
         arc_point[cur].resize(unique(arc_point[cur].begin(), arc_point[cur].end()) - arc_point[cur].begin());
         if (arc_point[cur].size() <= 1)
             continue;
         for (vector<point>::iterator j = arc_point[cur].begin(); j + 1 != arc_point[cur].end(); ++j)
             if (is_valid(arc(*i, *j, *(j + 1))))
                 ds.union_set(get_id(*j), get_id(*(j + 1)));
     }
 }

bool is_valid(const point& p) {
     for (vector<rectangle>::iterator i = rect.begin(); i != rect.end(); ++i)
         if (i->contain(p))
             return false;
     for (vector<circle>::iterator i = cir.begin(); i != cir.end(); ++i)
         if (i->contain(p))
             return false;
     return true;
 }

bool is_valid(const line_segment& seg) {
     if (!is_valid(seg.p1) || !is_valid(seg.p2) || !is_valid(point((seg.p1.x + seg.p2.x) / 2.0, (seg.p1.y + seg.p2.y) / 2.0)))
         return false;
     for (vector<rectangle>::iterator i = rect.begin(); i != rect.end(); ++i)
         if (i->intersect(seg))
             return false;
     for (vector<circle>::iterator i = cir.begin(); i != cir.end(); ++i)
         if (i->intersect(seg))
             return false;
     return true;
 }

bool is_valid(const arc& _arc) {
     for (vector<rectangle>::iterator i = rect.begin(); i != rect.end(); ++i)
         if (_arc.intersect(*i))
             return false;
     for (vector<circle>::iterator i = cir.begin(); i != cir.end(); ++i)
         if (_arc.intersect(*i))
             return false;
     return true;
 }

