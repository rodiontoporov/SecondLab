#include "BST.h"

// Increment (InOrder)
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
void BST<Key, Allocator, Compare, Tag>::BST_Iterator::IncrementHelper(InOrderTag tag) { // ?
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
        while (ptr_->right_) {
            ptr_ = ptr_->right_;
        }
    } else {
        auto prev = ptr_;
        ptr_ = ptr_->parent_;
        while (ptr_ && prev == ptr_->left_) {
            prev = ptr_;
            ptr_ = ptr_->parent_;
        }
    }
}

// Decrement (PreOrder)
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
void BST<Key, Allocator, Compare, Tag>::BST_Iterator::DecrementHelper(PreOrderTag tag) {
    if (!ptr_->parent_) {
        ptr_ = ptr_->left_;
        while (ptr_->right_) {
            ptr_ = ptr_->right_;
        }
        return;
    }
    if (!ptr_->parent_->left_ || ptr_->parent_->left_ == ptr_) {
        ptr_ = ptr_->parent_;
        return;
    }
    ptr_ = ptr_->parent_->left_;
    while (ptr_->right_) {
        ptr_ = ptr_->right_;
    }
}

// Decrement (PostOrder)
template<
    typename Key,
    typename Allocator,
    typename Compare,
    typename Tag>
void BST<Key, Allocator, Compare, Tag>::BST_Iterator::DecrementHelper(PostOrderTag tag) {
    if (!ptr_) return;
    if (ptr_->right_) {
        ptr_ = ptr_->right_;
        return;
    }
    while (ptr_->parent_->left_ == ptr_ || !ptr_->parent_->left_) {
        ptr_ = ptr_->parent_;
    }
    ptr_ = ptr_->parent_->left_;
}



