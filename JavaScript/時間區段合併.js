/*時間區段合併
請撰寫一個程式，接收一個包含多個時間區段的二維陣列 input，每個區段表示為 [start, end]（代表開始與結束時間）。
請將所有重疊的區間合併，並依照時間先後順序，回傳一個不包含重疊區間的新二維陣列。

EX:
輸入: [[1, 3], [2, 6], [8, 10], [15, 18]]
輸出: [[1, 6], [8, 10], [15, 18]]
(區間 [1, 3] 和 [2, 6] 重疊，合併為 [1, 6]。)

完成以下函式並使用 return 回傳答案：

function MyMainFunc(input) {
    return [];
} */
function MyMainFunc(input) {
    let intervals = input;

    if (typeof intervals === 'string') {
        try { intervals = JSON.parse(intervals); } catch(e) {}
    }
    while (Array.isArray(intervals) && intervals.length === 1 && Array.isArray(intervals[0]) && Array.isArray(intervals[0][0])) {
        intervals = intervals[0];
    }
    
    if (!Array.isArray(intervals) || intervals.length === 0) {
        return [];
    }

    intervals.sort((a, b) => a[0] - b[0]);
    const merged = [];
    for (const interval of intervals) {
        if (merged.length === 0 || merged[merged.length - 1][1] < interval[0]) {
            merged.push([...interval]);
        } else {
            merged[merged.length - 1][1] = Math.max(merged[merged.length - 1][1], interval[1]);
        }
    }
    return merged;
}