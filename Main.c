//
// Created by Agustin Bettati  on 24/5/17.
//

#include <printf.h>
#include "Material.h"
#include "Person.h"
#include "Library.h"

Person* getValuesOfNewPerson(){
    int typeOfPerson;
    char name[20];
    char surname[20];
    int id;
    printf("--Creating new Person--\n");
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your surname: ");
    scanf("%s", surname);
    printf("Enter your id number: ");
    scanf("%d", &id);
    printf("Are you a teacher(1) or a student(0)? ");
    scanf("%d",&typeOfPerson);
    if(typeOfPerson == 1){
        int numberOfEmployee;
        printf("Enter your employee number: ");
        scanf("%d", &numberOfEmployee);
        return createPerson(typeOfPerson,name,surname,id,numberOfEmployee,0,10);
    }
    else{
        int enrollmentNumber;
        printf("Enter your enrollment number: ");
        scanf("%d", &enrollmentNumber);
        return createPerson(typeOfPerson,name,surname,id,0,enrollmentNumber,10);

    }
}

Material* getValuesOfNewMaterial(){
    int code;
    int typeOfMaterial;
    char author[20];
    char title[20];
    int year;
    char editorial[20];
    printf("--Creating new Material--\n");
    printf("Enter code number: ");
    scanf("%d", &code);
    printf("Is it a book(1) or a magazine(0)?");
    scanf("%d", &typeOfMaterial);
    printf("Enter authors name: ");
    scanf("%s", author);
    printf("Enter the title: ");
    scanf("%s", title);
    printf("Enter year of creation: ");
    scanf("%d",&year);
    if(typeOfMaterial == 1){
        printf("Enter the name of editorial: ");
        scanf("%s", editorial);
        return createMaterial(typeOfMaterial,code,author,title,year,editorial);
    }
    else{
        return createMaterial(typeOfMaterial,code,author,title,year,"");
    }
}

void askForValuesAndMakeLoan(Library* library){
    int idOfPerson;
    int idOfMaterial;

    printf("Enter the id of the person: ");
    scanf("%d", &idOfPerson);
    printf("Enter the code of the material: ");
    scanf("%d", &idOfMaterial);

    makeLoanOfMaterialToPerson(library, idOfMaterial,idOfPerson);
}

void askForValuesAndReturnLoan(Library* library){
    int idPerson;
    int idLoan;

    printf("Enter the id of the person: ");
    scanf("%d", &idPerson);
    printf("Enter the id of the loan to be returned: ");
    scanf("%d", &idLoan);

    recieveLoanFromAPerson(library,idPerson, idLoan);
}



int main() {
    Material* book1 = createMaterial(1,10,"Jorge", "Perdido en la selva",2012, "Johnson");
    Material* book2 = createMaterial(1,8,"Carlos", "The return",1990, "Pearson");
    Material* magazine = createMaterial(0,15, "John", "Nat geo",2016, "");


    Person* teacher = createPerson(1,"Carlos","Perez",40269313,3001,0,10);
    Person* student = createPerson(0, "Pablo", "Verdeo", 23042143,0,12043,10);

    Library* library = createLibrary(10);

    addNewMaterial(library,book1);
    addNewMaterial(library,book2);
    addNewMaterial(library,magazine);

    addNewPerson(library, teacher);
    addNewPerson(library, student);

    printf("\nBefore starting the system, some people and materials where added \nto make it easier to see its functionality. \n");
    int action = -1;
    do{
        printf("Available operations:\n"
                       " 1 - List of people with thier respective loans.\n"
                       " 2 - List of available material.\n"
                       " 3 - Add new person.\n"
                       " 4 - Add new material.\n"
                       " 5 - Person asks for a loan.\n"
                       " 6 - Person returns a loan.\n"
                       " 7 - Close system.\n"
                       "Enter your desired operation: ");
        scanf("%d",&action);
        printf("\n");

        switch(action){
            case 1:
                printlistOfPeopleAndThierLoans(library);
                break;
            case 2:
                printlistOfMaterial(library);
                break;
            case 3:
                addNewPerson(library, getValuesOfNewPerson());
                break;
            case 4:
                addNewMaterial(library, getValuesOfNewMaterial());
                break;
            case 5:
                askForValuesAndMakeLoan(library);
                break;
            case 6:
                askForValuesAndReturnLoan(library);
                break;
            case 7:
                printf("Hope the system was useful!");
                break;
            default:
                printf("Please enter a valid operation! \n");
                break;
        }

    } while(action != 7);

    return 0;
}

