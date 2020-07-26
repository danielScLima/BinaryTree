// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "binarytree.h"

TEST_CASE( "Testing the insert call in the binary tree", "[single-file]" )
{
	BinaryTree b;
	BinaryTreeNode* node50 = b.insert(50);
	REQUIRE( node50 != nullptr);
	REQUIRE( node50->data == 50 );
	
	BinaryTreeNode* node40 = b.insert(40);
	REQUIRE( node40 != nullptr);
	REQUIRE( node40->data == 40 );
	BinaryTreeNode* node60 = b.insert(60);
	REQUIRE( node60 != nullptr);
	REQUIRE( node60->data == 60 );
	
	BinaryTreeNode* node35 = b.insert(35);
	REQUIRE( node35 != nullptr);
	REQUIRE( node35->data == 35 );
	BinaryTreeNode* node45 = b.insert(45);
	REQUIRE( node45 != nullptr);
	REQUIRE( node45->data == 45 );
	
	BinaryTreeNode* node55 = b.insert(55);
	REQUIRE( node55 != nullptr);
	REQUIRE( node55->data == 55 );
	BinaryTreeNode* node65 = b.insert(65);
	REQUIRE( node65 != nullptr);
	REQUIRE( node65->data == 65 );
	
	REQUIRE( b.getRoot()->data == 50 );
	REQUIRE( node50->data == 50 );
	
	REQUIRE( node50->left->data == 40 );
	REQUIRE( node50->right->data == 60 );
	
	REQUIRE( node40->left->data == 35 );
	REQUIRE( node40->right->data == 45 );
	
	REQUIRE( node60->left->data == 55 );
	REQUIRE( node60->right->data == 65 );
}

TEST_CASE( "Testing the remove call by mode 1 in the binary tree", "[single-file]" )
{
	BinaryTree b;
	BinaryTreeNode* node50 = b.insert(50);
	REQUIRE( node50 != nullptr);
	REQUIRE( node50->data == 50 );
	
	BinaryTreeNode* node40 = b.insert(40);
	REQUIRE( node40 != nullptr);
	REQUIRE( node40->data == 40 );
	BinaryTreeNode* node60 = b.insert(60);
	REQUIRE( node60 != nullptr);
	REQUIRE( node60->data == 60 );
	
	REQUIRE( b.getRoot()->data == 50 );
	REQUIRE( node50->data == 50 );
	
	REQUIRE( node50->left->data == 40 );
	REQUIRE( node50->right->data == 60 );
	
	BinaryTreeNode* rem = b.removeOne(40);
	REQUIRE( rem != nullptr );
	REQUIRE( rem->data == 40 );
	REQUIRE( b.getRoot()->left == nullptr );
	delete rem;
	
	rem = b.removeOne(60);
	REQUIRE( rem != nullptr );
	REQUIRE( rem->data == 60 );
	REQUIRE( b.getRoot()->right == nullptr );
	delete rem;
	
	rem = b.removeOne(50);
	REQUIRE( rem != nullptr );
	REQUIRE( rem->data == 50 );
	REQUIRE( b.getRoot() == nullptr );
	delete rem;
}

TEST_CASE( "Testing the remove call by mode 1 in the binary tree in a second case", "[single-file]" )
{
	BinaryTree b;
	BinaryTreeNode* node50 = b.insert(50);
	REQUIRE( node50 != nullptr);
	REQUIRE( node50->data == 50 );
	
	BinaryTreeNode* node40 = b.insert(40);
	REQUIRE( node40 != nullptr);
	REQUIRE( node40->data == 40 );
	BinaryTreeNode* node60 = b.insert(60);
	REQUIRE( node60 != nullptr);
	REQUIRE( node60->data == 60 );
	
	REQUIRE( b.getRoot()->data == 50 );
	REQUIRE( node50->data == 50 );
	
	REQUIRE( node50->left->data == 40 );
	REQUIRE( node50->right->data == 60 );
	
	BinaryTreeNode* rem = b.removeOne(50);
	REQUIRE( rem != nullptr );
	REQUIRE( rem->data == 50 );
	REQUIRE( b.getRoot()->right == nullptr );
	delete rem;
	
	REQUIRE( b.getRoot() != nullptr );
	REQUIRE( b.getRoot()->data == 60 );
	REQUIRE( b.getRoot()->left != nullptr );
	REQUIRE( b.getRoot()->left->data == 40 );
}

