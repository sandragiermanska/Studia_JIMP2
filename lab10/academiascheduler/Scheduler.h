//
// Created by sandra on 17.05.18.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;
namespace academia {

    class SchedulingItem {
    public:
        SchedulingItem(int course_id, int teacher_id, int room_id,
                       int time_slot, int year);
        int CourseId() const;
        int TeacherId() const;
        int RoomId() const;
        int TimeSlot() const;
        int Year() const;
    private:
        int course_id_;
        int teacher_id_;
        int room_id_;
        int time_slot_;
        int year_;
    };

    class Schedule {

    public:

        void InsertScheduleItem(const SchedulingItem &item);

        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        vector<int> AvailableTimeSlots(int n_time_slots) const;
        SchedulingItem operator[] (int n) const;

        size_t Size() const;

    private:
        vector<SchedulingItem> list_;
    };

    class Scheduler {
    public:
        virtual Schedule PrepareNewSchedule(const vector<int> &rooms, const map<int, vector<int>> &teacher_courses_assignment,
                                 const map<int, set<int>> &courses_of_year, int n_time_slots)=0;

    };

    class NoViableSolutionFound : public invalid_argument {
    public:
        NoViableSolutionFound() : invalid_argument("") {};
    };

    class GreedyScheduler : public Scheduler {
        Schedule PrepareNewSchedule(const vector<int> &rooms, const map<int, vector<int>> &teacher_courses_assignment,
                                    const map<int, set<int>> &courses_of_year, int n_time_slots) override ;
    };
}

#endif //JIMP_EXERCISES_SCHEDULER_H
