//
// Created by sandra on 21.04.18.
//

#include <bits/unique_ptr.h>
#include "Iterable.h"

using namespace std;
using namespace utility;

IterableIterator::IterableIterator() {

}

ZipperIterator::ZipperIterator(std::vector<int>::const_iterator left,
                               std::vector<std::string>::const_iterator right,
                               std::vector<int>::const_iterator left_end,
                               std::vector<std::string>::const_iterator right_end) {
    left_ = left;
    left_end_ = left_end;
    right_ = right;
    right_end_ = right_end;
}

std::pair<int, std::string> ZipperIterator::Dereference() const {
    pair<int, string> result;
    result.first = *left_;
    result.second = *right_;
    return result;
}

IterableIterator& ZipperIterator::Next() {
    if (left_ != left_end_ && right_ != right_end_) {
        left_++;
        right_++;
    }
    return *this;
}

bool ZipperIterator::NotEquals(const unique_ptr<IterableIterator> &other) const {
    if(left_ != other.get()->left_) {
        return true;
    }
    else {
        return false;
    }
}

bool ZipperIterator::NotEquals(const IterableIterator& other)const {
    if(left_ != other.left_) {
        return true;
    }
    else {
        return false;
    }
}


ZipperIterator::~ZipperIterator() {

}

IterableIteratorWrapper::IterableIteratorWrapper(std::unique_ptr<utility::IterableIterator> iterator) {
    iterator_ = iterator.get();
}

bool IterableIteratorWrapper::operator!=(const IterableIteratorWrapper &other) {
    return iterator_->NotEquals(*(other.iterator_));
}

std::pair<int, std::string> IterableIteratorWrapper::operator*() {
    return iterator_->Dereference();
}

IterableIteratorWrapper& IterableIteratorWrapper::operator++() {
    iterator_->Next();
    return *this;
}

Iterable::Iterable() {

}

Iterable::~Iterable() {

}

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
    int size = vi.size();
    for (int i = 0; i < size; ++i) {
        left_.push_back(vi[i]);
        right_.push_back(vs[i]);
    }


}

//Zipper::~Zipper() {
//
//}

unique_ptr<IterableIterator> Zipper::ConstBegin() const {
    //unique_ptr<ZipperIterator> result;
    unique_ptr<IterableIterator> res = unique_ptr<ZipperIterator>(new ZipperIterator (left_.begin(), right_.begin(), left_.end(), right_.end()));
//    unique_ptr<IterableIterator> r;
//    r.get() = &res;
//    unique_ptr<ZipperIterator> result (res);
//    return result;
    return res;
}

unique_ptr<IterableIterator> Zipper::ConstEnd() const {
    unique_ptr<IterableIterator> res = unique_ptr<ZipperIterator>(new ZipperIterator (left_.end(), right_.end(), left_.end(), right_.end()));
    return res;
}