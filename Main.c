//
// Created by Agustin Bettati  on 24/5/17.
//

#include "Material.h"
#include "Loan.h"
#include "Person.h"

int main() {
    Material* book = createMaterial(1,10,"Jorge", "Perdido en la selva",2012, "Johnson");

    Person* teacher = createPerson(1,"Carlos","Perez",40269313,10);

    makeLoan(book, teacher);

    printPerson(teacher);
    returnLoan(teacher, 10);
    printPerson(teacher);

    return 0;
}

