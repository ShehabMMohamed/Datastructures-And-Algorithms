#include <iostream>
using namespace std;

// Basic HashTable in C++ (Without Collision Handling).
template <typename KeyType, typename DataType>
class HashTable {
private:
   DataType **A;
   int size;
    int hash(int _key) { return _key % size; }
    int hash(char _key) { return (_key - '0') % size; }
    int hash(double _key) { return _key % size; }
    int hash(float _key) { return _key % size; }
    int hash(string _key) {
        int hashedKey = 0;
        for(char c : _key) {
            hashedKey += c - '0';
        }
        return hashedKey % size;
    }

    bool keyExists(KeyType _key) {
        int hashedKey = hash(_key);
        return A[hashedKey] != nullptr;
    }
public:
    HashTable(const int _size) : size(_size) {
        A = new DataType*[size];
        for(int i = 0; i < size; i++) {
            A[i] = nullptr;
        }
    }
    void Insert(KeyType k, DataType v) {
        int hashedKey = hash(k);
        A[hashedKey] = new DataType(v);
    }
    void Delete(KeyType k) {
        if(!keyExists(k)) {
            cout<<"Key: "<<k<<" does not exist."<<endl;
            return;
        }
        cout<<"Deleting with key: "<<k<<endl;
        int hashedKey = hash(k);
        A[hashedKey] = nullptr;
    }
    DataType Get(KeyType k) {
        if(!keyExists(k)) {
            cout<<"Key: "<<k<<" does not exist."<<endl;
            return DataType();
        }
        int hashedKey = hash(k);
        return *A[hashedKey];
    }
    void DisplayTable() {
        cout<<"\nHash Table Content...\n";
        for(int i = 0; i < size; i++) {
            if(A[i] == nullptr) {
                cout<<"Key: "<<i<<", Value: [...Empty...]"<<endl;
            }
            else {
                cout<<"Key: "<<i<<", Value: ["<<*A[i]<<"]"<<endl;
            }
        }
        cout<<endl;
    }
    ~HashTable() {
        for(int i = 0; i < size; i++) {
            delete A[i];
        }
        delete []A;
    }
};
