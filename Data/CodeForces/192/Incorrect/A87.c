#include <stdio.h>
#include <conio.h>

typedef long long ll;

ll timkiem(ll tmpn, ll a[])
{
    ll L = 1, R = 44721, mid;
    while (L < R)
    {
        mid = (L + R) / 2;
        if (a[mid] == tmpn)
            return 1;
        else if (a[mid]>tmpn)
            R = mid - 1;
        else
            L = mid + 1;
    }
    return 0;
}

ll kqua(ll n, ll a[])
{
    ll i, tmpn;
    for (i = 1; i <= 44721; i++)
        a[i] = i*(i + 1) / 2;
    for (i = 1; i <= 44721 && a[i] < n; i++)
    {
        tmpn = n - a[i];
        if (timkiem(tmpn,a))
            return 1;
    }
    return 0;
}

int main()
{
    ll n, a[44722];
    scanf("%I64d", &n);
    if (kqua(n, a))
        printf("YES");
    else printf("NO");
    
    return 0;
}