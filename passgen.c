#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

// Function to generate a random password
void generatePassword(int length, const char *charset, FILE *outputFile) {
    int charset_length = strlen(charset);
    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        int index = rand() % charset_length;
        char random_char = charset[index];
        fprintf(outputFile, "%c", random_char);
    }
}

int main() {
    int end = 0;
    int mode = -1;
    while(end != 1){
        printf(
            "██████╗  █████╗ ███████╗███████╗██╗    ██╗ ██████╗ ██████╗ ██████╗      ██████╗ ███████╗███╗   ██╗\n"
            "██╔══██╗██╔══██╗██╔════╝██╔════╝██║    ██║██╔═══██╗██╔══██╗██╔══██╗    ██╔════╝ ██╔════╝████╗  ██║\n"
            "██████╔╝███████║███████╗███████╗██║ █╗ ██║██║   ██║██████╔╝██║  ██║    ██║  ███╗█████╗  ██╔██╗ ██║\n"
            "██╔═══╝ ██╔══██║╚════██║╚════██║██║███╗██║██║   ██║██╔══██╗██║  ██║    ██║   ██║██╔══╝  ██║╚██╗██║\n"
            "██║     ██║  ██║███████║███████║╚███╔███╔╝╚██████╔╝██║  ██║██████╔╝    ╚██████╔╝███████╗██║ ╚████║\n"
            "╚═╝     ╚═╝  ╚═╝╚══════╝╚══════╝ ╚══╝╚══╝  ╚═════╝ ╚═╝  ╚═╝╚═════╝      ╚═════╝ ╚══════╝╚═╝  ╚═══╝\n");

         printf(
               "1.Generate Password\n"
               "0.Exit\n"
               "Type in number to choose mode\n"
               "Choose Mode:");
        scanf("%d",&mode);

        if(mode == 1){
            printf(
            "██████╗ ███████╗ ██████╗ ██╗   ██╗██╗██████╗ ███████╗███╗   ███╗███████╗███╗   ██╗████████╗\n"
            "██╔══██╗██╔════╝██╔═══██╗██║   ██║██║██╔══██╗██╔════╝████╗ ████║██╔════╝████╗  ██║╚══██╔══╝\n"
            "██████╔╝█████╗  ██║   ██║██║   ██║██║██████╔╝█████╗  ██╔████╔██║█████╗  ██╔██╗ ██║   ██║  \n"
            "██╔══██╗██╔══╝  ██║▄▄ ██║██║   ██║██║██╔══██╗██╔══╝  ██║╚██╔╝██║██╔══╝  ██║╚██╗██║   ██║  \n"
            "██║  ██║███████╗╚██████╔╝╚██████╔╝██║██║  ██║███████╗██║ ╚═╝ ██║███████╗██║ ╚████║   ██║\n"
            "╚═╝  ╚═╝╚══════╝ ╚══▀▀═╝  ╚═════╝ ╚═╝╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═══╝   ╚═╝  \n");
            printf(
                "1.Lowercase\n"
                "2.Lowercase and Uppercase\n"
                "3.Lowercase ,Uppercase and Number\n"
                "4.Lowercase, Uppercase, Number and Special Letter\n"
                "0.Back to Menu\n"
                "Choose Password Requirement:");
            int req;
            scanf("%d",&req);

            char charset[256];
            const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
            const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            const char digits[] = "0123456789";
            const char special[] = "!@#$%^&*";

            if(req == 1){
                strcpy(charset, lowercase);
            }
            else if (req == 2)
            {
                strcpy(charset, lowercase);
                strcat(charset, uppercase);
            }
            else if (req == 3)
            {
                strcpy(charset, lowercase);
                strcat(charset, uppercase);
                strcat(charset, digits);
            }
            else if (req == 4)
            {
                strcpy(charset, lowercase);
                strcat(charset, uppercase);
                strcat(charset, digits);
                strcat(charset, special);
            }
            else if (req == 0)
            {
                return 1;
            }

            int password_length;
            printf("Enter the desired password length: ");
            scanf("%d", &password_length);

            char filename[256];
            printf("Enter the name of the file to save the generated password: ");
            scanf("%s", filename);

            FILE *outputFile;
            outputFile = fopen(filename, "w");

            if(outputFile == NULL){
                perror("Error opening file");
                return 1;
            }

            generatePassword(password_length, charset, outputFile);

            fclose(outputFile);

            printf("Password generated and saved to '%s'.\n", filename);

            return 0;
        }
        else if(mode == 0){
            end = 1;
            return 1;
        }
    }

    return 0;
}