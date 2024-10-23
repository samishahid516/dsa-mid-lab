

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Node structure for Linked List representation of polynomial terms
template <typename T>
struct Node {
    T coefficient;
    int degree;
    Node* next;

    Node(T coeff, int deg) : coefficient(coeff), degree(deg), next(nullptr) {}
};

// Polynomial class declaration
template <typename T>
class Polynomial {
private:
    Node<T>* head; 

public:
    Polynomial();  
    ~Polynomial();

    void readFromFile(const string& fileName); 
    void add(Polynomial<T>& other);            
    void multiply(Polynomial<T>& other);     
    T evaluate(T x);                          
    void display();                          

private:
    void insertTerm(T coefficient, int degree); 
    void clear();                               
};
