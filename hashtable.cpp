#include <iostream>
#include <list>
using namespace std;

class HashTables {
    private:
        static const int rows = 3;
        list<pair<int,string>> table[rows];
    public:
        HashTables() {
            // empty constructor
        } 
        
        HashTables(int key, string value) {
            int pos = hashFunction(key);
            table[pos].push_back({key, value});
        }
        
        bool isEmpty();
        int hashFunction(int key);
        void insertValue(int key, string value);
        void removeValue(int key);
        string searchTable(int key);
        void printTable();
};

bool HashTables :: isEmpty() {
    int sz{};
    for(int i=0; i<rows; i++) {
        sz += table[i].size();
    }
    return (sz == 0) ? true : false;
}

int HashTables :: hashFunction(int key) {
    return key % rows;
}

void HashTables :: insertValue(int key ,string value) {
    int pos = hashFunction(key);
    bool keyExists = false;
    for(auto i = table[pos].begin(); i != table[pos].end(); i++) {
        if(i->first == key) {
            keyExists = true;
            i->second = value;
            break;
        }
    }
    if(!keyExists) {
        table[pos].push_back({key,value});
    }
    return;
}

void HashTables :: removeValue(int k) {
    int pos = hashFunction(k);
    bool keyExists = false;
    for(auto i = table[pos].begin(); i != table[pos].end(); i++) {
        if(i->first == k) {
            keyExists = true;
            i = table[pos].erase(i);
            break;
        }
    }
    if(!keyExists) {
        cout<<"The element with this key does not exist!"<<"\n";
    }
    return;
}  

string HashTables :: searchTable(int key) {
    int pos = hashFunction(key);
    bool keyExists = false;
    auto& element = table[pos];

    for(auto i = element.begin(); i != element.end(); i++) {
        if(i->first == key) {
            keyExists = true;
            return i->second;
        } 
    }
    
    if(!keyExists) {
        cout<<"The key does not exist!"<<"\n";
    }
    return "~";
}

void HashTables :: printTable() {
    if(isEmpty()) {
        cout<<"The table is empty!"<<"\n";
        return;
    }
    
    for(int i=0; i<rows; i++) {
        for(const pair<int,string> & x : table[i]) {
            cout<<x.first<<" "<<x.second<<"      ";
        }
        cout<<"\n";
    }
}

int main() {
	HashTables h(1,"Testing");
	// h.printTable();
    // cout<<"\n";
	h.insertValue(2,"Re-testing");
	// h.printTable();
    // cout<<"\n";
    h.insertValue(3,"Re-Re-testing");
	// h.printTable();
    // cout<<"\n";
    h.insertValue(4,"Re-Re-Re-testing");
	// h.printTable();

    h.insertValue(5,"tired of Re-testing");
	h.printTable();
    cout<<"\n";
    h.removeValue(2);
	h.printTable();
    // cout<<"\n";
    string s = h.searchTable(2);
	if(s != "~") {
        cout<<s<<"\n";
    }
    // cout<<"\n";
	return 0;
}

