//
// Created by giersand on 29.05.18.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

#include <memory>

using namespace std;
namespace tree {

    template<typename T>
    class Node {
    public:
        Node() {
            value_ = T {};
            left_ = nullptr;
            right_ = nullptr;
        }

        Node(T t) {
            value_ = t;
            left_ = nullptr;
            right_ = nullptr;
        }

        Node(const Node<T> &t) {
            value_ = t.value_();
            left_ = make_unique<Node<T>>(t.left_);
            right_ = make_unique<Node<T>>(t.right_);
        }

        T value_;
        unique_ptr<Node<T>> left_;
        unique_ptr<Node<T>> right_;
    };

    //=================================================================================

    template<typename T>
    class Tree {
    public:
        Tree();
        Tree(T t);

        size_t Size();
        void Insert(const T &e);
        Node<T> *Root();

    private:
        std::unique_ptr<Node<T>> root_;
        size_t size_;
    };

    template<typename T>
    Tree<T>::Tree() {
        root_ = nullptr;
        size_ = 0;
    }

    template<typename T>
    Tree<T>::Tree(T t) {
        root_ = make_unique<Node<T>>(t);
        size_ = 1;
    }

    template<typename T>
    size_t Tree<T>::Size() {
        return size_;
    }

    template<typename T>
    void Tree<T>::Insert(const T &e) {
        unique_ptr<Node<T>> new_node = make_unique<Node<T>>(e);
        Node<T> *current = root_.get();
        bool is_found = false;
        while (!is_found) {
            if (current->value_ > e) {
                if (current->left_ != nullptr) {
                    current = current->left_.get();
                } else {
                    is_found = true;
                    current->left_ = move(new_node);
                }
            } else {
                if (current->right_ != nullptr) {
                    current = current->right_.get();
                } else {
                    is_found = true;
                    current->right_ = move(new_node);

                }
            }
        }
        ++size_;
    }

    template<typename T>
    Node<T> *Tree<T>::Root() {
        return root_.get();
    }

    //==================================================================================

    template<typename T>
    class InOrderTreeIterator {
    public:
        InOrderTreeIterator(Node<T> *t);//unique_ptr<Node<T>> &t);
        ~InOrderTreeIterator() {};

        InOrderTreeIterator(const InOrderTreeIterator<T> &t);

        InOrderTreeIterator &operator++();

        T operator*();

        bool operator!=(const InOrderTreeIterator<T> &second) const;

        Node<T> *iterator_;
        Node<T> *root_;
    };

    template<typename T>
    InOrderTreeIterator<T>::InOrderTreeIterator(Node<T> *t) {//unique_ptr<Node<T>> &t) {
        root_ = t;
        iterator_ = t;//.get();
        while (iterator_->left_ != nullptr) {
            iterator_ = iterator_->left_.get();
        }
    }

    template<typename T>
    InOrderTreeIterator<T> &InOrderTreeIterator<T>::operator++() {
        Node<T> *parent;
        bool is_found = false;
        bool is_repeat = false;
        while (!is_found) {
            if (!is_repeat && iterator_->right_ != nullptr) {
                iterator_ = iterator_->right_.get();
                while (iterator_->left_ != nullptr) {
                    iterator_ = iterator_->left_.get();
                }
                is_found = true;
            } else {
                bool parent_is_found = false;
                parent = root_;
                while (!parent_is_found) {
                    if (parent->value_ > iterator_->value_ && parent->left_.get() != iterator_) {
                        parent = parent->left_.get();
                    } else if (parent->value_ <= iterator_->value_ && parent->right_.get() != iterator_) {
                        parent = parent->right_.get();
                    } else {
                        parent_is_found = true;
                    }
                }
                if (parent->left_.get() == iterator_) {
                    iterator_ = parent;
                    is_found = true;
                } else {
                    iterator_ = parent;
                    if (parent == root_) {
                        iterator_ = nullptr;
                        is_found = true;
                    }
                    is_repeat = true;
                }
            }
        }
        return *this;
    }

    template<typename T>
    T InOrderTreeIterator<T>::operator*() {
        return iterator_->value_;
    }

    template<typename T>
    bool InOrderTreeIterator<T>::operator!=(const InOrderTreeIterator<T> &second) const {
        return (iterator_ != second.iterator_);
    }

    template<typename T>
    InOrderTreeIterator<T>::InOrderTreeIterator(const InOrderTreeIterator<T> &t) {}

    //================================================================================


    template<typename T>
    class PostOrderTreeIterator {
    public:
        PostOrderTreeIterator(Node<T> *t);//unique_ptr<Node<T>> &t);
        ~PostOrderTreeIterator() {};

