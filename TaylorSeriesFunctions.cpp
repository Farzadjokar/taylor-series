#include<iostream>
#include<cmath>
#define numberOfIterations 20
int factoriel(int n){
    int product=1;
    for(int i=2;i<=n;i++){
        product*=i;
    }
    return product;
}
//taylor of e^x
//radius of convergence is infinity so you can pass everything you want
double e(double x){
    double sum=0;
    for(int i=0;i<=numberOfIterations;i++){
        sum+=(pow(x,i)/double(factoriel(i)));
    }
return sum;
}
//taylor of ln(x) based on ln(x+1)
//radius of convergence is "-1<x<1" so you have to pass 1<=x<=2
// to function inorder to work
double ln(double x){
double sum=0;
x--;
for(int i=1;i<numberOfIterations;i++){
    sum+=(pow(-x,i))/i;
}
return -sum;
}
// taylor of arcTanx again you have to pass -1<x<1 because radius of convergence
//or you can use pi/2-arctan(1/x)=arctan(x) formula
double arctan(double x){
    double sum=0;
    for(int i=0;i<numberOfIterations;i++){
        sum+=(pow(-1,i)*pow(x,2*i+1)/(2*i+1));
    }
    return sum;
}
// taylor of sinx again you can pass everything to it
double sin(double x){
double sum=0;
for(int i=1,j=0;i<numberOfIterations;i+=2,j++){
sum+=(pow(-1,j)*pow(x,i)/(factoriel(i)));
}
return sum;
}
int main(int length,char * args[]){
std::cout<<e(2)<<"\n";
std::cout<<ln(1.5)<<"\n";
std::cout<<sin(M_PI);
}