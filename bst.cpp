#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* left;
	Node* right; 
};
 Node* insert(Node* root, int data){
    if (root == NULL){
    	Node* bstnode = new Node;
    	bstnode->data = data;
    	bstnode->left = NULL;
    	bstnode->right = NULL;
    	return bstnode;
    }
    else if (root->data <= data)
    {
    	root->right = insert(root->right, data);
    }
    else{

    	root->left = insert(root->left, data);
    }
    return root;

}
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        //printf("%d \n", root->key);
        //cout <<"%d" << root->data ;
        cout << "Data is " << root->data << endl;
        inorder(root->right);
    }
}

bool search(Node *root, int data){
	if(root == NULL) return false;
	if (root->data == data)
	{
		return true;
	}
	else if (root->data >= data)
	{
		return search(root->left, data);
	}
	else{
		return search(root->right, data);
	}
	

}

int main(int argc, char const *argv[])
{
	Node* root = NULL;
	root = insert(root, 15);
	//root = insert(root, 15);
	root = insert(root, 9);
	root = insert(root, 32);
	root = insert(root, 13);
	root = insert(root, 18);
	root = insert(root, 19);
	inorder(root);
	if (search(root, 20))
	{
		cout <<"found element" << endl ;
	}
	else{
		cout <<"Not found";
	}
	return 0;
}