#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int toDecimal(int base);
void fromDecimal(int decimal,int desiredBase);

int main(void) 
{
    float inputBasef, desiredBasef;

    printf("Please enter the numbers base:\n");
    int successfullScanInput = scanf("%f", &inputBasef);
    if ((successfullScanInput != 1) || (inputBasef - (int) inputBasef != 0) || (inputBasef < 2 || inputBasef > 16)){
        printf("Invalid input base\n");
        //assert((successfullScanInput == 1) && (inputBasef - (int) inputBasef == 0) && (inputBasef >= 2 || inputBasef <= 16));
        exit(0);
    }

    printf("Please enter the desired base:\n");
    int successfullScanDesired = scanf("%f", &desiredBasef);
    if((successfullScanDesired != 1) || (desiredBasef - (int) desiredBasef != 0) || (desiredBasef < 2 || desiredBasef > 16)){
        printf("Invalid desired base\n");
        //assert((successfullScanDesired == 1) && (desiredBasef - (int) desiredBasef == 0) && (desiredBasef >= 2 || desiredBasef <= 16));
        exit(0);
    }

    int inputBase = (int) inputBasef;
    int desiredBase = (int) desiredBasef;
    
    int convertionToDecimal = toDecimal(inputBase);
    printf("The result is: ");
    fromDecimal(convertionToDecimal,desiredBase);
    
    return 0;
}

int toDecimal(int base)
{
    int convertion = 0;
    int ch = 0;
    int curr;
    
    printf("Please enter a number in base %d:\n", base);
    
    getchar();
    while ((ch = getchar()) != EOF && (ch != 10))
    {
        if (ch >= 48 && ch <= 57) {
            curr = ch - '0';
        }
        else if (ch >= 97 && ch <= 102) {
            curr = ch - 'a' + 10;
        }

        if ((ch == 45) || (ch == 32) || (curr < 0 || curr > base-1)) {
            printf("Invalid number!");
            exit(0); 
        }

        convertion *= base;
        convertion += curr;
     }
     return convertion;
}

void fromDecimal(int decimal,int desiredBase)
{ 
    int mod = decimal % desiredBase;
    decimal = decimal / desiredBase;
    
    if (decimal != 0) {
        fromDecimal(decimal, desiredBase);
    }

    if (mod == 10) {
        printf("%c", 'a');
    } else if (mod == 11) {
        printf("%c", 'b');
    } else if (mod == 12) {
        printf("%c", 'c');
    } else if (mod == 13) {
        printf("%c", 'd');
    } else if (mod == 14) {
        printf("%c", 'e');
    } else if (mod == 15) {
        printf("%c", 'f');
    } else {
        printf("%d", mod);
    }
}


