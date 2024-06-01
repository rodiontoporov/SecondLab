#include <iostream>

namespace my {
struct PreOrderTag {};
struct InOrderTag {};
struct PostOrderTag {};
template<
    typename Key,
    typename Alloc = std::allocator<Key>>
class BST_Node {
public:
    using key_type = Key;
    using value_type = Key;
    using allocator_type = Alloc;
    
private:
    using container_node_type = BST_Node<Key, Alloc>;
    using ator_traits = std::allocator_traits<allocator_type>;
    
    typename ator_traits::template rebind_traits<container_node_type>::pointer ptr_;
    std::optional<allocator_type> alloc_;
public:
    // constructors, copy and assignment
    constexpr BST_Node() noexcept : ptr_(), alloc_() {}
    BST_Node(BST_Node&&) noexcept;
    BST_Node& operator=(BST_Node&&);
    
    // destructor
    ~BST_Node();
    
    // observers
    value_type& value() const;
    
    allocator_type get_allocator() const;
};
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
};
}; // end of namespace my
