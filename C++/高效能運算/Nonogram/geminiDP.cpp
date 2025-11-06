#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include <sstream>
#include <algorithm> // for std::max
#include <numeric>   // for std::accumulate

using namespace std;

const int PUZZLE_SIZE = 25;

// 狀態別名和記憶化表格定義
using Line = const vector<int>&;
using Rules = const vector<int>&;
typedef vector<vector<int>> MemoTable;

// ----------------------------------------------------
// 1. 資料結構 (Data Structure)
// ----------------------------------------------------

struct Puzzle {
    vector<vector<int>> col_rules;
    vector<vector<int>> row_rules;
    vector<vector<int>> grid; // -1 = UNKNOWN, 0 = EMPTY (blank), 1 = FILLED (black)
    long long solve_time_ms = 0; // 記錄解謎所需時間 (毫秒)
    bool is_solved = false;      // 記錄謎題是否成功解出
    
    Puzzle() {
        col_rules.resize(PUZZLE_SIZE);
        row_rules.resize(PUZZLE_SIZE);
        grid.resize(PUZZLE_SIZE, vector<int>(PUZZLE_SIZE, -1));
    }
};

// ----------------------------------------------------
// 2. DP 單線可行性檢查 (DP Line Solver Core)
// ----------------------------------------------------

// 檢查單個格子是否可以留空 (0)
bool can_be_empty_at(Line line, int i) {
    return line[i] != 1; // 如果格子已經確定為填色 (1)，則不能留空
}

// 檢查從 start 開始的 k 個格子是否可以形成一個完整的「填色區塊」
bool can_form_block(Line line, int start, int k) {
    if (start < 0 || start + k > PUZZLE_SIZE) return false;
    
    // 區塊內部不能有留空 (0)
    for (int i = 0; i < k; ++i) {
        if (line[start + i] == 0) return false;
    }

    // 區塊後方緊接著的格子 (如果存在) 必須是留空 (0) 或未知 (-1)
    if (start + k < PUZZLE_SIZE) {
        if (line[start + k] == 1) return false; // 後面不能緊接著是填色 (1)
    }

    return true;
}


// 遞迴 DP 函式 (主體)
// L: 考慮線路的前 L 個格子, R: 考慮前 R 個規則
int is_line_possible_dp(Line line, Rules rules, int L, int R, MemoTable& memo) {
    
    // 1. 檢查記憶化表格
    if (memo[L][R] != -1) {
        return memo[L][R];
    }
    
    // 2. 基底案例 (Base Cases)
    if (R == 0) { // 所有規則區塊都已滿足
        for (int k = 0; k < L; ++k) {
            if (line[k] == 1) { 
                return memo[L][R] = 0;
            }
        }
        return memo[L][R] = 1;
    }
    
    // 預先檢查：線路長度 L 是否足以容納剩下的 R 個區塊
    int min_required_len = 0;
    for(int i = 0; i < R; ++i) {
        min_required_len += rules[i];
    }
    min_required_len += max(0, R - 1);
    if (L < min_required_len) {
        return memo[L][R] = 0;
    }
    
    if (L == 0) { // 線路已結束，但規則未滿足
        return memo[L][R] = 0; 
    }

    // ----------------------------------------------------
    // 3. 遞迴關係 (Transition)

    int result = 0;

    // 可能性 A: 假設 L-1 處為留空 (EMPTY = 0)
    if (can_be_empty_at(line, L - 1)) {
        if (is_line_possible_dp(line, rules, L - 1, R, memo)) {
            result = 1;
        }
    }

    // 可能性 B: 假設 L-1 處完成了第 R 個區塊 (FILLED = 1)
    if (result == 0) { // 只有在 A 失敗時才需要檢查 B
        int current_block_size = rules[R - 1];
        
        if (L >= current_block_size) {
            int block_start_idx = L - current_block_size;
            int space_before_idx = block_start_idx - 1;
            
            // a. 檢查該區塊是否可以填色
            if (can_form_block(line, block_start_idx, current_block_size)) {
                
                // b. 檢查區塊前一格是否是留空 (或從頭開始)
                if (space_before_idx < 0 || can_be_empty_at(line, space_before_idx)) {
                    
                    int next_L = (space_before_idx < 0) ? 0 : space_before_idx; 
                    int next_R = R - 1;
                    
                    if (is_line_possible_dp(line, rules, next_L, next_R, memo)) {
                        result = 1;
                    }
                }
            }
        }
    }
    
    return memo[L][R] = result;
}

