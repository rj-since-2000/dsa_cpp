#include<bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
    int weight;
    TrieNode *chars[26];
};

void insertNodes(pair<string, int> arr[], int n, TrieNode *head) {
    for (int i = 0; i < n; i++) {
        string s = arr[i].first;
        int weight = arr[i].second;
        TrieNode *curr = head;
        for (int j = 0; j < s.size(); j++) {
            char c = s[j];
            int ascii = c;
            int index = ascii - 97;
            if (curr->chars[index]) {
                if (curr->chars[index]->weight < weight) {
                    curr->chars[index]->weight = weight;
                }
            } else {
                curr->chars[index] = new TrieNode();
                curr->chars[index]->weight = weight;
            }
            curr = curr->chars[index];
        }
    }
}

int maxWeight(TrieNode *head, string t) {
    TrieNode *curr = head;
    for (int j = 0; j < t.size(); j++) {
        char c = t[j];
        int ascii = c;
        int index = ascii - 97;
        if (!curr->chars[index]) {
            return -1;
        }
        curr = curr->chars[index];
    }
    return curr->weight;
}

int main() {

	int n, q;
    cin >> n >> q;
    pair<string, int> arr[n];
    for (int i = 0; i < n; i++) {
        string s;
        int weight;
        cin >> s >> weight;
        arr[i].first = s;
        arr[i].second = weight;
    }
    TrieNode *head = new TrieNode();
    head->weight = 0;
    insertNodes(arr, n, head);
    while (q--) {
        string t;
        cin >> t;
        cout << maxWeight(head, t) << endl;
    }
    return 0;
}

