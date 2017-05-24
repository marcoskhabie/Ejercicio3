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

Material* createMaterial(int typeOfMaterial,int  code, char* author,char* title, char* editorial){
    Material* newMaterial = malloc(sizeof(Material));
    newMaterial->typeOfMaterial= typeOfMaterial;
    newMaterial->code=code;

    newMaterial->author= malloc(sizeof(char)* strlen(author)+1);
    newMaterial->title= malloc(sizeof(char)* strlen(title)+1);
    newMaterial->editorial= malloc(sizeof(char)* strlen(editorial)+1);

    strcpy(newMaterial->author,author);
    strcpy(newMaterial->title,title);
    strcpy(newMaterial->editorial,editorial);

    return newMaterial;
}

void destroyMaterial(Material* material){
    free(material->author);
    free(material->title);
    free(material->editorial);
    free(material);
}
#endif //EJERCICIO2_MATERIAL_H
