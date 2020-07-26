#include "binarytree.h"
#include <iostream>
#include <queue>
#include <string>

BinaryTree::BinaryTree()
{

}

BinaryTree::~BinaryTree()
{
    dealockNodes();
}

BinaryTreeNode* BinaryTree::insert(int data)
{
    struct BinaryTreeNode* t = new BinaryTreeNode(data);
    if (root == nullptr)
    {
        root = t;
    }
    else
    {
        struct BinaryTreeNode* tmp = root;
        while(true)
        {
            if (data < tmp->data) //go to left
            {
                if (tmp->left == nullptr)
                {
                    tmp->left = t;
                    break;
                }
                else
                {
                    tmp = tmp->left;
                }
            }
            else if (data > tmp->data)
            {
                if (tmp->right == nullptr)
                {
                    tmp->right = t;
                    break;
                }
                else
                {
                    tmp = tmp->right;
                }
            }
            else
            {
                delete t;
                t = nullptr;
                return nullptr;
            }
        }
    }

    return t;
}

BinaryTreeNode *BinaryTree::removeUsingPredecessor(int data)
{
    if (root == nullptr)
        return nullptr;
    if (root->data == data) //root is the data
    {
        if (root->left == nullptr)
            root = root->right;
        else if (root->right == nullptr)
            root = root->left;
        else
        {
            struct BinaryTreeNode* backup = root;
            if (root->left->right == nullptr)
            {
                root = root->left;
                root->right = backup->right;
                return backup;
            }
            else
            {
                BinaryTreeNode* fatherOfPred = getFatherOfPredecessor(root);
                root = fatherOfPred->right;
                fatherOfPred->right = root->left;
                root->left = backup->left;
                root->right = backup->right;
                return backup;
            }
        }
    }
    else // o root não é o dado
    {
        struct BinaryTreeNode *tmp = root;
        while (tmp != nullptr)
        {
            if (data < tmp->data) //pesquisar no ramo esquerdo
            {
                if (tmp->left == nullptr)
                    return nullptr;
                if (tmp->left->data == data)
                {
                    struct BinaryTreeNode* father = tmp;
                    struct BinaryTreeNode* toRemove = tmp->left;
                    struct BinaryTreeNode* left = toRemove->left;
                    struct BinaryTreeNode* right = toRemove->right;

                    if (left == nullptr)
                    {
                        father->left = right;
                        return toRemove;
                    }
                    else if (right == nullptr)
                    {
                        father->left = left;
                        return toRemove;
                    }
                    else
                    {
                        BinaryTreeNode* fatherOfPred = getFatherOfPredecessor(toRemove);
                        BinaryTreeNode* newBinaryTreeNode = fatherOfPred->right;
                        fatherOfPred->right = newBinaryTreeNode->left;
                        father->left = newBinaryTreeNode;
                        newBinaryTreeNode->left = left;
                        newBinaryTreeNode->right = right;
                        return toRemove;
                    }
                }
                else
                    tmp = tmp->left;
            }
            else //pesquisar no ramo direito
            {
                if (tmp->right == nullptr)
                    return nullptr;
                if (tmp->right->data == data)
                {
                    struct BinaryTreeNode* father = tmp;
                    struct BinaryTreeNode* toRemove = tmp->right;
                    struct BinaryTreeNode* left = toRemove->left;
                    struct BinaryTreeNode* right = toRemove->right;

                    if (left == nullptr)
                    {
                        father->right = right;
                        return toRemove;
                    }
                    else if (right == nullptr)
                    {
                        father->right = left;
                        return toRemove;
                    }
                    else
                    {
                        BinaryTreeNode* fatherOfPred = getFatherOfPredecessor(toRemove);
                        BinaryTreeNode* newBinaryTreeNode = fatherOfPred->right;
                        fatherOfPred->right = newBinaryTreeNode->left;
                        father->right = newBinaryTreeNode;
                        newBinaryTreeNode->left = left;
                        newBinaryTreeNode->right = right;
                        return toRemove;
                    }
                }
                else
                    tmp = tmp->right;
            }

        }
    }
    
    return nullptr;
}

BinaryTreeNode* BinaryTree::getFatherOfPredecessor(BinaryTreeNode * n)
{
    if (n->left->right == nullptr)
        return n;

    BinaryTreeNode * temp = n->left;

    while (temp->right->right != nullptr)
        temp = temp->right;
    return temp;
}

