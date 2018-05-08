//
// Created by giersand on 08.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <memory>
#include <vector>

using namespace std;

namespace academia {
    class Serializer;

    class Serializable {
    public:
        virtual void Serialize(Serializer *serializer)=0;
    };

    class Room : public Serializable {
    public:
        enum class Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };
        Room (int number, string name, Type type);
        void Serialize(Serializer *serializer) override ;
        string TypeToString (Type type);

        int number_;
        string name_;
        Type type_;
    };

    class Building : public Serializable {
    public:
        Building (int number, string name, initializer_list<Room> rooms);
        void Serialize(Serializer *serializer) override ;

        int number_;
        string name_;
        initializer_list<Room> rooms_;
    };

    class Serializer {
    public:
        Serializer(std::ostream *out);
        virtual void IntegerField(const std::string &field_name, int value)=0;
        virtual void DoubleField(const std::string &field_name, double value)=0;
        virtual void StringField(const std::string &field_name, const std::string &value)=0;
        virtual void BooleanField(const std::string &field_name, bool value)=0;
        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value)=0;
        virtual void ArrayField(const std::string &field_name, const vector<reference_wrapper<const academia::Serializable>> &value)=0;
        virtual void Header(const std::string &object_name)=0;
        virtual void Footer(const std::string &object_name)=0;
    };

    class JsonSerializer : public Serializer {
    public:
        JsonSerializer(ostream *out);

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

//    class Serialization {
//
//    };
}

#endif //JIMP_EXERCISES_SERIALIZATION_H
