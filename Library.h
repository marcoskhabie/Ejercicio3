//
// Created by Marcos khabie on 18/5/17.
//

#ifndef EJERCICIO2_LIBRARY_H
#define EJERCICIO2_LIBRARY_H

#include "Material.h"
#include "Person.h"

typedef struct library{
    Material** materials;
    int amountOfMaterials;
    int maxCapacityOfMaterials;

    Person** clients;
    int amountOfClients;
    int maxCapacityOfClients;
}Library;

Library* createLibrary(int initialCapacity);
void destroyLibrary(Library* library);

void addNewMaterial(Library* library, Material* material);
void addNewPerson(Library* library, Person* person);

int removeMaterial(Library* library, int codeOfMaterial);

void makeLoanOfMaterialToPerson(Library* library, int idMaterial, int idPerson);
void recieveLoanFromAPerson(Library* library, int idPerson, int idLoan);

Material* getMaterial(Library* library, int materialId);
Person* getPerson(Library* library,int idOfPerson);

void printlistOfMaterial(Library* library);
void printlistOfPeopleAndThierLoans(Library* library);

#endif //EJERCICIO2_LIBRARY_H
