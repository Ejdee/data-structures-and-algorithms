#include <iostream>

using namespace std;

class Node {
    public:
        int key;
        int data;
        Node* next;

        Node() {
            key = 0;
            data = 0;
            next = NULL;
        }

        Node(int k, int d) {
            key = k;
            data = d;
        }
};

class LinkedList {
    public:
        Node* head;

        LinkedList() {
            head = NULL;
        }

        LinkedList(Node *n) {
            head = n;
        }

        // kontrola zda node podle zadaneho klice existuje
        Node* nodeExists(int k) { // output bude bud ano nebo NULL, bud existuje node nebo ne
            Node* temp = NULL;
            Node* ptr = head; // prvni pointer bude na head

            while(ptr != NULL) {
                if(ptr->key == k) { //kontrola jestli se current node rovna zadanymu klici
                    temp = ptr;
                }
                ptr = ptr->next; // pointer se presune na dalsi node v listu
            }

            return temp;
        }

        // pridani dalsiho node
        void appendNode(Node* n) {
            if(nodeExists(n->key) != NULL) {
                cout << "node uz s timto klicem uz existuje" << endl;
            } else {
                if(head == NULL) {
                    head = n;
                    cout << "node byl pridan" << endl;
                } else {
                    Node* ptr = head;

                    while(ptr->next != NULL) { // traversing list dokud nebude v node[key][data]->[next]<- NULL, to znamena ze je posledni
                        ptr = ptr->next; 
                    }

                    ptr->next = n; // drive posledni node bude odkazovat na nove pridany node
                    cout << "node byl pridan" << endl;
                }
            }
        }

        //pridani dalsiho node na zacatatek
        void prependNode (Node* n) {
            if(nodeExists(n->key) != NULL) {
                cout << "tento node jiz existuje" << endl;
            } else {
                n->next = head; // nove pridany node bude odkazovat na drive prvni node, na ktery odkazoval head
                head = n; // head ted bude odkazovat na nove pridany (novy) node
                cout << "node byl pridan na zacatek" << endl;
            }
        }

        //pridani dalsiho node po nejakym specifickym node
        void insertNodeAfter(int k, Node* n) {
            Node* ptr = nodeExists(k);
            if(ptr == NULL) {
                cout << "node se zadanym klicem " << k << "neexistuje" << endl;
            } else {
                if(nodeExists(n->key) != NULL) {
                    cout << "node s timto klicem jiz existuje" << endl;
                } else {
                    if(ptr->next == NULL) {
                        ptr->next = n;
                        cout << "node byl uspesne vytvoren" << endl;
                    } else {
                        n->next = ptr->next;
                        ptr->next = n;
                        cout << "node byl uspesne vlozen za node s klicem " << k << endl;
                    }
                }
            }
        }

        //delete node
        void deleteNode(int k) {
            if(head == NULL) {
                cout << "list je prazdny, neni co mazat" << endl;
            } else if(head != NULL) {
                if (head->key == k) {
                    head = head->next;
                    cout << "node byl odpojen z listu" << endl;
                } else {
                    Node* temp = NULL;
                    Node* currentptr = head;
                    Node* nextptr = head->next;
                    while(nextptr != NULL) {
                        if(nextptr->key == k) {
                            temp = nextptr;
                            nextptr = NULL; // zastaveni while loop
                        } else {
                            currentptr = currentptr->next;
                            nextptr = nextptr->next;
                        }
                    }
                    if(temp != NULL) {
                        currentptr->next = temp->next;
                        cout << "node s klicem " << k << " byl odpojen z listu" << endl;
                    } else {
                        cout << "node s takovym klicem neexistuje" << endl;
                    }
                }
            }
        }

        // update node podle klice
        void updateNodeByKey(int k, int d) {
            Node* ptr = nodeExists(k);
            if(ptr != NULL) {
                ptr->data = d;
                cout << "hodnota byla uspesne zmenena" << endl;
            } else {
                cout << "node s takovym klicem neexistuje" << endl;
            }
        }

        //printing 
        void print() {
            if (head == NULL) {
                cout << "list je prazdny" << endl;
            } else {
                cout << endl << "hodnoty v listu jsou: ";
                Node* temp = head;

                while(temp != NULL) {
                    cout << "(" << temp->key << ", " << temp->data << ") --->";
                    temp = temp->next; 
                }
            }
        }
};

int main() {

  LinkedList l;
  int option;
  int key1, k1, data1;
  do {
    cout << "\nZadejte operaci, kterou chcete provest. Zadejte 0 pro ukonceni programu" << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;

    cin >> option;
    Node * n1 = new Node();
    //Node n1;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node \nZadejte klic a hodnotu, kterou bude mit pridany node" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      l.appendNode(n1);
      break;

    case 2:
      cout << "Prepend Node \nZadejte klic a hodnotu, kterou bude mit pridany node" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      l.prependNode(n1);
      break;

    case 3:
      cout << "Insert Node After \nZadejte klic jiz existujiciho node, po kterem chcete pridat novy node: " << endl;
      cin >> k1;
      cout << "Zadejte klic a hodnotu, kterou bude mit pridany node: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;

      l.insertNodeAfter(k1, n1);
      break;

    case 4:

      cout << "Delete Node By Key - \nZadejte klic node, ktery chcete smazat: " << endl;
      cin >> k1;
      l.deleteNode(k1);

      break;
    case 5:
      cout << "Update Node By Key - \nZadejte klic a novou hodnotu, kterou chcete zmenit: " << endl;
      cin >> key1;
      cin >> data1;
      l.updateNodeByKey(key1, data1);

      break;
    case 6:
      l.print();

      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Zadejte validni cislo" << endl;
    }

  } while (option != 0);

  return 0;
}