BinaryTreeNode *BinaryTree::getRoot()
{
    return root;
}

BinaryTreeNode *BinaryTree::removeOne(int data)
{
    if (root == nullptr)
        return nullptr;

    if (root->data == data)
    {
        if (root->left == nullptr)
        {
            BinaryTreeNode *bcp = root;
            root = root->right;
            return bcp;
        }
        else if (root->right == nullptr)
        {
            BinaryTreeNode *bcp = root;
            root = root->left;
            return bcp;
        }
        else
        {
            //A direita fica em cima
            //A esquerda fica oquanto mais a esquerda possivel da sub arv direita

            struct BinaryTreeNode* right = root->right;
            struct BinaryTreeNode* left = root->left;

            struct BinaryTreeNode* leftMostOfRight = right;
            while (leftMostOfRight->left != nullptr)
            {
                leftMostOfRight = leftMostOfRight->left;
            }

            //Altera o root
            struct BinaryTreeNode* backup = root;
            root = right;
            leftMostOfRight->left = left;
            return backup;
        }
    }
    else // o root não é o dado
    {
        struct BinaryTreeNode *tmp = root;
        while (tmp != nullptr)
        {
            if (data < tmp->data) //pesquisar no ramo esquerdo
            {
                if (tmp->left == nullptr)
                    return nullptr;
                if (tmp->left->data == data)
                {
                    struct BinaryTreeNode* father = tmp;
                    struct BinaryTreeNode* toRemove = tmp->left;
                    struct BinaryTreeNode* left = toRemove->left;
                    struct BinaryTreeNode* right = toRemove->right;

                    if (left == nullptr)
                    {
                        father->left = right;
                        return toRemove;
                    }
                    else if (right == nullptr)
                    {
                        father->left = left;
                        return toRemove;
                    }
                    else
                    {
                        //A direita fica em cima
                        //A esquerda fica oquanto mais a esquerda possivel da sub arv direita

                        struct BinaryTreeNode* leftMostOfRight = right;
                        while (leftMostOfRight->left != nullptr)
                        {
                            leftMostOfRight = leftMostOfRight->left;
                        }

                        //Altera o root
                        father->left = right;
                        leftMostOfRight->left = left;
                        return toRemove;
                    }
                }
                else
                    tmp = tmp->left;
            }
            else //pesquisar no ramo direito
            {
                if (tmp->right == nullptr)
                    return nullptr;
                if (tmp->right->data == data)
                {
                    struct BinaryTreeNode* father = tmp;
                    struct BinaryTreeNode* toRemove = tmp->right;
                    struct BinaryTreeNode* left = toRemove->left;
                    struct BinaryTreeNode* right = toRemove->right;

                    if (left == nullptr)
                    {
                        father->right = right;
                        return toRemove;
                    }
                    else if (right == nullptr)
                    {
                        father->right = left;
                        return toRemove;
                    }
                    else
                    {
                        //A direita fica em cima
                        //A esquerda fica oquanto mais a esquerda possivel da sub arv direita

                        struct BinaryTreeNode* leftMostOfRight = right;
                        while (leftMostOfRight->left != nullptr)
                        {
                            leftMostOfRight = leftMostOfRight->left;
                        }

                        //Altera o root
                        father->right = right;
                        leftMostOfRight->left = left;
                        return toRemove;
                    }
                }
                else
                    tmp = tmp->right;
            }

        }
    }

    return nullptr;
}

bool BinaryTree::search(int data)
{
    struct BinaryTreeNode* tmp = root;

    while(tmp != nullptr)
    {
        if (tmp->data == data)
            return true;
        else
        {
            if (data < tmp->data)
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }
    }

    return false;
}

const std::string BinaryTree::gitDotFileMode2()
{
    std::string textToFile = "digraph g{";
    textToFile += "node [shape=record, height=0.1]";

    if (root == nullptr)
    {
        textToFile += "NULL [label = \"<l> | <m> NULL | <r>\"];Root -> NULL;";
    }
    else
    {
        int count = 0;
        exibirSubArvore2(nullptr, true, root, textToFile, count);
    }

    textToFile += "}";

    return textToFile;
}

const std::string BinaryTree::gitDotFileMode1()
{
    std::string textToFile = "digraph g{";
    textToFile += "Root[shape=none fontcolor=blue];";

    if (root == nullptr)
    {
        textToFile += "NULL [ fontcolor=red ];Root -> NULL;";
    }
    else
    {
        int count = 0;
        textToFile += "Root->"+std::to_string(root->data)+";";
        exibirSubArvore1(root, textToFile, count);
    }

    textToFile += "}";

    return textToFile;
}

