// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    setlocale(0, "RUS");
    int vibor;
    DoublyLinkedList d;
    while (true)
    {
        std::cout << "Выберите:\n1. Добавить элемент в начало\n2. Добавить элемент в конец\n3. Удалить элемент с начала\n4. Удалить элемент с конца\n5. Отобразить список\n6. Сортировать список.\n7. Удалить дубликаты.\n8. Выход\n";
        std::cin >> vibor;
        switch (vibor)
        {
        case 1:
        {
            int value;
            std::cout << "Введите значение: ";
            std::cin >> value;
            d.push_front(value);
            break;
        }
        case 2:
        {
            int value;
            std::cout << "Введите значение: ";
            std::cin >> value;
            d.push_back(value);
            break;
        }
        case 3:
        {
            d.pop_front();
            break;
        }
        case 4:
        {
            d.pop_back();
            break;
        }
        case 5:
        {

        }
        case 6:
        {

        }
        case 7:
        {

            break;
        }
        case 8:
        {
            terminate();
        }
        default:
        {
            exit(0);
            break;
        }
        }
    }
    
    
}


struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {

    }
};

class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;


public:
    
    void push_front(int value) {
        
        Node*& node = new Node(value);
        if (head == nullptr)
        {
            head = tail = node;
            delete node;
        }
        else
        {
            node = head;
            head->prev = node;
            head = node;
            delete node;
        }
       
    }

    void push_back(int value) {

        Node* &node = new Node(value);

        if (head == nullptr)
        {
            tail = head = node;
            delete node;
        }
        else
        {
            node = tail;
            tail->next = node;
            tail = node;
            delete node;
        }
    }

    void pop_front() {
        Node* temp = head;
        head->next = head;
        head->prev = nullptr;
        if (temp == nullptr)
        {
            head == nullptr;
        }
    }

    void pop_back() {
        Node* temp = tail;
        tail->prev = tail;
        tail->next = nullptr;
        if (temp == nullptr)
        {
            tail == nullptr;
        }
    }

    void display()
    {
        
    }

    void sort()
    {
        // метод пузырька
        Node* levo = head;
        Node* pravo = head->next;

        Node* temp = new Node(0);

        if (levo->next)
        {
            while (pravo)
            {

            }
        }
    }

    void remove_duplicates()
    {

    }

};