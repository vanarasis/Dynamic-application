#include <iostream> // input output stream
#include <vector>
#include <algorithm> // for sorting
#include <string>

using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string data) {
        this->data = data;
        this->next = nullptr;
    }
};
// creating a class for a linkedlist
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }
    // Function to add a node to the end of the linked list
    void addNode(string data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    // Function to display all elements of the linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }
};
// Stack class
class Stack {
private:
    vector<string> items;
    // Function to push an item onto the stack
public:
    void push(string item) {
        items.push_back(item);
    }
    // Function to check if the stack is empty
    bool isEmpty() {
        return items.empty();
    }
    // Function to display all items in the stack
    void display() {
        cout << "Stack items:" << endl;
        for (string item : items) {
            cout << item << endl;
        }
    }
};
// Queue class
class Queue {
private:
    vector<string> items;
    // Function to enqueue an item into the queue
public:
    void enqueue(string item) {
        items.push_back(item);
    }
    // Function to check if the queue is empty
    bool isEmpty() {
        return items.empty();
    }
    // Function to display all items in the queue
    void display() {
        cout << "Queue items:" << endl;
        for (string item : items) {
            cout << item << endl;
        }
    }
};
// Binary Search class
class BinarySearch {
private:
    vector<string> array;
    // Function to add an element to the array and sort it
public:
    void addElement(string element) {
        array.push_back(element);
        sort(array.begin(), array.end());
    }
    // Function to perform binary search on the array
    int search(string key) {
        int low = 0;
        int high = array.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (array[mid] == key) {
                return mid;
            }
            else if (array[mid] < key) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return -1;
    }
    // Function to display all items in the array
    void display() {
        cout << "Array items:" << endl;
        for (string element : array) {
            cout << element << endl;
        }
    }
};
// Application class
class App {
public:    // Function to list user details using vectors
    void listItems() {
        cout << "List is implementing.." << endl;
        int n;
        cout << "Enter size of list: ";
        cin >> n;
        vector<vector<string>> users;
        for (int i = 0; i < n; ++i) {
            string name, address;
            int age, phone;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter address: ";
            cin >> address;
            cout << "Enter phone number: ";
            cin >> phone;
            users.push_back({ name, to_string(age), address, to_string(phone) });
        }
        cout << "User Details in List:" << endl;
        for (const auto& user : users) {
            for (const string& info : user) {
                cout << info << " ";
            }
            cout << endl;
        }
    }
    // Function to input elements into a linked list and display them
    void linkedListItems() {
        cout << "Linked List is implementing.." << endl;
        int n;
        cout << "Enter the number of elements : ";
        cin >> n;
        LinkedList linkedList;
        for (int i = 0; i < n; ++i) {
            string data;
            cout << "Enter data for node " << i + 1 << ": ";
            cin >> data;
            linkedList.addNode(data);
        }
        cout << "Elements in the Linked List:" << endl;
        linkedList.display();
    }
    // Function to input elements into an array and display them
    void arrayItems() {
        cout << "Array is implementing.." << endl;
        int n;
        cout << "Enter size of array: ";
        cin >> n;
        vector<string> array(n);
        for (int i = 0; i < n; ++i) {
            cout << "Enter element " << i + 1 << ": ";
            cin >> array[i];
        }
        cout << "Array items:" << endl;
        for (const string& element : array) {
            cout << element << endl;
        }
    }
    // Function to input elements into a stack and display them
    void stacksItems() {
        cout << "Stacks is implementing.." << endl;
        int n;
        cout << "Enter the number of elements : ";
        cin >> n;
        Stack stack;
        for (int i = 0; i < n; ++i) {
            string data;
            cout << "Enter data for item " << i + 1 << ": ";
            cin >> data;
            stack.push(data);
        }
        cout << "Stack items" << endl;
        stack.display();
    }
    // Function to input elements into a queue and display them
    void queuesItems() {
        cout << "Queues is implementing.." << endl;
        int n;
        cout << "Enter the number of elements : ";
        cin >> n;
        Queue queue;
        for (int i = 0; i < n; ++i) {
            string data;
            cout << "Enter data for item " << i + 1 << ": ";
            cin >> data;
            queue.enqueue(data);
        }
        cout << "Queue items:" << endl;
        queue.display();
    }
    // Function to input elements into an array, perform binary search, and display the result
    void binarySearchItems() {
        cout << "Binary Search is implementing.." << endl;
        int n;
        cout << "Enter the number of elements : ";
        cin >> n;
        BinarySearch binarySearch;
        for (int i = 0; i < n; ++i) {
            string element;
            cout << "Enter element " << i + 1 << ": ";
            cin >> element;
            binarySearch.addElement(element);
        }
        cout << "Array items:" << endl;
        binarySearch.display();
        string key;
        cout << "Enter the element to search for: ";
        cin >> key;
        int index = binarySearch.search(key);
        if (index != -1) {
            cout << "Element " << key << " found at index " << index << "." << endl;
        }
        else {
            cout << "Element " << key << " not found." << endl;
        }
    }
};

int main() {
    App myApp;
    while (true) {
        cout << "Welcome to Dynamic Application!!!" << endl << endl;
        cout << "Select an option:" << endl;
        cout << "1. List implementation" << endl;
        cout << "2. Linked List implementation" << endl;
        cout << "3. Array implementation" << endl;
        cout << "4. Stacks implementation" << endl;
        cout << "5. Queues implementation" << endl;
        cout << "6. Binary Search implementation" << endl;
        cout << "7. Exit" << endl;
        int choice;
        cout << "Choose one option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            myApp.listItems();
            break;
        case 2:
            myApp.linkedListItems();
            break;
        case 3:
            myApp.arrayItems();
            break;
        case 4:
            myApp.stacksItems();
            break;
        case 5:
            myApp.queuesItems();
            break;
        case 6:
            myApp.binarySearchItems();
            break;
        case 7:
            cout << "Exiting the application. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid option. Please choose from 1 to 7." << endl;
        }
    }
    return 0;
}