#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *trim(char *s) {
    char *ptr;
    if(!s) {return NULL;}
    if(!*s) {return s;}
    for (ptr =s +strlen(s)-1; ptr>=s&& isspace(*ptr); --ptr);
    ptr[1] = '\0';
    return s;
}

//Encrypts letter using the formula C = E(k,P) = (C +k)(mod 26) then moving it to the correct position in ASCII
char encryption(char letter) {
   letter=  toupper(letter);
    if ("%d", letter != 32 ) letter = ((("%d", letter -65) + 3) % 26) + 65;
       printf("%c", letter);
}

//sends word letter by letter into the encryption method to get encrypted until the array is empty
char encrypt(char word[]) {
    int i = 0;
    while (word[i] != 0) {
            encryption(word[i]);
            i++;
    }
    printf(" ");
};

//decrypts letter using the formula P = D(k,C) = (C -k)(mod 26) then moving it to the correct position in ASCII
char decryption(char letter) {
    letter = toupper(letter);
   if ("%d", letter != 32) {letter =(("%d", letter -16)%26)+65;}
       printf("%c", letter);

}

//sends word letter by letter into the decryption method to get decrypted until the array is empty
char decrypt(char word[]) {
    int i = 0;
    while (word[i] != 0) {
            decryption(word[(i)]);
            i++;
    }
    printf(" ");
}

char encoder(char c) {

    for (int i = 7; i >= 0; i--) {
        c = ((c&(1 << i)) ? '1' : '0');
        printf("%c", c);
    }
    return c;
}
char encode(char string[]) {
    char str[7];
    int len = strlen(string);
    for(int i =0; i<len; i++) {
     encoder(string[i]);
    }


}

int ExitTest;
int main() {
    char command[8];
    char string[100];

    do {

        printf(" Enter a command: \n");
        scanf("%s", command);
        fgets(string, 100, stdin);
        if(strcmp(command, "encrypt") == 0) {
            encrypt(trim(string));
            printf("\n");
        }
        else if (strcmp(command, "decrypt") == 0) {
            decrypt(trim(string));
            printf("\n");
        }else if (strcmp(command, "encode") == 0) {
            encode(trim(string));
            printf("\n");
        }else if (strcmp(command, "exit") == 0) {return 0;}
        else { printf("please enter command correctly!\n"); }


        ExitTest = strcmp(command, "exit");
    } while(ExitTest != 0);

    return 0;
};