TEST_CASE( "Testing the remove call by mode 2 in the binary tree", "[single-file]" )
{
	BinaryTree b;
	BinaryTreeNode* node50 = b.insert(50);
	REQUIRE( node50 != nullptr);
	REQUIRE( node50->data == 50 );
	
	BinaryTreeNode* node40 = b.insert(40);
	REQUIRE( node40 != nullptr);
	REQUIRE( node40->data == 40 );
	BinaryTreeNode* node60 = b.insert(60);
	REQUIRE( node60 != nullptr);
	REQUIRE( node60->data == 60 );
	
	REQUIRE( b.getRoot()->data == 50 );
	REQUIRE( node50->data == 50 );
	
	REQUIRE( node50->left->data == 40 );
	REQUIRE( node50->right->data == 60 );
	
	BinaryTreeNode* rem = b.removeUsingPredecessor(50);
	REQUIRE( rem != nullptr );
	REQUIRE( rem->data == 50 );
	REQUIRE( b.getRoot()->data == 40);
	REQUIRE( b.getRoot()->left == nullptr );
	REQUIRE( b.getRoot()->right != nullptr );
	REQUIRE( b.getRoot()->right->data == 60 );
	
	delete rem;
}

TEST_CASE( "Testing the search call in the binary tree", "[single-file]" )
{
	BinaryTree b;
	BinaryTreeNode* node50 = b.insert(50);
	REQUIRE( node50 != nullptr);
	REQUIRE( node50->data == 50 );
	
	BinaryTreeNode* node40 = b.insert(40);
	REQUIRE( node40 != nullptr);
	REQUIRE( node40->data == 40 );
	BinaryTreeNode* node60 = b.insert(60);
	REQUIRE( node60 != nullptr);
	REQUIRE( node60->data == 60 );
	
	REQUIRE( b.getRoot()->data == 50 );
	REQUIRE( node50->data == 50 );
	
	REQUIRE( node50->left->data == 40 );
	REQUIRE( node50->right->data == 60 );
	
	REQUIRE( b.search(50));
	REQUIRE( b.search(40));
	REQUIRE( b.search(60));
}

TEST_CASE( "Testing in level order traversal", "[single-file]" )
{
	BinaryTree b;
	BinaryTreeNode* node50 = b.insert(50);
	REQUIRE( node50 != nullptr);
	REQUIRE( node50->data == 50 );
	
	BinaryTreeNode* node40 = b.insert(40);
	REQUIRE( node40 != nullptr);
	REQUIRE( node40->data == 40 );
	BinaryTreeNode* node60 = b.insert(60);
	REQUIRE( node60 != nullptr);
	REQUIRE( node60->data == 60 );
	
	BinaryTreeNode* node35 = b.insert(35);
	REQUIRE( node35 != nullptr);
	REQUIRE( node35->data == 35 );
	BinaryTreeNode* node45 = b.insert(45);
	REQUIRE( node45 != nullptr);
	REQUIRE( node45->data == 45 );
	
	BinaryTreeNode* node55 = b.insert(55);
	REQUIRE( node55 != nullptr);
	REQUIRE( node55->data == 55 );
	BinaryTreeNode* node65 = b.insert(65);
	REQUIRE( node65 != nullptr);
	REQUIRE( node65->data == 65 );
	
	std::string ret = b.InLevelOrder();
	std::string strMustbe = "50 40 60 35 45 55 65 ";
	REQUIRE(ret.compare(strMustbe) == 0);
}

