#include "./ladder.h"
#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}

void error(string word1, string word2, string msg){
    cerr << "Error at " + word1 + " " + word2 + ": " + msg << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    int n = str1.size(), m = str2.size();
    vector<vector<int>> matrix(m+1, vector<int>(n+1, 0));

    for(int i=1; i<=m; ++i)
        matrix[i][0] = i;
    for(int j=1; j<=n; ++j)
        matrix[0][j] = j;
    
    for(int j=1; j<=n; ++j){
        for(int i=1; i<=m; ++i){
            int cost = 1;
            if(str1[j-1] == str2[i-1])
                cost = 0;
            matrix[i][j] = min(matrix[i-1][j]+1, min(matrix[i][j-1]+1, matrix[i-1][j-1] + cost));
        }
    }
    return matrix[m][n] <= d; 
}

bool is_adjacent(const string& word1, const string& word2){
    return edit_distance_within(word1, word2, 1);
}

/* vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    if(!word_list.contains(end_word)){error("End Word", end_word, "not in word_list");}
    queue<vector<string>> ladder_queue;
    ladder_queue.push(vector<string>(1, begin_word));
    set<string> visited;
    visited.insert(begin_word);

    while(!ladder_queue.empty()){
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();
        for(string word : word_list){
            if(is_adjacent(last_word, word)){
                if(!visited.contains(word)){
                    visited.insert(word);
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    if(word == end_word)
                        return new_ladder;
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    return vector<string>(0);
}
 */
void load_words(set<string> & word_list, const string& file_name){
    ifstream file(file_name);
    string word;
    while(file >> word){
        word[0] = tolower(word[0]);
        word_list.insert(word);
    }
    file.close();
}

void print_word_ladder(const vector<string>& ladder){
    for(string word : ladder){
        cout << word << "→";
    }
    cout << "[END]" << endl;
}

void verify_word_ladder(){
    set<string> word_list;
    load_words(word_list, "/home/lkhun/46/ics-46-hw-9-LucasKhun/src/words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}
