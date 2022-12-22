#include<bits/stdc++.h>

using namespace  std;

template<class T>
class _set{
    private:
        vector<T> data;
    public:
        _set() = default;
        ~_set() = default;

        void insert(const T& rhs);
        void remove(const T& rhs);
        bool exist(const T& rhs);
        T* PointerToData() const;
        int size () const;
        void print()const;
};


template<class T>
void _set<T>::insert(const T &rhs) {
    if(exist(rhs))
        return ;
    else data.emplace_back(rhs);
}

template<class T>
void _set<T>::remove(const T &rhs) {
    auto it = find(data.begin(), data.end(), rhs);
    data.erase( it);
}

template<class T>
bool _set<T>::exist(const T &rhs) {
    return (count(data.begin(), data.end(), rhs));
}

template<class T>
int _set<T>::size() const {
    return data.size();
}

template<class T>
void _set<T>::print() const {
    for(const auto& i: data)
        cout << i << ' ';

}

template<class T>
T *_set<T>::PointerToData() const {

    T* ptr = new T[data.size()];
    for(int i = 0; i < data.size(); i++)
        ptr[i] = data[i];

    return ptr;
}

int main(){
    _set<int> s;
    s.insert(1);
    s.insert(12);
    s.insert(3);
    s.insert(4);
    s.insert(200);

    int* ptr = s.PointerToData();
    for(int i = 0;i < s.size() ; i++){
        cout <<ptr[i + 10] << ' ';
    }

}
