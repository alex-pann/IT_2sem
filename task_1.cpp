#include <iostream>
#include <cmath>
#include <chrono>
#include <memory>

namespace Chrono{
    using clock = std::chrono::steady_clock;
    using timepoint = clock::time_point;
    using duration = clock::duration;
}

const int N =  15;

class Student {

public:
    Student() {};
    Student(std::string newName, int newGroup): name(newName), group(newGroup) {};
    ~Student() {};

    void setName(std::string newName) {
        this->name = newName;
    };
    void setGroup(int newGroup) {
        this->group = newGroup;
    }

    auto getName() {
        return name;
    }
    auto getGroup() {
        return group;
    }

private:
    std::string name;
    int group;
};

class Course {

public:
    Course(){
        begin = Chrono::clock::now();

        list = new Student[N];
        number = 0;
    };
    Course(std::string newTeacher): teacher(newTeacher) {
        begin = Chrono::clock::now();

        list = new Student[N];
        number = 0;
    };
    ~Course() {
        delete[] list;

        end = Chrono::clock::now();
        std::cout << "Class duration: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " ms" << std::endl;
    };

    void setTeacher() {
        std::string teachName;
        std::cout << "Enter teacher's name: ";
        std::cin >>  teachName;
        this->teacher = teachName;
    }

    void addStudent() {
        int b;
        std::string newName;
        int newGroup;
        for (; ;) {
            std::cout << "If you want to add a student, press 1, else press 0" << std::endl;
            std::cin >> b;
            if (b == 0) {
                break;
            } else {
                std::cout << "Enter name: ";
                std::cin >> newName;
                std::cout << "Enter group: ";
                std::cin >> newGroup;
                Student New(newName, newGroup);
                this->list[this->number] = New;
                this->number++;

                if (this->number == N) {
                    std::cout << "No more places" << std::endl;
                    return;
                }
            }

        }
    }

    void showInfo() {
        std::cout << "Teacher: " << teacher << std::endl;
        std::cout << "Students: " << std::endl;
        for (int i = 0; i < this->number; ++i) {
            std::cout << list[i].getName() << ", " << list[i].getGroup() << std::endl;
        }
    }

    void deleteStudent(int p) {
        if (p > this->number) {
            std::cout << "Cannot delete" << std::endl;
            return;
        } else {
            for (int i = p - 1; i < this->number; ++i) {
                list[i] = list[i + 1];
            }
            this->number--;
        }
    };

private:
    std::string teacher;
    Student* list;
    int number;

    Chrono::timepoint begin;
    Chrono::timepoint end;
};

int main() {
    Course math;

    math.setTeacher();
    math.addStudent();
    math.showInfo();

    math.deleteStudent(3);
    math.showInfo();

    math.setTeacher();
    math.showInfo();

    return 0;
}