#include <iostream>	// for cout
#include "Invoice.h"// for Invoice

using namespace std;

int main() {
	// create 2 instances of Invoice:
	// case 1:
	Invoice inv1("BV-254", "Can of Coca-Cola", 100, 50);

	// case 2:
	Invoice inv2("BV-366", "Bottle of Sprite", 100, 80);

	// display invoice amounts
    cout << "(" << inv1.getpartNumber() << ")" << inv1.getDescription() << ": " << inv1.getQuantity() << " x "  << inv1.getPrice() << " = " << inv1.getInvoiceAmount() << " NT$" << endl;

    cout << "(" << inv2.getpartNumber() << ")" << inv2.getDescription() << ": " << inv2.getQuantity() << " x "  << inv2.getPrice() << " = " << inv2.getInvoiceAmount() << " NT$" << endl;
		
	return 0;
}