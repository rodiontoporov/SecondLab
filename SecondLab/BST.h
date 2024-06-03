#pragma once
//#include "BST_Iterator.h"
#include <iostream>

struct PreOrderTag {};
struct InOrderTag {};
struct PostOrderTag {};
template<
    typename Key,
    typename Allocator = std::allocator<Key>,
    typename Compare = std::less<Key>,
    typename Tag = InOrderTag>
class BST {
    
    struct BST_Node {
        Key value_;
        BST_Node* left_;
        BST_Node* right_;
        BST_Node* parent_;
        BST_Node(Key value, BST_Node* parent)
        :   value_(value),
            left_(nullptr),
            right_(nullptr),
            parent_(parent)
        {}
        BST_Node(Key value, BST_Node* left, BST_Node* right, BST_Node* parent)
        :   value_(value)
        ,   left_(left)
        ,   right_(right)
        ,   parent_(parent)
        {}
    };
    
    class BST_Iterator {
    public:
        using key_type = BST_Node;
        using difference_type = std::ptrdiff_t;
        using value_type = BST_Node;
        using pointer = value_type*;
        using const_pointer = const value_type*;
        using reference = value_type&;
        using const_reference = const value_type&;
        using size_type = unsigned int;
        using iterator_category = std::bidirectional_iterator_tag;
        
        BST_Iterator();
        BST_Iterator(pointer, InOrderTag);
        BST_Iterator(pointer, PreOrderTag);
        BST_Iterator(pointer, PostOrderTag);
        BST_Iterator(const BST_Iterator&);
        BST_Iterator& operator=(const BST_Iterator&);
        ~BST_Iterator() = default;
        const_reference operator*() const;
        pointer operator->();
        bool operator==(const BST_Iterator&) const;
        bool operator!=(const BST_Iterator&) const;
        
        
        BST_Iterator& operator++();
        BST_Iterator  operator++(int); // post increment
        BST_Iterator& operator--();
        BST_Iterator  operator--(int);
    private:
        void IncrementHelper(InOrderTag tag);
        void IncrementHelper(PreOrderTag tag);
        void IncrementHelper(PostOrderTag tag);
        
        void DecrementHelper(InOrderTag tag);
        void DecrementHelper(PreOrderTag tag);
        void DecrementHelper(PostOrderTag tag);
        
        void SwapValues(BST_Iterator& other) noexcept {
            std::swap(ptr_, other.ptr_);
        }
        
        friend class BST<Key, Allocator, Compare, Tag>;
        
        const BST_Node *ptr_;
        const BST<Key, Allocator, Compare, Tag> *bst_;
        
        BST_Iterator(const BST_Node*, const BST<Key, Allocator, Compare, Tag>);
    };
    
    using key_type = Key;
    using reference = Key&;
    using const_reference = const Key&;
    using iterator = BST_Iterator;
    using const_iterator = BST_Iterator;
    using difference_type = BST_Iterator::difference_type;
    using size_type = std::size_t;
    using value_type = Key;
    using key_compare = Compare;
    using value_compare = Compare;
    using node_type = BST_Node;
    
    BST();
    BST(const key_compare c);
    BST(const BST&);
    BST(auto i, auto j, const key_compare c);
    BST(auto i, auto j);
    BST(std::initializer_list<value_type>);
    BST(std::initializer_list<value_type>, const key_compare);
    
    bool operator==(const BST&) const;
    bool operator!=(const BST& b) const { return !(*this == b); }
    auto operator=(std::initializer_list<value_type> il);
    
    // destructor
    // reference operator=(BST&& rv) ?
    // reference operator=(BST& r) ?
private:
    auto begin() const; // implemented below
    auto end() const { return nullptr; }
    auto cbegin() const; // implemented below
    auto cend() const; // implemented below
    
    bool empty() const { return begin() == end(); }
    auto size() const { return size_; }
    auto max_size() const { return max_size_; };
    
    auto key_comp() const { return c_; }
    auto value_comp() const { return c_; }
    
    void swap(const BST&); // implemented below
    static void swap(const BST& a, const BST& b) { a.swap(b); }
public:
    
    
private:
    Compare c_;
    Tag tag_;
    size_type size_;
    size_type max_size_ = 1000; // ?
    node_type root_;
};

// begin()
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
auto BST<Key, Allocator, Compare, Tag>::begin() const  {
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

// operator==
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
auto BST<Key, Allocator, Compare, Tag>::operator=(std::initializer_list<Key> il) {
    // destroy all existing elements
    // assign the range
    return *this;
}

// swap(b)
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
void BST<Key, Allocator, Compare, Tag>::swap(const BST& b) {
    // implement
}
