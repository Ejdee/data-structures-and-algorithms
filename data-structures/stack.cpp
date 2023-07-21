#include <iostream>
#include <string>

using namespace std;

class Stack {
    private:
        int arr[5];
    int top; // top item in stack, kdyz pridavame hodnotu pomoci push(), top++

    public:
        Stack() {
            top = -1;
            for (int i = 0; i < 5; i++) { // vytvarime prazdny stack s hodnotami 0
                arr[i] = 0;
            }
        }

    bool isEmpty() {
        if (top == -1)
            return true;
        else
            return false;
    }

    bool isFull() {
        if (top == 4)
            return true;
        else
            return false;
    }

    void push(int val) {
        if (isFull()) {
            cout << "stack overflow" << endl;
        } else {
            top++;
            arr[top] = val;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "stack underflow" << endl;
            return 0;
        } else {
            int deletedValue = arr[top];
            arr[top] = 0;
            top--;
            return deletedValue;
        }
    }

    int count() {
        return (top + 1);
    }

    int peek(int pos) {
        if (isEmpty()) {
            cout << "stack underflow" << endl;
        } else {
            return (arr[pos]);
        }
    }

    void change(int pos, int val) {
        if (isEmpty()) {
            cout << "stack underflow" << endl;
        } else {
            arr[pos] = val;
            cout << "hodnota zmenena na pozici " << pos << endl;
        }
    }

    void display() {
        cout << "vsechny hodnoty ve stacku jsou: " << endl;
        for (int i = 4; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};


int main() {

    Stack s1;
    int position, value, option;

    do {
        cout << "jakou operaci chcete provest?" << endl;
        cout << "1. push" << endl;
        cout << "2. pop" << endl;
        cout << "3. isEmpty" << endl;
        cout << "4. isFull" << endl;
        cout << "5. peek" << endl;
        cout << "6. count" << endl;
        cout << "7. change" << endl;
        cout << "8. display" << endl;
        cout << "9. clear screen" << endl;
        cout << "0. konec" << endl << endl;

        cin >> option;

        switch (option) {
            case 1:
                cout << "zadejte hodnotu ";
                cin >> value;
                s1.push(value);
                break;
            case 2:
                cout << "smazana hodnota je: " << s1.pop() << endl;
                break;
            case 3:
                if (s1.isEmpty()) {
                    cout << "stack je prazdny" << endl;
                } else {
                    cout << "stack neni prazdny" << endl;
                }
                break;
            case 4:
                if (s1.isFull()) {
                    cout << "stack je plny" << endl;
                } else {
                    cout << "stack neni plny" << endl;
                }
                break;
            case 5:
                cout << "zadejte pozici ve stacku: ";
                cin >> position;
                cout << endl;
                cout << "hodnota na pozici " << position << "je" << s1.peek(position) << endl;
                break;
            case 6:
                cout << "ve stacku je " << s1.count() << "hodnot" << endl;
                break;
            case 7:
                cout << "zadejte pozici: ";
                cin >> position;
                cout << endl << "zadejte hodnotu: ";
                cin >> value;
                s1.change((position - 1), value);
                cout << endl << "hodnota na pozici " << position << " byla zmenena na " << value << endl;
                break;
            case 8:
                s1.display();
                break;
            case 9:
                system("cls");
                break;
            default:
                cout << "zadejte validni hodnotu" << endl;
        }

    } while (option != 0);

    return 0;
}