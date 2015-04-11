#ifndef BST_H
#define BST_H

#include <memory>
#include <vector>
#include <cassert>
#define likely(x)       __builtin_expect((x),1)
#define unlikely(x)     __builtin_expect((x),0)

//just for some basic checks
// #include <iostream>
// using namespace std;
// using std::cout;
// using std::endl;

/*

Binary Search Tree implementation.

*/

template<typename Data>
class BST
{
public:
	BST();
	void insert(const Data&);
	decltype(auto) find(const Data&);

	inline decltype(auto) new_node();

private:

	struct BSTNode
	{
		Data data;
		std::shared_ptr<BSTNode> left   = nullptr;
		std::shared_ptr<BSTNode> right  = nullptr;
	};

	void insert(const Data&, std::shared_ptr<BSTNode>);
	decltype(auto) find(const Data&, std::shared_ptr<BSTNode>);
	std::shared_ptr<BSTNode> root;
};

template<typename Data>
BST<Data>::BST(){
	root = nullptr;
}

template<typename Data>
void BST<Data>::insert(const Data& d){
  if(likely(root != nullptr))
  {
    insert(d, root);
  }
  else if(unlikely(root == nullptr))
  {
    root.reset(new_node());
    root->data  = d;
  }
}

template<typename Data>
void BST<Data>::insert(const Data& d, std::shared_ptr<typename BST<Data>::BSTNode> leaf){
  if(d < leaf->data)
  {
    if(leaf->left != nullptr)
    {
      insert(d, leaf->left);
    }
    else
    {
      leaf->left.reset(new_node());
      leaf->left->data = d;
    }  
  }
  else if(d >= leaf->data)
  {
    if(leaf->right != nullptr)
    {
      insert(d, leaf->right);
    }
    else
    {
      leaf->right.reset(new_node());
      leaf->right->data = d;
    }
  }
}

template<typename Data>
decltype(auto) BST<Data>::find(const Data& d){
  return find(d, root);
}

template<typename Data>
decltype(auto) BST<Data>::find(const Data& d, std::shared_ptr<typename BST<Data>::BSTNode> leaf){
  if(leaf == nullptr)
    return leaf;
  
  if(d == leaf->data)
    return leaf;

  if(d < leaf->data)
    return find(d, leaf->left);

  else
    return find(d, leaf->right);
}

template<typename Data>
inline decltype(auto) BST<Data>::new_node(){
	return new BSTNode;
}

#endif
