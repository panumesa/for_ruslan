#include <iostream>
using namespace std;
class ccvector{
public:
    double * arr = nullptr;
    int sz = 0;
    int cap = 0;; 
public:
    cvector() = default ;
    cvector(int n):arr(new double[n]),sz(n){}
    cvector(const cvector& other){  //copy-constructor
        sz = other.sz;
        arr = new double[sz];
        std::copy(other.arr, other.arr + other.sz,arr);
    }
    double& operator[](int x){
        return arr[x];
    }
    int size() const{
        return sz;
    }
    cvector& operator=(const cvector& other){
        cvector tmp = other;
        this->swap(tmp);
        return *this;
    }
    cvector& operator+=(const cvector& other){
        if(arr == nullptr || other.arr == nullptr || sz != other.sz || sz == 0){
            throw std::runtime_error("bad sz");
        }
        for (int i = 0; i < sz; ++i) {
            arr[i]+=other.arr[i];
        }
        return *this;
    }
    cvector operator+(const cvector& other) const{
        cvector tmp = *this;
        return tmp+=other;
    }
    cvector& operator-=(const cvector& other){
        if(arr == nullptr || other.arr == nullptr || sz != other.sz || sz == 0){
            throw std::runtime_error("bad sz");
        }
        for (int i = 0; i < sz; ++i) {
            arr[i] -= other.arr[i];
        }
        return *this;
    }
    cvector operator-(const cvector& other) const{
        cvector tmp = *this;
        return tmp -= other;
    }
    void swap(cvector& other){ //
        std::swap(sz,other.sz);
        std::swap(arr, other.arr);
    }
    double operator*(const cvector& b) {
        if (arr == nullptr || b.arr == nullptr || sz != b.sz || sz == 0) {
            throw std::runtime_error("bad sz");
        }
        double sum = 0;
        for (int i = 0; i < sz; ++i) {
            sum += arr[i] * b.arr[i];
        }
        return sum;
    }
//    friend double operator()(const cvector &a, const cvector&b);
    friend std::ostream& operator<<(std::ostream& out , const cvector& a);
    ~cvector(){
        delete[] arr;
    }
};
std::ostream& operator<<(std::ostream& out , const cvector&a){
    for (int i = 0; i < a.sz; ++i) {
        out << a.arr[i] << ' ';
    }
    return out;
}



int main() {
    int n;
    cin >> n;
    cvector a(n);
    cvector b;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    b = a;
    cvector c = a;
    cout << a << '\n' << b << '\n' << c << '\n';
    cout << a + b <<'\n' << a - b << '\n' << a * b << '\n';
    cout << (a += b) << '\n'<< (a -=b)<< '\n' << (a[0] +1243);
    return 0;
}
