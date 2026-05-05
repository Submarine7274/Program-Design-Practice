/* 6. 展開巢狀陣列
輸入一個巢狀陣列，將此巢狀陣列展開成一維陣列
EX:
[1, 2, [4, [6, 7], 5], [8, 9]] => [1,2,4,6,7,5,8,9]

function MyMainFunc(array) {
    return [];
}


提示:flat */
function MyMainFunc(array) {
    if(!Array.isArray(array)){
        return null;
    }

    return array.flat(Infinity);
}