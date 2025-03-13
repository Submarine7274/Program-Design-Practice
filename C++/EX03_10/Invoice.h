/*Invoice 的各項宣告 函數原型及data member */
#ifndef INVOICE_H
#define INVOICE_H
#include<string>

class Invoice{
    public:
    Invoice(std::string newpartnumber, std::string newdescription, int newquantity, int newprice);

    void setPartNumber(std::string newpartnumber);
    std::string getPartNumber();

    void setDescription(std::string newdescription);
    std::string getDescription();

    void setQuantity(int newquantity);
    int getQuantity();

    void setPrice(int newprice);
    int getPrice();

    int getInvoiceAmount();


    private:
    std::string partnumber;
    std::string description;
    int quantity{0};
    int price{0};
};
#endif