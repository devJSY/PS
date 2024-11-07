class Node
{
public:
    Node(char val)
    {
        Val = val;
        bLast = false;
    }
    char Val;
    unordered_map<char, Node*> Children;
    bool bLast;
};

class Trie
{
public:
    Trie() { root = new Node(0); }

    void insert(string word)
    {
        Node* TrieNode = root;
        for (int i = 0; i < word.size(); ++i)
        {
            // 자식중에 해당 문자가 존재하지 않은 경우
            if (TrieNode->Children.end() == TrieNode->Children.find(word[i]))
            {
                TrieNode->Children.insert(make_pair(word[i], new Node(word[i])));
            }
            TrieNode = TrieNode->Children[word[i]];
        }

        TrieNode->bLast = true;
    }

    bool search(string word)
    {
        Node* TrieNode = root;
        for (int i = 0; i < word.size(); ++i)
        {
            // 자식중에 해당 문자가 존재하지 않은 경우
            if (TrieNode->Children.end() == TrieNode->Children.find(word[i]))
            {
                return false;
            }

            TrieNode = TrieNode->Children[word[i]];
        }

        return TrieNode->bLast ? true : false;
    }

    bool startsWith(string prefix)
    {
        Node* TrieNode = root;
        for (int i = 0; i < prefix.size(); ++i)
        {
            // 자식중에 해당 문자가 존재하지 않은 경우
            if (TrieNode->Children.end() == TrieNode->Children.find(prefix[i]))
            {
                return false;
            }

            TrieNode = TrieNode->Children[prefix[i]];
        }

        return true;
    }

private:
    Node* root;
};
