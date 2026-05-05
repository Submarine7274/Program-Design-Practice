/* 10. 解析JSON格式
輸入一個字串，回傳這個json物件key的數量
EX:
'{"a":1,"b":2}' => 2
'{"a":1,"b":{"c":2},"c":"1234","d":"e"}' => 4

function MyMainFunc(str) {
    return 0;
} */
function MyMainFunc(str) {
    let input = str;
    if (Array.isArray(str)) {
        input = str[0];
    }
    if(typeof input !== 'string'){
        return 0;
    }
    try {
        const parsedObj = JSON.parse(input);
        if(typeof parsedObj ==='object' &&parsedObj !== null&& !Array.isArray(parsedObj)){
            return Object.keys(parsedObj).length;
        }
        return 0;
    } catch (error) {
        return 0;
    }
    return 0;
}