        PostOrderTreeIterator(const PostOrderTreeIterator<T> &t);

        PostOrderTreeIterator &operator++();

        T operator*();

        bool operator!=(const PostOrderTreeIterator<T> &second) const;

        Node<T> *iterator_;
        Node<T> *root_;
    };

    template<typename T>
    PostOrderTreeIterator<T>::PostOrderTreeIterator(Node<T> *t) {//unique_ptr<Node<T>> &t) {
        root_ = t;
        iterator_ = t;//.get();
        bool is_found = false;
        while (!is_found) {
            while (iterator_->left_ != nullptr) {
                iterator_ = iterator_->left_.get();
            }
            if(iterator_->right_ == nullptr) {
                is_found = true;
            }
            else {
                iterator_ = iterator_->right_.get();
            }
        }

    }

    template<typename T>
    PostOrderTreeIterator<T> &PostOrderTreeIterator<T>::operator++() {
        Node<T> *parent;
        if(iterator_ == root_) {
            iterator_ = nullptr;
        }
        else {
            bool is_found = false;
            bool is_changed = false;
//            while (!is_found) {
                bool parent_is_found = false;
                parent = root_;
                while (!parent_is_found) {
                    if (parent->value_ > iterator_->value_ && parent->left_.get() != iterator_) {
                        parent = parent->left_.get();
                    } else if (parent->value_ <= iterator_->value_ && parent->right_.get() != iterator_) {
                        parent = parent->right_.get();
                    } else {
                        parent_is_found = true;
                    }
                }
                if (parent->left_.get() == iterator_ && parent->right_ != nullptr) {
                    iterator_ = parent->right_.get();
                    while (!is_found) {
//                        bool is_changed = false;
                        while (iterator_->left_ != nullptr) {
                            iterator_ = iterator_->left_.get();
//                            is_found = true;
                        }
                        if (iterator_ == parent->right_.get() && iterator_->right_ != nullptr) {
                            parent = iterator_;
                            iterator_ = iterator_->right_.get();
                        }
                        if (iterator_->left_ == nullptr && iterator_->right_ == nullptr) {
                            is_found = true;
                        }
                    }
//                    is_found = true;
                } else {
                    iterator_ = parent;
//                    is_found = true;
//                }
            }
        }
        return *this;
    }

    template<typename T>
    T PostOrderTreeIterator<T>::operator*() {
        return iterator_->value_;
    }

    template<typename T>
    bool PostOrderTreeIterator<T>::operator!=(const PostOrderTreeIterator<T> &second) const {
        return (iterator_ != second.iterator_);
    }

    template<typename T>
    PostOrderTreeIterator<T>::PostOrderTreeIterator(const PostOrderTreeIterator<T> &t) {}

    //================================================================================

    template<typename T>
    class PreOrderTreeIterator {
    public:
        PreOrderTreeIterator(Node<T> *t);//unique_ptr<Node<T>> &t);
        ~PreOrderTreeIterator() {};

        PreOrderTreeIterator(const PreOrderTreeIterator<T> &t);

        PreOrderTreeIterator &operator++();

        T operator*();

        bool operator!=(const PreOrderTreeIterator<T> &second) const;

        Node<T> *iterator_;
        Node<T> *root_;
    };

    template<typename T>
    PreOrderTreeIterator<T>::PreOrderTreeIterator(Node<T> *t) {//unique_ptr<Node<T>> &t) {
        root_ = t;
        iterator_ = t;//.get();
    }

    template<typename T>
    PreOrderTreeIterator<T> &PreOrderTreeIterator<T>::operator++() {
        Node<T> *parent;
        if (iterator_->left_ != nullptr) {
            iterator_ = iterator_->left_.get();
        } else if (iterator_->right_ != nullptr) {
            iterator_ = iterator_->right_.get();
        } else {

            bool is_found = false;
//        bool is_repeat = false;
//        while (!is_found) {
//            if (!is_repeat && iterator_->right_ != nullptr) {
//                iterator_ = iterator_->right_.get();
//                while (iterator_->left_ != nullptr) {
//                    iterator_ = iterator_->left_.get();
//                }
//                is_found = true;
//            } else {
            while (!is_found) {
                bool parent_is_found = false;
                parent = root_;
                while (!parent_is_found) {
                    if (parent->value_ > iterator_->value_ && parent->left_.get() != iterator_) {
                        parent = parent->left_.get();
                    } else if (parent->value_ <= iterator_->value_ && parent->right_.get() != iterator_) {
                        parent = parent->right_.get();
                    } else {
                        parent_is_found = true;
                    }
                }
                if (parent->left_.get() == iterator_) {
                    if (parent->right_ != nullptr) {
                        iterator_ = parent->right_.get();
                        is_found = true;
                    }
                    else {
                        iterator_ = parent;
                    }
//                while (iterator_->left_ != nullptr) {
//                    iterator_ = iterator_->left_.get();
//                }
//                    is_found = true;
                }
//                else if (iterator_->left_ == nullptr) {
//                    iterator_ = iterator_->right_.get();
//                    is_found = true;
//
//                }
//                else if (parent->right_.get() == iterator_) {
                else {
                    iterator_ = parent;
                    if (iterator_ == root_) {
                        iterator_ = nullptr;
                        is_found = true;
                    }
//                    if (parent == root_) {
//                        iterator_ = nullptr;
//                        is_found = true;
//                    }
//                    is_repeat = true;
//                }
//            }
                }
//                else {
//                    iterator_ = iterator_->right_.get();
//                    is_found = true;
//                }
            }
        }
        return *this;
    }