// 封裝函式，方便外部呼叫
int check_line_validity(Line line, Rules rules) {
    int line_len = PUZZLE_SIZE;
    int rule_len = rules.size();
    
    if (rule_len == 0) {
        for(int cell : line) {
            if (cell == 1) return 0;
        }
        return 1;
    }

    MemoTable memo(line_len + 1, vector<int>(rule_len + 1, -1));
    
    return is_line_possible_dp(line, rules, line_len, rule_len, memo);
}

// ----------------------------------------------------
// 3. 約束傳播 (Constraint Propagation)
// ----------------------------------------------------

// 嘗試推導並更新單條線路的狀態 (使用臨時修改和恢復)
bool deduce_and_update_line(vector<int>& line, Rules rules) {
    bool changed = false;
    
    for (int i = 0; i < PUZZLE_SIZE; ++i) {
        if (line[i] != -1) continue; 
        
        int original_val = line[i];

        // A. 檢查留空 (0) 的可能性 (直接修改 line 進行檢查)
        line[i] = 0;
        bool possible_if_empty = check_line_validity(line, rules);
        
        // B. 檢查填色 (1) 的可能性
        line[i] = 1;
        bool possible_if_filled = check_line_validity(line, rules);

        // 恢復原始狀態
        line[i] = original_val; 

        // 推導與更新
        if (possible_if_empty && !possible_if_filled) {
            line[i] = 0;
            changed = true;
        } else if (!possible_if_empty && possible_if_filled) {
            line[i] = 1;
            changed = true;
        } else if (!possible_if_empty && !possible_if_filled) {
             // 發現矛盾，返回 false
             return false; 
        }
    }
    return changed;
}

// 執行一次完整的約束傳播循環 (使用優化後的一致性檢查)
bool apply_constraint_propagation(Puzzle& p) {
    bool changed;
    
    do {
        changed = false;
        
        // 1. 檢查 Row
        for (int r = 0; r < PUZZLE_SIZE; ++r) {
            if (!deduce_and_update_line(p.grid[r], p.row_rules[r])) {
                return false; // 發現矛盾
            }
        }

        // 2. 檢查 Column
        for (int c = 0; c < PUZZLE_SIZE; ++c) {
            // 提取 Column 狀態
            vector<int> column_data(PUZZLE_SIZE);
            for(int r = 0; r < PUZZLE_SIZE; ++r) column_data[r] = p.grid[r][c];
            
            if (deduce_and_update_line(column_data, p.col_rules[c])) {
                changed = true;
                // 寫回 grid
                for(int r = 0; r < PUZZLE_SIZE; ++r) p.grid[r][c] = column_data[r];
            } else {
                return false; // 發現矛盾
            }
        }
    } while (changed);
    
    return true; // 一致
}

// ----------------------------------------------------
// 4. 回溯法核心 (Backtracking Core)
// ----------------------------------------------------

bool backtrack_solve(Puzzle& p) {
    
    // Step 1: 約束傳播
    if (!apply_constraint_propagation(p)) {
        return false; // 發現矛盾，回溯
    }
    
    // Step 2: 檢查是否已解完 (找到第一個未知格子)
    int best_r = -1, best_c = -1;
    for (int r = 0; r < PUZZLE_SIZE; ++r) {
        for (int c = 0; c < PUZZLE_SIZE; ++c) {
            if (p.grid[r][c] == -1) {
                best_r = r;
                best_c = c;
                goto find_unknown;
            }
        }
    }
    
    // 如果沒有未知格子，則表示成功找到一個解
    p.is_solved = true;
    return true;

find_unknown:
    // 如果沒有找到未知格子 (goto 跳轉到這裡)，代表回溯成功
    if (best_r == -1) {
        p.is_solved = true;
        return true;
    }
    
    // Step 3: 嘗試猜測 (Try Guessing)
    vector<vector<int>> original_grid = p.grid; 
    
    // A. 猜測：填色 (FILLED = 1)
    p.grid[best_r][best_c] = 1;
    if (backtrack_solve(p)) {
        return true; 
    }
    
    // B. 回溯並嘗試：留空 (EMPTY = 0)
    p.grid = original_grid; // 恢復狀態
    p.grid[best_r][best_c] = 0;
    
    if (backtrack_solve(p)) {
        return true; 
    }

    // C. 兩種猜測都失敗，最終恢復狀態，回傳失敗
    p.grid = original_grid; 
    return false;
}

