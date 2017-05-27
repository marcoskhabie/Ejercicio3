//
// Created by Marcos khabie on 18/5/17.
//

#ifndef EJERCICIO2_MATERIAL_H
#define EJERCICIO2_MATERIAL_H

#include <stdlib.h>
#include <string.h>

typedef struct material{

    int typeOfMaterial; // 0 magazine, 1 book.
    int code;
    char* author;
    char* title;
    int year;
    char* editorial;

}Material;

Material* createBook(int code, char* author,char* title,int year, char* editorial);
Material* createMagazine(int code, char* author,char* title,int year);
void destroyMaterial(Material* material);
void printMaterial(Material* material);
#endif //EJERCICIO2_MATERIAL_H
