#include<iostream>
#include<set>
using namespace std;

 int doUnion(int a[], int n, int b[], int m)  {
        set<int> x;

        for (int i = 0; i < n; i++) x.insert(a[i]);
        for (int i = 0; i < m; i++) x.insert(b[i]);

        return x.size();   
    }

int main(){
    int a[]={1,2,3,4,5}, b[]={1,2,3};
    cout<<doUnion(a,5,b,3);
    return 0;
}