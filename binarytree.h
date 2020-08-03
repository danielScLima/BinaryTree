#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

/*!
 * \brief The BinaryTreeNode struct
 */
struct BinaryTreeNode
{
    /*!
     * \brief BinaryTreeNode
     */
    BinaryTreeNode():
        data(0), left(nullptr), right(nullptr)
    {}

    /*!
     * \brief BinaryTreeNode
     * \param data
     */
    BinaryTreeNode(int data):
        data(data), left(nullptr), right(nullptr)
    {}

    int data = 0;
    struct BinaryTreeNode* left = nullptr;
    struct BinaryTreeNode* right = nullptr;

    /*!
     * \brief dealockSubTree
     */
    void dealockSubTree()
    {
        if (left != nullptr)
        {
            left->dealockSubTree();
            delete left;
            left = nullptr;
        }

        if (right != nullptr)
        {
            right->dealockSubTree();
            delete right;
            right = nullptr;
        }
    }
};

/*!
 * \brief The BinaryTree class
 */
class BinaryTree
{
public:
    /*!
     * \brief BinaryTree
     */
    BinaryTree();

    ~BinaryTree();

    /*!
     * \brief insert
     * \param data
     */
    BinaryTreeNode* insert(int data);
    /*!
     * \brief removeOne
     * \param data
     * \return
     */
    struct BinaryTreeNode* removeOne(int data);
    /*!
     * \brief search
     * \param data
     * \return
     */
    bool search(int data);

    /*!
     * \brief gitDotFileMode1
     * \return
     */
    const std::string gitDotFileMode1();
    /*!
     * \brief gitDotFileMode2
     * \return
     */
    const std::string gitDotFileMode2();

    /*!
     * \brief preOrder
     * \return
     */
    const std::string preOrder();
    /*!
     * \brief inOrder
     * \return
     */
    const std::string inOrder();
    /*!
     * \brief posOrder
     * \return
     */
    const std::string posOrder();
    /*!
     * \brief InLevelOrder
     * \return
     */
    const std::string InLevelOrder();

    /*!
     * \brief removeUsingPredecessor
     * \param data
     * \return
     */
    BinaryTreeNode *removeUsingPredecessor(int data);
    /*!
     * \brief getFatherOfPredecessor
     * \param n
     * \return
     */
    BinaryTreeNode *getFatherOfPredecessor(BinaryTreeNode *n);

    /*!
     * \brief getRoot
     * \return
     */
    BinaryTreeNode* getRoot();

    /*!
     * \brief dealockNodes
     */
    void dealockNodes();
private:
    struct BinaryTreeNode* root = nullptr;

    /*!
     * \brief exibirSubArvore1
     * \param n
     * \param content
     * \param count
     */
    void exibirSubArvore1(BinaryTreeNode *n, std::string &content, int& count);
    /*!
     * \brief exibirSubArvore2
     * \param father
     * \param isLeftSon
     * \param n
     * \param content
     * \param count
     */
    void exibirSubArvore2(BinaryTreeNode *father, bool isLeftSon, BinaryTreeNode *n, std::string &content, int &count);

    /*!
     * \brief preOrder
     * \param BinaryTreeNode
     * \param content
     */
    void preOrder(BinaryTreeNode *binaryTreeNode, std::string &content);
    /*!
     * \brief inOrder
     * \param BinaryTreeNode
     * \param content
     */
    void inOrder(BinaryTreeNode *binaryTreeNode, std::string &content);
    /*!
     * \brief posOrder
     * \param BinaryTreeNode
     * \param content
     */
    void posOrder(BinaryTreeNode *binaryTreeNode, std::string &content);


};

#endif // BINARYTREE_H
