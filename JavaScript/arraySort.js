/* 將輸入的陣列由大排序到小
EX:
[5,8,10,1,3]  =>  [10,8,5,3,1]

完成以下函式並使用return回傳答案

function MyMainFunc(input) {
    return [];
} */
function MyMainFunc(input) {
    if (!Array.isArray(input)) {
        return null; 
    }
    const isAllValidNumbers = input.every(item => {
        return typeof item === 'number' && !Number.isNaN(item);
    });
    if (!isAllValidNumbers) {
        return null;
    }
    return input.slice().sort((a, b) => b - a);
}