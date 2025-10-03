//FUNÇOES
/*
A--
 int semRetorno(int M, int W) {
    int C = M + W;
    printf("O resultado da operação C = M + W é: %d\n", C);
}
*/

/*
B--
int cRetorno(int M, int W) {
    return M + W; 
}
}
*/
int semRetorno(int M, int W) {
    int C = M + W;
    printf("A-- %d\n", C);
}
int cRetorno(int M, int W) {
    return (M + W); 
}
#include <stdio.h>

int main(){
    int M,W;
    int c;
    printf("Informe os valores de M e W\n");
    scanf("%d%d",&M,&W);
    
    c = semRetorno(M,W); 
    printf("\nB-- %d",cRetorno(M,W));
   
   
}