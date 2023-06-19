#pragma once
#include <iostream>
#include <set>
#include <vector>
template <typename T>
class Vector {
private:
    std::multiset<T> container;

public:
    void addElements3(const std::vector<T>& elements) {
        for (const auto& element : elements) {
            container.insert(element);
        }
    }

    void removeElement3(const T& key) {
        auto it = container.find(key);
        if (it != container.end()) {
            container.erase(it);
            std::cout << "Ýëåìåíò " << key << " óäàëåí èç êîíòåéíåðà.\n";
        }
        else {
            std::cout << "Ýëåìåíò " << key << " íå íàéäåí â êîíòåéíåðå.\n";
        }
    }

    void performTask3() {
        if (container.empty()) {
            std::cout << "Êîíòåéíåð ïóñò. Äîáàâüòå ýëåìåíòû ïåðåä âûïîëíåíèåì çàäàíèÿ.\n";
            return;
        }

        const T& minElement = *container.begin();

        container.insert(minElement);

        T keyElement; 
        auto keyIt = container.find(keyElement);
        if (keyIt != container.end()) {
            container.erase(keyIt);
            std::cout << "Ýëåìåíò ñ êëþ÷îì " << keyElement << " óäàëåí èç êîíòåéíåðà.\n";
        }
        else {
            std::cout << "Ýëåìåíò ñ êëþ÷îì " << keyElement << " íå íàéäåí â êîíòåéíåðå.\n";
        }

        const T& maxElement = *container.rbegin();
        for (auto element : container) {
            element += minElement + maxElement;
        }
    }
};