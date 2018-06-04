//
// Created by sandra on 03.06.18.
//

#ifndef JIMP_EXERCISES_TEACHERHASH_H
#define JIMP_EXERCISES_TEACHERHASH_H

#include <string>
#include <functional>

using namespace std;
namespace academia {

    class TeacherId {
    public:
        TeacherId() {
            id_;
        }

        TeacherId(int id) {
            id_ = id;
        }
        operator int() const {
            return id_;
        }

        bool operator!= (const TeacherId& other) const {
            return id_ != other.id_;
        }

        int id_;
    };

    class Teacher {
    public:
        Teacher(TeacherId id, string name, string department) {
            id_ = id;
            name_ = name;
            department_ = department;
        }
        TeacherId Id() const {
            return id_;
        }
        string Name() const {
            return name_;
        }
        string Department() const {
            return department_;
        }

        bool operator!= (const Teacher& other) const {
            return id_ != other.id_ || name_ != other.name_ || department_ != other.department_;
        }

        bool operator== (const Teacher& other) const {
            return id_ == other.id_ && name_ == other.name_ && department_ == other.department_;
        }

    private:
        TeacherId id_;
        string name_;
        string department_;
    };

    class TeacherHash {
    public:
        TeacherHash() {}

        size_t operator() (const Teacher teacher) const {
            return hash<int>()(teacher.Id()) * hash<string>()(teacher.Name())
                   * hash<string>()(teacher.Department());
        }
    };

}

#endif //JIMP_EXERCISES_TEACHERHASH_H
