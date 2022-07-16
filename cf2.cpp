#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void fastscan(int &number)
{
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c=='-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
    if (negative)
        number *= -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int count;
    cin>>count;
    for (int  i = 0; i < count; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        
    }
    
    return 0;
}