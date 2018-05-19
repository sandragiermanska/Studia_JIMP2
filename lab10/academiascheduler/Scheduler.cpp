//
// Created by sandra on 17.05.18.
//

#include "Scheduler.h"

using namespace std;
using namespace academia;

academia::SchedulingItem::SchedulingItem(int course_id, int teacher_id, int room_id,
                                         int time_slot, int year) {
    course_id_ = course_id;
    teacher_id_ = teacher_id;
    room_id_ = room_id;
    time_slot_ = time_slot;
    year_ = year;
}

int academia::SchedulingItem::CourseId() const {
    return course_id_;
}

int academia::SchedulingItem::TeacherId() const {
    return teacher_id_;
}

int academia::SchedulingItem::RoomId() const {
    return room_id_;
}

int academia::SchedulingItem::TimeSlot() const {
    return time_slot_;
}

int academia::SchedulingItem::Year() const {
    return year_;
}

//============================================================

void academia::Schedule::InsertScheduleItem(const academia::SchedulingItem &item) {
    list_.push_back(item);
}

academia::Schedule academia::Schedule::OfTeacher(int teacher_id) const {
    Schedule result;
    copy_if(list_.begin(), list_.end(), back_inserter(result.list_), [teacher_id](SchedulingItem current)
    {return (current.TeacherId() == teacher_id)?true:false;});
    return result;
}

academia::Schedule academia::Schedule::OfRoom(int room_id) const {
    Schedule result;
    copy_if(list_.begin(), list_.end(), back_inserter(result.list_), [room_id](SchedulingItem current)
    {return (current.RoomId() == room_id)?true:false;});
    return result;
}

academia::Schedule academia::Schedule::OfYear(int year) const {
    Schedule result;
    copy_if(list_.begin(), list_.end(), back_inserter(result.list_), [year](SchedulingItem current)
    {return (current.Year() == year)?true:false;});
    return result;
}

struct c_unique {
    int current;
    c_unique() {current=0;}
    int operator()() {return ++current;}
} NumberInTurn;

vector<int> academia::Schedule::AvailableTimeSlots(int n_time_slots) const {
    vector<int> result (n_time_slots);
    generate(result.begin(), result.end(), NumberInTurn);
    result.erase(remove_if(result.begin(), result.end(), [this](int current1){
        return any_of(list_.begin(), list_.end(), [current1](SchedulingItem current2){
            return current1 == current2.TimeSlot();
        });
    }), result.end());
    return result;
}

size_t academia::Schedule::Size() const {
    return list_.size();
}

academia::SchedulingItem academia::Schedule::operator[](int n) const {
    if(list_.size() > n) {
        return list_[n];
    }
}

//======================================================

Schedule GreedyScheduler::PrepareNewSchedule(const vector<int> &rooms, const map<int, vector<int>> &teacher_courses_assignment,
                                    const map<int, set<int>> &courses_of_year, int n_time_slots) {
    Schedule result;

    map<int, vector<int>> courses;
    int repeat = 0;
    for (auto year : courses_of_year) {
        vector<int> temp;
        for (auto course : year.second) {
            for (auto teacher : teacher_courses_assignment) {
                for (auto course2 : teacher.second) {
                    if(course == course2) {
                        ++repeat;
                    }
                }
            }
            for (int j = 0; j < repeat; ++j) {
                temp.push_back(course);
            }
            repeat = 0;
        }
        courses.insert(pair<int, vector<int>>(year.first, temp));
    }

    map<int, vector<int>> teachers_availability;
    for (auto teacher : teacher_courses_assignment) {
        vector<int> temp (n_time_slots);
        generate(temp.begin(), temp.end(), NumberInTurn);
        teachers_availability.insert(pair<int, vector<int>> (teacher.first, temp));
    }

    map<int,int> teachers_number_of_courses;
    for (auto teacher : teacher_courses_assignment) {
        teachers_number_of_courses.insert(pair<int, int> (teacher.first, teacher.second.size()));
    }

    map<int, vector<int>> years_availability;
    for (auto year : courses_of_year) {
        vector<int> temp (n_time_slots);
        generate(temp.begin(), temp.end(), NumberInTurn);
        years_availability.insert(pair<int, vector<int>> (year.first, temp));
    }

    bool is_course_to_add = true;
    bool course_is_added = false;
    int current_time = 1;

    for (auto room : rooms) {
        current_time = 1;
        while (current_time <= n_time_slots && is_course_to_add) {
            for (auto year : courses) {
                if (any_of(years_availability[year.first].begin(),
                           years_availability[year.first].end(),
                           [current_time](int current) {
                               return current == current_time;
                           })) {

                    for (auto course : year.second) {
                        int myteacher = -1;
                        for (auto teacher : teacher_courses_assignment) {
                            if (any_of(teacher.second.begin(), teacher.second.end(),
                                       [course](int current) { return current == course; }) &&
                                any_of(teachers_availability[teacher.first].begin(),
                                       teachers_availability[teacher.first].end(),
                                       [current_time](int current) {
                                           return current == current_time;
                                       })) {
                                myteacher = teacher.first;
                                break;
                            }
                        }
                        if (myteacher != -1) {
                            SchedulingItem lesson(course, myteacher, room, current_time, year.first);
                            result.InsertScheduleItem(lesson);
                            course_is_added = true;

                            teachers_availability[myteacher].erase(remove_if(teachers_availability[myteacher].begin(),
                                                                             teachers_availability[myteacher].end(),
                                                                             [current_time](int current) {
                                                                                 return current == current_time;
                                                                             }),
                                                                   teachers_availability[myteacher].end());


                            if (teachers_availability[myteacher].size() <= n_time_slots - teachers_number_of_courses[myteacher]) {
                                teachers_availability.erase(myteacher);
                            }

                            years_availability[year.first].erase(remove_if(years_availability[year.first].begin(),
                                                                           years_availability[year.first].end(),
                                                                           [current_time](int current) {
                                                                               return current == current_time;
                                                                           }), years_availability[year.first].end());

                            for (auto it = courses[year.first].begin(); it != courses[year.first].end(); ++it) {
                                if (*it == course) {
                                    courses[year.first].erase(it);
                                    break;
                                }
                            }
                            break;
                        }
                    }
                    if (course_is_added) {
                        course_is_added = false;
                        break;
                    }
                }
            }
            is_course_to_add = !all_of(courses.begin(), courses.end(),
                       [](pair<int, vector<int>> current) { return current.second.empty(); });
            ++current_time;
        }
        if(!is_course_to_add) {
            break;
        }
    }
    if (is_course_to_add) {
        throw NoViableSolutionFound();
    }
    return result;
}