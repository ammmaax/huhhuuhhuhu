#include <iostream>

using namespace std;

class Student
{
private:
    string name;
    int age;
    int course;

public:
    Student() : name("Unknown"), age(17), course(1) {}

    Student(string name, int age, int course)
    {
        this->name = name;
        this->age = age;
        this->course = course;
    }

    string GetName() const
    {
        return name;
    }

    void SetName(string name)
    {
        this->name = name;
    }

    int GetAge() const
    {
        return age;
    }

    void SetAge(int age)
    {
        this->age = age;
    }

    int GetCourse() const
    {
        return course;
    }

    void SetCourse(int course)
    {
        this->course = course;
    }

    void Input()
    {
        cout << "Enter name: ";
        cin >> name;

        cout << "Enter age: ";
        cin >> age;

        cout << "Enter course: ";
        cin >> course;
    }

    void Output() const
    {
        cout << "Name: " << name
             << "  Age: " << age
             << "  Course: " << course << endl;
    }
};

Student operator++(Student& obj, int)
{
    Student temp = obj;
    obj.SetCourse(obj.GetCourse() + 1);
    return temp;
}

Student& operator--(Student& obj)
{
    obj.SetCourse(obj.GetCourse() - 1);
    return obj;
}

Student& operator+=(Student& obj, int value)
{
    obj.SetAge(obj.GetAge() + value);
    return obj;
}

Student& operator-=(Student& obj, int value)
{
    obj.SetAge(obj.GetAge() - value);
    return obj;
}

int main()
{
    Student obj1("Alex", 19, 2);

    cout << "Initial state:\n";
    obj1.Output();
    cout << "------------------------\n";

    obj1++;
    cout << "After obj1++:\n";
    obj1.Output();

    --obj1;
    cout << "After --obj1:\n";
    obj1.Output();

    obj1 += 2;
    cout << "After obj1 += 2:\n";
    obj1.Output();

    obj1 -= 2;
    cout << "After obj1 -= 2:\n";
    obj1.Output();

    return 0;
}

//Использовал перегрузку через указатель this, так как мне легче было сделать ну и другие операции. Плюс при этом рассмотрел тему указаелей по подробнее.