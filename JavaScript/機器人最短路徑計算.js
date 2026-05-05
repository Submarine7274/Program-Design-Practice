/*機器人最短路徑計算

你正在為物流倉庫的自動搬運機器人編寫路徑規劃程式，倉庫的地圖可以看作是一個 m x n 的二維陣列，陣列中的每個數字代表機器人經過該區域所需消耗的「電量」，機器人每次只能向「右」或向「下」移動一步。



請計算機器人從左上角 (0, 0) 移動到右下角 (m-1, n-1) 所需的「最少總消耗電量」。



【輸入格式】

一個二維整數陣列 grid，代表每個網格的耗電量（數字皆為正整數）。



【輸出格式】

回傳一個整數，代表最少的總耗電量。



EX:

輸入:

[

[1, 3, 1],

[1, 5, 1],

[4, 2, 1]

]

輸出: 7

(說明：最佳路徑為 1 -> 3 -> 1 -> 1 -> 1，總耗電量為 7)



完成以下函式並使用 return 回傳答案：



function MyMainFunc(input) {

return [];

}*/
function MyMainFunc(input) {
    let grid = input;
    
    // 為什麼要這樣寫：應對測試平台的輸入封裝。
    // 如果傳入的最外層是陣列，且只有一個元素，且該元素也是陣列（二維陣列），則將其解開。
    if (Array.isArray(input) && input.length === 1 && Array.isArray(input[0]) && Array.isArray(input[0][0])) {
        grid = input[0];
    }

    // 防呆機制：確保 grid 是有效的二維陣列
    if (!Array.isArray(grid) || grid.length === 0 || !Array.isArray(grid[0]) || grid[0].length === 0) {
        return 0;
    }

    const m = grid.length;
    const n = grid[0].length;

    // 為什麼要這樣寫：建立一個與 grid 大小相同的二維陣列 dp，用來記憶到達每個格子的最少電量。
    // Array.from 是建立二維陣列最乾淨的寫法，避免所有列指向同一個記憶體位址。
    const dp = Array.from({ length: m }, () => Array(n).fill(0));

    // 1. 初始化起點
    dp[0][0] = grid[0][0];

    // 2. 初始化第一列 (Row 0)
    // 為什麼要這樣寫：第一列的格子只能從「左邊」走過來，沒有上方選項，只能不斷累加。
    for (let j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // 3. 初始化第一行 (Column 0)
    // 為什麼要這樣寫：第一行的格子只能從「上面」走下來，沒有左方選項。
    for (let i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // 4. 填滿剩餘的 dp 表格
    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            // 為什麼要這樣寫：到達 (i, j) 的最少耗電量 = 本身耗電量 + min(上方耗電量, 左方耗電量)
            dp[i][j] = grid[i][j] + Math.min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // 回傳右下角的數值，即為全局最佳解
    return dp[m - 1][n - 1];
}
function MyMainFunc(input) {
    let grid = input;
    if(Array.isArray(input) &&input.length ==1 && Array.isArray(input[0])){
        grid = input[0];
    }
    if (!Array.isArray(grid) || grid.length === 0 || !Array.isArray(grid[0]) || grid[0].length === 0) {
        return 0;
    }
    
    const m = grid.length;
    const n = grid[0].length;
    const dp = Array.from({ length: m }, () => Array(n).fill(0));
    dp[0][0] = grid[0][0];
    for (let j = 1; j < n; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    for (let i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            dp[i][j] = grid[i][j] + Math.min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
     return dp[m - 1][n - 1];
}