
// 1. 建立一個全域變數，用來記錄「色相的偏移量」
// 這個變數必須放在函式外面，它的值才不會在每次點擊時被重置
let hueOffset = 0;

// 2. 將產生畫面的邏輯打包成一個函式
function renderNumbers() {
    let text = "";
    
    for (let i = 0; i < 10; i++) {
        // 將原本的 i * 40 加上偏移量 hueOffset
        let currentHue = (i * 40) + hueOffset;
        
        text += `<div style="color: hsl(${currentHue}, 70%, 50%); font-weight: bold;">
                   The number is ${i}
        </div>`;
    }
    
    // 將組合好的 HTML 字串寫入頁面
    document.getElementById("demo").innerHTML = text;
}

// 3. 網頁剛載入時，先手動呼叫一次函式，把初始的數字印出來
renderNumbers();

// 4. 按鈕點擊時要執行的函式
function changeColors() {
    // 每次點擊，讓色相偏移 60 度（你可以修改這個數值觀察變化）
    hueOffset += 60; 
    
    // 數值改變後，重新呼叫產生畫面的函式，覆蓋掉原本的內容
    renderNumbers();
} 
