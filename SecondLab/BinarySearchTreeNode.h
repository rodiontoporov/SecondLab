#include <iostream>

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
    BST_Node& operator=(const BST_Node&);
    
    // destructor
    ~BST_Node();
    
    // observers
    value_type& value() const;
    
    allocator_type get_allocator() const;
    explicit operator bool() const noexcept;
    [[nodiscard]] bool empty() const noexcept;
    
    // modifiers
    void swap(BST_Node&)
        noexcept(ator_traits::propagate_on_container_swap::value || ator_traits::is_always_equal::value);
    friend void swap(BST_Node& x, BST_Node& y) noexcept(noexcept(x.swap(y))) {
        x.swap(y);
    }
};

template<
    typename Key,
    typename Alloc>
BST_Node<Key, Alloc>::BST_Node(BST_Node&& nh) noexcept {
    ptr_ = nh.ptr_;
    alloc_(std::move(nh.alloc_));
    nh.ptr_ = nullptr;
    nh.alloc_ = std::nullopt;
};

template<
    typename Key,
    typename Alloc>
BST_Node<Key, Alloc>& BST_Node<Key, Alloc>::operator=(const BST_Node<Key, Alloc>& nh) {
    if (ptr_ != nullptr) {
        ator_traits::destroy(alloc_, ptr_); // ? alloc
        ator_traits::template rebind_traits<container_node_type>::deallocate(ptr_, 1);
    }
    ptr_ = nh.ptr_;
    if (!alloc_ || ator_traits::propagate_on_container_move_assignment == true) {
        alloc_(std::move(nh.alloc_));
    }
    nh.ptr_ = nullptr;
    nh.alloc_ = std::nullopt;
    
    return *this;
}

template<
    typename Key,
    typename Alloc>
BST_Node<Key,Alloc>::~BST_Node() {
    if (ptr_ != nullptr) {
        ator_traits::destroy(alloc_, ptr_);
        ator_traits::template rebind_traits<container_node_type>::deallocate(ptr_, 1);
    }
}

template<
    typename Key,
    typename Alloc>
bool BST_Node<Key, Alloc>::empty() const noexcept {
    return ptr_ == nullptr;
}

template<
    typename Key,
    typename Alloc>
BST_Node<Key, Alloc>::operator bool() const noexcept {
    return ptr_ != nullptr;
}

template<
    typename Key,
    typename Alloc>
void BST_Node<Key, Alloc>::swap(BST_Node& nh) noexcept(ator_traits::propagate_on_container_swap::value || ator_traits::is_always_equal::value) {
    std::swap(ptr_, nh.ptr_); // ?
    if (!alloc_ || !nh.alloc_ || ator_traits::propagate_on_container_swap::value) {
        std::swap(alloc_, nh.alloc_); // ?
    }
}
