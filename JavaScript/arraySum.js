/*陣列總和
將輸入的陣列數值全部加總
EX:
[1,2,3]  =>  6

完成以下函式並使用return回傳答案
function MyMainFunc(numbers) {
    return 0;
}*/
function MyMainFunc(numbers) {
    if (!Array.isArray(numbers)) {
        return 0;
    }
    // reduce 接收兩個參數：一個是 callback 函式（也就是 Reducer），另一個是初始值 (0)。
    // 為什麼要給初始值 0：這能直接滿足「空陣列自動回傳 0」的邊界條件。
    // 如果空陣列沒有給定初始值，reduce 執行時會拋出 TypeError。
    return numbers.reduce((accumulator, currentValue) => {
        if (typeof currentValue !== 'number' || Number.isNaN(currentValue)) {
            return accumulator; 
        }
        return accumulator + currentValue;
    }, 0);
}