#include<iostream>
using namespace std;
long long min(string s, long long i){
        long long j=i,c1=0,c2=0;
        while(i!=-1 || j!=s.size()){
            if(s[i]=='1')
            {
             return c1;
            }
            else{
              i--;
            c1++;
           }

            if(s[j]!='1')
            {return c2;
            }
            else{
             j++;
             c2++;}
        }

}

int main(){

   long long n;
   cin>>n;
   for (long long i = 0; i < n; i++)
   {
       long long a;
       cin>>a;
       string s;
       cin>>s;
       
        long long sum=0;
       for (long long j = 0; j < a; j++)
       {  
          if(s[j]=='1')
          continue;
        else{
            sum = sum+min(s,j);
        }
       }
     cout<<"Case #"<<i+1<<": "<<sum<<endl;

   }
    return 0;
}