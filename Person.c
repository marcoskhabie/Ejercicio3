//
// Created by Marcos khabie on 18/5/17.
//

#include "Person.h"


  Person* createPerson(int typeOfPerson, char* name, char* surname, int amountOfLoans, double debt, Loan** loans,int initialCapacityOfLoans ){

    Person* newPerson = malloc(sizeof(Person));

    newPerson->typeOfPerson=typeOfPerson;
    newPerson->amountOfLoans=amountOfLoans;
    newPerson->debt=debt;
    newPerson->maxCapacityOfLoans=initialCapacityOfLoans;

    newPerson->name= malloc(sizeof(char)*strlen(name)+1);
    newPerson->surname= malloc(sizeof(char)*strlen(surname)+1);
    newPerson->loans= malloc(sizeof(Loan*)* initialCapacityOfLoans);

    strcpy(newPerson->name,name);
    strcpy(newPerson->surname,surname);


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
        if (person->loans[i]->id==idLoan){
            result= person->loans[i]->material;

            for (int j = i; j <person->amountOfLoans-1 ; j++) {
                person->loans[j]=person->loans[j+1];
            }
            person->amountOfLoans--;
        }
    }
    return result;
}
void destroyPerson(Person* person){

}