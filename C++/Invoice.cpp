#include<iostream>
#include"Invoice.h"

using namespace std;
    Invoice::Invoice(std::string number, std::string descript, int qty, int prc){
        setPartNumber(number);
        setDescription(descript); 
        setQuantity(qty); 
        setPrice(prc);
    }
    void Invoice::setPartNumber(std::string number){
        partNumber = number;
    }
    void Invoice::setDescription(std::string descript){
        description = descript;
    }
    void Invoice::setQuantity(int qty){
        quantity = (qty < 0) ? 0 : qty;
    }
    void Invoice::setPrice(int prc){
        price = (prc < 0) ? 0 : prc; 
    }
    string Invoice::getpartNumber() {
        return partNumber;
    }
    string Invoice::getDescription(){
        return description;
    }
    int Invoice::getQuantity(){
        return quantity;
    }
    int Invoice::getPrice(){
        return price;
    }
    int Invoice::getInvoiceAmount(){
        return quantity * price;
    }