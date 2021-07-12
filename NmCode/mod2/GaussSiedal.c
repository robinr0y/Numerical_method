#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int count, t, limit;
    float temp, error, a, sum = 0;
    float matrix[10][10], y[10], allowed_error;
    system("clear");
    printf("\n Enter the Total Number of Equations:\t");
    scanf("%d", &limit);
    printf(" Enter Allowed Error:\t");
    scanf("%f", &allowed_error);
    printf("\n Enter the Co-Efficients\n");
    for (count = 1; count <= limit; count++)
    {
        for (t = 1; t <= limit + 1; t++)
        {
            printf("  Matrix[%d][%d] = ", count, t);
            scanf("%f", &matrix[count][t]);
        }
    }
    for (count = 1; count <= limit; count++)
    {
        y[count] = 0;
    }
    do
    {
        a = 0;
        for (count = 1; count <= limit; count++)
        {
            sum = 0;
            for (t = 1; t <= limit; t++)
            {
                if (t != count)
                {
                    sum = sum + matrix[count][t] * y[t];
                }
            }
            temp = (matrix[count][limit + 1] - sum) / matrix[count][count];
            error = fabs(y[count] - temp);
            if (error > a)
            {
                a = error;
            }
            y[count] = temp;
            printf("\n  Y[%d]=\t%f", count, y[count]);
        }
        printf("\n");
    } while (a >= allowed_error);
    printf("\n\n  Solution\n\n");
    for (count = 1; count <= limit; count++)
    {
        printf("\n  Y[%d]:\t%f", count, y[count]);
    }
    printf("\n\n");

    return 0;
}