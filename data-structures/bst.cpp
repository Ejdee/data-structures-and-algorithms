#include<bits/stdc++.h>

using namespace std;
#define SPACE 5

class TreeNode
{
    public:
        int val;
        TreeNode *right;
        TreeNode *left;

        TreeNode(){
            val=0;
            right=NULL;
            left=NULL;
        }

        TreeNode(int v){
            val=v;
            right=NULL;
            left=NULL;
        }
};

class BST
{
    public:
        TreeNode* root;
        BST() {
            root=NULL;
        }
        int lheight;
        int rheight;

        bool isEmpty(){
            if(root==NULL){
                return true;
            } else {
                return false;
            }
        }

        void insert(TreeNode* new_node) {
            if (root == NULL) {
                root = new_node;
                cout << "hodnota byla ulozena na pozici root node" << endl;
            } else {
                TreeNode* temp = root;
                while (temp != NULL) {
                    if (new_node->val == temp->val) {
                        cout << "hodnota uz je ve strome ulozena, zadejte jinou hodnotu" << endl;
                        break;
                    } else if (new_node->val < temp->val) {
                        if (temp->left == NULL) {
                            temp->left = new_node;
                            cout << "hodnota byla pridana na levou pozici" << endl;
                            break;
                        } else {
                            temp = temp->left;
                        }
                    } else if (new_node->val > temp->val) {
                        if (temp->right == NULL) {
                            temp->right = new_node;
                            cout << "hodnota byla pridana pravou pozici" << endl;
                            break;
                        } else {
                            temp = temp->right;
                        }
                    }
                }
            }
        }

        void print2D(TreeNode* r, int space){
            if(r==NULL){
                return;
            } else {
                space+= SPACE;
                print2D(r->right, space);
                cout<<endl;
                for(int i=SPACE; i<space; i++) {
                    cout<<" ";
                }
                cout<<r->val<<"\n";
                print2D(r->left, space);
            }
        }


        void printPreorder(TreeNode* tree){
            if(tree==NULL){
                return;
            } else {
                cout<<tree->val<< " ";
                printPreorder(tree->left);
                printPreorder(tree->right);
            }
        }

        void printInorder(TreeNode* tree){ //inorder je funkce ktera vytiskne strom vzestupne(ascending)
            if(tree==NULL){
                return;
            } else {
                printInorder(tree->left);
                cout<<tree->val<<" ";
                printInorder(tree->right);
            }
        }

        void printPostorder(TreeNode* tree)
            if(tree==NULL){
                return;
            } else {
                printPostorder(tree->left);
                printPostorder(tree->right);
                cout<<tree->val<<" ";
            }
        };

        TreeNode* searchVal(int value){
            if(root==NULL){
                return root;
            } else {
                TreeNode* temp=root;
                while(temp!=NULL){
                    if(value==temp->val){
                        return temp;
                    } else if(value<temp->val){
                        temp=temp->left;
                    } else {
                        temp=temp->right;
                    }
                }
                return NULL;
            }
        }

        TreeNode* recursiveSearchVal(TreeNode* r, int value){
            if(r==NULL || r->val==value){
                return r;
            } else if(value>r->val) {
                return recursiveSearchVal(r->right, value);
            } else {
                return recursiveSearchVal(r->left, value);
            }
        }

        int depth(TreeNode* r) {
            if(r==NULL){
                return -1;
            } else {
                lheight=depth(r->left);
                rheight=depth(r->right);

                if(lheight>rheight){
                    return (lheight+1);
                } else {
                    return (rheight+1);
                }
            }
        }
};


int main()
{
    BST tree;
    int opt,val;

    do
    {
        cout<<endl<<endl;
        cout<<"Zadejte operaci, kterou chcete vyuzit."<<endl;
        cout<<"Kliknete 1. pro isEmpty()"<<endl;
        cout<<"Kliknete 2. pro insert()"<<endl;
        cout<<"Kliknete 3. pro print2D()"<<endl;
        cout<<"Kliknete 4. pro searchVal()"<<endl;
        cout<<"Kliknete 5. pro depth()"<<endl;
        cout<<"Kliknete 7. pro vymazani obrazovky"<<endl;
        
        cin>>opt;
        TreeNode* new_node=new TreeNode(); // vytvori nove zazemi pro praci se stromem a uzivatelem

        switch (opt)
        {
        case 1:
            if(tree.isEmpty()){
                cout<<"strom je prazdny"<<endl;
            } else {
                cout<<"strom neni prazdny"<<endl;
            }
            break;
        case 2:
            cout<<"zadejte hodnotu pro vlozeni: ";
            cin>>val;
            cout<<endl;
            new_node->val=val;
            tree.insert(new_node);
            break;

        case 3:
            tree.print2D(tree.root, 5);
            cout << "Inorder" << endl;
            tree.printInorder(tree.root);
            cout << endl << "Postorder" << endl;
            tree.printPostorder(tree.root);
            cout << endl << "Preorder" << endl;
            tree.printPreorder(tree.root);
            break;

        case 4:
            cout<<"Zadejte hodnotu: ";
            cin>>val;
            new_node=tree.searchVal(val);
            if(new_node==NULL){
                cout<<"Hodnota ve strome nebyla nalezena"<<endl;
            } else {
                cout<<"Hodnota ve strome byla nalezena"<<endl;
            }
            break;

        case 5:
            cout<<"Hloubka stromu je: "<< tree.depth(tree.root)<<endl;
            break;

        case 7:
            system("cls");
            break;       

        default:
            cout<<"Zadejte validni cislo."<<endl;
            break;
        }
    } while (opt!=0);
    


    return 0;
}