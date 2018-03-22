#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

template<class T>
class dynamicArray {
    T* base;
    int used = 0;
    int size = 10;
public:
    dynamicArray(int);
    void resize();
    void allocate(int);
    void pop();
    void push(T&);
    void set(T&);
    T get(int);
    T begin();
    T end();
    int length();
    int capacity();
    int getUsed();
    void setUsed(int);
    int getSize();
    void setSize(int);
};

template<class T>
dynamicArray<T>::dynamicArray(int c) {
    allocate(c);
}

template<class T>
void dynamicArray<T>::resize() {
    T* ptemp = new T [size*2];
    for (int i = 0; i < used; i++) {
        ptemp[i] = base[i];
    }
    delete [] base;
    base = ptemp;
    int x = capacity();
    x = x *2;
    setSize(x);
}

template<class T>
void dynamicArray<T>::allocate(int c) {
    setSize(c);
    base = new T [c];
}

template<class T>
void dynamicArray<T>::pop() {

    for (int i = 1; i < used; i++) {
        base[i - 1] = base[i];
        if (i == used - 2) {
            used--;
        }
        if (used == 0) {
            cout << "The value of variable 'used' is 0" << endl;
            cout << "" << endl;
        }
    }
}

template<class T>
void dynamicArray<T>::push(T& item) {
    set(item);
}

template<class T>
void dynamicArray<T>::set(T& item) {
    if (used == size) {
        resize();
    }
    else {
    base[used] = item;
    used++;
    }
}

template<class T>
T dynamicArray<T>::get(int c) {
    return base[c];
}

template<class T>
T dynamicArray<T>::begin() {
    return base[0];
}

template<class T>
T dynamicArray<T>::end() {
    return base[used - 1];
}

template<class T>
int dynamicArray<T>::length() {
    return used;
}

template<class T>
int dynamicArray<T>::capacity() {
    return size;
}

template<class T>
int dynamicArray<T>::getUsed() {
    return used;
}

template<class T>
void dynamicArray<T>::setUsed(int c) {
    used = c;
}

template<class T>
int dynamicArray<T>::getSize() {
    return size;
}

template<class T>
void dynamicArray<T>::setSize(int c) {
    size = c;
}

template <class T>
class Node {
public:
  T item;
  Node<T>* next;
  Node<T>* prev;
  Node();
  Node(T data) {
    item = data;
    next = nullptr;
    prev = nullptr;
  }
};

template <class T>
class List {
  Node<T>* head;
  Node<T>* tail;
  int itemCount = 0;
public:
  List() {
    head = nullptr;
    tail = nullptr;
  };
  bool isEmpty() {
    Node<T>* temp;
    temp = head;
    if (temp == nullptr) {
      return true;
    }
    else {
      return false;
    }
  }
  bool add(T newEntry) {
// adds to end of list
    if (head == nullptr) {
      Node<T>* a = new Node<T>(newEntry);
      head = a;
      tail = a;
      itemCount++;
      return true;
    }
    else {
      Node<T>* b = new Node<T>(newEntry);
      tail->next = b;
      b->prev = tail;
      tail = b;
      itemCount++;
      return true;
    }
  }
  bool remove(T anEntry) {
    if (head == nullptr) {
      cout << "The list is empty, cannot remove" << endl;
      return false;
    }
    else if (head->item == anEntry) {
        delete head;
        cout << "The entry: " << anEntry << " has been successfully removed." << endl;
        return true;
    }
    else {
      Node<T>* temp;
      temp = head;
      int counter = 0;
      while (temp->item != anEntry) {
        temp = temp->next;
        counter++;
        if (counter > itemCount) {
          cout << "The list does not contain " << anEntry << endl;
          return false;
        }
      }
      Node<T>* n;
      n = temp->prev;
      n->next = temp->next;
      if (temp->next == nullptr) {
        delete temp;
        tail = n;
        itemCount--;
        cout << "The entry: " << anEntry << " has been successfully removed." << endl;
        return true;
      }
      else {
        delete temp;
        itemCount--;
        cout << "The entry: " << anEntry << " has been successfully removed." << endl;
        temp->next->prev = n;
        return true;
      }
    }
  }
  void clear() {
    Node<T>* n;
    n = head;
    while (n) {
      cout << n->item << endl;
      if(n->prev) {
        delete n->prev;
      }
      n = n->next;
    }
    delete n;
    head = nullptr;
    tail = nullptr;
    itemCount = 0;
    cout << "The array has been successfully cleared" << endl;
  }
  int getFrequencyOf(T anEntry) {
    int counter = 0;
    Node<T>* a;
    a = head;
    for (int i = 0; i < itemCount; i++) {
        if (a->item == anEntry) {
            counter++;
        }
        a = a->next;
    }
    return counter;
  }
  bool contains(T anEntry) {
    Node<T>* a;
    a = head;
    for (int i = 0; i < itemCount; i++) {
        if (a->item == anEntry) {
            return true;
        }
        a = a->next;
    }
    return false;
  }
  int returnCount() {
    return itemCount;
  }
  T returnHead() {
    return head->item;
  }
  T returnTail() {
    return tail->item;
  }

  Node<T>* getHead() {
    return head;
  }
  Node<T>* getTail() {
    return tail;
  }
  void print() {
    Node<T>* a;
    a = head;
    for (int i = 0; i < itemCount; i++) {
      cout << a->item << endl;
      a = a->next;
    }
  }
  void printReverse() {
    Node<T>* a;
    a = tail;
    for (int i = 0; i < itemCount; i++) {
      cout << a->item << endl;
      a = a->prev;
    }
  }
};

void radixSort(string l) {
    dynamicArray< List<char> > buckets(36);

    for(auto c: l) {
        if(isdigit(c)) {
            int t = c;
            auto g = buckets.get(t);
            g.add(c);
            g.print();
        }
        else {
            int t = (int)c - 87;
            auto g = buckets.get(t);
            g.add(c);
            g.print();
        }
    }

    string result = "";
    for(int i = 0; i < 36; i++) {
        buckets.get(i).print();
        /*auto a = buckets.get(i);
        Node<char>* head = a.getHead();
        for(int j = 0; j < a.returnCount(); j++) {
            result += head->item;
            head = head->next;
        }
        */
    }
    cout << result << endl;

}
int main() {
    dynamicArray<string> xyz(10);
    string line;

    ifstream infile;
    infile.open("words.txt");
    while (!infile.eof()) {
        getline(infile, line);
        xyz.push(line);
    }
    infile.close();

    for(int i = 0; i < xyz.getSize(); i++) {
       radixSort(xyz.get(i));
    }
    return 0;
}
