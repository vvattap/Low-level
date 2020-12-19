/*

    Number converter

    Menu
    Convert between integer, binary, octal and hexadecimal

    This program should accept numeric values in hexadecimal,
    decimal, octal and binary formats as:

        Hex 0x0 to 0xFFFFFFFF
        Dec 0 to 4294967295
        Oct o0 to o37777777777
        Bin b0 to b11111111111111111111111111111111

    After a value is input the code in main will interpret the
    data types above an process the conversion to an unsigned
    int.  The unsigned int will be used to convert the input to
    strings containing hexadecimal, octal and binary strings.

*/

#include <stdio.h>
#include <string.h>
//#include "Calc.h"
#include <stdlib.h>

//int input_to_decimal(char *input);
unsigned int bin_to_uint(char *input);
unsigned int oct_to_uint(char *input);
unsigned int hex_to_uint(char *input);
unsigned int dec_to_uint(char *input);
void uint_to_hex(unsigned int n, char *output);
void uint_to_oct(unsigned int n, char *output);
void uint_to_bin(unsigned int n, char *output);


int error = 0;


int main(){
    char input[50];
    unsigned int n = 0;
    char output[50];
 

    // Write code here to test your functions
    // Uncomment code below when done

    printf("Enter a binary, octal, decimal or hexadecimal number\n");
    printf("convert > ");
    gets(input);

    char *ptr;
    if(strtol(input, &ptr ,10) > UINT32_MAX) {
        printf("In order to avoid overflow error, will exit now.");
        exit(0);
    }


    // printf("%d\n", hex_to_uint(input));
    // printf("%s\n", input);
//    printf("%d\n", dec_to_uint(input));
    // printf("%d\n", oct_to_uint(input));
    // printf("%d\n", bin_to_uint(input));
    
    // printf("%d\n", uint_to_hex(16), output);
    // uint_to_hex(567890, output);
    // uint_to_oct(74920263, output);
    // uint_to_bin(45678, output);
    // printf("%s\n", output);
    

    // Detect input data type
    // Hexadecimal
    if(input[0] == '0' && input[1] == 'x'){
        n = hex_to_uint(input);
    }
    // Decimal
    else if(input[0] >= '0' && input[0] <= '9'){
        n = dec_to_uint(input);
    }
    // Octal
    else if(input[0] == 'o'){
        n = oct_to_uint(input);
    }
    // Binary
    else if(input[0] == 'b'){
        n = bin_to_uint(input);
    }
    // Unknown
    else{
        printf("ERROR: Unknown data type: %s\n", input);
        exit(0);
    }

    // Print results
    printf("The decimal value of %s is %u\n", input, n);
    uint_to_hex(n, output);
    printf("The hexadecimal value of %s is %s\n", input, output);
    uint_to_oct(n, output);
    printf("The octal value of %s is %s\n", input, output);
    uint_to_bin(n, output);
    printf("The binary value of %s is %s\n", input, output);


    return 0;
}


/*
    This function converts the value part of the hex
    string to an unsigned integer value.  The first
    two chars are 0x, which tells that the string is
    in hex.  Start processing the value at index 2 until
    the null, calculating the int value as you would on
    paper.  Try on paper first.
*/
// Convert a hexadecimal char array to uint
unsigned int hex_to_uint(char *input){
    // Declare result and set to zero
    unsigned int res = 0;
    // Declare and set multiplier to 1
    int multiplier = 1;
    // Declare iterator
    // Loop through value part of input string
    for(int i = strlen(input) - 1; i >= 2; i--){
        // If between 0 and 9 add 0 to 9 to res with multiplier  
        if(input[i] >= 48 && input[i] <= 57){
            res +=  (input[i] - 48) * multiplier;
        }       
        // If between A and F add 10 to 15 to res with multiplier
        else if (input[i] >= 65 && input[i] <= 70){
            res += (input[i] - 55) * multiplier;
        }
        // Error - exit
        else {
            printf("The values entered were not within hexadecimal ranges.");
            exit(error); 
        }
        // Advance multiplier to next position value   
        multiplier <<= 4;
        }
    return res;
}


