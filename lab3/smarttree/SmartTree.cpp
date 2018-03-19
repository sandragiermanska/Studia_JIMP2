//
// Created by sandra on 18.03.18.
//

#include "SmartTree.h"

using namespace datastructures;

std::unique_ptr <SmartTree> datastructures::CreateLeaf(int value) {
    unique_ptr <SmartTree> leaf (new SmartTree);
    leaf.get()->value = value;
    leaf.get()->left = nullptr;
    leaf.get()->right = nullptr;
    leaf.get()->parent = nullptr;
    return leaf;
}

std::unique_ptr <SmartTree> datastructures::InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree) {
    tree.get()->left = move(left_subtree);
    return tree;
}

std::unique_ptr <SmartTree> datastructures::InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree) {
    tree.get()->right = move(right_subtree);
    return tree;
}

void datastructures::PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out) {
    if(unique_ptr.get()->left) {
        PrintTreeInOrder(unique_ptr.get()->left, out);
    }
    *out << unique_ptr.get()->value << ", ";
    if(unique_ptr.get()->right) {
        PrintTreeInOrder(unique_ptr.get()->right, out);
    }
}

std::string datastructures::DumpTree(const std::unique_ptr<SmartTree> &tree) {
    string result;
    result += "[";
    result += to_string(tree.get()->value);
    if (tree.get()->left) {
        result += " ";
        result += datastructures::DumpTree(tree.get()->left);
    }
    else {
        result += " [none]";
    }
    if (tree.get()->right) {
        result += " ";
        result += datastructures::DumpTree(tree.get()->right);
    }
    else {
        result += " [none]";
    }
    result += "]";
    return result;
}

string DeletePartOfString(string tree_temp) {
    int number_of_bracket = 1;
    tree_temp.erase(tree_temp.begin());
    while (number_of_bracket) {
        if (tree_temp.front() == '[') {
            number_of_bracket++;
        } else if (tree_temp.front() == ']') {
            number_of_bracket--;
        }
        tree_temp.erase(tree_temp.begin());
    }
    tree_temp.erase(tree_temp.begin());
    return tree_temp;
}

std::unique_ptr <SmartTree> datastructures::RestoreTree(const std::string &tree) {
    unique_ptr<SmartTree> root (new SmartTree);
    string tree_temp = tree;

    if (tree_temp[1] == 'n') {
        return nullptr;
    }
    else {
        tree_temp.erase(tree_temp.begin());
        string string_value;
        int int_value;
        while (tree_temp.front() != ' ') {
            string_value += tree_temp.front();
            tree_temp.erase(tree_temp.begin());
        }
        int_value = stoi(string_value);
        root.get()->value = int_value;
        if (tree_temp.front() != ']'){
            tree_temp.erase(tree_temp.begin());
            root.get()->left = datastructures::RestoreTree(tree_temp);
            tree_temp = DeletePartOfString(tree_temp);
            root.get()->right = datastructures::RestoreTree(tree_temp);
            tree_temp = DeletePartOfString(tree_temp);
        }
    }
    if(tree_temp.empty() == 0) {
        tree_temp.erase(tree_temp.begin());
    }
    return root;
}

