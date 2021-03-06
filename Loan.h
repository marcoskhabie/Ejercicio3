//
// Created by Marcos khabie on 18/5/17.
//

#ifndef EJERCICIO2_LOAN_H
#define EJERCICIO2_LOAN_H

#include "Material.h"

typedef struct loan{
    int idOfLoan;
    Material* material;
    char* dateOfLoan;
    char* dateOfReturn;

}Loan;

Loan* createLoan(Material* material, int idOfLoan);
void destroyLoan(Loan* loan);

void printLoan(Loan* loan);

#endif //EJERCICIO2_BORROWING_H
