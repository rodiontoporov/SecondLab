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
        using difference_type = std::ptrdiff_t;
        using value_type = Key;
        
        BST_Iterator();
        bool operator==(const BST_Iterator&) const;
        bool operator!=(const BST_Iterator& rhs) const;
        
        const Key& operator*() const; // ?
        
        BST_Iterator& operator++();
        BST_Iterator  operator++(int); // post increment
        BST_Iterator&  operator--();
        BST_Iterator  operator--(int);
    private:
        void IncrementHelper(InOrderTag tag);
        void IncrementHelper(PreOrderTag tag);
        void IncrementHelper(PostOrderTag tag);
        
        void DecrementHelper(InOrderTag tag);
        void DecrementHelper(PreOrderTag tag);
        void DecrementHelper(PostOrderTag tag);
        
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
    bool operator!=(const BST&) const;
    auto operator=(std::initializer_list<value_type> il);
    
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
    auto key_comp() const;
    auto value_comp() const;
    void swap(const BST&);
    static void swap(const BST&, const BST&);
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

// operator!=
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
bool BST<Key, Allocator, Compare, Tag>::operator!=(const BST& b) const {
    return !(*this == b);
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

// swap(a, b)
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
void BST<Key, Allocator, Compare, Tag>::swap(const BST& a, const BST& b) {
    a.swap(b);
}

// size()
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
auto BST<Key, Allocator, Compare, Tag>::size() const {
    // implement
}

// max_size()
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
auto BST<Key, Allocator, Compare, Tag>::max_size() const {
    // implement
}

// empty()
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
bool BST<Key, Allocator, Compare, Tag>::empty() const {
    return begin() == end();
}

// key_comp()
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
auto BST<Key, Allocator, Compare, Tag>::key_comp() const {
    return c_;
}

// value_comp()
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
auto BST<Key, Allocator, Compare, Tag>::value_comp() const {
    return c_;
}

// Increment (InOrder)
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
void BST<Key, Allocator, Compare, Tag>::BST_Iterator::IncrementHelper(InOrderTag tag) { // ?
    if (!ptr_) throw std::runtime_error("Attempted end() increment!");
    
    if (ptr_->right_) {
        ptr_ = ptr_->right_;
        while (ptr_->left_) {
            ptr_ = ptr_->left_;
        }
    } else {
        auto temp = ptr_;
        while (temp->parent_ && temp == temp->parent_->right_) {
            temp = temp->parent_;
        }
        ptr_ = temp->parent_;
    }
}

// Increment (PreOrder)
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
void BST<Key, Allocator, Compare, Tag>::BST_Iterator::IncrementHelper(PreOrderTag tag) {
    if (!ptr_) throw std::runtime_error("Attempted end() increment!");
    
    if (ptr_->left_) {
        ptr_ = ptr_->left_;
    } else if (ptr_->right_) {
        ptr_ = ptr_->right_;
    } else {
        while (ptr_->parent_ && ptr_ == ptr_->parent_->right_) {
            ptr_ = ptr_->parent_;
        }
        if (ptr_->parent_) {
            ptr_ = ptr_->parent_->right_;
        }
    }
}

// Increment (PostOrder)
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
void BST<Key, Allocator, Compare, Tag>::BST_Iterator::IncrementHelper(PostOrderTag tag) {
    if (!ptr_) throw std::runtime_error("Attempted end() increment!");
    
    if (!ptr_->parent_) {
        ptr_ = nullptr;
    }
    if (ptr_->parent_->right_ == ptr_ || !ptr_->parent_->right_) {
        ptr_ = ptr_->parent_;
        return;
    }
    ptr_ = ptr_->parent_->right_;
    while(ptr_ && (ptr_->left_ || ptr_->right_)) {
        ptr_ = ptr_->left_ ? ptr_->left_ : ptr_->right_;
    }
}

// Decrement (InOrder)
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
void BST<Key, Allocator, Compare, Tag>::BST_Iterator::DecrementHelper(InOrderTag tag) {
    if (ptr_->left_) {
        ptr_ = ptr_->left_;
        while (ptr_->right_ != nullptr) {
            ptr_ = ptr_->right_;
        }
    } else {
        auto prev = ptr_;
        ptr_ = ptr_->parent_;
        while (ptr_ != nullptr && prev == ptr_->left_) {
            prev = ptr_;
            ptr_ = ptr_->parent_;
        }
    }
}


