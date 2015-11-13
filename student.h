#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student
{
protected:
    std::string group;
    float averageScore;
public:
    Student(const char* grp, float avg) : group(grp), averageScore(avg) {}
    virtual ~Student(){}
    virtual float calcScolarship() const = 0;
};

class MaleStudent : public Student
{
private:
    static constexpr float TRESHOLD_SCORE = 4.0;
    static constexpr float FIXED_MONEY = 1000.0;
public:
    explicit MaleStudent(const char* grp, float avg) : Student(grp,avg) {}
    float calcScolarship() const
    {
        if (averageScore >= TRESHOLD_SCORE)
            return FIXED_MONEY;
        return 0.0;
    }
};

class FemaleStudent : public Student
{
private:
    static constexpr float COEFFICIENT = 250.0;
public:
    explicit FemaleStudent(const char* grp, float avg) : Student(grp,avg) {}
    float calcScolarship() const
    {
        return COEFFICIENT * averageScore;
    }
};

void students()
{
    MaleStudent s("Group T11",4.1);
    FemaleStudent f("erer",2.5);

    Student* students[] = {&s,&f};

    for (int i = 0; i < 2; i++)
    {
        std::cout << students[i]->calcScolarship() << std::endl;
    }
}

#endif // STUDENT_H
