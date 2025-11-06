#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include <sstream>

using namespace std;

const int PUZZLE_SIZE = 25;

struct Puzzle{
    vector<vector<int>> col_rules;
    vector<vector<int>> row_rules;
    vector<vector<int>> grid; // -1 = u, 0 = blank, 1 = black
    Puzzle(){
        col_rules.resize(PUZZLE_SIZE);
        row_rules.resize(PUZZLE_SIZE);
        grid.resize(PUZZLE_SIZE, vector<int>(PUZZLE_SIZE, -1));
    }
};

bool fix(int i, int j){
    if(i == 0 && j == 0){
        return true;
    }
    if(i ==0&&j>0){
        return false;
    }
    //fix0(i,j) fix1(i,j)
    bool canFix0 = fix0(i,j);
    bool canFix1 = fix1(i,j);
    return canFix0 || canFix1;
}
bool fix0(int i,int j){
    if(i>0){
        return fix(i-1,j);
    }
    return false;
}
bool fix1(int i, int j){
    if(i>0 && j>0){
        return fix(i-1,j-1);
    }
    return false;
}

vector<int> parse_a_clue_line(const string& line){
    vector<int> clues;
    string token;
    stringstream ss(line);
    while(getline(ss, token,'\t')){
        if(!token.empty()){
            clues.push_back(stoi(token));
        }
    }
    return clues;
}

void read_input_file(const string& filename, vector<Puzzle>& puzzles){
    ifstream input_file(filename);
    string line;
    int puzzle_id=0;
    if(!input_file.is_open()){
        cerr << "Error opening input file." << endl;
        return;
    }
    while (getline(input_file, line)) {
        if(line.size() > 0 &&line[0]=='$'){
            Puzzle puzzle;
            puzzle_id = puzzles.size() + 1;
            for(int i=0;i<PUZZLE_SIZE;i++){
                if(!getline(input_file, line)){
                    cerr<<"Error while reading column rules for puzzle "<<puzzle_id<<endl;
                    return;
                }
                puzzle.col_rules[i] = parse_a_clue_line(line);
            }
            for(int i=0;i<PUZZLE_SIZE;i++){
                if(!getline(input_file, line)){
                    cerr<<"Error while reading row rules for puzzle "<<puzzle_id<<endl;
                    return;
                }
                puzzle.row_rules[i] = parse_a_clue_line(line);
            }
            puzzles.push_back(puzzle);
        }
    }
    /*
    int puzzle_num = 1;
    for (const auto& p : puzzles) {
        
        cout << "Puzzle #" << puzzle_num << "\n";

        cout << "Rows:\n";
        for (const auto& r : p.row_rules) {
            for (int c : r) cout << c << "\t";
            cout << "\n";
        }

        cout << "---\nColumns:\n";
        for (const auto& c : p.col_rules) {
            for (int v : c) cout << v << "\t";
            cout << "\n";
        }

        cout << "========\n";

        puzzle_num++;
        if (puzzle_num > 2) break; // 只印前兩題
    }
    */
}

int main(){
    vector<Puzzle> puzzles;
    ofstream output_file("output.txt");
    read_input_file("input.txt", puzzles);
    //write_output_file(output_file, puzzles);

    output_file.close();
    return 0;
}