/*
    Copy hex_to_uint() and modify for decimal input.
*/
// Convert a unsigned integer char array to uint
unsigned int dec_to_uint(char *input){
    // Declare result and set to zero
    unsigned int res = 0;
    int multiplier = 1;
    for(int i = strlen(input) - 1; i >= 0; i--){
        if(input[i] >= '0' && input[i] <= '9'){
            res += (input[i] - '0') * multiplier;
        }
        else{
            printf("The values were not within decimal ranges\n");
            exit(error);
        }
        multiplier *= 10;
    }
    return res;


     
}
// Oct o0 to o37777777777

/*
    Copy dec_to_uint() and modify for octal input.
*/
// Convert a octal char array to uint
unsigned int oct_to_uint(char *input){
    // Declare result and set to zero
    unsigned int res = 0;
    int multiplier = 1;
    for(int i = strlen(input) - 1; i >=1 ; i-- ){
        if(input[i] >= '0' && input[i] <= '9'){
            res += (input[i] - '0') * multiplier;
        }
        multiplier <<= 3;
        
    }

    return res;
}


/*
    Copy oct_to_uint() and modify for binary input.
*/
// Convert a binary char array to unsigned int
unsigned int bin_to_uint(char *input){
    // Declare result and set to zero
    unsigned int res = 0;
    int multiplier = 1;

   for(int i = strlen(input) -1; i >= 1 ;i-- ){
       if(input[i] <= '1' && input[i] >= '0'){
           res += (input[i] - '0') * multiplier;
       }
       multiplier <<= 1;
   }

    return res;
}


/*
    This function converts from unsigned int to a hex
    char array.  Try this on paper before coding.
*/
// Convert a unsigned integer char array to hexadecimal
void uint_to_hex(unsigned int n, char *output){
    // Declare a uint for remainder
    unsigned int remainder;
    // Declare an int for division
    // int divisor = 16;
    // Declare a char array buffer
    char buffer[strlen(output)];
    // Use a loop to generate a hex string - string will be reverse
    
    // Get last hex char

    // Put null at end of buffer

    // Copy 0x to output string

    // Copy chars from buffer in reverse order to output string
    int i = 0;
    while(n != 0){
        remainder = n % 16;
        n /= 16;

        if(remainder < 10){
            buffer[i++] = remainder + 48; 
        }
        else{
            buffer[i++] = remainder + 55;
        }
    } buffer[i--] = '\0';

    output[0] = '0';   output[1] = 'x';
    int j = 2;
    for( ; i >= 0; i--){
        output[j++] = buffer[i];
    }
    return;
}


/*
    Copy uint_to_hex() and modify for octal
*/
// Convert a unsigned integer char array to octal
void uint_to_oct(unsigned int n, char *output){
    unsigned int remainder;
    char buffer[strlen(output)];
    memset(output, 0, sizeof output);

    int i = 0; 
    while(n != 0){
        remainder = n % 8;
        n /= 8;

        buffer[i++] = remainder + 48;
    } buffer[i--] = '\0';

    int j =0;
    output[j++] = 'o';
    for( ; i >= 0; i--){
        output[j++] = buffer[i];
    } output[j] = '\0';

    return;
}


/*
    Copy uint_to_oct() and modify for binary
*/
// Convert a unsigned integer char array to binary
void uint_to_bin(unsigned int n, char *output){
    unsigned int remainder;
//    char buffer[strlen(output)];
    char buffer[50];
    int i = 0;
    while(n != 0){
        remainder = n % 2;
        n /= 2;

        buffer[i++] = remainder + 48;
    } buffer[i--] = '\0';
// Bin b0 to b11111111111111111111111111111111
    output[0] = 'b';
    int j =1;
    for( ; i >= 0; i--){
        output[j++] = buffer[i];
    }



    return;
}

