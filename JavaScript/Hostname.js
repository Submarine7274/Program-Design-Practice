/**將輸入一個URL字串需回傳URL的主機名稱
EX:
"https://google.com/"   =>   "google.com"
"http://120.108.204.116/onlinetest" => "120.108.204.116"

完成以下函式並使用return回傳答案
function MyMainFunc(url) {
    return "";
}*/
function MyMainFunc(url) {
    const fixedUrl = url.includes("://") ? url : "http://" + url;
    const parsedUrl = new URL(fixedUrl);
    return parsedUrl.hostname;
}