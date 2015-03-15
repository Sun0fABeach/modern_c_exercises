#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

float compute_GPA(char grades[], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
        switch(toupper(grades[i])) {
            case 'A': sum += 4; break;
            case 'B': sum += 3; break;
            case 'C': sum += 2; break;
            case 'D': sum += 1; break;
        }
    return (float) sum / n;

}


int main()
{
    char a[10] = {'A', 'b', 'c', 'd', 'F', 'A', 'b', 'c', 'd', 'F'};

    printf("Average grade: %f\n", compute_GPA(a, 10));

    exit(EXIT_SUCCESS);
}
