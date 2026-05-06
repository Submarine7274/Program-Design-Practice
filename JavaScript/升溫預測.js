/*  升溫預測
系統會傳入一個整數陣列 input，代表未來連續幾天的每日預測氣溫。請計算出：對於每一天，需要「再等幾天」才會出現比當天更高的氣溫？

1. 請回傳一個與輸入陣列長度相同的陣列。
2. 陣列中的第 i 個數字，代表第 i 天需要等待的天數。
3. 如果未來都沒有更高的氣溫，則該天請填入 0。

EX:
輸入: [73, 74, 75, 71, 69, 72, 76, 73]
輸出: [1, 1, 4, 2, 1, 1, 0, 0]

完成以下函式並使用 return 回傳答案：

function MyMainFunc(input) {
    return [];
} */
function MyMainFunc(input) {
    let temps = input;
    if (typeof temps === 'string') {
        try { temps = JSON.parse(temps); } catch(e) {}
    }
    while (Array.isArray(temps) && temps.length === 1 && Array.isArray(temps[0])) {
        temps = temps[0];
    }
    if (!Array.isArray(temps) || temps.length === 0) {
        return [];
    }

    const n = temps.length;
    const result = new Array(n).fill(0);
    const stack = []; 
    for (let i = 0; i < n; i++) {
        const currentTemp = temps[i];

        while (stack.length > 0 && currentTemp > temps[stack[stack.length - 1]]) {
            const prevIndex = stack.pop(); 
            result[prevIndex] = i - prevIndex;
        }
        stack.push(i);
    }
    return result;
}