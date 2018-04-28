//
// Created by sandra on 21.04.18.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H

#include <string>
#include <vector>

using namespace std;

namespace utility {

    class IterableIterator {
    public:
        IterableIterator();
        ~IterableIterator()=default;
        virtual std::pair<int, std::string> Dereference() const =0;
        virtual IterableIterator &Next()=0;
        virtual bool NotEquals(const unique_ptr<IterableIterator> &other)const =0;
        vector<int>::const_iterator left_;
        vector<string>::const_iterator right_;
        vector<int>::const_iterator left_end_;
        vector<string>::const_iterator right_end_;
    };

    class MyIterableIterator : public IterableIterator {
    public:
        explicit MyIterableIterator(std::vector<int>::const_iterator left,
                                    std::vector<std::string>::const_iterator right,
                                    std::vector<int>::const_iterator left_end,
                                    std::vector<std::string>::const_iterator right_end);
        std::pair<int, std::string> Dereference() const override;
        IterableIterator &Next() override;
        bool NotEquals(const unique_ptr<IterableIterator> &other) const override;
    };

    class ZipperIterator : public MyIterableIterator {
    public:
        explicit ZipperIterator(std::vector<int>::const_iterator left,
                                std::vector<std::string>::const_iterator right,
                                std::vector<int>::const_iterator left_end,
                                std::vector<std::string>::const_iterator right_end);
    };

    class IterableIteratorWrapper {
    public:
        IterableIteratorWrapper(std::unique_ptr<utility::IterableIterator> iterator);
        bool operator!=(const IterableIteratorWrapper &other);
        std::pair<int, std::string> operator*();
        IterableIteratorWrapper &operator++();
    private:
        std::unique_ptr<utility::IterableIterator>  iterator_;
    };

    class Iterable {
    public:
        Iterable();
        ~Iterable();
        virtual std::unique_ptr<IterableIterator> ConstBegin() const =0;
        virtual std::unique_ptr<IterableIterator> ConstEnd() const =0;
        IterableIteratorWrapper cbegin() const;
        IterableIteratorWrapper cend() const;
        IterableIteratorWrapper begin() const;
        IterableIteratorWrapper end() const;
        vector<int> left_;
        vector<string> right_;
    };

    class MyIterable : public Iterable {
    public:
        MyIterable()= default;
        unique_ptr<IterableIterator> ConstBegin() const override;
        unique_ptr<IterableIterator> ConstEnd() const override;
    };

    class Zipper : public MyIterable {
    public:
        Zipper(vector<int> vi, vector<string> vs);
    };

    class Product : public MyIterable {
    public:
        Product(vector<int> vi, vector<string> vs);
    };

    class ProductIterator : public MyIterableIterator {
        explicit ProductIterator(std::vector<int>::const_iterator left,
                std::vector<std::string>::const_iterator right,
                std::vector<int>::const_iterator left_end,
                std::vector<std::string>::const_iterator right_end);
    };

    class Enumerate : public MyIterable {
    public:
        Enumerate(vector<string> vs);
    };

    class EnumerateIterator : public MyIterableIterator {
    public:
        explicit EnumerateIterator (std::vector<int>::const_iterator left,
                std::vector<std::string>::const_iterator right,
                std::vector<int>::const_iterator left_end,
                std::vector<std::string>::const_iterator right_end);
    };
}

#endif //JIMP_EXERCISES_ITERABLE_H