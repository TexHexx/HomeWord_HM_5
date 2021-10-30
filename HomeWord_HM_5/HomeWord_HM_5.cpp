#include <iostream>
#include <unordered_set>
#include <set>
#include <array>
#include <forward_list>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

//firstTask
template<typename _InIt, typename T = typename _InIt::value_type>
void printUniqueElements(_InIt _begin, const _InIt& _end) {
    unordered_set<T> result;
    cout << "Unique elements: ";
    for_each(_begin, _end, [&result](const auto& element) { 
        if (result.find(element) == result.end()) {
            result.insert(element);
            cout << element << ", ";
        }
    });
    cout << endl;
};

void firstTask() {
    vector<string> vectorInfo{ "Hi"s, "Buy"s, "Hello"s, "Me"s, "You"s, "Buy"s, "Me"s, "Hi"s, "Here"s, "There"s, };
    printUniqueElements(vectorInfo.begin(), vectorInfo.end());
    list<string> listInfo{ "Hi"s, "Buy"s, "Hello"s, "Me"s, "You"s, "Buy"s, "Me"s, "Hi"s, "Here"s, "There"s, };
    printUniqueElements(listInfo.begin(), listInfo.end());
    array<string, 10> arrayInfo{ "Hi"s, "Buy"s, "Hello"s, "Me"s, "You"s, "Buy"s, "Me"s, "Hi"s, "Here"s, "There"s, };
    printUniqueElements(arrayInfo.begin(), arrayInfo.end());
    forward_list<string> flistInfo{ "Hi"s, "Buy"s, "Hello"s, "Me"s, "You"s, "Buy"s, "Me"s, "Hi"s, "Here"s, "There"s, };
    printUniqueElements(flistInfo.begin(), flistInfo.end());
};
//firstTask
//secondTask
void secondTask() {
    multimap<size_t, string> result;
    cout << "Enter a text:" << endl; 
    cout.flush();
    string text;
    getline(cin, text);
    istringstream iss(text);
    std::string sentance;
    while (getline(iss, sentance, '.'))
    {
        result.insert({ sentance.size(), sentance });
    }
    cout << "Found sentences:" << endl;
    for_each(result.begin(), result.end(), [](const auto& element) {
        cout << element.second << endl;
    });
};
//secondTask
int main() {
    firstTask ();
    secondTask();
}

