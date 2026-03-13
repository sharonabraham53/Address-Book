#include "contact.h"
// Dummy contact data
static Contact dummyContacts[] = {
    {"John Doe", "1234567890", "john@example.com"},
    {"Alice Smith", "0987654321", "alice@example.com"},
    {"Bob Johnson", "1112223333", "bob@company.com"},
    {"Carol White", "4445556666", "carol@company.com"},
    {"David Brown", "7778889999", "david@example.com"},
    {"Eve Davis", "6665554444", "eve@example.com"},
    {"Frank Miller", "3334445555", "frank@example.com"},
    {"Grace Wilson", "2223334444", "grace@example.com"},
    {"Hannah Clark", "5556667777", "hannah@example.com"},
    {"Ian Lewis", "8889990000", "ian@example.com"}
};

void populate(AddressBook *addressbook){
    // addressbook->contactCount = 0;

    // //logic to copy dummy contacts to contacts
    // for (int i = 0; i < 10; i++)
    // {
    //     addressbook->contacts[i] = dummyContacts[i];
    //     addressbook->contactCount++;

    // }
    
    //declare variable
    FILE *fptr;

    //open file
    fptr = fopen("contact.csv","r");

    //error handling
    if(fptr == NULL){
        printf("Failed to open file.");
        return ;
    }

    //read input from file
    fscanf(fptr,"%d\n",&addressbook->contactCount);

    for(int i = 0;i<addressbook->contactCount;i++){
        fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressbook->contacts[i].name,addressbook->contacts[i].phone,addressbook->contacts[i].email);
    }

    //close file
    fclose(fptr);
}
