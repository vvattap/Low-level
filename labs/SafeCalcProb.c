/*

    Safe integer calculator - warns if an overflow or
    underflow error occurs.

    Menu
    Negation
    Safe unsigned ops
    Safe signed ops
    Arithmetic without + - * / % ++ or --

    Code the functions below and uncomment the code in main()
    when completed.

    Code the functions in order as they appear.  Subsequent
    functions depend on previous functions.  You cannot use
    any math operators (+ - * / % ++ or --) except simple
    assignment (=).  However, you may use relational and
    logical operators.

    The _add() function should only use bitwise operators.  All
    other functions can call functions necessary to complete the
    required operation.  I added some hints above functions.

*/

#include <stdio.h>
#include <limits.h>
#include<string.h>

// Prototypes
int _add(int a, int b);
int add(int a, int b);
int sub(int a, int b);
int neg(int a);
int mul(int a, int b);
int div(int a, int b);
int mod(int a, int b);
int pow(int a, int b);
int convert(char *input);
void menu();


// Main
//int main(int argc, char *argv[]){
//
//    int res = 0;        // Cumulative result - running total
//    int n = 0;          // For number conversion from input string
//    char input[50];     // Input string
//    input[0] = '\0';    // Put null in operator char so loop works
//
//    // printf("%d\n", add(INT_MIN,-5));
//    //  printf("%d\n",sub(INT_MAX,-6));
//    // printf("%d\n", mul(-4,-5) );
//    // printf("%d\n", div(5,10));
//    // printf("%d\n", pow(-5,3));
//    // printf("%d\n", mod(3,2));
//    // gets(input);
//    // convert(input);
//    // printf("%d\n", convert(input));
//
//
//    // Write code here to test your functions
//    // Uncomment code below when done
//
//    // Loop until quit is selected
//    while(input[0] != 'q' && input[0] != 'Q'){
//        // Show menu choices
//        menu();
//        // Print prompt with running total
//        printf("\nres = %d > ", res);
//        // Get input string
//        gets(input);
//        // Clear screen
//        //system("cls");
//
//        // Switch on operator char input[0]
//        switch (input[0]){
//            case '+':
//                res = add(res, convert(input));
//                break;
//            case '-':
//                res = sub(res, convert(input));
//                break;
//            case '*':
//                res = mul(res, convert(input));
//                break;
//            case '/':
//                res = div(res, convert(input));
//                break;
//            case '%':
//                res = mod(res, convert(input));
//                break;
//            case '~':
//                res = neg(res);
//                break;
//            case '^':
//                res = pow(res, convert(input));
//                break;
//            case 'c':
//            case 'C':
//                res = 0;
//                break;
//            case 'q':
//            case 'Q':
//                printf("Good-bye!\n");
//                break;
//            default:
//                printf("Enter a valid operator and operand\n");
//
//        }
//
//    }
//
//
//    return 0;
//}


// Show menu choices
void menu(){
    printf("\nSafe Integer Calculator\n");
    printf("+ x to add\n");
    printf("- x to subtract\n");
    printf("* x to multiply\n");
    printf("/ x to divide\n");
    printf("%% x to modulus\n");
    printf("~ x to negate\n");
    printf("^ x to raise by power x\n");
    printf("c x to clear result\n");
    printf("q x to quit\n");
    return;
}


/*
    This function should only use bitwise operators and
    relational operators
*/
// Add operation using only bitwise operators
int _add(int a, int b){
    // Loop until b is zero
    while(b != 0){
        // Find carry 1 bits - a AND b assign to carry
        int c = a & b;
        // Find non carry 1 bits - a XOR b assign to a
        a = a ^ b;
        // Multiply carry by 2 by shift and assign to b
        b = c <<1;
    }
    return a;
}
// Say you have 8-bits signed integers. The range of representable integers start at −128 and ends at 127.

// If you perform 127+1, you obtain −128 : 01111111+00000001=10000000 and the overflow flag is turned on.

// If you perform −128−1, you obtain 127 : 10000000−00000001=01111111 and the overflow flag is turned on.

// In both cases, these are overflows.

/*
    Safe add() should call _add() and check for both
    overflow and underflow errors.
*/
// Safe add operation
int add(int a, int b){
    // Declare int for result
    int res = 0;
    // Call to _add() a and b and assign to result
    res = _add(a,b);
    // Check for overflow - look at page 90 in book
    if( (a < 0 && b < 0) && res > 0){
        printf("Underflow Error");
        return res; }
    // Check for underflow - look at page 90 in book
    else if((a > 0 && b > 0) && res < 0){
        printf("Overflow Error");
        return res;
    }
    return res;
}


