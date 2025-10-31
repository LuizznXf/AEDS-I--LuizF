// CALCULAR Y
#include <stdio.h>

int CalcularY(int fx, int gx)
{
    return (fx+gx);
}

int main()
{
    int x,fx,hx,gx;
   
    printf("INFORME x:\n");
    scanf("%d",&x);
    hx = (x*x) - 16;
    
    if(hx>=0){
        fx=hx;
    } else {
        fx=1;
    }

    if(fx==0){
        gx = (x*x) + 16;
    }else if(fx>0){
        gx=0;
    }
    
    printf("\n%d",CalcularY(fx,gx));
    return (0);
}
