#include <iostream>
#include <exception>

using namespace std;

class IndexOutOfBoundsException : public exception
{
    virtual const char* what() const throw()
    {
        return "Index is out of bounds!";
    }
};

class InvalidCapacityException : public exception
{
    virtual const char* what() const throw()
    {
        return "Capacity must be greater than or equal to 0!";
    }
};

class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator
{
private:
    int Current;
    T** Elements;
    int Size;

public:
    ArrayIterator() : Current(0), Elements(nullptr), Size(0) {}

    ArrayIterator(T** elements, int size, int start)
        : Elements(elements), Size(size), Current(start) {
    }

    ArrayIterator& operator ++ ()
    {
        if (Current < Size) Current++;
        return *this;
    }

    ArrayIterator& operator -- ()
    {
        if (Current > 0) Current--;
        return *this;
    }

    bool operator= (const ArrayIterator<T>& other)
    {
        Current = other.Current;
        Elements = other.Elements;
        Size = other.Size;
        return true;
    }

    bool operator!=(const ArrayIterator<T>& other)
    {
        return Current != other.Current;
    }

    T* GetElement()
    {
        if (Current >= 0 && Current < Size)
            return Elements[Current];
        return nullptr;
    }
};

template<class T>
class Array
{
private:
    T** List;
    int Capacity;
    int Size;

    void EnsureCapacity(int needed)
    {
        if (needed <= Capacity) return;
        int newCap = (Capacity == 0) ? 2 : Capacity * 2;
        while (newCap < needed) newCap *= 2;

        T** newList = new T * [newCap];
        for (int i = 0; i < Size; i++)
        {
            newList[i] = List[i];
        }
        delete[] List;
        List = newList;
        Capacity = newCap;
    }

public:
    Array() : List(nullptr), Capacity(0), Size(0) {}

    ~Array()
    {
        for (int i = 0; i < Size; i++) {
            delete List[i];
        }
        delete[] List;
    }

    Array(int capacity) : Size(0)
    {
        if (capacity < 0) throw InvalidCapacityException();
        Capacity = capacity;
        List = new T * [Capacity];
    }

    Array(const Array<T>& otherArray)
    {
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];
        for (int i = 0; i < Size; i++) {
            List[i] = new T(*(otherArray.List[i]));
        }
    }

    T& operator[] (int index)
    {
        if (index < 0 || index >= Size)
            throw IndexOutOfBoundsException();
        return *(List[index]);
    }

    const Array<T>& operator+=(const T& newElem)
    {
        EnsureCapacity(Size + 1);
        List[Size++] = new T(newElem);
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElem)
    {
        if (index < 0 || index > Size)
            throw IndexOutOfBoundsException();

        EnsureCapacity(Size + 1);
        for (int i = Size; i > index; i--) {
            List[i] = List[i - 1];
        }
        List[index] = new T(newElem);
        Size++;
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T> otherArray)
    {
        if (index < 0 || index > Size)
            throw IndexOutOfBoundsException();

        EnsureCapacity(Size + otherArray.Size);
        for (int i = Size - 1; i >= index; i--) {
            List[i + otherArray.Size] = List[i];
        }
        for (int i = 0; i < otherArray.Size; i++) {
            List[index + i] = new T(*(otherArray.List[i]));
        }
        Size += otherArray.Size;
        return *this;
    }

    const Array<T>& Delete(int index)
    {
        if (index < 0 || index >= Size)
            throw IndexOutOfBoundsException();

        delete List[index];
        for (int i = index; i < Size - 1; i++) {
            List[i] = List[i + 1];
        }
        Size--;
        return *this;
    }

    bool operator=(const Array<T>& otherArray)
    {
        if (this == &otherArray) return true;

        for (int i = 0; i < Size; i++) delete List[i];
        delete[] List;

        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];
        for (int i = 0; i < Size; i++) {
            List[i] = new T(*(otherArray.List[i]));
        }
        return true;
    }

    void Sort()
    {
        for (int i = 0; i < Size - 1; i++) {
            for (int j = i + 1; j < Size; j++) {
                if (*(List[i]) > *(List[j])) {
                    T* temp = List[i];
                    List[i] = List[j];
                    List[j] = temp;
                }
            }
        }
    }

    void Sort(int(*compare)(const T&, const T&))
    {
        for (int i = 0; i < Size - 1; i++) {
            for (int j = i + 1; j < Size; j++) {
                if (compare(*(List[i]), *(List[j])) > 0) {
                    swap(List[i], List[j]);
                }
            }
        }
    }

    void Sort(Compare* comparator)
    {
        for (int i = 0; i < Size - 1; i++) {
            for (int j = i + 1; j < Size; j++) {
                if (comparator->CompareElements(List[i], List[j]) > 0) {
                    swap(List[i], List[j]);
                }
            }
        }
    }

    int BinarySearch(const T& elem)
    {
        int l = 0, r = Size - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (*(List[mid]) == elem) return mid;
            if (*(List[mid]) < elem) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }

    int Find(const T& elem)
    {
        for (int i = 0; i < Size; i++) {
            if (*(List[i]) == elem) return i;
        }
        return -1;
    }

    int GetSize() { return Size; }
    int GetCapacity() { return Capacity; }

    ArrayIterator<T> GetBeginIterator()
    {
        return ArrayIterator<T>(List, Size, 0);
    }

    ArrayIterator<T> GetEndIterator()
    {
        return ArrayIterator<T>(List, Size, Size);
    }
};

int main()
{
    try
    {
        Array<int> arr;

        arr += 10;
        arr += 20;
        arr += 30;

        cout << "Array size: " << arr.GetSize() << endl;

        arr.Insert(1, 15);
        cout << "Element at index 1: " << arr[1] << endl;

        cout << "\nAttempting to access arr[10]..." << endl;
        cout << arr[10] << endl;
    }
    catch (exception& e)
    {
        cout << "Exception Caught: " << e.what() << endl;
    }

    try
    {
        Array<int> arr2;
        arr2 += 1;

        cout << "\nAttempting to insert at index 5..." << endl;
        arr2.Insert(5, 100);
    }
    catch (exception& e)
    {
        cout << "Exception Caught: " << e.what() << endl;
    }

    cout << "\nIterating over elements:" << endl;
    Array<int> arr3;
    arr3 += 5;
    arr3 += 10;
    arr3 += 15;

    ArrayIterator<int> it = arr3.GetBeginIterator();
    ArrayIterator<int> endIt = arr3.GetEndIterator();

    while (it != endIt)
    {
        cout << *(it.GetElement()) << " ";
        ++it;
    }
    cout << endl;

    return 0;
}