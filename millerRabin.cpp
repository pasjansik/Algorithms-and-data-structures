#include<bits/stdc++.h>
using namespace std;
using u128 = __uint128_t;
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
 
bool czyZlozona(long long a, long long m, long long n, long long k)
{
    long long b = pot(a, m, n);
    if(b == 1 || b == n - 1) return false;
    for(int i = 0; i < k - 1; i++)
    {
        b = (u128) b * b % n;
        if(b == n - 1) return false;
        else if(b == 1) return true;
    }
    return true;
}
 
int iter = 5;
long long m, k;
bool millerRabin(long long n)
{
    if(n < 4)
        {
            if(n == 2 || n == 3) return true;
            else return false;
            return 0;
        }
 
        k = 0;
        m = n - 1;
        while(m % 2 == 0)
        {
            m /= 2;
            k++;
        }
 
        for(int i = 0; i < iter; i++)
        {
            long long a = rand() % (n - 3) + 2;
            if(czyZlozona(a, m, n, k))
            {
                return false;
            }
        }
 
        return true;
}
 
long long n, z;
int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    srand(5);
    cin >> n;
    if(millerRabin(n)) cout << "TAK";
    else cout << "NIE";
} 