#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class TreeNode {
public:
    int MSV;
    string name;
    int age;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int MSV, string name, int age) 
        :MSV(MSV), name(name), age(age), left(nullptr), right(nullptr) {}
};

// Lớp BST
class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int MSV, string name, int age) {
        if (node == nullptr) {
            return new TreeNode(MSV, name, age);
        }

        if (MSV < node->MSV) {
            node->left = insert(node->left, MSV, name, age);
        } else if (MSV > node->MSV) {
            node->right = insert(node->right, MSV, name, age);
        }

        return node;
    }

    TreeNode* search(TreeNode* node, int MSV) {
        if (node == nullptr || node->MSV == MSV) {
            return node;
        }

        if (MSV < node->MSV) {
            return search(node->left, MSV);
        }

        return search(node->right, MSV);
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    TreeNode* remove(TreeNode* node, int MSV) {
        if (node == nullptr) {
            return node;
        }

        if (MSV < node->MSV) {
            node->left = remove(node->left, MSV);
        } else if (MSV > node->MSV) {
            node->right = remove(node->right, MSV);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* temp = findMin(node->right);
            node->MSV = temp->MSV;
            node->name = temp->name;
            node->age = temp->age;
            node->right = remove(node->right, temp->MSV);
        }

        return node;
    }

    void inOrder(TreeNode* node) {
        if (node == nullptr) return;

        inOrder(node->left);
        cout << "MSV: " << node->MSV << ", Name: " << node->name << ", Age: " << node->age << endl;
        inOrder(node->right);
    }

    void writeToFile(TreeNode* node, ofstream& outFile) {
        if (node == nullptr) return;

        writeToFile(node->left, outFile);
        outFile << node->MSV << " " << node->name << " " << node->age << endl;
        writeToFile(node->right, outFile);
    }

public:
    BinarySearchTree(){
        root = nullptr;
    }

    void insert(int MSV, string name, int age) {
        root = insert(root, MSV, name, age);
    }

    TreeNode* search(int MSV) {
        return search(root, MSV);
    }

    void remove(int MSV) {
        root = remove(root, MSV);
    }

    void inOrder() {
        inOrder(root);
    }

    void writeToFile(ofstream& outFile) {
        writeToFile(root, outFile);
    }
};
