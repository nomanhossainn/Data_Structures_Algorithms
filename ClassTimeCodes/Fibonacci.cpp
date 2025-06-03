#include <stdio.h>

void printFibonacci(int n);
int fibonacci(int n);
int main()
{
    int n;

    // Input the number of terms
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Display the Fibonacci series
    printf("Fibonacci Series: ");
    printFibonacci(n);

    return 0;
}

// Recursive function to calculate and print Fibonacci series
void printFibonacci(int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", fibonacci(i));
    }
}

// Recursive function to calculate the nth term of Fibonacci series
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}


// #include <stdio.h>

// int fibonacci(int n);

// int main() {
//     int n;

//     // Input the value of n
//     printf("Enter the value of n: ");
//     scanf("%d", &n);

//     // Display the nth term of the Fibonacci series
//     printf("The %dth term of the Fibonacci series is: %d\n", n, fibonacci(n));

//     return 0;
// }

// // Recursive function to calculate the nth term of Fibonacci series
// int fibonacci(int n) {
//     if (n <= 1) {
//         return n;
//     } else {
//         return fibonacci(n - 1) + fibonacci(n - 2);
//     }
// }
