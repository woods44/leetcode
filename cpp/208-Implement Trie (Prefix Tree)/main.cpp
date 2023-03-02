#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

class Trie
{
public:
    unordered_set<string> word;
    Trie()
    {
        this->word;
    }

    void insert(string word)
    {
        this->word.insert(word);
    }

    bool search(string word)
    {
        return this->word.find(word) != this->word.end();
    }

    bool startsWith(string prefix)
    {
        for (const auto &it : this->word)
        {
            if (it.size() >= prefix.size() && it.compare(0, prefix.size(), prefix) == 0)
            {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{
    Trie t;
    t.insert("apple");
    cout << t.search("apple") << endl;
    cout << t.startsWith("pp") << endl;
}