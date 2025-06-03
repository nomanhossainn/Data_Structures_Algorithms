// #include<iostream>
// using namespace std;
// // int sum = 0;

// // // void printNumbers(int n){
// // //     if(n==1){
// // //         printf("1 ");
// // //         //cout << 1<<" ";
// // //         return;
// // //     }
// // //     printNumbers(n - 1);
// // //     printf("%d ", n);
// // //     // printf("Sum: %d", sum);
// // //     //  cout << n<<" ";
// // // }
// // // int calSum(int n){
    
// // //     if(n==0){
// // //         return 0;
// // //     }
// // //     else{
// // //         //int sum = 0;
        
// // //         sum = sum + n;
// // //         calSum(n - 1);
// // //     }
// // //     return sum;
// // // }

// // // int factorial(int n){
// // //     if(n==0){
// // //         return 1;
// // //     }
// // //     int sum = n * factorial(n - 1);
// // //     return sum;
// // // }
// // // int digitSum(int n){
// // //     if(n==0){
// // //         return 0;
// // //     }
// // //     int lastDigit = n % 10;
// // //     int remainingDigits = n / 10;
// // //     int sum = lastDigit + digitSum(remainingDigits);
// // //     return sum;
// // // }
// bool firstCall = false;
// int countDigits(int n)
// {
//     if(n==0){
//         if (firstCall == false){
//             return 1;
//         }
//         else
//             return 0;
//     }
//     if(firstCall==false){
//         firstCall = true;
//     }
//     int remainingDigits = n / 10;
//     int count = 1 + countDigits(remainingDigits);
//     return count;
// }
// int main(){
//     int n;
//     cout << "Enter the value: ";
//     cin >> n;
//     int x = countDigits(n);
//     cout << "Total: " << x;
//     // int x = digitSum(n);
//     // cout << "Sum: " << x;
//     // int x = factorial(n);
//     // cout << "Total: ";
//     // cout << x;
//     // printNumbers(n);
//     // cout<<endl<< calSum(n)<<endl;
// }



// // #include <stdio.h>

// // int countDigits(int n);

// // int main() {
// //     int number;
    
// //     // Input the number
// //     printf("Enter a number: ");
// //     scanf("%d", &number);

// //     // Call the recursive function to count digits
// //     int result = countDigits(number);

// //     // Display the result
// //     printf("Number of digits: %d\n", result);

// //     return 0;
// // }

// // // Recursive function to count digits
// // int countDigits(int n) {
// //     // Base case: if the number is 0, it has 0 digits
// //     if (n == 0) {
// //         return 0;
// //     }
// //     // Recursive case: count digits in the remaining part of the number
// //     else {
// //         return 1 + countDigits(n / 10);
// //     }
// // }
#include <stdio.h>

int fibonacci(int n);

int main() {
    int n;

    // Input the value of n
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Display the nth term of the Fibonacci series
    printf("The %dth term of the Fibonacci series is: %d\n", n, fibonacci(n));

    return 0;
}

// Recursive function to calculate the nth term of Fibonacci series
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
