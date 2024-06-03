#include "BinarySearchTreeNode.h"
struct PreOrderTag {};
struct InOrderTag {};
struct PostOrderTag {};
template<
    typename Key,
    typename Allocator = std::allocator<Key>,
    typename Compare = std::less<Key>,
    typename Tag = InOrderTag>
class BST {
    class BST_Iterator {
        using difference_type = std::ptrdiff_t;
    };
    
    using key_type = Key;
    using reference = Key&;
    using const_reference = const Key&;
    using iterator = BST_Iterator;
    using const_iterator = BST_Iterator;
    using difference_type = BST_Iterator::difference_type;
    using size_type = std::size_t;
    using value_type = Key; // Erasable
    using key_compare = Compare; // CopyConstructible
    using value_compare = Compare;
    using node_type = BST_Node<Key, Allocator>; // ? // Public nested types are the same
    
    BST();
    BST(const Compare c);
    BST(const BST&);
    BST(auto i, auto j, const Compare c);
    BST(auto i, auto j);
    BST(std::initializer_list<value_type> il);
    BST(std::initializer_list<value_type> il, const key_compare c)
    {
        BST(il.begin(), il.end(), c);
    }
    
    
    
    // destructor
    // reference operator=(BST&& rv) ?
    // reference operator=(BST& r) ?
private:
    auto begin() const;
    auto end() const;
    auto cbegin() const;
    auto cend() const;
    auto size() const;
    auto max_size() const;
    bool empty() const;
    
    bool operator==(const BST&) const;
    bool operator!=(const BST&) const;
    
    void swap(const BST&);
    static void swap(const BST&, const BST&);
    
    BST& operator=(std::initializer_list<value_type> il) {
        // destroy all existing elements
        // assign the range
        return *this;
    }
    key_compare key_comp() const {
        return c_;
    }
    value_compare value_comp() const {
        return c_;
    }
public:
    
    
private:
    Compare c_;
    Tag tag_;
    size_type size_;
    node_type root_;
};

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

template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
BST<Key, Allocator, Compare, Tag>::BST(const BST& b) {
    // destroy all elements first and deallocate
}

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































// begin()
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
auto BST<Key, Allocator, Compare, Tag>::begin() const  {
    return nullptr;
}

// end()
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
auto BST<Key, Allocator, Compare, Tag>::end() const  {
    return nullptr;
}

// cbegin()
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
auto BST<Key, Allocator, Compare, Tag>::cbegin() const  {
    return nullptr;
}

// cend()
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
auto BST<Key, Allocator, Compare, Tag>::cend() const  {
    return nullptr;
}

// operator==
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
bool BST<Key, Allocator, Compare, Tag>::operator==(const BST& b) const {
    // if (a.size != b.size()) return false;
    // implement
    return true;
}

// operator!=
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
bool BST<Key, Allocator, Compare, Tag>::operator!=(const BST& b) const {
    return !(*this == b);
}

template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
void BST<Key, Allocator, Compare, Tag>::swap(const BST& b) {
    // implement
}

template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
void BST<Key, Allocator, Compare, Tag>::swap(const BST& a, const BST& b) {
    a.swap(b);
}

template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
auto BST<Key, Allocator, Compare, Tag>::size() const {
    // implement
}

template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
auto BST<Key, Allocator, Compare, Tag>::max_size() const {
    // implement
}

template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
bool BST<Key, Allocator, Compare, Tag>::empty() const {
    return begin() == end();
}




