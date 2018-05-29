//
// Created by giersand on 29.05.18.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H

namespace tree {

    template<typename T>
    class Tree {
    public:
        Tree(T t);
        void Insert (T t);
        Tree Root();

    private:
        Tree* parent;
        Tree* left;
        Tree* right;
        T value;
    };

    class InOrder {

    };

    template<typename T>
    class InOrderTreeIterator {
    public:
        InOrderTreeIterator(Tree<T> t);
        InOrderTreeIterator& operator++();
        T& operator*();
        bool operator!=(InOrderTreeIterator<T> second);

    };

    template<typename T>
    class InOrderTreeView {
    public:
        InOrderTreeView(Tree<T> t);
    };

    class TreeIterators {

    };
}


#endif //JIMP_EXERCISES_TREEITERATORS_H
