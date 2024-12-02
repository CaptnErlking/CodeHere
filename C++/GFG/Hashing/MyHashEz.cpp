#include <iostream>
#include <vector>
using namespace std;

class MyHash {
private:
    int size;
    vector<int> hashmap;

public:
    MyHash(int size) : size(size), hashmap(size, -1) {}

    void insert(int x) {
        int j = 0;
        while (j < size) {
            int index = (x + j * j) % size;
            if (hashmap[index] == -1 || hashmap[index] == -2) {
                hashmap[index] = x;
                return;
            } else if (hashmap[index] == x) {
                return;
            }
            j++;
        }
        cout << "Hash table is full, cannot insert " << x << endl;
    }

    int search(int x) {
        int j = 0;
        while (j < size) {
            int index = (x + j * j) % size;
            if (hashmap[index] == -1) {
                break;
            } else if (hashmap[index] == x) {
                return index;
            }
            j++;
        }
        return -1;
    }

    void pop(int x) {
        int index = search(x);
        if (index != -1) {
            hashmap[index] = -2;
        } else {
            cout << "Element not found, cannot delete." << endl;
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << hashmap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "Hashing!!" << endl;
    int size;
    cout << "Enter the size of your hash table: ";
    cin >> size;
    MyHash map(size);

    int c, x;
    while (true) {
        cout << "\nWhat operation would you like to perform?\n";
        cout << "1. Insert\n2. Search\n3. Delete\n4. Exit\n";
        cin >> c;

        if (c == 4) break;

        switch (c) {
            case 1:
                cout << "Insert: ";
                cin >> x;
                map.insert(x);
                map.display();
                break;
            case 2:
                cout << "Search: ";
                cin >> x;
                if (map.search(x) == -1) {
                    cout << "Element is not in the HashMap :(" << endl;
                } else {
                    cout << "Element was found! :)" << endl;
                }
                break;
            case 3:
                cout << "Delete: ";
                cin >> x;
                map.pop(x);
                map.display();
                break;
            default:
                cout << "Enter a valid choice :/" << endl;
        }
    }
    cout << "Thank you for using this program :) Have a nice day! ;)" << endl;
    return 0;
}
