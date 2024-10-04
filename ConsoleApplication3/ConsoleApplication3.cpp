// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_front(int value) {

        Node* node = new Node(value);
        if (head == nullptr)
        {
            head = tail = node;
        }
        else
        {
            node->next = head;
            head->prev = node;
            head = node;
        }

    }

    void push_back(int value) {

        Node* node = new Node(value);

        if (head == nullptr)
        {
            tail = head = node;
        }
        else
        {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }

    void pop_front() {
        Node* temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        else
        {
            tail = nullptr;
        }
        delete temp;
    }

    void pop_back() {
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr)
        {
            tail->next = nullptr;
        }
        else
        {
            head = nullptr;
        }
        delete temp;
    }

    void display()
    {
        Node* node = head;
        while (node != nullptr)
        {
            std::cout << node->data << " ";
            node = node->next;
        }
        std::cout << std::endl;
    }

    void sort()
    {
        // метод пузырька
        Node* levo = head;
        Node* pravo = head->next;

        bool proverka;

        Node* temp = new Node(0);

        if (levo->next) 
        {
            do 
            {
                proverka = false;
                while (pravo != nullptr) 
                {
                    if (levo->data > pravo->data) 
                    {
                        temp->data = levo->data;
                        levo->data = pravo->data;
                        pravo->data = temp->data;
                        proverka = true;
                    }
                    levo = levo->next;
                    pravo = pravo->next;
                }

            } 
            while (proverka);
        }
        delete temp;
    }

    void remove_duplicates()
    {
        Node* node = head;

        while (node != nullptr)
        {
            Node* number = node;
            while (node->next != nullptr)
            {
                if (node->next->data == number->data)
                {
                    Node* d_num = node->next;
                    node->next = node->next->next;
                    if (node->next != nullptr)
                    {
                        node->next->prev = node;
                    }
                    delete d_num;
                }
                else
                {
                    node = node->next;
                }
        
            }
            node = number->next;
            
        }
    }

};

int main()
{
    setlocale(0, "RUS");
    int vibor;
    DoublyLinkedList d{};
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
            d.display();
            break;
        }
        case 6:
        {
            d.sort();
            break;
        }
        case 7:
        {
            d.remove_duplicates();
            break;
        }
        case 8:
        {
            return 0;
            break;
        }
        default:
        {
            return 0;
            break;
        }
        }
    }
    
    
}
