#include <stdio.h>
#include <string.h>
#include <ctype.h>

char line[100], lineN[100];

char* convtobin(char *command) {
    static char temp[9];  

    if (strcmp(command, "RA=RA+RB") == 0) {
        strcpy(temp, "00000000");
    }
    else if (strcmp(command, "RB=RA+RB") == 0) {
        strcpy(temp, "00010000");
    }
    else if (strcmp(command, "RA=RA-RB") == 0) {
        strcpy(temp, "00000100");
    }
    else if (strcmp(command, "RB=RA-RB") == 0) {
        strcpy(temp, "00010100");
    }
    else if (strcmp(command, "RO=RA") == 0) {
        strcpy(temp, "00100000");
    }
    else if (strcmp(command, "RA=0") == 0) {
        strcpy(temp, "00001000");
    }
    else if (strcmp(command, "RA=1") == 0) {
        strcpy(temp, "00001001");
    }
    else if (strcmp(command, "RA=2") == 0) {
        strcpy(temp, "00001010");
    }
    else if (strcmp(command, "RA=3") == 0) {
        strcpy(temp, "00001011");
    }
    else if (strcmp(command, "RA=4") == 0) {
        strcpy(temp, "00001100");
    }
    else if (strcmp(command, "RA=5") == 0) {
        strcpy(temp, "00001101");
    }
    else if (strcmp(command, "RA=6") == 0) {
        strcpy(temp, "00001110");
    }
    else if (strcmp(command, "RA=7") == 0) {
        strcpy(temp, "00001111");
    }
    else if (strcmp(command, "RB=0") == 0) {
        strcpy(temp, "00011000");
    }
    else if (strcmp(command, "RB=1") == 0) {
        strcpy(temp, "00011001");
    }
    else if (strcmp(command, "RB=2") == 0) {
        strcpy(temp, "00011010");
    }
    else if (strcmp(command, "RB=3") == 0) {
        strcpy(temp, "00011011");
    }
    else if (strcmp(command, "RB=4") == 0) {
        strcpy(temp, "00011100");
    }
    else if (strcmp(command, "RB=5") == 0) {
        strcpy(temp, "00011101");
    }
    else if (strcmp(command, "RB=6") == 0) {
        strcpy(temp, "00011110");
    }
    else if (strcmp(command, "RB=7") == 0) {
        strcpy(temp, "00011111");
    }
    else if (strcmp(command, "JC=0") == 0) {
        strcpy(temp, "01110000");
    }
    else if (strcmp(command, "JC=1") == 0) {
        strcpy(temp, "01110001");
    }
    else if (strcmp(command, "JC=2") == 0) {
        strcpy(temp, "01110010");
    }
    else if (strcmp(command, "JC=3") == 0) {
        strcpy(temp, "01110011");
    }
    else if (strcmp(command, "JC=4") == 0) {
        strcpy(temp, "01110100");
    }
    else if (strcmp(command, "JC=5") == 0) {
        strcpy(temp, "01110101");
    }
    else if (strcmp(command, "JC=6") == 0) {
        strcpy(temp, "01110110");
    }
    else if (strcmp(command, "JC=7") == 0) {
        strcpy(temp, "01110111");
    }
    else if (strcmp(command, "J=0") == 0) {
        strcpy(temp, "10110000");
    }
    else if (strcmp(command, "J=1") == 0) {
        strcpy(temp, "10110001");
    }
    else if (strcmp(command, "J=2") == 0) {
        strcpy(temp, "10110010");
    }
    else if (strcmp(command, "J=3") == 0) {
        strcpy(temp, "10110011");
    }
    else if (strcmp(command, "J=4") == 0) {
        strcpy(temp, "10110100");
    }
    else if (strcmp(command, "J=5") == 0) {
        strcpy(temp, "10110101");
    }
    else if (strcmp(command, "J=6") == 0) {
        strcpy(temp, "10110110");
    }
    else if (strcmp(command, "J=7") == 0) {
        strcpy(temp, "10110111");
    }
    else {
        strcpy(temp, "11111111"); 
    }
    printf("%s -> %s\n", command, temp);
    return temp;
}

void assembler() {
    FILE *fi = fopen("fibonacci.asm", "r");
    FILE *fo = fopen("fibonacci.bin", "w");

    if (fi == NULL) {
        printf("Error! Could not open input file.\n");
        return;
    }
    if (fo == NULL) {
        printf("Error! Could not open output file.\n");
        fclose(fi);
        return;
    }

    while (fgets(line, 100, fi)) {
    int j = 0;
    memset(lineN, 0, sizeof(lineN));
      for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] != '\n' && line[i] != ' ') {
         lineN[j++] = toupper(line[i]);
    }
    }
        lineN[j] = '\0';  
        char *bin = convtobin(lineN);
        fprintf(fo, "%s\n", bin);
    }

    fclose(fi);
    fclose(fo);
}

int main() {
    assembler();  
    return 0;
}