    template<typename T>
    T PreOrderTreeIterator<T>::operator*() {
        return iterator_->value_;
    }

    template<typename T>
    bool PreOrderTreeIterator<T>::operator!=(const PreOrderTreeIterator<T> &second) const {
        return (iterator_ != second.iterator_);
    }

    template<typename T>
    PreOrderTreeIterator<T>::PreOrderTreeIterator(const PreOrderTreeIterator<T> &t) {}

    //================================================================================

    template<typename T>
    class InOrderTreeView {
    public:
        InOrderTreeView();

        InOrderTreeView(Tree<T> *t);

//        InOrderTreeView(InOrder inOrder);
        InOrderTreeIterator<T> begin();
        InOrderTreeIterator<T> end();
        Node<T>* root_;
        size_t size_;
    };

    template<typename T>
    InOrderTreeView<T>::InOrderTreeView(Tree<T> *t) {
        root_ = t->Root();
        size_ = t->Size();
    }

    template<typename T>
    InOrderTreeIterator<T> InOrderTreeView<T>::begin() {
        return InOrderTreeIterator<T>(root_);
    }

    template<typename T>
    InOrderTreeIterator<T> InOrderTreeView<T>::end() {
        InOrderTreeIterator<T> it (root_);
        for (int i = 0; i < size_; ++i) {
            ++it;
        }
        return it;
    }

    //========================================================

    template<typename T>
    class PostOrderTreeView {
    public:
        PostOrderTreeView();

        PostOrderTreeView(Tree<T> *t);

//        InOrderTreeView(InOrder inOrder);
        PostOrderTreeIterator<T> begin();
        PostOrderTreeIterator<T> end();
        Node<T>* root_;
        size_t size_;
    };

    template<typename T>
    PostOrderTreeView<T>::PostOrderTreeView(Tree<T> *t) {
        root_ = t->Root();
        size_ = t->Size();
    }

    template<typename T>
    PostOrderTreeIterator<T> PostOrderTreeView<T>::begin() {
        return PostOrderTreeIterator<T>(root_);
    }

    template<typename T>
    PostOrderTreeIterator<T> PostOrderTreeView<T>::end() {
        PostOrderTreeIterator<T> it (root_);
        for (int i = 0; i < size_; ++i) {
            ++it;
        }
        return it;
    }

    //========================================================

    template<typename T>
    class PreOrderTreeView {
    public:
        PreOrderTreeView();

        PreOrderTreeView(Tree<T> *t);

//        InOrderTreeView(InOrder inOrder);
        PreOrderTreeIterator<T> begin();
        PreOrderTreeIterator<T> end();
        Node<T>* root_;
        size_t size_;
    };

    template<typename T>
    PreOrderTreeView<T>::PreOrderTreeView(Tree<T> *t) {
        root_ = t->Root();
        size_ = t->Size();
    }

    template<typename T>
    PreOrderTreeIterator<T> PreOrderTreeView<T>::begin() {
        return PreOrderTreeIterator<T>(root_);
    }

    template<typename T>
    PreOrderTreeIterator<T> PreOrderTreeView<T>::end() {
        PreOrderTreeIterator<T> it (root_);
        for (int i = 0; i < size_; ++i) {
            ++it;
        }
        return it;
    }

    //========================================================

    template<typename T>
    InOrderTreeView<T> InOrder(Tree<T> *t) {
        return InOrderTreeView<T>(t);
    }

    template<typename T>
    PostOrderTreeView<T> PostOrder(Tree<T>* t) {
        return PostOrderTreeView<T>(t);
    }

    template<typename T>
    PreOrderTreeView<T> PreOrder(Tree<T>* t) {
        return PreOrderTreeView<T>(t);
    }
};


#endif //JIMP_EXERCISES_TREEITERATORS_H