// ----------------------------------------------------
// 5. 主解算控制與計時 (Solver Control and Timing)
// ----------------------------------------------------

void solve_nonogram(vector<Puzzle>& puzzles, long long& total_solve_time_ms) {
    auto start_total = chrono::high_resolution_clock::now(); 
    
    for (Puzzle& p : puzzles) {
        auto start_puzzle = chrono::high_resolution_clock::now();
        
        cout << "開始解題 Puzzle #" << (&p - &puzzles[0]) + 1 << "...\n";

        if (backtrack_solve(p)) {
            p.is_solved = true;
            cout << "Puzzle #" << (&p - &puzzles[0]) + 1 << " 成功解出。\n";
        } else {
            p.is_solved = false;
            cout << "Puzzle #" << (&p - &puzzles[0]) + 1 << " 無法找到解。\n";
        }

        auto end_puzzle = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end_puzzle - start_puzzle);
        p.solve_time_ms = duration.count();
        cout << "   耗時: " << p.solve_time_ms << " 毫秒\n";
    }
    
    auto end_total = chrono::high_resolution_clock::now();
    total_solve_time_ms = chrono::duration_cast<chrono::milliseconds>(end_total - start_total).count();
    
    cout << "\n========================================\n";
    cout << "所有謎題總解算時間: " << total_solve_time_ms << " 毫秒\n";
    cout << "========================================\n";
}

// ----------------------------------------------------
// 6. 輸入/輸出 函式 (I/O Functions)
// ----------------------------------------------------

vector<int> parse_a_clue_line(const string& line){
    vector<int> clues;
    string token;
    stringstream ss(line);
    // 這裡使用 TAB ('\t') 作為分隔符
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
        cerr << "Error opening input file: " << filename << endl;
        return;
    }
    while (getline(input_file, line)) {
        if(line.size() > 0 &&line[0]=='$'){
            Puzzle puzzle;
            puzzle_id = puzzles.size() + 1;
            // 讀取 25 行 Column Rules (上到下)
            for(int i=0;i<PUZZLE_SIZE;i++){
                if(!getline(input_file, line)){
                    cerr<<"Error while reading column rules for puzzle "<<puzzle_id<<endl;
                    return;
                }
                puzzle.col_rules[i] = parse_a_clue_line(line);
            }
            // 讀取 25 行 Row Rules (左到右)
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
}

// 實作輸出函式，使用 '1' 填色, '0' 留空, TAB 分隔, $ 符號開頭
void write_output_file(ofstream& output_file, const vector<Puzzle>& puzzles, long long total_solve_time_ms) {
    int puzzle_num = 1;

    for (const auto& p : puzzles) {
        // 輸出謎題編號前的 $ 符號
        output_file << "$" << puzzle_num << "\n";
        
        // 輸出棋盤 grid (25x25 矩陣)
        for (int i = 0; i < PUZZLE_SIZE; ++i) {
            for (int j = 0; j < PUZZLE_SIZE; ++j) {
                // 1. 轉換狀態: 1 -> "1", 0 -> "0", -1 -> "0"
                int output_val = (p.grid[i][j] == 1) ? 1 : 0;
                
                output_file << output_val;

                // 2. 使用 TAB 分隔 (除了行尾的最後一個數字)
                if (j < PUZZLE_SIZE - 1) {
                    output_file << "\t";
                }
            }
            output_file << "\n"; // 每行結束換行
        }
        
        puzzle_num++;
    }
    
    // 輸出總時間
    output_file << "$TOTAL_TIME_MS\n";
    output_file << total_solve_time_ms << "\n";
}

// ----------------------------------------------------
// 7. Main 函式
// ----------------------------------------------------

int main(){
    vector<Puzzle> puzzles;
    ofstream output_file("output.txt");
    long long total_solve_time_ms = 0;
    
    // 1. 讀取輸入
    read_input_file("input.txt", puzzles);
    
    // 2. 解算謎題 (包含 DP 約束傳播和回溯法)
    // 為了準確計時，我們將總計時邏輯移回 main
    auto start_total = chrono::high_resolution_clock::now();
    solve_nonogram(puzzles, total_solve_time_ms);
    auto end_total = chrono::high_resolution_clock::now();
    total_solve_time_ms = chrono::duration_cast<chrono::milliseconds>(end_total - start_total).count();
    
    // 3. 輸出結果
    write_output_file(output_file, puzzles, total_solve_time_ms);

    output_file.close();
    return 0;
}