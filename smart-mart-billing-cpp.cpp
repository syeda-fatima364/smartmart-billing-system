#include <iostream>
using namespace std;

double calculateDiscount(double total, bool isRegular);

int main() {
    string customerName;
    char regular;
    int numProducts;

    cout << "===== SMARTMART BILLING SYSTEM =====\n";

    cout << "Enter Customer Name: ";
    cin >>customerName ;

    cout << "Is Regular Customer? (Y/N): ";
    cin >> regular;

    bool isRegular = (regular == 'Y' || regular == 'y');

    cout << "Enter Number of Products: ";
    cin >> numProducts;

    while (numProducts <= 0) {
        cout << "Invalid! Enter positive number: ";
        cin >> numProducts;
    }

    string productName;
    double price, subtotal, total = 0;
    int quantity;

    cout << "\n----- Enter Product Details -----\n";

    for (int i = 1; i <= numProducts; i++) {
        cout << "\nProduct " << i << " Name: ";
        cin >> productName;

        cout << "Price: ";
        cin >> price;
        while (price < 0) {
            cout << "Invalid! Enter positive price: ";
            cin >> price;
        }

        cout << "Quantity: ";
        cin >> quantity;
        while (quantity <= 0) {
            cout << "Invalid! Enter positive quantity: ";
            cin >> quantity;
        }

        subtotal = price * quantity;
        total += subtotal;
    }

    double discountRate = calculateDiscount(total, isRegular);
    double discountAmount = total * discountRate;
    double finalAmount = total - discountAmount;

    cout << "\n========== FINAL BILL ==========\n";
    cout << "Customer: " << customerName << endl;


    cout << "Total Amount: Rs. " << total << endl;
    cout << "Discount Applied: " << discountRate * 100 << "%\n";
    cout << "Final Payable Amount: Rs. " << finalAmount << endl;

    return 0;
}


double calculateDiscount(double total, bool isRegular) {
    double discount = 0;

    if (total < 5000)
        discount = 0;
    else if (total <= 9999)
        discount = 0.05;
    else if (total <= 19999)
        discount = 0.10;
    else
        discount = 0.15;

    if (isRegular)
        discount += 0.03;

    return discount;
}
