#include <map>
#include <algorithm>
#include <iostream>

void func (std::pair <const std::string, int> A){
   std::cout << A.first << " " << A.second << std::endl;
}

int main(){
    std::map <std::string, int> A;
    std::map <std::string, int>::iterator first, last;
    A["begin"] = 5;
    A["word"] = 7;
    first = A.begin();
    last = A.end();
    for_each(first, last, func);
    return 0;
}


//в конец вектора добавить среднее арифм
//функция, выбираем из вектора четные элементы, упорядочиваем
//база данных студентов
