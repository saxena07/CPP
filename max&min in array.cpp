#include<iostream>
using namespace std;

int main(){
int count;
cin>>count;
int a[count];

for (int i = 0; i < count; i++) cin>>a[i];
int max=INT_MIN;
int min=INT_MAX;
for (int i = 0; i < count; i++)
{
 if(max<a[i]) max=a[i];
 if(min>a[i]) min=a[i];
}
cout<<"Max : "<<max<<endl;
cout<<"Min : "<<min<<endl; 

return 0;   
}