const std::string BinaryTree::preOrder()
{
    std::string content;
    preOrder(root, content);
    return content;
}

const std::string BinaryTree::inOrder()
{
    std::string content;
    inOrder(root, content);
    return content;
}

const std::string BinaryTree::posOrder()
{
    std::string content;
    posOrder(root, content);
    return content;
}

const std::string BinaryTree::InLevelOrder()
{
    std::string content;

    std::queue<BinaryTreeNode*> queue;

    if (root != nullptr)
        queue.push(root);

    BinaryTreeNode* binaryTreeNode = nullptr;
    while(queue.size() > 0)
    {
        BinaryTreeNode* binaryTreeNode = queue.front(); //acessa o primeiro
        queue.pop(); //remove o primeiro

        content += std::to_string(binaryTreeNode->data)+" ";

        if (binaryTreeNode->left != nullptr)
            queue.push(binaryTreeNode->left);

        if (binaryTreeNode->right != nullptr)
            queue.push(binaryTreeNode->right);
    }

    return content;
}

void BinaryTree::preOrder(struct BinaryTreeNode* binaryTreeNode, std::string& content)
{
    if (binaryTreeNode != nullptr)
    {
        content += std::to_string(binaryTreeNode->data) + " ";
        preOrder(binaryTreeNode->left, content);
        preOrder(binaryTreeNode->right, content);
    }
}
void BinaryTree::inOrder(struct BinaryTreeNode* binaryTreeNode, std::string& content)
{
    if (binaryTreeNode != nullptr)
    {
        inOrder(binaryTreeNode->left, content);
        content += std::to_string(binaryTreeNode->data) + " ";
        inOrder(binaryTreeNode->right, content);
    }
}
void BinaryTree::posOrder(struct BinaryTreeNode* binaryTreeNode, std::string& content)
{
    if (binaryTreeNode != nullptr)
    {
        posOrder(binaryTreeNode->left, content);
        posOrder(binaryTreeNode->right, content);
        content += std::to_string(binaryTreeNode->data) + " ";
    }
}

void BinaryTree::dealockNodes()
{
    if (root != nullptr)
    {
        root->dealockSubTree();
        delete root;
    }
}

void BinaryTree::exibirSubArvore1
(
    struct BinaryTreeNode* n,
    std::string& content,
    int& count
)
{
    //Desenha o dado do nó n
    content += std::to_string(n->data)+";";

    if (n->left == nullptr)
    {
        content += std::to_string(n->data)+"->NULL"+std::to_string(count++)+";";
    }
    else
    {
        content += std::to_string(n->data)+"->"+std::to_string(n->left->data)+";";
        exibirSubArvore1
        (
            n->left,
            content,
            count
        );
    }

    if (n->right == nullptr)
    {
        content += std::to_string(n->data)+"->NULL"+std::to_string(count++)+";";
    }
    else
    {
        content += std::to_string(n->data)+"->"+std::to_string(n->right->data)+";";
        exibirSubArvore1
        (
            n->right,
            content,
            count
        );
    }
}

void BinaryTree::exibirSubArvore2
(
    struct BinaryTreeNode *father,
    bool isLeftSon,
    struct BinaryTreeNode* n,
    std::string& content,
    int& count
)
{
    //Desenha o dado do nó n
    content += std::to_string(n->data)+" [label = \"<l> | <m> "+std::to_string(n->data)+" | <r>\"]";

    //desenha a ligação entre o pai e ele
    if (father != nullptr)
    {
        if (isLeftSon)
            content += std::to_string(father->data)+":l->"+std::to_string(n->data)+";";
        else
            content += std::to_string(father->data)+":r->"+std::to_string(n->data)+";";
    }
    else
    {
        //é o root
        content += "ROOT[shape=none fontcolor=blue];";
        content += "ROOT->"+std::to_string(n->data)+";";
    }

    if (n->left != nullptr)
    {
        exibirSubArvore2
        (
            n,
            true, //is left
            n->left,
            content,
            count
        );
    }

    if (n->right != nullptr)
    {
        exibirSubArvore2
        (
            n,
            false, //is not left
            n->right,
            content,
            count
        );
    }
}
