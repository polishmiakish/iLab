#include <iostream>

class Drob{
    private:
        int N, M;
    public:
        Drob(int a, int b);
        ~Drob();
        int get_N();
        int get_M();
        void set_N(int a);
        void set_M(int a);
        friend Drob operator+ (Drob A, Drob B);
        friend Drob operator- (Drob A, Drob B);
        friend Drob operator* (Drob A, Drob B);
        friend Drob operator* (Drob A, int a);
        friend Drob operator/ (Drob A, Drob B);
        Drob operator= (Drob A);
        friend void Normal (Drob A);
        friend Drob makeEasy (Drob A);
        friend std::ostream & operator << (std::ostream &os, Drob A);
        friend std::istream & operator >> (std::istream &os, Drob &A);
};

Drob::Drob(int a, int b){
    N = a;
    M = b;
}

Drob::~Drob(){
}

int Drob::get_N(){
    return N;
}

int Drob::get_M(){
    return M;
}

void Drob::set_N(int a){
    N = a;
}

void Drob::set_M(int a){
    M = a;
}

Drob operator+ (Drob A, Drob B){
    return makeEasy(Drob(A.N * B.M + B.N * A.M, A.M * B.M)); 
}

Drob operator- (Drob A, Drob B){
    return makeEasy(Drob(A.N * B.M - B.N * A.M, A.M * B.M));
}

Drob operator* (Drob A, Drob B){
    return makeEasy(Drob(A.N * B.N, A.M * B.M));
}

Drob operator* (Drob A, int a){
    return makeEasy(Drob(a*A.N, A.M));
}

Drob operator/ (Drob A, Drob B){
    return makeEasy(Drob(A.N * B.M, A.M * B.N));
}

Drob Drob::operator= (Drob A){
    return makeEasy(Drob(A.N, A.M));
}

std::ostream & operator << (std::ostream &os, Drob A){
    os << A.get_N() << "/" << A.get_M() << std::endl;
    return os;
}

std::istream & operator >> (std::istream &os, Drob &A){
    int a, b;
    os >> a >> b;
    A.set_N(a);
    A.set_M(b);
    return os;
}

void Normal (Drob A){
    int C = 0;
    while (A.N > A.M){
        A.set_N(A.get_N() - A.get_M());
        C++;
    }
    if ((C != 0) && (A.get_N() != 0)){
        std::cout << C << " " << A;
    } else if (C == 0){
        std::cout << A;
    } else {
        std::cout << C;
    }
    std::cout << std::endl;
}

Drob makeEasy(Drob A){
    int D = 2, firstN = A.get_N();
    while (D <= firstN){
        if ((A.get_N() % D == 0) && (A.get_M() % D == 0)){
            A.set_N (A.get_N() / D);
            A.set_M (A.get_M() / D);
        } else
            D++;
    }
    return A;
}

/*int main(){
    Drob * A = new Drob (1, 2);
    std::cin >> *A;
    Drob * B = new Drob (1, 2);
    *B = (*A + *A/ *B);
    std::cout << *B << std::endl;
    Normal(*A * 5);
    return 0;
}*/
