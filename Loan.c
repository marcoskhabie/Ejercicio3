//
// Created by Marcos khabie on 18/5/17.
//

#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <printf.h>
#include "Loan.h"

Loan* createLoan(Material* material, int id){
    Loan* newLoan = malloc(sizeof(Loan));
    newLoan->material = material;
    newLoan->id = id;

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];
    strftime(s, sizeof(s), "%c", tm);

    newLoan->dateOfLoan = malloc(sizeof(char)*(strlen(s)+1));
    strcpy(newLoan->dateOfLoan, s);

    //Falta fecha entrega.

    return newLoan;
}
void destroyLoan(Loan* loan){
    free(loan->material);
    free(loan->dateOfLoan);
    free(loan->dateOfReturn);
    free(loan);
}

void printLoan(Loan* loan){
    printf("Id of loan: %d \n", loan->id);
    printf("Material -> ");
    printMaterial(loan->material);
    printf("Date of loan is %s \n", loan->dateOfLoan);
    printf("Date of return is %s \n", loan->dateOfLoan);


}