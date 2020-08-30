#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        char data;
        unordered_map<char, Node*> children;
        bool terminal;
        Node(char ch)
        {
            data = ch;
            terminal = false;
        }
};

class Trie{
    Node* root;
    int cnt;

    public:
        Trie()
        {
            root = new Node('\0');
            cnt = 0;
        }

        void insertIntoTrie(string word)
        {
            int n = word.length();
            Node* temp = root;
            for(int i = 0 ; i < n ; i++)
            {
                char curCh = word[i];
                if (temp->children.find(curCh) == temp->children.end())
                {
                    Node* curChNode = new Node(curCh);
                    temp->children[curCh] = curChNode;
                    temp = curChNode;
                }
                else
                {
                    temp = temp->children[curCh];
                }
            }
            temp->terminal = true;
        }

        bool searchInTrie(string word)
        {
            int n = word.length();
            Node* temp = root;
            for(int i = 0 ; i < n ; i++)
            {
                char curCh = word[i];
                if (temp->children.find(curCh) == temp->children.end())
                    return false;
                else
                    temp = temp->children[curCh];
            }
            return temp->terminal;
        }
};

signed main() {
    Trie trie;
    int no;
    cin >> no;
    while(no--)
    {
        string word;
        cin >> word;
        trie.insertIntoTrie(word);
    }

    cout << trie.searchInTrie("Vivek") << "\n";
}
