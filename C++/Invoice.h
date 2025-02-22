#include <string>

class Invoice {
public:
    Invoice(std::string number, std::string descript, int qty, int prc);
    
    
    void setPartNumber(std::string number); 
    
    void setDescription(std::string descript); 
    
    void setQuantity(int qty); 
    
    void setPrice(int prc);
    
    std::string getpartNumber();
    
    std::string getDescription();
    
    int getQuantity(); 
    
    int getPrice();
    
    int getInvoiceAmount();
    
private:
    std::string partNumber;
    std::string	description;
    int quantity;
    int price;
};