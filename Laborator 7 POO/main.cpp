#include <iostream>

constexpr float operator"" _Kelvin(unsigned long long k) {
    return static_cast<float>(k) - 273.15f;
}

constexpr float operator"" _Fahrenheit(unsigned long long f) {
    return (static_cast<float>(f) - 32.0f) * 5.0f / 9.0f;
}

constexpr float operator"" _Kelvin(long double k) {
    return static_cast<float>(k) - 273.15f;
}

constexpr float operator"" _Fahrenheit(long double f) {
    return (static_cast<float>(f) - 32.0f) * 5.0f / 9.0f;
}

template <typename T>
class Tree {
public:
    struct Node {
        T value;
        Node** children;
        int num_children;
        int capacity;
        Node* parent;

        Node(const T& val, Node* p = nullptr) : value(val), parent(p) {
            capacity = 2;
            num_children = 0;
            children = new Node * [capacity];
        }

        ~Node() {
            delete[] children;
        }

        void resize_if_needed() {
            if (num_children == capacity) {
                capacity *= 2;
                Node** new_children = new Node * [capacity];
                for (int i = 0; i < num_children; ++i) {
                    new_children[i] = children[i];
                }
                delete[] children;
                children = new_children;
            }
        }
    };

    Node* root;

    Tree() : root(nullptr) {}

    ~Tree() {
        if (root) {
            delete_node_recursive(root);
        }
    }

    Node* add_node(Node* parent, const T& value) {
        if (parent == nullptr) {
            if (root) {
                delete_node_recursive(root);
            }
            root = new Node(value, nullptr);
            return root;
        }
        else {
            Node* child = new Node(value, parent);
            parent->resize_if_needed();
            parent->children[parent->num_children++] = child;
            return child;
        }
    }

    Node* get_node(Node* parent, int index = 0) {
        if (parent == nullptr) return root;
        if (index >= 0 && index < parent->num_children) {
            return parent->children[index];
        }
        return nullptr;
    }

    void delete_node(Node* node) {
        if (!node) return;

        if (node->parent) {
            Node* p = node->parent;
            for (int i = 0; i < p->num_children; ++i) {
                if (p->children[i] == node) {
                    for (int j = i; j < p->num_children - 1; ++j) {
                        p->children[j] = p->children[j + 1];
                    }
                    p->num_children--;
                    break;
                }
            }
        }
        else if (node == root) {
            root = nullptr;
        }

        delete_node_recursive(node);
    }

    Node* find(Node* start, const T& param, bool (*cmp)(const T&, const T&)) {
        if (!start) start = root;
        if (!start) return nullptr;

        if (cmp(start->value, param)) {
            return start;
        }

        for (int i = 0; i < start->num_children; ++i) {
            Node* found = find(start->children[i], param, cmp);
            if (found) return found;
        }
        return nullptr;
    }

    Node* insert(Node* parent, const T& value, int index) {
        if (!parent) return nullptr;
        if (index < 0) index = 0;
        if (index > parent->num_children) index = parent->num_children;

        Node* child = new Node(value, parent);
        parent->resize_if_needed();

        for (int i = parent->num_children; i > index; --i) {
            parent->children[i] = parent->children[i - 1];
        }
        parent->children[index] = child;
        parent->num_children++;

        return child;
    }

    void sort(Node* node, bool (*cmp)(const T&, const T&) = nullptr) {
        if (!node) node = root;
        if (!node) return;

        for (int i = 0; i < node->num_children - 1; ++i) {
            for (int j = i + 1; j < node->num_children; ++j) {
                bool swap_needed = false;
                if (cmp) {
                    if (cmp(node->children[j]->value, node->children[i]->value)) {
                        swap_needed = true;
                    }
                }
                else {
                    if (node->children[j]->value < node->children[i]->value) {
                        swap_needed = true;
                    }
                }

                if (swap_needed) {
                    Node* temp = node->children[i];
                    node->children[i] = node->children[j];
                    node->children[j] = temp;
                }
            }
        }
    }

    int count(Node* node) {
        if (!node) node = root;
        if (!node) return 0;

        int total = node->num_children;
        for (int i = 0; i < node->num_children; ++i) {
            total += count(node->children[i]);
        }
        return total;
    }

private:
    void delete_node_recursive(Node* node) {
        if (!node) return;
        for (int i = 0; i < node->num_children; ++i) {
            delete_node_recursive(node->children[i]);
        }
        delete node;
    }
};

bool compare_values(const int& node_val, const int& search_val) {
    return node_val == search_val;
}

bool sort_desc(const int& a, const int& b) {
    return a > b;
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;

    std::cout << "300 Kelvin in Celsius: " << a << "\n";
    std::cout << "120 Fahrenheit in Celsius: " << b << "\n\n";

    Tree<int> tree;

    auto root = tree.add_node(nullptr, 10);
    auto child1 = tree.add_node(root, 30);
    auto child2 = tree.add_node(root, 20);
    auto child3 = tree.add_node(root, 40);

    tree.add_node(child1, 100);

    std::cout << "Numar total de descendenti de la radacina: " << tree.count(nullptr) << "\n";

    tree.insert(root, 25, 1);

    auto node25 = tree.get_node(root, 1);
    std::cout << "Nodul de la indexul 1 din radacina este: " << node25->value << "\n";

    std::cout << "Sortam copiii radacinii crescator\n";
    tree.sort(root, nullptr);
    for (int i = 0; i < root->num_children; ++i) {
        std::cout << tree.get_node(root, i)->value << " ";
    }
    std::cout << "\n";

    std::cout << "Cautam valoarea 100\n";
    auto found = tree.find(nullptr, 100, compare_values);
    if (found) {
        std::cout << "Nodul cu valoarea 100 a fost gasit\n";
    }

    std::cout << "Stergem nodul cu valoarea 30\n";
    auto node30 = tree.find(nullptr, 30, compare_values);
    tree.delete_node(node30);

    std::cout << "Numar curent de descendenti de la radacina dupa stergere: " << tree.count(nullptr) << "\n";

    return 0;
}