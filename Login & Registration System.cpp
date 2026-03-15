#include <stdio.h>
#include <string.h>

void registerUser() {
    char username[50], password[50];

    FILE *fp = fopen("users.txt", "a");

    printf("\n--- Registration ---\n");

    printf("Enter Username: ");
    scanf("%s", username);

    printf("Enter Password: ");
    scanf("%s", password);

    fprintf(fp, "%s %s\n", username, password);

    fclose(fp);

    printf("Registration Successful!\n");
}

void loginUser() {
    char username[50], password[50];
    char fileUser[50], filePass[50];
    int found = 0;

    FILE *fp = fopen("users.txt", "r");

    printf("\n--- Login ---\n");

    printf("Enter Username: ");
    scanf("%s", username);

    printf("Enter Password: ");
    scanf("%s", password);

    while(fscanf(fp, "%s %s", fileUser, filePass) != EOF) {
        if(strcmp(username, fileUser) == 0 && strcmp(password, filePass) == 0) {
            found = 1;
            break;
        }
    }

    fclose(fp);

    if(found)
        printf("Login Successful!\n");
    else
        printf("Invalid Username or Password!\n");
}

int main() {

    int choice;

    printf("\n1. Register\n");
    printf("2. Login\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);

    if(choice == 1)
        registerUser();
    else if(choice == 2)
        loginUser();
    else
        printf("Invalid Choice");

    return 0;
}
