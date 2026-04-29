#include <stdio.h>

template <typename K, typename V>
class Map {
public:
    struct Element {
        K key;
        V value;
        int index;
    };

    class Iterator {
    private:
        Element* ptr;
    public:
        Iterator(Element* p) : ptr(p) {}

        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }

        void operator++() {
            ptr++;
        }

        Element& operator*() {
            return *ptr;
        }
    };

private:
    Element* elements;
    int capacity;
    int count;

    void resize() {
        capacity *= 2;
        Element* newData = new Element[capacity];
        for (int i = 0; i < count; i++) {
            newData[i] = elements[i];
        }
        delete[] elements;
        elements = newData;
    }

public:
    Map() {
        capacity = 10;
        count = 0;
        elements = new Element[capacity];
    }

    ~Map() {
        delete[] elements;
    }

    V& operator[](const K& key) {
        for (int i = 0; i < count; i++) {
            if (elements[i].key == key) {
                return elements[i].value;
            }
        }

        if (count == capacity) {
            resize();
        }

        elements[count].key = key;
        elements[count].index = count;
        count++;

        return elements[count - 1].value;
    }

    void Set(const K& key, const V& value) {
        (*this)[key] = value;
    }

    bool Get(const K& key, V& value) const {
        for (int i = 0; i < count; i++) {
            if (elements[i].key == key) {
                value = elements[i].value;
                return true;
            }
        }
        return false;
    }

    int Count() const {
        return count;
    }

    void Clear() {
        count = 0;
    }

    bool Delete(const K& key) {
        for (int i = 0; i < count; i++) {
            if (elements[i].key == key) {
                for (int j = i; j < count - 1; j++) {
                    elements[j] = elements[j + 1];
                    elements[j].index = j;
                }
                count--;
                return true;
            }
        }
        return false;
    }

    bool Includes(const Map<K, V>& map) const {
        for (int i = 0; i < map.count; i++) {
            bool found = false;
            for (int j = 0; j < count; j++) {
                if (elements[j].key == map.elements[i].key) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }

    Iterator begin() const {
        return Iterator(elements);
    }

    Iterator end() const {
        return Iterator(elements + count);
    }
};

int main() {
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto [key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";

    for (auto [key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    return 0;
}