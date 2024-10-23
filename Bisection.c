#include <stdio.h>
#include <math.h>
double f(double x){
    return x-cos(x);
}
int main()
{
    double x0,x1,x2,f0,f1,f2,error;
    do{
     printf("Enter first approximation: ");
     scanf("%lf",&x0);
    
     printf("Enter second approximation: ");
     scanf("%lf",&x1);
     if(f(x0)*f(x1)<0){
         break;
     }
     else{
         printf("!!!Enter Valid range.");
     }
     
    }while(1);
    
    printf("Allowed Error: ");
    scanf("%lf",&error);
    
    int maxStep;
    printf("Max Steps: ");
    scanf("%d",&maxStep);
    
    int i=0;
    while(i<maxStep){
        x2=(x0+x1)/2;
        printf("Value of root at iteration %d: %lf\n", i + 1, x2);
        
        if(fabs(f(x2))<error||fabs(x1 - x0) < error){
            printf("Root is : %lf\n",x2);
            break;
        }
        if(f(x0)*f(x2)<0){
            x1=x2;
        }
        else{
            x0=x2;
        }
        
        i++;
    }
    

    return 0;
}