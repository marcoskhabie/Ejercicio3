//
// Created by Marcos khabie on 18/5/17.
//

#include <printf.h>
#include "Material.h"

Material* createBook(int code, char* author,char* title,int year, char* editorial){
    Material* newMaterial = malloc(sizeof(Material));
    newMaterial->typeOfMaterial= 1;
    newMaterial->code=code;
    newMaterial->year = year;

    newMaterial->author= malloc(sizeof(char)* strlen(author)+1);
    newMaterial->title= malloc(sizeof(char)* strlen(title)+1);
    newMaterial->editorial= malloc(sizeof(char)* strlen(editorial)+1);

    strcpy(newMaterial->author,author);
    strcpy(newMaterial->title,title);
    strcpy(newMaterial->editorial,editorial);

    return newMaterial;
}
Material* createMagazine(int code, char* author,char* title,int year){
    Material* newMaterial = malloc(sizeof(Material));
    newMaterial->typeOfMaterial= 0;
    newMaterial->code=code;
    newMaterial->year = year;

    newMaterial->author= malloc(sizeof(char)* strlen(author)+1);
    newMaterial->title= malloc(sizeof(char)* strlen(title)+1);
    newMaterial->editorial= "";

    strcpy(newMaterial->author,author);
    strcpy(newMaterial->title,title);

    return newMaterial;
}

void destroyMaterial(Material* material){
    free(material->author);
    free(material->title);
    free(material->editorial);
    free(material);
}

void printMaterial(Material* material){
    if(material->typeOfMaterial == 1){
        printf("Book (Code: %d)-> ",  material->code);
        printf("editorial: %s, ", material->editorial);
    }
    else{
        printf("Magazine (Code: %d)-> ", material->code);
    }

    printf("title: %s, ", material->title);
    printf("author: %s ",material->author);
    printf("(%d) \n", material->year);
}







