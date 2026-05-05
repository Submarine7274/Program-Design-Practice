/* 9. 取得timestamp的UTC時間
輸入一個數字，為毫秒的時間戳，輸出一個為UTC時間的字串
輸出格式:"YYYY/MM/DD HH:MM:SS"，須補0
EX:
1646230477994 => "2022/03/02 14:14:37"
0 => "1970/01/01 00:00:00"

function MyMainFunc(timestamp) {
    return "";
} */
function MyMainFunc(timestamp) {
    if(!Number.isInteger(timestamp)){
        return null;
    }
    const date = new Date(timestamp);
    const year = date.getUTCFullYear();
    const month = date.getUTCMonth()+1;
    const day = date.getUTCDate();
    const hour = date.getUTCHours();
    const minute = date.getUTCMinutes();
    const second = date.getUTCSeconds();
    const padding = str =>{
        return str.toString().padStart(2,'0');
    };
    const str = `${year}/${padding(month)}/${padding(day)} ${padding(hour)}:${padding(minute)}:${padding(second)}`;
    return str;
} 