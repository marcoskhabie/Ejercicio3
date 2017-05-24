//
// Created by Marcos khabie on 18/5/17.
//

#ifndef EJERCICIO2_LIBRARY_H
#define EJERCICIO2_LIBRARY_H

#include "Material.h"

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

void removeMaterial(Library* library, int idOfMaterial);

void makeLoanOfMaterialToPerson(Library* library, int idMaterial, int idPerson);

#endif //EJERCICIO2_LIBRARY_H
