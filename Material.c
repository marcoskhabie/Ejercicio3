//
// Created by Marcos khabie on 18/5/17.
//

#include "Material.h"
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






