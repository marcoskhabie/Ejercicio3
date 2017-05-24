//
// Created by Agustin Bettati  on 24/5/17.
//

#include "Material.h"
#include "Person.h"
#include "Library.h"

int main() {
    Material* book1 = createMaterial(1,10,"Jorge", "Perdido en la selva",2012, "Johnson");
    Material* book2 = createMaterial(1,8,"Carlos", "The return",1990, "Pearson");
    Material* magazine = createMaterial(0,15, "John", "Nat geo",2016, "");


    Person* teacher = createPerson(1,"Carlos","Perez",40269313,10);
    Person* student = createPerson(0, "Pablo", "Verdeo", 23042143, 10);

    Library* library = createLibrary(10);

    addNewMaterial(library,book1);
    addNewMaterial(library,book2);
    addNewMaterial(library,magazine);

    addNewPerson(library, teacher);
    addNewPerson(library, student);

    makeLoanOfMaterialToPerson(library,10,40269313);

    printlistOfPeopleAndThierLoans(library);

    recieveLoanFromAPerson(library,40269313, 10);

    printlistOfPeopleAndThierLoans(library);

    return 0;
}

