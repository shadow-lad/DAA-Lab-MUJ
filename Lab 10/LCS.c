#include<stdio.h>

int lcs (char* string1, char* string2, int size1, int size2){

    if(size1 == 0 || size2 == 0)
        return 0;
    
    if(string1[size1-1] == string2[size2 - 1])
        return 1 + lcs(string1, string2, size1-1, size2-1);
    else {

        int a1 = lcs(string1, string2, size1, size2 - 1);
        int a2 = lcs(string1, string2, size1 -1, size2);
        return a1 > a2 ? a1 : a2;

    }
    

}

int main() {

    char string1[100], string2[100];

    printf("Enter string1: ");
    gets(string1);
    printf("Enter string2: ");
    gets(string2);

    int size1 = 0, size2 = 0;
    int i = 0, j = 0;
    while(string1[i++]!='\0');
    size1 = i-1;
    while(string2[j++]!='\0');
    size2 = j-1;
    
    printf("Length of LCS: %d\n",lcs(string1,string2,size1,size2));

}