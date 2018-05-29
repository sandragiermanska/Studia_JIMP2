//
// Created by giersand on 29.05.18.
//

#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H

#include <memory>

using namespace std;
namespace tree {

    template<typename T>
    class Node {
    public:
        Node() {
            value_=T {};
            parent_ = nullptr;
            left_ = nullptr;
            right_ = nullptr;
        }
        Node(T t) {
            value_ = t;
            parent_ = nullptr;
            left_ = nullptr;
            right_ = nullptr;
        }

        T GetValue() {
            return value_;
        }

    private:
        T value_;
        unique_ptr<Node<T>> parent_;
        unique_ptr<Node<T>> left_;
        unique_ptr<Node<T>> right_;

    };

    template<typename T>
    class Tree {
    public:
        Tree();
        Tree(T t);

        T Value();

        size_t Size();
        size_t Depth();

        void Insert(const T &e);
        bool Find(const T &e);

//        Tree Root();

    private:
        std::unique_ptr<Node<T>> root_;
        size_t size_;
    };

    template<typename T>
    Tree<T>::Tree() {
        root_ = make_unique<Node<T>>();
        size_ = 0;
    }

    template<typename T>
    Tree<T>::Tree(T t) {
        root_ = make_unique<Node<T>>(t);
        size_ = 1;
    }

    template<typename T>
    T Tree<T>::Value() {

    }

    template<typename T>
    size_t Tree<T>::Size() {
        return size_;
    }

    template<typename T>
    size_t Tree<T>::Depth() {
        return 0;
    }

    template<typename T>
    void Tree<T>::Insert(const T &e) {
        Node<T> new_node (e);
        Node<T> *current = root_.get();
//        while (current.GetValue()) {
//
//        }
        ++size_;
    }

    template<typename T>
    bool Tree<T>::Find(const T &e) {
        return false;
    }

}

#endif //JIMP_EXERCISES_TREE_H
