/* 8. 移除重複的單字
輸入一個字串，單字由空格分開，將重複的單字移除後回傳
EX:
"abc abc abc" => "abc"
"aa bb cc aa dd" => "aa bb cc dd"

function MyMainFunc(str) {
    return "";
} */
function MyMainFunc(str) {
    if(typeof str !=='string'){
        return null;
    }
    str = str.trim();
    if(str ===""){
        return str;
    }
    const uniqueWords = [...new Set(str.split(/\s+/))];
    return uniqueWords.join(' ');
}