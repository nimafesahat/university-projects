#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct Page
{
    int data;
    Page *next;
    explicit Page(int d) : data(d), next(nullptr) {}
};

struct Word
{
    string data;
    Word *next;
    Page *page;
    explicit Word(string d) : data(d), next(nullptr), page(nullptr) {}
};

struct Letter
{
    char data;
    Letter *next;
    Word *firstword;
    explicit Letter(char d) : data(d), next(nullptr), firstword(nullptr) {}
};

class PageList
{
private:
    struct Page *start;

public:
    PageList() : start(nullptr) {}

    int IsEmpty()
    {
        if (start == nullptr)
        {
            return 1;
        }
        return 0;
    }

    struct Page *insert(int d)
    {
        Page *n = new Page(d);
        if (IsEmpty())
        {
            start = n;
        }
        else
        {
            Page *cur = start;
            while (cur->next)
            {
                cur = cur->next;
            }
            cur->next = n;
        }
        return n;
    }
};

class WordList
{
private:
    struct Word *start;

public:
    WordList() : start(nullptr) {}

    int IsEmpty()
    {
        if (start == nullptr)
        {
            return 1;
        }
        return 0;
    }

    struct Word *insert(string d, Page *pagenumber)
    {
        Word *n = new Word(d);
        n->page = pagenumber;

        if (IsEmpty())
        {
            start = n;
        }
        else
        {
            Word *cur = start;
            while (cur->next)
            {
                cur = cur->next;
            }
            cur->next = n;
        }
        return n;
    }

    void update(vector<string> d)
    {
        if (IsEmpty())
        {
            cout << "List is Empty!";
            return;
        }
        else
        {
            Word *cur = start;
            int i = 0;
            while (cur)
            {
                cur->data = d[i++];
                cur = cur->next;
            }
        }
    }

    struct Word *find(int d)
    {
        int i = 1;
        Word *cur = start;
        while (cur)
        {
            if (i == d)
            {
                return cur;
                break;
            }
            cur = cur->next;
            i++;
        }
        return 0;
    }

    void show()
    {
        if (IsEmpty())
        {
            cout << "List is Empty!";
            return;
        }
        else
        {
            Word *cur = start;
            while (cur)
            {
                cout << cur->data << " ";
                cur = cur->next;
            }
        }
    }

    struct Word *getStart()
    {
        return start;
    }
};

class LetterList
{
private:
    struct Letter *start;

public:
    LetterList() : start(nullptr) {}

    int IsEmpty()
    {
        if (start == nullptr)
        {
            return 1;
        }
        return 0;
    }

    void insert(char d, Word *word)
    {
        Letter *n = new Letter(d);
        n->firstword = word;

        if (IsEmpty())
        {
            start = n;
        }
        else
        {
            Letter *cur = start;
            while (cur->next)
            {
                cur = cur->next;
            }
            cur->next = n;
        }
    }

    struct Letter *getStart()
    {
        return start;
    }
};

int main()
{
    string filename;
    cout << "Please enter the file name : ";
    cin >> filename;
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error : File wasn't open!\n";
    }

    string line;
    vector<string> words;
    int countline = 0;
    int countpage = 1;

    WordList wordList;
    PageList pageList;
    Page *page = pageList.insert(countpage);

    while (getline(file, line))
    {
        stringstream ss(line);
        string w;
        while (ss >> w)
        {
            words.push_back(w);
            wordList.insert(w, page);
        }

        countline++;
        if (countline == 40)
        {
            page = pageList.insert(countpage);
            countline = 0;
            countpage++;
            continue;
        }
    }
    file.close();

    // Sort words alphabetically
    sort(words.begin(), words.end());
    wordList.update(words);

    char c = 'a';
    Word *wrd = wordList.find(1);
    LetterList letterList;
    letterList.insert(c, wrd);

    int j = 1;
    for (string w : words)
    {
        if (w[0] != c)
        {
            c = w[0];
            wrd = wordList.find(j);
            letterList.insert(c, wrd);
        }
        j++;
    }

    Letter *startLetter = letterList.getStart();
    while (startLetter)
    {
        cout << startLetter->data << " : " << startLetter->firstword->data << " : " << startLetter->firstword->page->data;
        cout << "\n";
        startLetter = startLetter->next;
    }
}
