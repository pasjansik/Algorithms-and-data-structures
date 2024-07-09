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
    if((cross(a1, a2, b1) == 0 && cross(a1, a2, b2) == 0) || (cross(a1, a2, b1) == 0 && cross(a1, a2, b2) == 0))
    {
        if((cross(b1, b2, a1) == 0 && cross(b1, b2, a2) == 0) || (cross(b1, b2, a1) == 0 && cross(b1, b2, a2) == 0))
        {
            if(min(a1.x, a2.x) <= b1.x && max(a1.x, a2.x) >= b1.x && min(a1.y, a2.y) <= b1.y && max(a1.y, a2.y) >= b1.y) return true;
            if(min(a1.x, a2.x) <= b2.x && max(a1.x, a2.x) >= b2.x && min(a1.y, a2.y) <= b2.y && max(a1.y, a2.y) >= b2.y) return true;
            if(min(b1.x, b2.x) <= a1.x && max(b1.x, b2.x) >= a1.x && min(b1.y, b2.y) <= a1.y && max(b1.y, b2.y) >= a1.y) return true;
            if(min(b1.x, b2.x) <= a2.x && max(b1.x, b2.x) >= a2.x && min(b1.y, b2.y) <= a2.y && max(b1.y, b2.y) >= a2.y) return true;
            return false;
        }
    }


    if((cross(a1, a2, b1) >= 0 && cross(a1, a2, b2) <= 0) || (cross(a1, a2, b1) <= 0 && cross(a1, a2, b2) >= 0))
        if((cross(b1, b2, a1) >= 0 && cross(b1, b2, a2) <= 0) || (cross(b1, b2, a1) <= 0 && cross(b1, b2, a2) >= 0))
            return true;
    return false;
}

int t;
int main()
{
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int a, b, c, d, e, f, g, h;
        cin >> a >> b >> c >> d >> e >> f >> g >> h;
        point u; u.x = a; u.y = b;
        point w; w.x = c; w.y = d;
        point z; z.x = e; z.y = f;
        point j; j.x = g; j.y = h;
        if(intersect(u, w, z, j)) cout << "YES\n";
        else cout << "NO\n";
    }
}