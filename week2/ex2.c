#include <stdio.h>
#include <string.h>
int main(){
    char string[256];
    char newstr[256];
    printf("Print the string:");
    scanf("%s",string);
    for(int i=0; i<strlen(string)&&string[i]!='\n';i++){
        newstr[strlen(string)-i-1]=string[i];
    }
    printf("The reverse string is:\n%s", newstr);
    return 0;
}
