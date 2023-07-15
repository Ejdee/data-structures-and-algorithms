#include<iostream>

using namespace std;

class Queue {
    private:
        int arr[5];
        int front;
        int rear;
        int size;

    public:
        Queue() {
            front = -1;
            rear = -1;
            size = end(arr)-begin(arr);
            for(int i = 0; i < 5; i++) {
                arr[i] = 0;
            }
        }

        bool isEmpty() {
            if(front == -1 && rear == -1) {
                return true;
            } else {
                return false;
            }
        }

        bool isFull() {
            if(rear == (size)-1) { //rear = velikost array -1
                return true;
            } else {
                return false;
            }
        }

        void enqueue(int a) { 
            if(isFull()) {
                cout << "queue je plna" << endl;
            } else if(isEmpty()) {
                rear++;
                front++;
                arr[rear] = a;
                cout << a << " pridano jako prvni hodnota" << endl;
            } else {
                rear++;
                arr[rear] = a;
                cout << a << " pridano" << endl;
            }
        }

        int dequeue() {
            int deletedValue;
            if(isEmpty()) {
                cout << "queue je prazdna" << endl;
                return 0;
            } else if(front == rear) {
                deletedValue = arr[front];
                arr[front] = 0;
                front = rear = -1;
                return deletedValue;
            } else {
                deletedValue = arr[front];
                arr[front] = 0;
                front ++;
                return deletedValue;
            }
        }

        int count() {
            return (rear - front + 1);
        }

        void display() {
            for(int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
        }

};

int main() {

    Queue q1;
    int option, value;

    do {
        cout << "jakou operaci chcete provest?" << endl;
        cout << "1. enqueue" << endl;
        cout << "2. dequeue" << endl;
        cout << "3. isEmpty" << endl;
        cout << "4. isFull" << endl;
        cout << "5. count " << endl;
        cout << "6. display" << endl;
        cout << "7. clear screen" << endl;
        cout << "0. konec" << endl << endl;

        cin>>option;

        switch (option) {
            case 1:
                cout << "zadejte hodnotu, kterou chcete pridat: ";
                cin >> value;
                cout << endl;
                q1.enqueue(value);
                break;
            case 2:
                if(q1.isEmpty()) {
                    cout << "queue je prazdna" << endl;
                } else {
                    cout << q1.dequeue() << " uspesne smazano" << endl;
                }
                break;
            case 3:
                if(q1.isEmpty()) {
                    cout << "queue je prazdna" << endl;
                } else {
                    cout << "queue neni prazdna" << endl;
                }
                break;
            case 4:
                if(q1.isFull()) {
                    cout << "queue je plna" << endl;
                } else {
                    cout << "queue neni plna" << endl;
                }
                break;
            case 5:
                cout << "v queue je " << q1.count() << " hodnot" << endl;
                break;
            case 6:
                q1.display();
                cout << endl;
                break;
            case 7:
                system("cls");
                break;
            default:
                cout << "zadejte validni hodnotu" << endl;
        }

    } while (option != 0);

    return 0;
}