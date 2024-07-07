#include<bits/stdc++.h>
using namespace std;
long long cross(long long x1, long long y11, long long x2, long long y2, long long x3, long long y3)
{
    return (x1 - x3) * (y2 - y3) - (x2 - x3) * (y11 - y3);
}

bool czy(long long x1, long long y11, long long x2, long long y2, long long x3, long long y3, long long x4, long long y4)
{
    if((cross(x1, y11, x4, y4, x3, y3) == 0 && cross(x2, y2, x4, y4, x3, y3) == 0) || (cross(x1, y11, x4, y4, x3, y3) == 0 && cross(x2, y2, x4, y4, x3, y3) == 0))
    {
        if((cross(x3, y3, x1, y11, x2, y2) == 0 && cross(x4, y4, x1, y11, x2, y2) == 0) || (cross(x3, y3, x1, y11, x2, y2) == 0 && cross(x4, y4, x1, y11, x2, y2) == 0))
        {
            if(min(x3, x4) <= x2 && max(x4, x3) >= x2 && min(y3, y4) <= y2 && max(y3, y4) >= y2) return true;
            if(min(x3, x4) <= x1 && max(x4, x3) >= x1 && min(y3, y4) <= y11 && max(y3, y4) >= y11) return true;
            if(min(x1, x2) <= x3 && max(x1, x2) >= x3 && min(y11, y2) <= y3 && max(y11, y2) >= y3) return true;
            if(min(x1, x2) <= x4 && max(x1, x2) >= x4 && min(y11, y2) <= y4 && max(y11, y2) >= y4) return true;
            return false;
        }
    }

    if((cross(x1, y11, x4, y4, x3, y3) >= 0 && cross(x2, y2, x4, y4, x3, y3) <= 0) || (cross(x1, y11, x4, y4, x3, y3) <= 0 && cross(x2, y2, x4, y4, x3, y3) >= 0))
        if((cross(x3, y3, x1, y11, x2, y2) >= 0 && cross(x4, y4, x1, y11, x2, y2) <= 0) || (cross(x3, y3, x1, y11, x2, y2) <= 0 && cross(x4, y4, x1, y11, x2, y2) >= 0))
            return true;

    return false;
}

long long t;
long long a, b, c, d, e, f, g, h;
int main()
{
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> a >> b >> c >> d >> e >> f >> g >> h;
        if(czy(a, b, c, d, e, f, g, h)) cout << "YES\n";
        else cout << "NO\n";
    }
}