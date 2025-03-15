#include "./ladder.h"
#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}

void error(string word1, string word2, string msg){
    cerr << "Error at " + word1 + " " + word2 + ": " + msg << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
/*     set<string> nei1, nei2;
    int size1 = str1.size(), size2 = str2.size();
    int edit_distance = 0;

    for(int i=0; i<d; ++i){
        for()
    }




    return edit_distance <= d; 
*/
    return false;
}

bool is_adjacent(const string& word1, const string& word2){
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    if(!word_list.contains(end_word)){error("End Word", end_word, "not in word_list");}
    vector<string> ladder = {begin_word};
    queue<vector<string>> ladder_queue;
    ladder_queue.push(ladder);
    set<string> visited;
    visited.insert(begin_word);

    while(!ladder_queue.empty()){
        ladder = ladder_queue.front();
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
    ladder.clear()
    return ladder;
}

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
    load_words(word_list, "words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}
