 #include<iostream>
 using namespace std;

 int divide(int dividend, int divisor) {
        int i=0;
        int d=divisor;

        if((divisor>0 && dividend>0)||(divisor<0 && dividend<0)){
          if(dividend<0){
        dividend = 0-dividend;
        divisor = 0-divisor;}
        while(dividend>divisor && dividend!=divisor){
          divisor+=d;
          i++;
     
        }
        if(dividend-divisor==0){
          return i+1;
        }

        return i;
        }

        int di;
        if(dividend<0){
        di = 0-divisor;
        cout<<dividend<<endl<<di<<endl;}
        if(divisor<0){
        dividend = 0-dividend;
        cout<<dividend<<endl<<divisor<<endl;}

         while(dividend<di && dividend!=di){
          di+=d;
          i++;
     
        } i=0-i;
        if(dividend-di==0){
          return i-1;
        }

        return i;
    }

int main(){
   int a ,b;
   cin>> a>>b;
   cout<<divide(a,b);
       return 0;
}    