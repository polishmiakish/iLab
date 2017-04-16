#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

void print(int num){
    std::cout << num << " ";
}

void dump(int num){
    std::cout << num << " ";
}
int main(){
    std::vector<int>::iterator first, last;
    std::vector<int> A;
    A.push_back(4);
    A.push_back(16);
    A.push_back(15);
    first = A.begin();
    last = A.end();
    //for_each(first, last, dump);
    std::set <int> B;
    for (int i = 0; i < A.size(); i++){
        if (A[i] % 2 == 0) {
            //std::cout << A[i] << std::endl;
            B.insert(A[i]);
        }
    }
    
    std::set<int>::iterator First, Last;
    First = B.begin();
    Last = B.end();
    //std::cout << *First << " " << *Last;
    for_each(First, Last, print);
    return 0;
}