/*
    Negate a by using a bitwise operator and safe add().
    Look on page 95 in book.
    Replace the zero with an expression that solves this.
*/
// Define negation with ~ and safe add
int neg(int a){
    // Return negation of a and add 1
    return add(~a, 1);   // Replace 0 with code
}


/*
    Remember that subtraction is the same as addition
    if you negate one of the operands.
    Replace the zero with an expression that solves this.
*/
// Define safe subtract by safe add - negate b
int sub(int a, int b){
    b = neg(b);
    return add(a,b);
}


/*
    Safe mul() uses an iterative call to safe add()
    to calculate a product. Remember that
        5 x 4 = 5 + 5 + 5 + 5 = 20
*/
// Define safe multiply by calling safe add b times
int mul(int a, int b){
    // Declare and initialize cumulative result
    int res = 0;
    // Declare sign of product - initially assume positive
    int sign =1;
    // Absolute value of a and flip sign
    if(a < 0){
        a = neg(a);
        sign = neg(sign);
    }
    // Absolute value of b and flip sign
    if(b < 0){
        b = neg(b);
        sign = neg(sign);
    }
    // For efficiency - smaller number should be multiplier
    int multiplier, toAdd;
    if(a <= b){
        multiplier = a; 
        toAdd = b;  }
    else {
        multiplier = b;
        toAdd = a;  }
    // Accumulate result
    while(multiplier != 0){
        res = add(res, toAdd);
        multiplier = sub(multiplier,1);
    }
    // Set sign to output
    if (sign<0){
        res = neg(res);  }
    return res;
}


/*
    Safe div() repeatedly subtracts b from a, counting the
    number of subtractions until a < b, which it returns.
*/
// Define safe divide by calling safe subtract b times
int div(int a, int b){
    // Declare int to count how many times can b be subtracted from a
    int cnt = 0;
    // Declare sign
    int sign = 1;
    // Absolute value of a and flip sign
    if(a < 0){
        a = neg(a);
        sign = neg(a);
    }
    // Absolute value of b and flip sign
    if(b< 0){
        b = neg(b);
        sign = neg(b);
    }
    // loop to calculate how many times can b be subtracted from a
    while(a >= b){
        a = sub(a, b);
        cnt = add(cnt, 1);
    }
    // Set sign to output
    if (sign < 0){
        cnt = neg(cnt);
    }
    return cnt;
}


/*
    Safe mod() repeatedly subtracts b from a until a < b, returning a.
*/
// Define safe modulus by calling safe subtract
int mod(int a, int b){
    // Absolute value of a
    if(a < 0){
        a = neg(a);
    }
    // Absolute value of b
    if(b< 0){
        b = neg(b);
    }
    // Find remainder by repeated subtraction a - b
    while(sub(a,b) >= 0){
        a = sub(a, b);
        }
    return a;
}


/*
    Safe pow() calculates as the math pow function but
    only uses the safe operations.
        res = n^exp
    Loop until exp is zero
        res = res * n
        exp = exp - 1
    Remember the special case for n^0

*/
// Define safe pow by calling safe multiply exp times
int pow(int n, int exp){
    // Declare int for result of n^exp
    int res = n; 
    // Loop and multiply to calculate n^exp
    while(exp > 1 ){   //used to be exp -1 > 0
        res = mul(res, n);
        exp = sub(exp, 1);
    }
    return res;
}


/*
    This function extracts the integer value from the input string.
        If input = "+ -123", res = -123.
        If input = "* 987654", res = 987654.
    The best way to solve complicated problems is to work them out
    on paper first.
*/
// Extract the integer from the input string and convert to int
int convert(char *input){
    // Declare int for result extracted from input
    int res = 0;
    // Declare int for sign of result
    int sign = 1;
    // Declare two iterators
    int i =1; // j;
    // Declare a buffer for numeric chars   -- didn't use the buffer    
    // Set error to zero - no error found yet
    int error = 0;
    // Check for space in element 1
    if(input[1] == ' ') i = 2;
    // Check for negative integer at element 2
    if(input[2] == '-'){
        sign = -1;
        i = add(i, 1);
        //i++;
        }
    
    // Loop to copy all numeric chars to buffer
    // i is iterator for input string and should start at first numeric char
    // j is iterator for buffer where numeric chars are copied
    // This must test for chars between 0 and 9
    for(; i< strlen(input); i = add(i , 1)  ){
        res = add(mul(10, res), sub(input[i], '0'));
        //i = add(i, 1);
        
    }
    // i gets position of last numeric char in buffer
    // j is now used for pow function - start at zero   
   
    // Construct integer from buffer using pow j increases and i decreases   
   
    
    return res * sign;
}

