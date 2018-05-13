//
// Created by giersand on 08.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <sstream>
#include <functional>
#include <experimental/optional>

using namespace std;

namespace academia {

    class Serializer;

    class Serializable {
    public:
        virtual void Serialize(Serializer *serializer) const=0;
    };

    class Room : public Serializable {
    public:
        enum class Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };
        Room () {};
        Room (int number, string name, Type type);
        void Serialize(Serializer *serializer) const override ;
        string TypeToString (Type type) const;

        int number_;
        string name_;
        Type type_;
    };

    class Building : public Serializable {
    public:
        Building (int number, string name, vector<academia::Room> rooms);
        void Serialize(Serializer *serializer) const override ;
        vector<reference_wrapper<const Serializable>> VectorToReferenceVector() const;
        int Id();

        int number_;
        string name_;
        vector<Room> rooms_;
    };

    class Serializer {
    public:
        Serializer(stringstream *out);
        Serializer(ostream *out);
        virtual void IntegerField(const std::string &field_name, int value)=0;
        virtual void DoubleField(const std::string &field_name, double value)=0;
        virtual void StringField(const std::string &field_name, const std::string &value)=0;
        virtual void BooleanField(const std::string &field_name, bool value)=0;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value)=0;
        virtual void ArrayField(const std::string &field_name, const vector<reference_wrapper<const academia::Serializable>> &value)=0;
        virtual void Header(const std::string &object_name)=0;
        virtual void Footer(const std::string &object_name)=0;

        stringstream* out_;
    };

    class JsonSerializer : public Serializer {
    public:
        JsonSerializer(stringstream *out) : Serializer(out) {};

        void IntegerField(const std::string &field_name, int value) override;

        void DoubleField(const std::string &field_name, double value) override;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                        const vector<reference_wrapper<const academia::Serializable>> &value) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;
    };

    class XmlSerializer : public Serializer {
    public:
        XmlSerializer(stringstream *out) : Serializer(out) {};

        void IntegerField(const std::string &field_name, int value) override;

        void DoubleField(const std::string &field_name, double value) override;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                        const vector<reference_wrapper<const academia::Serializable>> &value) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;
    };

    class BuildingRepository {
    public:
        BuildingRepository ();
        BuildingRepository (academia::Building building);
        BuildingRepository (vector<academia::Building> buildings);
        vector<reference_wrapper<const Serializable>> VectorToReferenceVector() const;
        void StoreAll(Serializer *serializer);
        void Add(Building building);
        std::experimental::optional<Building> operator[] (int number) const;

        vector <Building> buildings_;
    };
}

#endif //JIMP_EXERCISES_SERIALIZATION_H
