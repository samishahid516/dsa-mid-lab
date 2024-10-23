#include "Polynomial.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Polynomial<double> poly1, poly2;
    string fileName;

    
    cout << "Enter the name of the polynomial file ( e.g., 'name.txt'): ";
    cin >> fileName;

    poly1.readFromFile(fileName);
    cout << "Polynomial from " << fileName << ": ";
    poly1.display();

    int choice;
    do {
        cout << "\n1. ADD polynomial\n"
             << "2. MULTIPLY polynomial\n"
             << "3. EVALUATE polynomial\n"
             << "4. QUIT\n"
             << "Enter choice #: ";
        cin >> choice;

        if (choice == 1) 
        {
            cout << "Enter the file containing the polynomial to add ( e.g.,'name.txt'): ";
            cin >> fileName;

            poly2.readFromFile(fileName);

            poly1.add(poly2);
            cout << "Sum: ";
            poly1.display();
        }

        else if (choice == 2)
        {
            cout << "Enter the file containing the polynomial to multiply (e.g., 'name.txt'): ";
            cin >> fileName;

            poly2.readFromFile(fileName);

            poly1.multiply(poly2);
            cout << "Product: ";
            poly1.display();
        }

        else if (choice == 3) 
        {
            double x;
            cout << "Enter the value of x for evaluation: ";
            cin >> x;

        
            cout << "Result: " << poly1.evaluate(x) << endl;
        }

    } while (choice != 4);

    return 0;
}
