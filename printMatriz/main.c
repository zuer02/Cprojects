#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, M[3][10];
    for(i=0; i<3; i++){
        for(j=0; j<10; j++){
            M[i][j] = (i+1)*100 + (j*10);
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }

    return 0;
}
