//GCD


#include<iostream>
using namespace std;
int count=1;
int gcd(int  a,int b){

    int r=0;
    while(b!=0){
        count++;
        r=a%b;
        a=b;
        b=r;
    }
    return a;
    count++;

}
int main()

{
    int a,b;
    cout << "Program by: Sagar Thapa"<<endl;
    cout<<"enter any no two no.";
    cin>>a>>b;
    cout<<"The GCD of "<<a<<" and " << b<<" is " <<gcd(a,b)<<endl;
    cout<<"The time complexity is "<<count;
    
}