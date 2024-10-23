#include "Polynomial.h"

template <typename T>
Polynomial<T>::Polynomial() : head(nullptr) {}


template <typename T>
Polynomial<T>::~Polynomial() {
    clear();
}

template <typename T>
void Polynomial<T>::insertTerm(T coefficient, int degree) {
    if (coefficient == 0) return; 

    Node<T>* newNode = new Node<T>(coefficient, degree);

    if (!head || degree < head->degree) 
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node<T>* current = head;
        Node<T>* prev = nullptr;
        while (current && current->degree < degree)
        {
            prev = current;
            current = current->next;
        }
        if (current && current->degree == degree)
        {
            current->coefficient += coefficient;
            if (current->coefficient == 0) 
            {
                if (prev) prev->next = current->next;
                else head = current->next;
                delete current;
            }
            delete newNode;
        }
        else {
            newNode->next = current;
            if (prev) prev->next = newNode;
        }
    }
}


template <typename T>
void Polynomial<T>::readFromFile(const string& fileName) 
{
    ifstream file(fileName);
    if (!file)
    {
        cerr << "Error opening file!" << endl;
        return;
    }

    T coefficient;
    int degree;
    char x;
    while (file >> coefficient >> x >> x >> degree)
    {
        insertTerm(coefficient, degree);
    }
    file.close();
}


template <typename T>
void Polynomial<T>::add(Polynomial<T>& other)
{
    Node<T>* current = other.head;
    while (current) 
    {
        insertTerm(current->coefficient, current->degree);
        current = current->next;
    }
}


template <typename T>
void Polynomial<T>::multiply(Polynomial<T>& other)
{
    Polynomial<T> result;

    for (Node<T>* p1 = head; p1; p1 = p1->next) 
    {
        for (Node<T>* p2 = other.head; p2; p2 = p2->next) 
        {
            result.insertTerm(p1->coefficient * p2->coefficient, p1->degree + p2->degree);
        }
    }

    clear(); 
    Node<T>* current = result.head;
    while (current) 
    {
        insertTerm(current->coefficient, current->degree);
        current = current->next;
    }
}


template <typename T>
T Polynomial<T>::evaluate(T x) 
{
    T result = 0;
    Node<T>* current = head;
    while (current)
    {
        result += current->coefficient * pow(x, current->degree);
        current = current->next;
    }
    return result;
}


template <typename T>
void Polynomial<T>::display() 
{
    if (!head) 
    {
        cout << "0";
        return;
    }

    Node<T>* current = head;
    bool first = true;
    while (current) {
        if (!first && current->coefficient > 0) 
        {
            cout << " + ";
        }
        else if (current->coefficient < 0)
        {
            cout << " - ";
        }

        cout << abs(current->coefficient) << "x^" << current->degree;
        current = current->next;
        first = false;
    }
    cout << endl;
}

template <typename T>
void Polynomial<T>::clear() 
{
    Node<T>* current = head;
    while (current) 
    {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

template class Polynomial<double>;
