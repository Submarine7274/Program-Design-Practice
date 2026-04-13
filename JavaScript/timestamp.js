/* 取得timestamp的UTC時間
輸入一個數字，為毫秒的時間戳，輸出一個為UTC時間的字串
輸出格式:"YYYY/MM/DD HH:MM:SS"，須補0
EX:
1646230477994 => "2022/03/02 14:14:37"
0 => "1970/01/01 00:00:00"

function MyMainFunc(timestamp) {
    return "";
} */
function MyMainFunc(timestamp) {
    if(!Number.isInteger(timestamp)||Number.isNaN(timestamp)){
        return null;
    }
    const time = Number(timestamp);
    const date = new Date(time);
    if (Number.isNaN(date.getTime())) {
        return null;
    }
    const year = date.getUTCFullYear();
    const month = date.getUTCMonth()+1;
    const day = date.getUTCDate();
    const hh = date.getUTCHours();
    const mm = date.getUTCMinutes();
    const ss = date.getUTCSeconds();
    const pad = n => n.toString().padStart(2, '0');
    const str = `${year}/${pad(month)}/${pad(day)} ${pad(hh)}:${pad(mm)}:${pad(ss)}`;
    return str;
}
//哪個天才想到月份從0開始的
//const pad = n => (n < 10 ? '0' + n : '' + n); 這是舊的padding寫法
//padStart(目標長度, '補充字元');