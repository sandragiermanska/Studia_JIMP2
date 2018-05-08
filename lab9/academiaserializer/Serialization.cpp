//
// Created by giersand on 08.05.18.
//

#include "Serialization.h"

using namespace std;
using namespace academia;

academia::Serializer::Serializer(std::ostream *out) {

}

academia::Room::Room(int number, string name, academia::Room::Type type) {
    number_ = number;
    name_ = name;
    type_ = type;
}

void academia::Room::Serialize(academia::Serializer *serializer) {
    serializer->Header("Room");
    serializer->IntegerField("Number", number_);
    serializer->StringField("Name", name_);
    serializer->StringField("Type", TypeToString(type_));
    serializer->Footer("Room");
}

string Room::TypeToString(Room::Type type) {
    return std::__cxx11::string();
}

void JsonSerializer::IntegerField(const std::string &field_name, int value) {

}

void JsonSerializer::DoubleField(const std::string &field_name, double value) {

}

void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {

}

void JsonSerializer::BooleanField(const std::string &field_name, bool value) {

}

void JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {

}

void JsonSerializer::ArrayField(const std::string &field_name,
                                const vector<reference_wrapper<const academia::Serializable>> &value) {

}

void JsonSerializer::Header(const std::string &object_name) {

}

void JsonSerializer::Footer(const std::string &object_name) {

}

JsonSerializer::JsonSerializer(ostream *out) : Serializer(out) {}

Building::Building(int number, string name, initializer_list<Room> rooms) {

}

void Building::Serialize(Serializer *serializer) {

}
