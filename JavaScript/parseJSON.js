/* 解析JSON格式
輸入一個字串，回傳這個json物件key的數量
EX:
'{"a":1,"b":2}' => 2
'{"a":1,"b":{"c":2},"c":"1234","d":"e"}' => 4

function MyMainFunc(str) {
    return 0;
} */
function MyMainFunc(input) {
    if (!Array.isArray(input) || input.length === 0) {
        return 0;
    }
    let jsonString = input[0];
    if (typeof jsonString !== 'string') {
        return 0;
    }
    let obj; 
    try { obj = JSON.parse(jsonString); } 
    catch (e){
        return 0;
    }
    if(typeof obj !=='object'||obj ===null||Array.isArray(obj)){
        return 0;
    }
    return Object.keys(obj).length;
}