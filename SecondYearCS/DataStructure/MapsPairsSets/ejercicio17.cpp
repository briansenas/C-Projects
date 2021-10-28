#include <iostream>
#include <list>
using namespace std;

template<typename T>
ostream &operator<<(ostream &out, const list<T> &obj) {
    out << "< ";
    for (typename list<T>::const_iterator it = obj.begin();
         it != obj.end(); it++) {
        out << *it << " ";
    }
    out << " >";
    return out;
}

template<typename T>
class vector_dinamico{
public:
    class iterator {
    public:
        using ValueType = T;
        using PointerType = ValueType *;
        using ReferenceType = ValueType &;

        iterator() : m_Ptr(0) {}

        iterator(typename list<T>::iterator ptr) : m_Ptr(ptr) {}

        iterator &operator++() {
            m_Ptr++;
            return *this;
        }

        iterator operator++(int) {
            iterator it;
            it.m_Ptr = this->m_Ptr;
            this->m_Ptr++;
            return it;
        }

        iterator &operator--() {
            m_Ptr--;
            return *this;
        }

        iterator operator--(int) {
            iterator it;
            it.m_Ptr = this->m_Ptr;
            this->m_Ptr--;
            return it;
        }

        ReferenceType operator[](int index) {
            for (int i = 0; i < index; i++) {
                m_Ptr++;
            }
            return *m_Ptr;
        }

        PointerType operator->() {
            return *m_Ptr;
        }

        ReferenceType operator*() {
            return *m_Ptr;
        }

        bool operator==(const iterator &other) const {
            return m_Ptr == other.m_Ptr;
        }

        bool operator!=(const iterator &other) const {
            return m_Ptr != other.m_Ptr;
        }

        friend class vector_dinamico<T>;

    private:
        typename list<T>::iterator m_Ptr;
    };

    iterator insert(iterator it, const T &x){
        if(it!=this->end())
            vec.insert(it.m_Ptr,x);
        return it;
    }

    iterator erase(iterator it){
        vec.erase(it.m_Ptr);
        return it;
    }

    iterator erase(int i){
        vector_dinamico<T>::iterator it;
        it.m_Ptr = vec.begin();
        for(int n = 0; n < i; n++)
            it++;
        vec.erase(it.m_Ptr);
        return it;
    }

    void push_back(const T &x){
        vec.push_back(x);
    }

    T &operator[](int i){
        vector_dinamico<T>::iterator it;
        it = this->begin();
        return it[i];
    }

    int size() const{
        return vec.size();
    }

    iterator begin() {
        vector_dinamico<T>::iterator it;
        it.m_Ptr = vec.begin();
        return it;
    }

    iterator end(){
        vector_dinamico<T>::iterator it;
        it.m_Ptr = vec.end();
        return it;
    }

    friend ostream& operator <<(ostream& out, const vector_dinamico<T>& obj){
        out << obj.vec;
        return out;
    }

private:
    list<T> vec;
};


int main() {
    //SAMPLES
    vector_dinamico<int> cad1;
    for(int i=0;i<10;i++){
        cad1.push_back(i);
    }
    //END SAMPLES
    cout << "############# Test Sample 1 ##############" << endl;
    cout << "Vector: " << cad1 << endl;
    cout << "Vector size: " << cad1.size() << endl;
    cout << "Remove value: " << 2 << endl;
    cad1.erase(2);
    cout << "Result: " << cad1 << endl;
    cout << "Vector size: " << cad1.size() << endl;
    cout << "Remove iterator in pos 1 " << endl;
    vector_dinamico<int>::iterator it = cad1.begin();
    it++;
    cad1.erase(it);
    cout << "Result: " << cad1 << endl;
    cout << "Vector size: " << cad1.size() << endl;
    cout << "Insert iterator in pos 1 the value 10" << endl;
    it = cad1.begin();
    it++;
    it = cad1.insert(it,10);
    cout << "Result: " << cad1 << endl;
    cout << "Accedemos a Vector[2]: " << cad1[2] << endl;
    cout << "############# End Test Sample ##############" << endl;
}