//          LAKSHYA SAXENA
//          A1- 19102026
#include <iostream>
#include <vector>
using namespace std;


int median(vector<int> a, vector<int> b) {
    size_t i = 0, j = b.size();

    int length = (a.size() + b.size())/2 ;

    while (length > 0 && i < a.size() && j > 0) {
        if (a[i] < b[j - 1]) 
            ++i;
        else 
            --j;
        length -= 1;
    }

    if (length > 0 && i < a.size())
        {++i; length--; }
    if (length > 0 && j >= 0)
        {--j; length--;}

    return a[i] < b[j - 1] ? a[i] : b[j - 1];
}


int main() {
    vector<int> a = {1, 6, 8, 12, 16, 18, 20};
    vector<int> b = {35, 31, 27, 24, 11, 3};

    // 1 3 6 8 11 12 16 18 20 24 27 31 35

    cout << median(a, b) << "\n";
  return 0;
}










 int l=0,e=n,in=0,f=0;
    while(l<=e){
        int mid=l+(e-l)/2;
        if(x==arr[mid]) {in=mid; f=1; break;}
        else if(x<arr[mid]) e=mid;
        else l=mid+1;
    }
    if(f==0) return{-1,-1};
    int in1=in,in2=in;
    while(in1-1>=0 && arr[in1-1]==x) in1--;
    while(in2+1<n && arr[in2+1]==x) in2++;
    return {in1,in2};