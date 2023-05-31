#include <bits/stdc++.h>
using namespace std;

class Node {
	public:
	int data;
	struct Node *left, *right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

void printLevelorder(Node* root) {
    if(root == NULL){
		return;
	}

    queue<Node*> q; 
    q.push(root); 

    while(!q.empty()) {
        int size = q.size(); 
        for(int i = 0;i<size;i++) {
            Node *node = q.front(); 
            q.pop(); 
            if(node->left != NULL) q.push(node->left); 
            if(node->right != NULL) q.push(node->right); 
            cout<<node->data<<" "; 
        }
		cout<<endl; 
    } 
}

void printPostorder(Node* node){
	if (node == NULL)
		return;

	printPostorder(node->left);
	printPostorder(node->right);
	cout << node->data << " ";
}

void printInorder(Node* node){
	if (node == NULL)
		return;

	printInorder(node->left);
	cout << node->data << " ";
	printInorder(node->right);
}

void printPreorder(Node* node){
	if (node == NULL)
		return;

	cout << node->data << " ";
	printPreorder(node->left);
	printPreorder(node->right);
}

bool dep_search(Node* root, int lvl, int val, int height){
	if (root == NULL){
		return false;
	}

	if (height > lvl){
		return false;
	}

	if (root->data == val){
		return true;
	}

	return (dep_search(root->left, lvl, val, height+1) || dep_search(root->right, lvl, val, height+1));
}
bool dfs(Node* root, int val){
	if (root == NULL){
		return false;
	}

	if (root->data == val){
		return true;
	}

	return (dfs(root->left, val) || dfs(root->right, val));
}

bool bfs_search(Node* root, int val) {
    if(root == NULL){
		return false;
	}

	if (root->data == val){
		return true;
	}

    queue<Node*> q; 
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
		 
        for(int i = 0;i<size;i++) {
            Node *node = q.front();
            q.pop(); 
            if(node->left != NULL){
				q.push(node->left);
			} 
            if(node->right != NULL){
				q.push(node->right);
			}

            if(node->data == val){
				return true;
			} 
        }
    }

	return false; 
}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	cout << "\nLevel order traversal of binary tree is \n";
	printLevelorder(root);

	cout << "\nPreorder traversal of binary tree is \n";
	printPreorder(root);

	cout << "\nInorder traversal of binary tree is \n";
	printInorder(root);

	cout << "\nPostorder traversal of binary tree is \n";
	printPostorder(root);

	while(true){
	int choice;
	cout<<"\n\nUser Manual : \n1. DLS Search \n2. BFS Search \n3. DFS";
	cout<<"\n\nEnter your choice : ";
	cin>>choice;


	if (choice == 1){
		int val, lvl;

		cout<<"\n\nEnter the value you want to search : ";
		cin>>val;
		cout<<"Enter the level to which you want to search : ";
		cin>>lvl;
		
		if (dep_search(root, lvl, val, 1)){
			cout<<"\nElement found";
		}
		else{
			cout<<"\nElement Not found";
		}
	}
	else if (choice == 2){
		int val;

		cout<<"\n\nEnter the value you want to search : ";
		cin>>val;
	
		if (bfs_search(root, val)){
			cout<<"\nElement Found\n";
		}
		else{
			cout<<"\nElement Not Found\n";
		}

	}
	else if (choice == 3){
		int val;

		cout<<"\n\nEnter the value you want to search : ";
		cin>>val;
	
		if (dfs(root, val)){
			cout<<"\nElement Found\n";
		}
		else{
			cout<<"\nElement Not Found\n";
		}

	}
	else{
		cout<<"Thanks !!!\n";
		break;
	}

	}
	return 0;
}
