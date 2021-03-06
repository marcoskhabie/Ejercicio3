//
// Created by Marcos khabie on 18/5/17.
//

#include <printf.h>
#include "Person.h"


Person* createStudent(char* name, char* surname,int id,int enrollmentNumber,int initialCapacityOfLoans){
    Person* newPerson = malloc(sizeof(Person));

    newPerson->typeOfPerson= 0;
    newPerson->id = id;
    newPerson->amountOfLoans= 0;
    newPerson->maxCapacityOfLoans=initialCapacityOfLoans;
    newPerson->numberOfEmployee = -1;
    newPerson->enrollmentNumber = enrollmentNumber;


    newPerson->name= malloc(sizeof(char)*strlen(name)+1);
    newPerson->surname= malloc(sizeof(char)*strlen(surname)+1);

    strcpy(newPerson->name,name);
    strcpy(newPerson->surname,surname);

    newPerson->loans= malloc(sizeof(Loan*)* initialCapacityOfLoans);

    return newPerson;
}
Person* createTeacher(char* name, char* surname,int id,int numberOfEmployee, int initialCapacityOfLoans){
    Person* newPerson = malloc(sizeof(Person));

    newPerson->typeOfPerson=1;
    newPerson->id = id;
    newPerson->amountOfLoans= 0;
    newPerson->maxCapacityOfLoans=initialCapacityOfLoans;
    newPerson->numberOfEmployee = numberOfEmployee;
    newPerson->enrollmentNumber = -1;


    newPerson->name= malloc(sizeof(char)*strlen(name)+1);
    newPerson->surname= malloc(sizeof(char)*strlen(surname)+1);

    strcpy(newPerson->name,name);
    strcpy(newPerson->surname,surname);

    newPerson->loans= malloc(sizeof(Loan*)* initialCapacityOfLoans);

    return newPerson;
}
void makeLoan(Material* material, Person* person){
    Loan* loan= createLoan(material,material->code);
    if (person->amountOfLoans== person->maxCapacityOfLoans){

        person->loans = realloc(person->loans, sizeof(Loan*) * person->maxCapacityOfLoans* 2);
        person->maxCapacityOfLoans = person->maxCapacityOfLoans * 2;
    }
    person->loans[person->amountOfLoans]=loan;
    person->amountOfLoans++;

}

Material* returnLoan(Person* person, int idLoan){
    Material* result;
    for (int i = 0; i <person->amountOfLoans ; i++) {
        if (person->loans[i]->idOfLoan==idLoan){
            result= person->loans[i]->material;

            for (int j = i; j <person->amountOfLoans-1 ; j++) {
                person->loans[j]=person->loans[j+1];
            }
            person->amountOfLoans--;
            return result;
        }
    }

}
void destroyPerson(Person* person){
    free(person->name);
    free(person->surname);
    free(person->loans);
    free(person);
}

void printPerson(Person* person){
    printf("%s ", person->name);
    printf("%s ", person->surname);
    printf("id: %d", person->id);
    if(person->typeOfPerson == 0){
        printf("(student), ");
        printf("enrollmentNumber: %d, ", person->enrollmentNumber);
    }
    else {
        printf("(teacher), numberOfEmployee: %d, ", person->numberOfEmployee);
    }
    printf("loans: \n");
    if(person->amountOfLoans == 0){
        printf("Empty.\n");
    }
    for (int i = 0; i < person->amountOfLoans; i++) {
        printLoan(person->loans[i]);
    }
}