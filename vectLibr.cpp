#include <iostream>
#include <vector>
#include <algorithm>

int S = 0;

void func(int num){
    S += num;
}

void dump(int num){
    std::cout << num << " ";
}

int main(){
    std::vector<int>::iterator first, last;
    std::vector<int> A;
    A.push_back(4);
    A.push_back(16);
    first = A.begin();
    last = A.end();
    for_each(first, last, dump);
    for_each(first, last, func);
    S = (int)(S / A.size());
    std::cout << S << " ";
    A.push_back(S);
    first = A.begin();
    last = A.end();
    for_each(first, last, dump);
    return 0;
}
