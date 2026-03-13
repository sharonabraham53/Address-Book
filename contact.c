#include "contact.h"

void listContacts(AddressBook *addressBook) 
{
    printf("--------------------------------------------------\n");
    printf("\t   ENTERED INTO LIST CONTACT\n");
    printf("--------------------------------------------------\n");

    //display contact
    printf("--------------------------------------------------\n");
    printf(" Name\t\t Mobile\t\t Email\n");
    printf("--------------------------------------------------\n");
    for(int i = 0;i<addressBook->contactCount;i++){
        printf("%-15s",addressBook->contacts[i].name);
        printf("%-15s",addressBook->contacts[i].phone);
        printf("%-25s",addressBook->contacts[i].email);
        printf("\n");
    }
    printf("--------------------------------------------------\n");
    
}

void initialize(AddressBook *addressBook) 
{
    populate(addressBook);
}

void createContact(AddressBook *addressBook) 
{
     printf("--------------------------------------------------\n");
    printf("\t   ENTERED INTO CREATE CONTACT\n");
    printf("--------------------------------------------------\n");
    //declare variables
    int flag=0;
    char* pos;

    //prompt message
    printf("Enter name: \n");
    //read input from user
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);

    //read phone number and validate it
    do{
        //set flag
        flag = 0;
        //prompt message
        printf("Enter Phone number: \n");
        //read input from user
        scanf("%s",addressBook->contacts[addressBook->contactCount].phone);

        //logic to validate phone number
        if(strlen(addressBook->contacts[addressBook->contactCount].phone) != 10){
            printf("Invalid Phone number.\n");
            flag = 1;
        }
    }while(flag == 1);

    //logic to read and validate email id
    do{
        //set flag
        flag = 0;
        //prompt message
        printf("Enter email: \n");
        //read input from user
        scanf("%s",addressBook->contacts[addressBook->contactCount].email);

        //logic to validate
        pos = strstr(addressBook->contacts[addressBook->contactCount].email,"@gmail.com");

        if(pos == NULL || strcmp(pos,"@gmail.com") != 0){
            printf("Invalid Email.");
            flag = 1;
        }
    }while(flag == 1);

    //increment contact count
    addressBook->contactCount++;
}

void searchContact(AddressBook *addressBook) 
{
     printf("--------------------------------------------------\n");
    printf("\t   ENTERED INTO SEARCH CONTACT\n");
    printf("--------------------------------------------------\n");

    //declare variable
    int i = search(addressBook);

    //check if it is found
    if(i == -1){
        printf("Contact not found.");
        return;
    }

    //display output
     printf("--------------------------------------------------\n");
    printf(" Name\t\t Mobile\t\t Email\n");
    printf("--------------------------------------------------\n");
    
    printf("%-15s",addressBook->contacts[i].name);
    printf("%-15s",addressBook->contacts[i].phone);
    printf("%-25s",addressBook->contacts[i].email);
    printf("\n");
    
    printf("--------------------------------------------------\n");
}

void editContact(AddressBook *addressBook) 
{
     printf("--------------------------------------------------\n");
    printf("\t   ENTERED INTO EDIT CONTACT\n");
    printf("--------------------------------------------------\n");
    //decalre variable
    int i = search(addressBook);
    int option;

    if(i == -1){
        printf("Contact not found.");
        return;
    }

    //display contact
    printf("%s\t%s\t%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);

    printf("You want to edit : \n");
    printf("1.Name\n2.Phone number\n3.Email\n");

    printf("Enter your choice : ");
    scanf("%d",&option);

    switch(option){
        case 1:
            printf("Enter name : ");
            scanf(" %[^\n]",addressBook->contacts[i].name);
            break;

        case 2:
            printf("Enter Phone number : ");
            scanf(" %[^\n]",addressBook->contacts[i].phone);
            break;

        case 3:
            printf("Enter name : ");
            scanf(" %[^\n]",addressBook->contacts[i].email);
            break;

        default:
            printf("Invalid option");
            break;
        

    }



}

void deleteContact(AddressBook *addressBook) 
{
    //declare variable
    int i = search(addressBook);

    //check if contact is found
    if(i == -1){
        printf("Contact not found.");
        return;
    }

    for(int j = i;j<(addressBook->contactCount)-1;j++)
    {
        addressBook->contacts[j] = addressBook->contacts[j+1];
    }

    addressBook->contactCount--;

    printf("Contact deleted successfully.\n");
}

int search(AddressBook *addressBook)
{
    //declare variables
    static int choice;
    char input[20];

    printf("Search By :\n1.Name\n2.Phone number\n3.Email\n");
    //prompt message
    printf("Enter your choice : ");
    //read input from user
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        printf("Enter name : ");
        scanf("\n%[^\n]",input);

        //logic to search for input
        for(int i =0;i<addressBook->contactCount;i++){
            if(strcmp(addressBook->contacts[i].name,input)==0){
                return i;
            }
        }
        break;
    case 2:
        printf("Enter Phone number : ");
        scanf("\n%[^\n]",input);

        //logic to search for input
        for(int i =0;i<addressBook->contactCount;i++){
            if(strcmp(addressBook->contacts[i].phone,input)==0){
                return i;
            }
        }
        break;
    case 3:
        printf("Enter Email : ");
        scanf("\n%[^\n]",input);

        //logic to search for input
        for(int i =0;i<addressBook->contactCount;i++){
            if(strcmp(addressBook->contacts[i].email,input)==0){
                return i;
            }
        }
        break;
    
    default:
        
        break;
    }

    return -1;

}

void save(AddressBook *addressBook){
    //  printf("--------------------------------------------------\n");
    // printf("\t   ENTERED INTO SAVE CONTACT\n");
    // printf("--------------------------------------------------\n");

    //declare variables
    FILE *fptr;

    //open file
    fptr = fopen("contact.csv","w");

    //error handling
    if(fptr == NULL){
        printf("Failed to open file.");
        return ;
    }

    //write data to contacts.csv
    fprintf(fptr,"%d\n",addressBook->contactCount);
    
    for(int i = 0;i<addressBook->contactCount;i++){
        fprintf(fptr,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }

    //close file
    fclose(fptr);
}