/* 移除重複的單字
輸入一個字串，單字由空格分開，將重複的單字移除後回傳
EX:
"abc abc abc" => "abc"
"aa bb cc aa dd" => "aa bb cc dd"

function MyMainFunc(str) {
    return "";
} */
function removeDuplicate(input){
    if (typeof input !== 'string' || !input.trim()) {
        return null;
    }
    let words = input.trim().split(/\s+/);
    let seen = new Set();
    let result = [];
    for(let w of words){
        if(!seen.has(w)){
            seen.add(w);
            result.push(w);
        }
    }
    return result.join(' '); 
}