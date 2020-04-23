#include <stdio.h>
#include <stdlib.h>

int int_pow(int a, int b)
{
    int result = 1;
    int i;
    for (i = 0; i < b; i++)
        result = result*a;

    return result;
}

void createPowerMatrix(int ***matrix, int base, int power)
{
    int i, j, count;
    int size = int_pow(base, power);

    *matrix = (int **) malloc (size * sizeof(int *)); 
    for (i = 0; i < size; i++) 
        *(*matrix + i) = (int *) malloc(size * sizeof(int)); 

    count = 0;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            *(*(*matrix + i) + j) = count;
            count++;
        }
    }
}

void freePowerMatrix(int **matrix, int base, int power)
{
    int size = int_pow(base, power);
    int i;

    for (i = 0; i < size; i++) 
        free(matrix[i]);
    free(matrix);
}

void printMatrix(int **matrix, int base, int power)
{
    int i, j;
    int size = int_pow(base, power);

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%03d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void recursivePrintCall(int **matrix, int base, int power, int startI, int startJ)
{
    if (power == 0)
        printf("%03d ", matrix[startI][startJ]);
    else 
    {
        int size = int_pow(base, power);
        int step = int_pow(base, power-1);
        int i, j;
        for (i = 0; i < size; i+=step)
        {
            for (j = 0; j < size; j+=step)
            {
                recursivePrintCall(matrix, base, power-1, startI + i, startJ + j);
            }
        }
    }  
}

void recursivePrint(int **matrix, int base, int power)
{
    recursivePrintCall(matrix, base, power, 0, 0);
}

int main()
{
    int** myPowerMatrix = NULL;
     
    int base, power;
    
    printf("Base: ");
    scanf("%d", &base);
    printf("Power: ");
    scanf("%d", &power);
    
    createPowerMatrix(&myPowerMatrix, base, power);
    printMatrix(myPowerMatrix, base, power);
    printf("\n");
    recursivePrint(myPowerMatrix, base, power);
    freePowerMatrix(myPowerMatrix, base, power);
    return 0;
}
