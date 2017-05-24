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
    newLoan->idOfLoan = id;

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char dateOfLoan[64];
    strftime(dateOfLoan, sizeof(dateOfLoan), "%c", tm);

    newLoan->dateOfLoan = malloc(sizeof(char)*(strlen(dateOfLoan)+1));
    strcpy(newLoan->dateOfLoan, dateOfLoan);

    time_t f = time(NULL);
    struct tm *fm = localtime(&f);
    fm->tm_wday = fm->tm_wday;

    fm->tm_mday = fm->tm_mday + 4;
    char dateOfReturn[64];
    strftime(dateOfReturn, sizeof(dateOfReturn), "%c", fm);

    newLoan->dateOfReturn = malloc(sizeof(char)*(strlen(dateOfReturn)+1));
    strcpy(newLoan->dateOfReturn, dateOfReturn);

    return newLoan;
}
void destroyLoan(Loan* loan){
    free(loan->material);
    free(loan->dateOfLoan);
    free(loan->dateOfReturn);
    free(loan);
}

void printLoan(Loan* loan){
    printf("Id of loan: %d \n", loan->idOfLoan);
    printf("Material == ");
    printMaterial(loan->material);
    printf("Date of loan is %s \n", loan->dateOfLoan);
    printf("Date of return is %s \n", loan->dateOfReturn);

}