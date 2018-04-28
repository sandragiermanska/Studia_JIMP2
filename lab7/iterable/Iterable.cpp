//
// Created by sandra on 21.04.18.
//

#include <bits/unique_ptr.h>
#include "Iterable.h"

using namespace std;
using namespace utility;

IterableIterator::IterableIterator() { }

MyIterableIterator::MyIterableIterator(std::vector<int>::const_iterator left,
                                       std::vector<std::string>::const_iterator right,
                                       std::vector<int>::const_iterator left_end,
                                       std::vector<std::string>::const_iterator right_end){
    left_ = left;
    left_end_ = left_end;
    right_ = right;
    right_end_ = right_end;
}

std::pair<int, std::string> MyIterableIterator::Dereference() const {
    pair<int, string> result;
    result.first = *left_;
    result.second = *right_;
    return result;
}

IterableIterator& MyIterableIterator::Next() {
    if (left_ != left_end_ && right_ != right_end_) {
        left_++;
        right_++;
    }
    return *this;
}

bool MyIterableIterator::NotEquals(const unique_ptr<IterableIterator> &other) const {
    if(left_ != other.get()->left_) {
        return true;
    }
    else {
        return false;
    }
}

ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left,
                               std::vector<std::string>::const_iterator right,
                               std::vector<int>::const_iterator left_end,
                               std::vector<std::string>::const_iterator right_end)
        : MyIterableIterator(left, right, left_end, right_end) { }

IterableIteratorWrapper::IterableIteratorWrapper(std::unique_ptr<utility::IterableIterator> iterator) {
    iterator_ = unique_ptr<utility::IterableIterator>(std::move(iterator));
}

bool IterableIteratorWrapper::operator!=(const IterableIteratorWrapper &other) {
    return iterator_->NotEquals(other.iterator_);
}

std::pair<int, std::string> IterableIteratorWrapper::operator*() {
    return iterator_->Dereference();
}

IterableIteratorWrapper& IterableIteratorWrapper::operator++() {
    iterator_->Next();
    return *this;
}

Iterable::Iterable() { }

Iterable::~Iterable() { }

IterableIteratorWrapper Iterable::cbegin() const {
    return IterableIteratorWrapper(ConstBegin());
}

IterableIteratorWrapper Iterable::cend() const {
    return IterableIteratorWrapper(ConstEnd());
}

IterableIteratorWrapper Iterable::begin() const {
    return cbegin();
}

IterableIteratorWrapper Iterable::end() const {
    return cend();
}

Zipper::Zipper(vector<int> vi, vector<string> vs) {
    int size_vs = vs.size();
    int size_vi = vi.size();
    int size = size_vs>size_vi?size_vs:size_vi;
    for (int j = 0; j < size; ++j) {
        int i= j<size_vi?j:size_vi-1;
        int s=j<size_vs?j:size_vs-1;
        left_.push_back(vi[i]);
        right_.push_back(vs[s]);
    }
}

unique_ptr<IterableIterator> MyIterable::ConstBegin() const {
    unique_ptr<IterableIterator> res = unique_ptr<MyIterableIterator>(new MyIterableIterator (left_.begin(), right_.begin(), left_.end(), right_.end()));
    return res;
}

unique_ptr<IterableIterator> MyIterable::ConstEnd() const {
    unique_ptr<IterableIterator> res = unique_ptr<MyIterableIterator>(new MyIterableIterator (left_.end(), right_.end(), left_.end(), right_.end()));
    return res;
}

Enumerate::Enumerate(vector<string> vs) {
    int size = vs.size();
    for (int i = 0; i < size; ++i) {
        left_.push_back(i+1);
        right_.push_back(vs[i]);
    }
}

EnumerateIterator::EnumerateIterator(std::vector<int>::const_iterator left,
                                     std::vector<std::string>::const_iterator right,
                                     std::vector<int>::const_iterator left_end,
                                     std::vector<std::string>::const_iterator right_end)
        : MyIterableIterator(left, right, left_end, right_end) { }

Product::Product(vector<int> vi, vector<string> vs) {
    int size_vi = vi.size();
    int size_vs = vs.size();
    for (int i = 0; i <size_vi; ++i) {
        for (int s = 0; s < size_vs; ++s) {
            left_.push_back(vi[i]);
            right_.push_back(vs[s]);
        }
    }

}

ProductIterator::ProductIterator(std::vector<int>::const_iterator left,
                               std::vector<std::string>::const_iterator right,
                               std::vector<int>::const_iterator left_end,
                               std::vector<std::string>::const_iterator right_end)
        : MyIterableIterator(left, right, left_end, right_end) { }