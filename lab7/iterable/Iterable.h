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
        virtual bool NotEquals(const IterableIterator &other)const=0;
        vector<int>::const_iterator left_;
        vector<string>::const_iterator right_;
        vector<int>::const_iterator left_end_;
        vector<string>::const_iterator right_end_;
    };

    class ZipperIterator : public IterableIterator {
    public:
        explicit ZipperIterator(std::vector<int>::const_iterator left,
                                std::vector<std::string>::const_iterator right,
                                std::vector<int>::const_iterator left_end,
                                std::vector<std::string>::const_iterator right_end);
        std::pair<int, std::string> Dereference() const override;
        IterableIterator &Next() override;
        bool NotEquals(const unique_ptr<IterableIterator> &other)const override ;//(const IterableIterator &other) override;
        bool NotEquals(const IterableIterator& other)const override ;
        ~ZipperIterator();
    //private:
//        vector<int>::const_iterator left_;
//        vector<string>::const_iterator right_;
//        vector<int>::const_iterator left_end_;
//        vector<string>::const_iterator right_end_;
    };

    class IterableIteratorWrapper {
    public:
        IterableIteratorWrapper(std::unique_ptr<utility::IterableIterator> iterator);
        bool operator!=(const IterableIteratorWrapper &other);
        std::pair<int, std::string> operator*();
        IterableIteratorWrapper &operator++();
    private:
        utility::IterableIterator* iterator_;
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

    };

    class Zipper : public Iterable {
    public:
        Zipper(vector<int> vi, vector<string> vs);
        //~Zipper();
        unique_ptr<IterableIterator> ConstBegin() const override;
        unique_ptr<IterableIterator> ConstEnd() const override;
        vector<int> left_;
        vector<string> right_;
    };

    class Product : public Iterable {
        Product();
        ~Product();
        unique_ptr<IterableIterator> ConstBegin() const override;
        unique_ptr<IterableIterator> ConstEnd() const override;
    };

    class ProductIterator : public IterableIterator {

    };

    class Enumerate : public Iterable {
    public:
        Enumerate();
        Enumerate(vector<string>);
        ~Enumerate();
        unique_ptr<IterableIterator> ConstBegin() const override;
        unique_ptr<IterableIterator> ConstEnd() const override;
    };

    class EnumerateIterator : public IterableIterator {

    };

}

#endif //JIMP_EXERCISES_ITERABLE_H