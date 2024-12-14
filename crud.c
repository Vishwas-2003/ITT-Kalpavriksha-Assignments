#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct User{
    int id,age;
    char name[50];
};

void writeFile(struct User user,FILE* file){
    fwrite(&user,sizeof(struct User),1,file);
}
bool readUser(FILE* file, struct User* user) {
    return fread(user, sizeof(struct User), 1, file) == 1;
}

void createFile(){
    FILE* file = fopen("users.txt", "a+");
    if(file == NULL){
        printf("Error opening file\n");
        return;
    }
    fclose(file);
}
bool userPresent(int id){
    FILE* file = fopen("users.txt", "r");
    if(file==NULL){
        printf("Error opening file\n");
        exit(1);
    }
    struct User user;
    while(readUser(file,&user)){
        if(user.id == id){
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}
void createUser(){
    FILE* file = fopen("users.txt", "a");
    if(file==NULL){
        printf("Error opening file\n");
        exit(1);
    }
    struct User user;
    printf("Enter ID: ");
    scanf("%d",&user.id);
    printf("Enter Name: ");
    scanf("%s", user.name);
    printf("Enter Age: ");
    scanf("%d",&user.age);
    if(!userPresent(user.id)){
        writeFile(user,file);
        printf("User created successfully\n");
    }
    else   
        printf("Users already exists\n");
    fclose(file);
}
void readData(){
    FILE* file = fopen("users.txt", "r");
    if(file==NULL){
        printf("Error opening file\n");
        exit(1);
    }
    struct User user;
    printf("ID\t\tName\t\tAge\n");
    while(readUser(file,&user)){
        printf("%d\t\t%s\t\t%d\n",user.id,user.name,user.age);
    }
    fclose(file);
}

void updateUser(){
    FILE* file = fopen("users.txt", "r");
    FILE* tempFile=fopen("tempUsers.txt","a");
    if(file==NULL || tempFile==NULL){
        printf("Error opening file\n");
        exit(1);
    }
    int id;
    struct User user;
    printf("Enter ID of user to update: ");
    scanf("%d",&id);
    while(readUser(file,&user)){
        if(user.id != id){
            writeFile(user,tempFile);
        }
        else{
            printf("Enter New Name: ");
            scanf("%s", user.name);
            printf("Enter New Age: ");
            scanf("%d",&user.age);
            writeFile(user,tempFile);
            printf("User updated\n");
        }
    }
    fclose(tempFile);
    fclose(file);

    remove("users.txt");
    rename("tempUsers.txt","users.txt");

}

void deleteUser(){
    FILE* file = fopen("users.txt", "r");
    FILE* tempFile=fopen("tempUsers.txt","a");
    if(file==NULL || tempFile==NULL){
        printf("Error opening file\n");
        exit(1);
    }
    struct User user;
    int id;
    printf("Enter ID of user to delete: ");
    scanf("%d",&id);
    while(readUser(file,&user)){
        if(user.id != id){
            writeFile(user,tempFile);
        }
        else{
            printf("User deleted\n");
        }
    }
    fclose(tempFile);
    fclose(file);

    remove("users.txt");
    rename("tempUsers.txt","users.txt");
}
void main(){
    createFile();
    int choice=0;
    while(choice!=-1){
        printf("\nWhich operation do you want to perform\n1. Create User\n2. Read\n3. Update User\n4. Delete User\n5. Exit\nYour choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:createUser();
            break;
            case 2:readData();
            break;
            case 3:updateUser();
            break;
            case 4:deleteUser();
            break;
            case 5:choice=-1;
            break;
            default:printf("Invalid Input\n");
            break;
        }
    }
}