#include <iostream>

//1. реализовать класс время, есть часы минуты секунды, конструкторы с проверкой корректности, реализовать исключения (напр., 70 секунд - ошибка)
//Сделать пустой, от трех значений, для времени от секунд, которые надо бует переводить
//Операторы сложения и вычитания, метод возвращающий число секунд, часть методов следать методами класса, часть фрэндами(аналогично число часов и минут)

class Time{
    int hours;
    int minutes;
    int seconds;
public:
    Time(){
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    Time(int a, int b, int c){
        hours = a;
        minutes = b;
        seconds = c;
    }
    Time(int a){
        int t = a;
        hours = (int) (t/3600);
        t = t % 3600;
        minutes = (int) (t/60);
        t = t % 60;
        seconds = t;
    }
    void dumpTime(){
        std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
    }
    friend Time operator+ (Time A, Time B);
    friend Time operator- (Time A, Time B);
    friend int Seconds(Time A);
    friend double Minutes(Time A);
    friend double Hours(Time A);
    friend int getHours(Time A);
    friend int getMinutes(Time A);
    friend int getSeconds(Time A);
};

int getHours(Time A){
    return A.hours;
}

int getMinutes(Time A){
    return A.minutes;
}

int getSeconds(Time A){
    return A.seconds;
}

int Seconds(Time A){
    return (A.hours * 3600 + A.minutes * 60 + A.seconds);
}

double Minutes(Time A){
    double s = ((double)Seconds(A)/60);
    return s;
}

double Hours(Time A){
    double s = Minutes(A)/60;
    return s;
}

Time operator+ (Time A, Time B){
    int s;
    s = (A.seconds + B.seconds) + (A.minutes + B.minutes) * 60 + (A.hours + B.hours) * 3600;
    return Time(s);
}

Time operator- (Time A, Time B){
    int s;
    s = (A.seconds - B.seconds) + (A.minutes - B.minutes) * 60 + (A.hours - B.hours) * 3600;
    if (s < 0)
        s = 86400 + s;
    return Time(s);
}

int main(){
    Time * A = new Time();
    Time * B = new Time(1, 2, 3);
    Time * C = new Time(70);
    Time * D = new Time(87000);
    try{
        if ((getHours(*C) > 23) || (getHours(*C) < 0))
            throw getHours(*C);
    }
    catch(int h){
        std::cout << "Error: C number of hours more than 23 or less than 0" <<std::endl;
    }

    try{
        if ((getHours(*B) > 23) || (getMinutes(*B) > 59) || (getSeconds(*C) > 59))
            throw getHours(*B);
    }
    catch(int h){
        std::cout << "Error: B wrong time format"<< std::endl;
    }
    
    try{
        if ((getHours(*D) > 23) || (getHours(*D) < 0)) 
            throw getHours(*D);
    }
    catch(int h){
        std::cout << "Error: D number of hours more than 23 or less than 0" <<std::endl;
    }
    
    (*A).dumpTime();
    (*B).dumpTime();
    (*C).dumpTime();
    
    try{
        if (getHours(*C + *B) > 23)
            throw getHours(*C + *B);
    }
    catch(int h){
        std::cout << "Error: C + B number of hours more than 23 or less than 0" <<std::endl;
    }

    std::cout << "C + B = ";
    (*C + *B).dumpTime();
    
    try{
        if (getHours(*C + *B) > 59)
            throw getHours(*C + *B);
    }
    catch(int h){
        std::cout << "Error: C - B number of hours more than 23 or less than 0" <<std::endl;
    }
    std::cout << "C - B = ";
    (*C - *B).dumpTime();
    std::cout << "C - hours = " << Hours(*C) << std::endl;
    std::cout << "B - minutes = " << Minutes(*B) << std::endl;
    return 0;
}
