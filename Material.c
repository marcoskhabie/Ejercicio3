//
// Created by Marcos khabie on 18/5/17.
//

#include "Material.h"




typedef struct material{

    int numberOfBill;
    // Flata un supuesto "NitHotel"
    char* nameOfHotel;
    char* nameOfClient;
    char* idClient;
    double amountToPay;
}Material;

Bill* createBill(int numberOfBill,char* nameOfHotel, char* nameOfClient,char* idClient, double amountToPay);

void payRoom(Bill* aBill, Receptionist* receptionist);

void freeBill(Bill* bill);


