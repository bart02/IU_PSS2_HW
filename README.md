# Programming Software Systems 2
## Homework1
### Requirements
C++14
gcc

### Compile and run
UNIX:
```bash
g++ main.cpp -std=c++14 -o main
./main
```

### What this program do?
1. Reads the data from the file _in.txt_;
2. Breaks the input text into sentences;
3. Finds the words in collection of sentences;
4. Transform this words to UPPERCASE;
5. Print these sentences in a specific format.

### Input format
First comes the text line, then comes the line that indicates the number of words, and then in each line comes the query word.

### Output format
For each word it prints the number of found sentences and these sentences with uppercased word.
