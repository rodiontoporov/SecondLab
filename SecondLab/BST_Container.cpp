#include "BST.h"

// Empty constructor
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
BST<Key, Allocator, Compare, Tag>::BST()
:   c_(Compare())
,   size_(0)
,   root_(nullptr)
{}

// Constructor from comparison object
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
BST<Key, Allocator, Compare, Tag>::BST(const Compare c)
:   c_(c)
,   size_(0)
,   root_(nullptr)
{}

// Copy constructor
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
BST<Key, Allocator, Compare, Tag>::BST(const BST& b) {
    // destroy all elements first and deallocate
}

// Construct from range and comparison object
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
BST<Key, Allocator, Compare, Tag>::BST(auto i, auto j, const Compare c)
:   c_(c)
,   size_(0)
,   root_(nullptr) // ?
{
    for (; i != j; ++i) { /* insert *i */ }
}

// Construct from range
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
BST<Key, Allocator, Compare, Tag>::BST(auto i, auto j)
:   size_(0)
,   c_(Compare())
,   root_(nullptr) // ?
{
    for (; i != j; ++i) { /* insert *i */ }
}

// Construct from initializer list
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
BST<Key, Allocator, Compare, Tag>::BST(std::initializer_list<Key> il)
:   size_(0)
,   c_(Compare())
,   root_(nullptr) // ?
{
    BST<Key, Allocator, Compare, Tag>(il.begin(), il.end());
}

// Construct from initializer list and comparison object
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
BST<Key, Allocator, Compare, Tag>::BST(std::initializer_list<Key> il, const Compare c)
:   size_(0)
,   c_(Compare())
,   root_(nullptr) // ?
{
    BST<Key, Allocator, Compare, Tag>(il.begin(), il.end(), c);
}
