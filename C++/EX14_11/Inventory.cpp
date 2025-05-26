#include"Inventory.h"
#include<stdexcept>

Inventory::Inventory(int newRecordNumber,const string& newToolName, int newQuantity, double newCost)

{
    setRecordNumber(newRecordNumber);
    setQuantity(newQuantity);
    setCost(newCost);
}
int Inventory::getRecordNumber() const{return recordNumber;}
void Inventory::setRecordNumber(int newRecordNumber){
    if(newRecordNumber <1||newRecordNumber >100){
        throw invalid_argument("Record Number must between 1 and 100.");
    }
    recordNumber = newRecordNumber;
}

string Inventory::getToolName() const{return toolName;}
void Inventory::setToolName(const string& newToolName){
    size_t length{newToolName.length()};
    length = (length < 30? length:29);
    newToolName.copy(toolName,length);
    toolName[length] = '\0';        //要檢查字串長度
}

int Inventory::getQuantity() const{return quantity;}
void Inventory:: setQuantity(int newQuantity){
    if(newQuantity <0){
        throw invalid_argument("Quantity must greater than 0.");
    }
    quantity = newQuantity;
}

double Inventory::getCost() const{return cost;}
void Inventory::setCost(double newCost){
    if(newCost <0){
        throw invalid_argument("Cost must greater than 0.");
    }
    cost = newCost;
}