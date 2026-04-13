/* a743. 10420 - List of Conquests

標籤 :

通過比率: 2325人/ 2476人 ( 94%) [非即時]

評分方式： 

最近更新 : 2013-11-29 02:13



內容

In Act I, Leporello is telling Donna Elvira about his master's long list of conquests:

``This is the list of the beauties my master has loved, a list I've made out myself: take a look, read it with me. In Italy six hundred and forty, in Germany two hundred and thirty-one, a hundred in France, ninety-one in Turkey; but in Spain already a thousand and three! Among them are country girls, waiting-maids, city beauties; there are countesses, baronesses, marchionesses, princesses: women of every rank, of every size, of every age.'' (Madamina, il catalogo è questo)

As Leporello records all the ``beauties'' Don Giovanni ``loved'' in chronological order, it is very troublesome for him to present his master's conquest to others because he needs to count the number of ``beauties'' by their nationality each time. You are to help Leporello to count.

輸入說明

The input consists of at most 2000 lines, but the first. The first line contains a number n, indicating that there will be n more lines. Each following line, with at most 75 characters, contains a country (the first word) and the name of a woman (the rest of the words in the line) Giovanni loved. You may assume that the name of all countries consist of only one word.

輸出說明

The output consists of lines in alphabetical order. Each line starts with the name of a country, followed by the total number of women Giovanni loved in that country, separated by a space.

範例輸入 #1

3

Spain Donna Elvira

England Jane Doe

Spain Donna Anna

範例輸出 #1

England 1

Spain 2 */
#include <iostream>
#include <string>
#include <map> // 引入 map 函式庫來進行自動排序與計數

using namespace std;

int main() {
    // 為什麼要這樣寫：解除 I/O 同步，提升讀取測資的效率
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // 讀取測資的總行數 n
    if (cin >> n) {
        // 宣告一個 map，鍵 (Key) 為 string(國家名稱)，值 (Value) 為 int(該國家的美女數量)
        map<string, int> counts;
        string country, name;

        // 為什麼要這樣寫：n-- 會執行 n 次迴圈，處理接下來的 n 行測資
        while (n--) {
            // 讀取該行的第一個單字（國家名稱）
            cin >> country; 
            
            // 讀取該行剩下的所有字元（包含前面的空白與人名），直到遇到換行符號
            // 為什麼要這樣寫：因為我們不關心人名，用 getline 把後面的字串吃掉並覆蓋掉 name 變數，可以確保下一次迴圈能正確讀取下一行的國家名稱。
            getline(cin, name); 

            // 將該國家的計數加 1
            // 為什麼要這樣寫：如果 country 尚未存在於 map 中，map 會自動建立這個鍵，並將值初始化為 0，然後執行 ++ 變成 1。
            // 如果已經存在，就會直接將對應的值加 1。這行程式碼同時完成了「尋找、建立、累加」三個動作。
            counts[country]++;
        }

        // 為什麼要這樣寫：這稱為「範圍基礎的 for 迴圈 (Range-based for loop)」，是 C++11 之後的語法。
        // auto 會自動推導資料型態，這裡的 pair 代表 map 中的每一組資料 (包含鍵與值)。
        // 使用 const auto& 可以避免複製資料，提升效能，同時確保不會不小心修改到 map 裡面的內容。
        for (const auto& pair : counts) {
            // pair.first 是鍵（國家名稱），pair.second 是值（數量）
            cout << pair.first << " " << pair.second << "\n";
        }
    }

    return 0;
}