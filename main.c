#include "contact.h"

int main()
{
    //all function calls should be inside the main 
    //declare variable
    int option;
    AddressBook addressBook;

    //function call for initialize
    initialize(&addressBook);

    //loop until exit
    do {
        //display options
        printf("1. Create contact\n");
        printf("2. Edit contact\n");
        printf("3. Delete contact\n");
        printf("4. Search contact\n");
        printf("5. List contact\n");
        printf("6. Save and Exit\n");

        //prompt  message
        printf("Enter your choice : ");
        //read input from user
        scanf("%d",&option);
        
        //funtion calls
        switch(option){
            case 1:
                // printf("Create contact is selected\n");
                createContact(&addressBook);
                break;
            case 2:
                // printf("Edit contact is selected\n");
                editContact(&addressBook);
                break;
            case 3:
                // printf("Delete contact is selected\n");
                deleteContact(&addressBook);
                break;
            case 4:
                // printf("Search contact is selected\n");
                searchContact(&addressBook);
                break;
            case 5:
                // printf("List contact is selected\n");
                listContacts(&addressBook);
                break;
            case 6:
                printf("Save contact is selected\n");
                save(&addressBook);
                break;
            default:
                printf("Invalid option!!,Enter number between 1 and 6\n");
                break;
                
        }
    } while(option != 6);

    return 0;
}

