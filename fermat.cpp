#include<bits/stdc++.h>
using namespace std;
using u128 = __uint128_t;
long long n;

long long gcd(long long a, long long b)
{
    if(b > a) swap(a, b);
    while(b > 0)
    {
        int pom = b;
        b = a % b;
        a = pom;
    }return a;
}

long long pot(long long a, long long b, long long c)
{
    long long w = 1;
    while(b > 0)
    {
        if(b % 2 == 1)
            w = (u128)w * a % c;
        
        a = (u128)a * a % c;
        b /= 2;
    }
    return w;
}

int main()
{
    srand(5);
    cin >> n;
    if(n == 1)
    {
        cout << "NIE";
        return 0;
    }
    else if(n == 2 || n == 3) 
    {
        cout << "TAK";
        return 0;
    }

    for(int i = 0; i < 50; i++)
    {
        long long a = rand() % (n - 2) + 1;
        if(gcd(a, n) != 1)
        {
            cout << "NIE";
            return 0;
        }
        if(pot(a, n - 1, n) != 1)
        {
            cout << "NIE";
            return 0;
        }
    }

    cout << "TAK";
}