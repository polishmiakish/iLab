#include <iostream>
#include <cstring>

class Person{
    protected:
        std::string Name;
        std::string Surname;
        int Age;
        virtual std::string getName() = 0;
        virtual std::string getSurname() = 0;
        virtual int getAge() = 0;
        virtual void setName(std::string name) = 0;
        virtual void setSurname(std::string surname) = 0;
        virtual void setAge(int age) = 0;
        Person();
        Person(std::string name, std::string surname, int age);
};

Person::Person() {
    Name = "noName";
    Surname = "noSurname";
    Age = 0;
}

Person::Person(std::string name, std::string surname, int age){
    Name = name;
    Surname = surname;
    Age = age;
}

class Student: public Person{
    int Score;
    public:
        std::string getName(){
            return Name;
        }
        std::string getSurname(){
            return Surname;
        }
        int getAge(){
            return Age;
        }
        void setName(std::string name){
            Name = name;
        }
        void setSurname(std::string surname){
            Surname = surname;
        }
        void setAge(int age){
            Age = age;
        }
        Student(){
            Name = "noName";
            Surname = "noSurname";
            Age = 0;
            Score = 0;
        }
        Student(std::string name, std::string surname, int age, int score){
            setName(name);
            setSurname(surname);
            setAge(age);
            Score = score;
        }
        friend std::ostream &operator<< (std::ostream & os, Student A);
        friend std::istream &operator>> (std::istream & os, Student A);
        friend Student setter (std::string name, std::string surname, int age, int score);
};


std::ostream &operator<< (std::ostream & os, Student A){
    os << A.Name << " " << A.Surname << " " << A.Age << " " << A.Score << "\n";
    return os;
}

Student setter (std::string name, std::string surname, int age, int score){
    return Student(name, surname, age, score);
}

std::istream &operator>> (std::istream & os, Student A){
    std::string name;
    std::string surname;
    int age, score;
    os >> name >> surname >> age >> score;
    A = setter(name, surname, age, score);
    return os;
}

class Tutor: public Person{
    int Salary;
    public:
        std::string getName(){
            return Name;
        }
        std::string getSurname(){
            return Surname;
        }
        int getAge(){
            return Age;
        }
        void setName(std::string name){
            Name = name;
        }
        void setSurname(std::string surname){
            Name = surname;
        }
        void setAge(int age){
            Age = age;
        }
         Tutor(){
            Name = "noName";
            Surname = "noSurname";
            Age = 
            Salary = 0;
        }
        Tutor(std::string name, std::string surname, int age, int salary){
            setName(name);
            setSurname(surname);
            setAge(age);
            Salary = salary;
        }
        friend std::ostream &operator<< (std::ostream & os, Tutor A);
        friend std::istream &operator>> (std::istream & os, Tutor A);
        friend Tutor Setter (std::string name, std::string surname, int age, int salary);

};

std::ostream &operator<< (std::ostream & os, Tutor A){
    os << A.Name << " " << A.Surname << " " << A.Age << " " << A.Salary << "\n";
    return os;
}

Tutor Setter (std::string name, std::string surname, int age, int salary){
    return Tutor(name, surname, age, salary);
}

std::istream &operator>> (std::istream & os, Tutor A){
    std::string name;
    std::string surname;
    int age, salary;
    os >> name >> surname >> age >> salary;
    A = Setter(name, surname, age, salary);
    return os;
}
/*
std::string getName(){
    return Name;
}

std::string getSurname(){
    return Surname;
}

int getAge(){
    return Age;
}

void setName(std::string name){
    Name = name;
}

void setSurname(std::string surname){
    Name = surname;
}
        
void setAge(int age){
    Age = age;
}
*/
