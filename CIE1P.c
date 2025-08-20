#include <stdio.h>
#include <omp.h>
int main() {
    char name[50];
    int age;
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your age: ");
    scanf("%d", &age);
    long long sum = 0;
    double start, end;
    start = omp_get_wtime();
    #pragma omp parallel for reduction(+:sum)
    for (long long i = 0; i < 100000000; i++) {
        sum += i % 10;
    }
    end = omp_get_wtime();
    printf("\n--- User Info ---\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Processed sum: %lld\n", sum);
    printf("Execution time: %.4f seconds\n", end - start);
    return 0;
}