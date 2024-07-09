#include<bits/stdc++.h>
using namespace std;
#define int long long
struct point
{
    int x, y;
};

int cross(point z, point a, point b)
{
    return (a.x - z.x) * (b.y - z.y) - (a.y - z.y) * (b.x - z.x);
}

bool intersect(point a1, point a2, point b1, point b2)
{
    if((cross(a1, a2, b1) >= 0 && cross(a1, a2, b2) <= 0) || (cross(a1, a2, b1) <= 0 && cross(a1, a2, b2) >= 0))
        if((cross(b1, b2, a1) >= 0 && cross(b1, b2, a2) <= 0) || (cross(b1, b2, a1) <= 0 && cross(b1, b2, a2) >= 0))
            return true;
    return false;
}

bool linia(point a1, point a2, point b)
{
    if(cross(a1, a2, b) != 0) return false;
    if(min(a1.x, a2.x) <= b.x && max(a1.x, a2.x) >= b.x && min(a1.y, a2.y) <= b.y && max(a1.y, a2.y) >= b.y) return true;
    return false;
}

vector<point> v;

int pointInPolygon(point p) //0 -> outside, 1 -> inside, 2 -> boundary
{
    point p0, b1, b2;
    int nin = INT_MAX;
    
    for(int i = 0; i < v.size(); i++)
        nin = min(nin, v[i].y);
    p0.x = p.x - 1;
    p0.y = nin - 5;

    for(int i = 1; i <= v.size(); i++)
    {
        b1 = v[i - 1];
        b2 = v[i];
        if(i == v.size()) b2 = v[0];
        if(linia(b1, b2, p)) return 2;
    }

    int wyn = 0;
    for(int i = 1; i <= v.size(); i++)
    {
        b1 = v[i - 1];
        b2 = v[i];
        if(i == v.size()) b2 = v[0];
        if(intersect(p, p0, b1, b2)) wyn++;
    }
    if(wyn % 2 == 0) return false;
    return true;
}
int n, m;
int32_t main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        point p; p.x = a; p.y = b;
        v.push_back(p);
    }
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        point p; p.x = a; p.y = b;
        int res = pointInPolygon(p);
        if(res == 0) cout << "OUTSIDE\n";
        else if(res == 1) cout << "INSIDE\n";
        else cout << "BOUNDARY\n";
    }
}