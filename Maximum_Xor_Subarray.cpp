#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node* left;
        Node* right;
        Node()
        {
            left = nullptr;
            right = nullptr;
        }
};

class Trie{
    Node* root;
    public:
        Trie()
        {
            root = new Node();
        }

        void insertIntoTrie(int n)
        {
            Node* temp = root;
            for(int i = 31 ; i >= 0 ; i--)
            {
                int bit = (n >> i) & 1 ;
                if (bit == 0)
                {
                    if (temp->left == nullptr)
                    {
                        Node* neww = new Node();
                        temp->left = neww;
                        temp = neww;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else 
                {
                    if (temp->right == nullptr)
                    {
                        Node* neww = new Node();
                        temp->right = neww;
                        temp = neww;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
        }

        int max_xor_helper(int num)
        {
            int current_max_xor = 0;
            Node* temp = root;
            for(int i = 31 ; i >= 0 ; i--)
            {
                int bit = (num >> i) & 1;
                if (bit == 0)
                {
                    if (temp->right != nullptr)
                    {
                        current_max_xor += (1 << i);
                        temp = temp->right;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else
                {
                    if (temp->left != nullptr)
                    {
                        current_max_xor += (1 << i);
                        temp = temp->left;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
            return current_max_xor;
        }

        int max_xor_subarray_finder(vector<int>& arr)
        {
            int n = arr.size();
            int max_xor = 0;
            for(int i = 0 ; i < n ; i++)
            {
                insertIntoTrie(arr[i]);
                int current_val_max_xor = max_xor_helper(arr[i]);
                max_xor = max(max_xor, current_val_max_xor);
            }
            return max_xor;
        }
};

signed main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &ele: arr)
        cin >> ele;
    vector<int> prefix_xor;
    int prefixXor = 0;
    for(int i = 0 ; i < n ; i++)
    {
        prefixXor = prefixXor ^ arr[i];
        prefix_xor.push_back(prefixXor);
    }
    Trie trie;
    cout << trie.max_xor_subarray_finder(prefix_xor) << "\n";
}
