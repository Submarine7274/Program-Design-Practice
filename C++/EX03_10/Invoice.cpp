/*做一個發票class，四個data member:string partnumber、string description、int quantity{0}、int price{0}
    要有constructor
    每個data member都要有set get的member function
    最後還要有getInvoiceAmount的member function來計算quantity*price
*/
#include <string>
#include<iostream>
#include"Invoice.h"
using namespace std;

    Invoice::Invoice(std::string newpartnumber, std::string newdescription, int newquantity, int newprice)  //constructor建構子，傳入四個參數
    :partnumber{newpartnumber},description{newdescription}{                                                 //constructor 的member intializer
        if(newquantity >0){
            setQuantity(newquantity);                                                                       //初始值大於0，直接呼叫setQuantity()函式，並傳入newquantity參數
        }
        if(newprice >0){
            setPrice(newprice);                                                                             //初始值大於0，直接呼叫setPrice()函式，並傳入newprice參數
        }
    }

    void Invoice::setPartNumber(std::string newpartnumber){
        partnumber = newpartnumber;
    }
    string Invoice::getPartNumber(){
        return partnumber;
    }

    void Invoice::setDescription(std::string newdescription){
        description = newdescription;
    }
    string Invoice::getDescription(){
        return description;
    }

    void Invoice::setQuantity(int newquantity){
        if(newquantity >=0){                                                                                //資料檢查機制，只有數量大於等於0，才可以將傳入的參數賦值給quantity
            quantity= newquantity;
        }
    }
    int Invoice::getQuantity(){
        return quantity;
    }

    void Invoice::setPrice(int newprice){
        if(newprice >=0){
            price= newprice;                                                                                //資料檢查機制，只有數量大於等於0，才可以將傳入的參數賦值給price
        }
    }
    int Invoice::getPrice(){
        return price;
    }
    
    int Invoice::getInvoiceAmount(){
        return quantity*price;
    }