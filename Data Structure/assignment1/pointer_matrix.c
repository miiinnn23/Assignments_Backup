#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ** MATRIX(int row, int column);
void PRINT(int **matrix, int row, int column) {
    int i, j;
    for(i = 0; i < row; i++) {
        for(j = 0; j < column; j++) {
            printf("%d\t", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    int a, b, c;
    int **M, **N, **L;
    int i, j, k, sum;

    a = atoi(argv[1]);
    b = atoi(argv[2]);
    c = atoi(argv[3]); 

    printf("MATRIX M\n");

    M = MATRIX(a, b);
    PRINT(M, a, b);

    // for(i = 0; i < a; i++) {
    //     for(j = 0; j < b; j++) {
    //        printf("%d\t", *(*(M + i)+ j));
    //    }
    //    printf("\n");
    // }
    printf("M POINTER ADDRESS : %p\n", M);

    srand(time(NULL));
    printf("\nMATRIX N\n");
    N = MATRIX(b, c);

    for(i = 0; i < b; i++) {
        for(j = 0; j < c; j++) {
            printf("%d\t", *(*(N + i)+ j));
        }
        printf("\n");
    }
    printf("N POINTER ADDRESS : %p\n", N);

    L = (int **)malloc(sizeof(int) * a);

    for(i = 0; i < a; i++) {
        *(L + i) = (int *)malloc(sizeof(int) * c);
    }

    for(i = 0; i < a; i++) {        
        for(j = 0; j < c; j++) {
            sum = 0;
            for(k = 0; k < b; k++) {
                sum += (*(*(M + i) + k)) * (*(*(N + k) + j)); // A[i][k] * B[k][j];
            }
            *(*(L + i) + j) = sum;
        }
    }

    printf("\nMATRIX L : M * N\n");
    for(i = 0; i < a; i++) {
        for(j = 0; j < c; j++) {
            printf("%d\t", *(*(L + i)+ j));
        }
        printf("\n");
    }
    printf("L POINTER ADDRESS : %p", L);

    free(L);
    free(N);
    free(M);
    return 0;
}

int ** MATRIX(int row, int column) {
    int i, j;
    int **matrix = (int **)malloc(sizeof(int) * row);

    for(i = 0; i < row; i++) {
        *(matrix + i) = (int *)malloc(sizeof(int) * column);
    }
    for(i = 0; i < row; i++) {
        
        for(j = 0; j < column; j++) {
            *(*(matrix + i) + j) = rand() % 10 + 1;
        }
    }

    return matrix;
}