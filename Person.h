//
// Created by Marcos khabie on 18/5/17.
//

#ifndef EJERCICIO2_PERSON_H
#define EJERCICIO2_PERSON_H


#include "Loan.h"

typedef struct person{  

    int typeOfPerson; // 0 Student, 1 Teacher. 
    char* name; 
    char* surname; 
    int id;
    Loan** loans;
    int amountOfLoans; 
    int maxCapacityOfLoans;

    int numberOfEmployee;
    int enrollmentNumber;
}Person;

Person* createStudent(char* name, char* surname,int id,int enrollmentNumber,int initialCapacityOfLoans);
Person* createTeacher(char* name, char* surname,int id,int numberOfEmployee, int initialCapacityOfLoans);
void makeLoan(Material* material, Person* person);

Material* returnLoan(Person* person, int idLoan);
void destroyPerson(Person* person);

void printPerson(Person* person);

#endif //EJERCICIO2_PERSON_H
