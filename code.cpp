#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

void getWords(vector <string> &words, ifstream &file);
string cleanedWord(string w);
void sortWords(vector <string> &words);
void printWords(vector <pair<string, int>> &result, ifstream &file);
vector <pair <string, int>> countWords(vector <string> &words);
//define a function to clean the words
//getWords

int main()
{
    vector<string> words;
    string word;
    ifstream fin;
    vector<pair<string, int>> result;

    getWords(words, fin);
    sortWords(words);
    result = countWords(words);
    printWords(result, fin);

    return 0;
}

void getWords(vector <string> &words, ifstream &file)
{
string word;

file.open("holmes.txt");

ifstream infile("holmes.txt");
    if ( !file.is_open() )
    {
        cout << " File is not open " << endl;
    }
    
    while (file >> word )
    {
        string clean = cleanedWord(word);
        words.push_back(clean);
    }
}

string cleanedWord(string w)
{
    string clean = " ";
    for (char c: w)
    {
        if ( isalpha(c))
        {
            clean += c;
        }
    }
    return clean;
}

void sortWords(vector <string> &words)
{
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = i + 1; j < words.size(); j++)
        {
            if (words[i] > words[j])
            {
                string temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

vector <pair <string, int>> countWords(vector <string> &words)
{
    int wordCount = 1;
    vector <pair <string, int>> countedWords;
    string currentWord = words[0];
    if(words.size() == 0)
    {
        return countedWords;
    }
    else{
        currentWord = words[0];
    }
    for (int i = 1; i < words.size(); i++)
    {
        if (currentWord == words[i])
        {
            wordCount++;
        }
        else {
            countedWords.push_back({currentWord, wordCount});
            currentWord = words[i];
            wordCount = 1;
        }
    }

    countedWords.push_back({currentWord, wordCount});

    return countedWords;
}
void printWords(vector <pair<string, int>> &result, ifstream &file)
{
    for ( pair<string, int> r: result)
    {
        cout << r.first << ", " << r.second << endl;
    }

    file.close();
}
