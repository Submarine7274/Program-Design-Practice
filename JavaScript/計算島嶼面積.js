 /* 計算島嶼面積
系統會傳入一個二維整數陣列 input，代表俯瞰地圖，地圖中的 0 代表海，1 代表陸地。只要是「上下左右」相鄰的 1，就可以連接起來構成一個「島嶼」。

請撰寫一個程式，計算並回傳地圖中「面積最大」的島嶼面積（也就是該島嶼包含幾個 1）。
如果地圖上完全沒有陸地，請回傳 0。

EX:
輸入: 
[
  [0, 1, 1, 0],
  [0, 1, 0, 0],
  [0, 0, 0, 1],
  [1, 1, 0, 1]
]
輸出: 3

完成以下函式並使用 return 回傳答案：

function MyMainFunc(input) {
    return "";
} */
function MyMainFunc(input) {
    let data = input;

    if (typeof data === 'string') {
        try { data = JSON.parse(data); } catch(e) {}
    }
    while (Array.isArray(data) && data.length === 1 && Array.isArray(data[0]) && Array.isArray(data[0][0])) {
        data = data[0];
    }
    if (!Array.isArray(data) || data.length === 0) {
        return 0;
    }
    const grid = [];
    for (let i = 0; i < data.length; i++) {
        let row = data[i];
        if (typeof row === 'string') {
            grid.push(row.split('').map(Number));
        } else if (Array.isArray(row)) {
            grid.push(row.map(Number));
        }
    }
    if (grid.length === 0 || grid[0].length === 0) {
        return 0;
    }
    const rows = grid.length;
    const cols = grid[0].length;
    let maxArea = 0;
    function dfs(r, c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] === 0) {
            return 0;
        }
        grid[r][c] = 0;
        let area = 1;
        area += dfs(r + 1, c);
        area += dfs(r - 1, c);
        area += dfs(r, c + 1);
        area += dfs(r, c - 1);

        return area;
    }
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (grid[i][j] === 1) {
                maxArea = Math.max(maxArea, dfs(i, j));
            }
        }
    }
    return maxArea;
}