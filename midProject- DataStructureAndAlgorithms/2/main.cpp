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

    void insert(int d)
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
    }

    struct Page *find(int d)
    {
        Page *cur = start;
        while (cur)
        {
            if (cur->data == d)
            {
                return cur;
            }
            cur = cur->next;
        }
        return 0;
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
        return 1;
    }

    string line;
    vector<pair<string, int>> words;
    int countline = 0;
    int countpage = 1;

    PageList pageList;
    pageList.insert(countpage);

    while (getline(file, line))
    {
        stringstream ss(line);
        string w;
        while (ss >> w)
        {
            words.push_back({w, countpage});
        }

        countline++;
        if (countline == 40)
        {
            countpage++;
            pageList.insert(countpage);
            countline = 0;
            continue;
        }
    }
    file.close();

    // Sort words alphabetically
    sort(words.begin(), words.end());

    WordList wordList;
    char c = '\0';
    LetterList letterList;
    Page *page;
    for (auto &w : words)
    {
        page = pageList.find(w.second);
        Word *wrd = wordList.insert(w.first, page);
        if (c != '\0' && c != w.first[0])
        {
            c = w.first[0];
            letterList.insert(c, wrd);
        }
        else if (c == '\0')
        {
            c = w.first[0];
            letterList.insert(c, wrd);
        }
    }

    Letter *startLetter = letterList.getStart();
    ofstream out("out.txt");

    if (!out.is_open())
    {
        cout << "Error : File wasn't created!\n";
        return 1;
    }
    else
    {
        cout << "\nFile created successfully.\n";
    }

    while (startLetter)
    {
        Word *startWord = startLetter->firstword;
        int i = 0;
        while (startWord)
        {
            out << "Char : " << startLetter->data << " Word : " << startWord->data << " Page : " << startWord->page->data << "  |  ";
            startWord = startWord->next;
            i++;
            if (i == 15)
            {
                i = 0;
                out << "\n";
            }
        }
        startLetter = startLetter->next;
    }
    out.close();
    cout << "\nFile is ok; The number of words :" << words.size() << "; Name : out.txt\n";
}
