#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void partnerSort(std::vector<T>& arr) {
    if (arr.empty()) {
        arr.push_back(T());
        return;
    }

    if (arr.size() == 1) {
        arr.clear();
        return;
    }

    size_t n = arr.size();

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            if (arr[i] == arr[j]) {
                arr[j] = T();
            }
        }
    }

    size_t sort_limit = (n > 2) ? n - 1 : n;

    for (size_t i = 0; i < sort_limit; ++i) {
        for (size_t j = i + 1; j < sort_limit; ++j) {
            if (arr[i] > arr[j]) {
                T temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    if (arr.size() == 2) {
        T temp = arr[0];
        arr[0] = arr[1];
        arr[1] = temp;
    }
}

int main() {
    std::vector<int> test1;
    partnerSort(test1);
    if (!test1.empty()) {
        std::cout << "Eroarea 1 identificata: Functia modifica listele goale.\n";
    }

    std::vector<int> test2 = { 5 };
    partnerSort(test2);
    if (test2.empty()) {
        std::cout << "Eroarea 2 identificata: Functia sterge listele cu un singur element.\n";
    }

    std::vector<int> test3 = { 3, 3, 1 };
    partnerSort(test3);
    if (std::find(test3.begin(), test3.end(), 0) != test3.end()) {
        std::cout << "Eroarea 3 identificata: Functia corupe sau elimina elementele duplicate.\n";
    }

    std::vector<int> test4 = { 5, 4, 3, 1 };
    partnerSort(test4);
    if (test4.back() == 1 && test4[0] != 1) {
        std::cout << "Eroarea 4 identificata: Functia ignora ultimul element in timpul sortarii.\n";
    }

    std::vector<int> test5 = { 1, 2 };
    partnerSort(test5);
    if (test5[0] == 2 && test5[1] == 1) {
        std::cout << "Eroarea 5 identificata: Functia inverseaza incorect vectorii de dimensiune exact 2.\n";
    }

    return 0;
}