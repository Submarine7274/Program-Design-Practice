/* 展開巢狀陣列
輸入一個巢狀陣列，將此巢狀陣列展開成一維陣列
EX:
[1, 2, [4, [6, 7], 5], [8, 9]] => [1,2,4,6,7,5,8,9]

function MyMainFunc(array) {
    return [];
}


提示:flat */
function flatArray(input) {
    if (!Array.isArray(input)) return null;
    let result = [];
    for (let i = 0; i < input.length; i++) {
        if (Array.isArray(input[i])) {
            result.push(...flatArray(input[i]));
        } else {
            result.push(input[i]);
        }
    }
    return result;
}