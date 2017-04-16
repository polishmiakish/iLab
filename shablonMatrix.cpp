#include "shablonArray.cpp"
#define length 3
#define width 3

template <typename T, int m>

class Matrix{
private:
    T elem[m][m];
public:
    Matrix();
    template <typename T1, int m1> friend Matrix<T1, m1> operator+ (Matrix<T1, m1> A, Matrix<T1, m1> B);
    template <typename T1, int m1> friend std::ostream & operator << (std::ostream &os, Matrix<T1, m1> A);
    template <typename T1, int m1> friend Matrix<T1, m1> operator * (Matrix<T1, m1> A, Matrix<T1, m1> B);
    void set_elem(int a, int b, T c);
    T get_elem(int a, int b);
};
template <typename T, int m>
Matrix<T, m>::Matrix(){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            elem[i][j] = i * m + j;
        }
    }
}
template <typename T, int m>
void Matrix<T, m>::set_elem(int a, int b, T c){
    elem[a][b] = c;
}

template <typename T, int m>
T Matrix<T, m> ::get_elem(int a, int b){
    return elem[a][b];
}

template <typename T, int m>
Matrix<T, m> operator+ (Matrix<T, m> A, Matrix<T, m> B){
    Matrix<T, m> *C = new Matrix<T, m> ();
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            C->set_elem(i, j, A.get_elem(i, j) + B.get_elem(i, j));
        }
    }
    return *C;
}

template <typename T, int m>
std::ostream & operator << (std::ostream &os, Matrix<T, m> A){
    T c;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            c = A.get_elem(i, j);
            os << c << " ";
        }
        os << std::endl;
    }
    os << std::endl;
    return os;
}

class DividErr{};

template <typename T, int m>
Matrix<T, m> operator * (Matrix<T, m> A, Matrix<T, m> B){
    Matrix<T, m> * A = new Matrix<T, m> ();
    Matrix<T, n> * B = new Matrix<T, n> ();
    try{
        for (i = 0; i < m; i++){
            for (j = 0; j < n; j++){
                A.elem[i][j]
            }
        }
        return A * B;
    }
    catch (int a){
    }
    catch (DividErr){
    }
}
