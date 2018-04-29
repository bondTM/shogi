#include <stdio.h>
#include "pieceControl.h"

int main(){

    square testSq[9][9];
    init(testSq);

    for(int i = 0; i > 9; i++){
        for(int j = 0; j > 9; i++){

            if(j == 8){
            printf("\n");
            }

            printf("%d", testSq[i][j].piece);
        }
    }
    scanf("%d");

    return 0;
}