TEST_CASE( "Testing pre order traversal", "[single-file]" )
{
	BinaryTree b;
	BinaryTreeNode* node50 = b.insert(50);
	REQUIRE( node50 != nullptr);
	REQUIRE( node50->data == 50 );
	
	BinaryTreeNode* node40 = b.insert(40);
	REQUIRE( node40 != nullptr);
	REQUIRE( node40->data == 40 );
	BinaryTreeNode* node60 = b.insert(60);
	REQUIRE( node60 != nullptr);
	REQUIRE( node60->data == 60 );
	
	BinaryTreeNode* node35 = b.insert(35);
	REQUIRE( node35 != nullptr);
	REQUIRE( node35->data == 35 );
	BinaryTreeNode* node45 = b.insert(45);
	REQUIRE( node45 != nullptr);
	REQUIRE( node45->data == 45 );
	
	BinaryTreeNode* node55 = b.insert(55);
	REQUIRE( node55 != nullptr);
	REQUIRE( node55->data == 55 );
	BinaryTreeNode* node65 = b.insert(65);
	REQUIRE( node65 != nullptr);
	REQUIRE( node65->data == 65 );
	
	std::string ret = b.preOrder();
	std::string strMustbe = "50 40 35 45 60 55 65 ";
	REQUIRE(ret.compare(strMustbe) == 0);
}

TEST_CASE( "Testing in order traversal", "[single-file]" )
{
	BinaryTree b;
	BinaryTreeNode* node50 = b.insert(50);
	REQUIRE( node50 != nullptr);
	REQUIRE( node50->data == 50 );
	
	BinaryTreeNode* node40 = b.insert(40);
	REQUIRE( node40 != nullptr);
	REQUIRE( node40->data == 40 );
	BinaryTreeNode* node60 = b.insert(60);
	REQUIRE( node60 != nullptr);
	REQUIRE( node60->data == 60 );
	
	BinaryTreeNode* node35 = b.insert(35);
	REQUIRE( node35 != nullptr);
	REQUIRE( node35->data == 35 );
	BinaryTreeNode* node45 = b.insert(45);
	REQUIRE( node45 != nullptr);
	REQUIRE( node45->data == 45 );
	
	BinaryTreeNode* node55 = b.insert(55);
	REQUIRE( node55 != nullptr);
	REQUIRE( node55->data == 55 );
	BinaryTreeNode* node65 = b.insert(65);
	REQUIRE( node65 != nullptr);
	REQUIRE( node65->data == 65 );
	
	std::string ret = b.inOrder();
	std::string strMustbe = "35 40 45 50 55 60 65 ";
	REQUIRE(ret.compare(strMustbe) == 0);
}

TEST_CASE( "Testing pos order traversal", "[single-file]" )
{
	BinaryTree b;
	BinaryTreeNode* node50 = b.insert(50);
	REQUIRE( node50 != nullptr);
	REQUIRE( node50->data == 50 );
	
	BinaryTreeNode* node40 = b.insert(40);
	REQUIRE( node40 != nullptr);
	REQUIRE( node40->data == 40 );
	BinaryTreeNode* node60 = b.insert(60);
	REQUIRE( node60 != nullptr);
	REQUIRE( node60->data == 60 );
	
	BinaryTreeNode* node35 = b.insert(35);
	REQUIRE( node35 != nullptr);
	REQUIRE( node35->data == 35 );
	BinaryTreeNode* node45 = b.insert(45);
	REQUIRE( node45 != nullptr);
	REQUIRE( node45->data == 45 );
	
	BinaryTreeNode* node55 = b.insert(55);
	REQUIRE( node55 != nullptr);
	REQUIRE( node55->data == 55 );
	BinaryTreeNode* node65 = b.insert(65);
	REQUIRE( node65 != nullptr);
	REQUIRE( node65->data == 65 );
	
	std::string ret = b.posOrder();
	std::string strMustbe = "35 45 40 55 65 60 50 ";
	REQUIRE(ret.compare(strMustbe) == 0);
}

TEST_CASE( "Testing the insert call of duplicated entries in the binary tree", "[single-file]" )
{
	BinaryTree b;
	REQUIRE( b.insert(50) != nullptr);
	REQUIRE( b.insert(60) != nullptr);
	REQUIRE( b.insert(40) != nullptr);
	
	REQUIRE( b.insert(50) == nullptr);
	REQUIRE( b.insert(60) == nullptr);
	REQUIRE( b.insert(40) == nullptr);
}


