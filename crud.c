#include<stdio.h>
#include<stdbool.h>
struct User{//structure for user data
    int id,age;
    char name[50];
};

void createFile(){//function to create new file
    FILE* file = fopen("users.txt", "a+");
    if(file == NULL){
        printf("Error opening file\n");
        return;
    }
    fclose(file);
}
bool userPresent(int id){
    FILE* file = fopen("users.txt", "r");//opening users.txt file in reading mode
    struct User user;
    while(fread(&user,sizeof(struct User),1,file)){//reading each record from file
        if(user.id == id){//if user id matches then returning 1 else 0
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}
void createUser(){
    FILE* file = fopen("users.txt", "a");//opening users.txt file in append mode
    struct User user;
    printf("Enter ID: ");
    scanf("%d",&user.id);
    printf("Enter Name: ");
    scanf("%s", user.name);
    printf("Enter Age: ");
    scanf("%d",&user.age);
    if(!userPresent(user.id)){//checking if user already exists
        fwrite(&user,sizeof(struct User),1,file);
        printf("User created successfully\n");
    }
    else   
        printf("Users already exists\n");
    fclose(file);
}
void readData(){
    FILE* file = fopen("users.txt", "r");//opening users.txt file in read mode
    struct User user;
    printf("ID\t\tName\t\tAge\n");
    while(fread(&user,sizeof(struct User),1,file)){//reading each record from file
        printf("%d\t\t%s\t\t%d\n",user.id,user.name,user.age);
    }
    fclose(file);
}

void updateUser(){
    FILE* file = fopen("users.txt", "r");//opening users.txt file in read mode
    FILE* tempFile=fopen("tempUsers.txt","a");//opening temp file in append mode
    int id;//id of user to update
    struct User user;
    printf("Enter ID of user to update: ");
    scanf("%d",&id);
    while(fread(&user,sizeof(struct User),1,file)){//reading each record from file
        if(user.id != id){
            fwrite(&user,sizeof(struct User),1,tempFile);
        }
        else{//if user id matches then we need to update the user details
            printf("Enter New Name: ");
            scanf("%s", user.name);
            printf("Enter New Age: ");
            scanf("%d",&user.age);
            fwrite(&user,sizeof(struct User),1,tempFile);
        }
    }
    printf("User updated\n");
    fclose(tempFile);
    fclose(file);

    remove("users.txt");//removing the user.txt file
    rename("tempUsers.txt","users.txt");//renaming temp file as users.txt

}

void deleteUser(){
    FILE* file = fopen("users.txt", "r");//opening users.txt file in read mode
    FILE* tempFile=fopen("tempUsers.txt","a");//opening temp file in append mode
    struct User user;
    int id;//id of user to delete
    printf("Enter ID of user to delete: ");
    scanf("%d",&id);
    while(fread(&user,sizeof(struct User),1,file)){//reading each record from file
        if(user.id != id){//if user id not exists then writing in another file
            fwrite(&user,sizeof(struct User),1,tempFile);
        }
    }
    printf("User deleted\n");
    fclose(tempFile);
    fclose(file);

    remove("users.txt");//removing the user.txt file
    rename("tempUsers.txt","users.txt");//renaming temp file as users.txt
}
void main(){
    createFile();//creating a file if not exists
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