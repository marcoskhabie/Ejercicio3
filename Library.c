//
// Created by Marcos khabie on 18/5/17.
//

#include "Library.h"


Library* createLibrary(int initialCapacity){
    Library* newLibrary = malloc(sizeof(Library));
    newLibrary->amountOfClients = 0;
    newLibrary->amountOfMaterials = 0;
    newLibrary->maxCapacityOfClients = initialCapacity;
    newLibrary->maxCapacityOfMaterials = initialCapacity;

    newLibrary->clients = malloc(sizeof(Person*)*initialCapacity);
    newLibrary->materials = malloc(sizeof(Material*)*initialCapacity);
    return newLibrary;
}
void destroyLibrary(Library* library){
    for (int i = 0; i < library->amountOfMaterials; i++) {
        destroyMaterial(library->materials[i]);
    }
    for (int j = 0; j < library->maxCapacityOfClients; j++) {
        destroyPerson(library->clients[j]);
    }
    free(library->clients);
    free(library->materials);
    free(library);
}

void addNewMaterial(Library* library, Material* material){
    if(library->amountOfMaterials == library->maxCapacityOfMaterials){
        library->materials = realloc(library->materials, sizeof(Library*) * library->maxCapacityOfMaterials* 2);
        library->maxCapacityOfMaterials = library->maxCapacityOfMaterials * 2;
    }
    library->materials[library->amountOfMaterials] = material;
    library->amountOfMaterials++;
}

void addNewPerson(Library* library, Person* person){

}

void removeMaterial(Library* library, int idOfMaterial);

void makeLoanOfMaterialToPerson(Library* library, int idMaterial, int idPerson);