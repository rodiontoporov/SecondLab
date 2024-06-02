#include "BinarySearchTreeNode.h"
struct PreOrderTag {};
struct InOrderTag {};
struct PostOrderTag {};
template<
    typename Key,
    typename Alloc = std::allocator<Key>,
    typename Compare = std::less<Key>,
    typename TraversalTag = InOrderTag>
class BST {
    class BST_Iterator;
    
    using key_type = Key;
    using value_type = Key; // Erasable
    using key_compare = Compare; // CopyConstructible
    using value_compare = Compare;
    using node_type = BST_Node<Key, Alloc>; // ? // Public nested types are the same
    
    BST(key_compare c) : c_(c) {}
    BST() = default;
    BST(auto i, auto j, key_compare c) : c_(c) 
    { 
        for (; i != j; ++i) { } /* do sth */
    }
    BST(auto i, auto j)
    {
        for (; i != j; ++i) { } /* do sth */
    }
    BST(std::initializer_list<value_type> il) 
    {
        BST(il.begin(), il.end());
    }
    BST(std::initializer_list<value_type> il, key_compare c)
    {
        BST(il.begin(), il.end(), c);
    }
    
    
private:
    Compare c_;
    
};

