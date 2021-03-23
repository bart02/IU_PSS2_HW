#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Delete spaces from the beginning and the end of the string.
 *
 * @param str String that you need to trim.
 */
void trim(string& str)
{
    str.erase(find_if_not(str.rbegin(), str.rend(), ::isspace).base(),
              str.end());
    str.erase(str.begin(),
              find_if_not(str.begin(), str.end(), ::isspace));
}

/**
 * Split a text on sentences.
 *
 * @param str String that you need to split.
 * @param delimiter String that will be a delimiter (it would save in splitted string).
 * @return vector of sentences.
 */
vector<string> splitOnSentences(string str, const string& delimiter) {
    vector<string> sentences;
    while (!str.empty()) {
        trim(str);
        int pos = str.find(delimiter);
        if (pos != string::npos) {
            sentences.push_back(str.substr(0, pos + 1));
            str = str.substr(pos + 1);
        }
        else {
            sentences.push_back(str);
            str = "";
        }
    }
    return sentences;
}

/**
 * Make a substring in string UPPERCASE.
 *
 * @param str Reference to a string that you need to update.
 * @param begin Start position of substring.
 * @param length Length of substring.
 */
void wordToUpper(string& str, int begin, int length) {
    auto ibegin = str.begin() + begin;
    transform(ibegin, ibegin + length, ibegin, ::toupper);
}

/**
 * Make a substring in string UPPERCASE.
 *
 * @param str Reference to a string that you need to update.
 * @param substring Substring to find.
 * @return vector of sentences, with UPPERACASed substring.
 */
vector<string> search(const vector<string>& sentences, const string& substring) {
    vector<string> sentences_with_word;
    for (auto s : sentences) {
        bool to_vector = false;
        while (true) {
            int pos = s.find(substring);
            if (pos == string::npos) break;

            wordToUpper(s, pos, substring.length());
            to_vector = true;
        }
        if (to_vector) sentences_with_word.push_back(s);
    }
    return sentences_with_word;
}


int main() {
    ifstream fin("in.txt");
    if (!fin.is_open()) {
        cout << "Input file couldn't be opened" << endl;
        exit(-1);
    }
    ofstream fout("out.txt");
    if (!fout.is_open()) {
        cout << "Output file couldn't be opened" << endl;
        exit(-1);
    }

    string text;
    getline(fin, text);

    auto sentences = splitOnSentences(text, ".");

    int n;
    fin >> n;
    for (int i = 0; i < n; i++) {
        string word;
        fin >> word;

        auto sentences_with_word = search(sentences, word);

        fout << sentences_with_word.size() << endl;
        for (const auto& s : sentences_with_word) {
            fout << s << endl;
        }
    }
    fin.close();
    fout.close();
}
