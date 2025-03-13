/*這個TestDriver沒測完所有member function就是了*/
#include<iostream>
#include<string>
#include"Invoice.h"
using namespace std;
int main(void){
    Invoice invoiceobject1{"BV-254","Can of Coca-Cola",100,50}; //建立一個Invoice的物件叫做invoiceobject1
    Invoice invoiceobject2{"BV-366","Bottle of Sprite",100,80}; //建立一個Invoice的物件叫做invoiceobject2
    
    cout<<"("<<invoiceobject1.getPartNumber()<<")"              //直接用cout串流輸出各項datamember的值
    <<invoiceobject1.getDescription()<<": "
    <<invoiceobject1.getQuantity()<<" x "
    <<invoiceobject1.getPrice()<<" = "
    <<invoiceobject1.getInvoiceAmount()<<" NT$\n";

    cout<<"("<<invoiceobject2.getPartNumber()<<")"
    <<invoiceobject2.getDescription()<<": "
    <<invoiceobject2.getQuantity()<<" x "
    <<invoiceobject2.getPrice()<<" = "
    <<invoiceobject2.getInvoiceAmount()<<" NT$\n";

}