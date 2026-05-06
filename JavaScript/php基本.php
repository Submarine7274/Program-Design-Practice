 <!-- Echo HTML
直接回傳一個字串"<div>hello world</div>" -->
<?php
echo "<div>hello world</div>";
?>

<!--  Echo
將輸入的內容重新輸出出來

example:
------輸入------
abcdefg
------輸出------
abcdefg -->

<?php
// fopen 開啟標準輸入流 (STDIN)，用於讀取終端機或批改系統的輸入
$input = trim(fgets(STDIN));

// 迴圈讀取每一行輸入，直到沒有輸入為止 (EOF)
while (($line = fgets($input)) !== false) {
    // 直接將讀取到的內容輸出
    echo $line;
}
fclose($input);
?>

<!--  數字加總
輸入多個數字，輸出所有數字的加總

example:
----輸入----
1 100 20 30
----輸出----
151 -->

<?php
// 讀取所有標準輸入的內容
$input = trim(fgets(STDIN));

// 使用正則表達式 preg_split，將字串依照一個或多個空白字元（包含換行、空格）切割成陣列
$numbers = preg_split('/\s+/', trim($input));

$sum = 0;
// 遍歷陣列中的每一個元素
foreach ($numbers as $num) {
    // 確認該元素是數字後再相加，避免空字串或無效字元導致計算錯誤
    if (is_numeric($num)) {
        $sum += $num;
    }
}

echo $sum . "\n";
?>

<!-- 邏輯運算子 (Logic Operators)
小蘇最近在學三種邏輯運算子 AND、OR 和 XOR。這三種運算子都是二元運算子，也就是說在運算時需要兩個運算元，例如 a AND b。對於整數 a 與 b，以下三個二元運算子的運算結果定義如下列三個表格：
-------------------------
a AND b
        b 為 0  b 不為 0
a 為 0     0       0
a 不為 0   0       1
-------------------------
a OR b
        b 為 0  b 不為 0
a 為 0     0       1
a 不為 0   1       1
-------------------------
a XOR b
        b 為 0  b 不為 0
a 為 0     0       1
a 不為 0   1       0
-------------------------
舉例來說：
(1) 0 AND 0 的結果為 0，0 OR 0 以及 0 XOR 0 的結果也為 0。
(2) 0 AND 3 的結果為 0，0 OR 3 以及 0 XOR 3 的結果則為 1。
(3) 4 AND 9 的結果為 1，4 OR 9 的結果也為 1，但 4 XOR 9 的結果為 0。



請撰寫一個程式，讀入 a、b 以及邏輯運算的結果，輸出可能的邏輯運算為何。

輸入格式
輸入只有一行，共三個整數值，整數間以一個空白隔開。第一個整數代表 a，第二個整數代表 b，這兩數均為非負的整數。第三個整數代表邏輯運算的結果，只會是 0 或 1。

輸出格式
輸出可能得到指定結果的運算，若有多個，輸出順序為 AND、OR、XOR，每個可能的運算單獨輸出一行，每行結尾皆有換行。若不可能得到指定結果，輸出 IMPOSSIBLE

範例一
輸入:
0 0 0
輸出:
AND
OR
XOR

範例二
輸入:
1 1 1
輸出:
AND
OR -->
<?php
// 讀取一行輸入
$line = trim(fgets(STDIN));
// 使用 sscanf 依照格式將字串解析成三個變數
sscanf($line, "%d %d %d", $a, $b, $target);

// 將輸入的整數轉換為布林值 (非 0 為 true，0 為 false)
$bool_a = ($a != 0);
$bool_b = ($b != 0);
$bool_target = ($target != 0);

$possible = false;

// 驗證 AND 運算
if (($bool_a && $bool_b) == $bool_target) {
    echo "AND\n";
    $possible = true;
}
// 驗證 OR 運算
if (($bool_a || $bool_b) == $bool_target) {
    echo "OR\n";
    $possible = true;
}
// 驗證 XOR 運算。PHP 中可用 ^ 符號或 != 進行布林值的 XOR 比較
if (($bool_a ^ $bool_b) == $bool_target) {
    echo "XOR\n";
    $possible = true;
}

// 若三者皆不符合
if (!$possible) {
    echo "IMPOSSIBLE\n";
}
?>
<!-- For迴圈
依據輸入的數量輸出div

example:
------輸入------
4
------輸出------
<div>1</div>
<div>2</div>
<div>3</div>
<div>4</div> -->
<?php
// 讀取輸入的數量
$n = (int)trim(fgets(STDIN));

// for 迴圈，從 1 執行到 $n
for ($i = 1; $i <= $n; $i++) {
    // 雙引號內可以直接解析變數 $i
    echo "<div>$i</div>\n";
}
?>
<!-- 質數判斷
依據輸入的數字判斷是否為質數，是的話輸出"YES"，不是的話輸出"NO"

example:
------輸入------
101
------輸出------
YES -->
<?php
$n = (int)trim(fgets(STDIN));
$is_prime = true;

// 小於等於 1 的數字不是質數
if ($n <= 1) {
    $is_prime = false;
} else {
    // 迴圈檢查因數，只需檢查到根號 $n 即可，寫法 $i * $i <= $n 可避免開根號的效能消耗
    for ($i = 2; $i * $i <= $n; $i++) {
        if ($n % $i == 0) {
            $is_prime = false;
            break; // 找到因數，提早結束迴圈
        }
    }
}

// 根據布林值輸出對應結果
echo $is_prime ? "YES\n" : "NO\n";
?>
<!-- 判斷密碼安全性
輸入第一行表示有n個密碼，密碼長度必須至少8，包含大小寫的英文和數字，符合時輸出"Y"，不符合時輸出"N"

example:
----輸入----
3
abcdefgh
aabbccddEE11
abc
----輸出----
NYN -->
<?php
// 讀取第一行，取得密碼數量
$n = (int)trim(fgets(STDIN));
$result = "";

for ($i = 0; $i < $n; $i++) {
    $pw = trim(fgets(STDIN));
    
    // 使用 strlen 檢查長度是否至少為 8
    // 使用 preg_match 配合正則表達式，分別檢查是否包含大寫字母、小寫字母與數字
    if (strlen($pw) >= 8 &&
        preg_match('/[A-Z]/', $pw) &&
        preg_match('/[a-z]/', $pw) &&
        preg_match('/[0-9]/', $pw)) {
        $result .= "Y";
    } else {
        $result .= "N";
    }
}

echo $result . "\n";
?>
<!-- 擷取文章簡介
輸入一篇文章，當長度超過30個字元時只輸出前30個字元並加上"..."，沒超過20個字直接輸出文章，簡介需放在<p></p>裡面

example:
----輸入----
Russian forces bombarded Kyiv and Chernihiv Wednesday.
----輸出----
<p>Russian forces bombarded Kyiv ...</p> -->
<?php
$text = trim(fgets(STDIN));

echo "<p>";
// 使用 mb_strlen 與 mb_substr 是為了正確處理多位元組字元（如中文）。
// 若只用 strlen，中文字會被計算為 3 個位元組，導致擷取長度錯誤。
if (mb_strlen($text, 'UTF-8') > 30) {
    echo mb_substr($text, 0, 30, 'UTF-8') . "...";
} else {
    echo $text;
}
echo "</p>\n";
?>
<!-- 時間戳
輸入一個ISO 8601的時間戳，輸出特定格式的時間(時區為Asia/Taipei)
輸出格式範例:"2019/01/01 01:01:00"

example:
----輸入----
2020-05-03T17:30:08+00:00
----輸出----
2020/05/04 01:30:08 -->
<?php
// 設定預設時區為台北，確保後續轉換輸出的時間正確
date_default_timezone_set('Asia/Taipei');

$iso_time = trim(fgets(STDIN));

// strtotime 能夠將 ISO 8601 格式字串自動解析成 Unix 時間戳（整數）
$timestamp = strtotime($iso_time);

// date 函式將時間戳格式化為指定的 "Y/m/d H:i:s" 格式
echo date("Y/m/d H:i:s", $timestamp) . "\n";
?>
<!-- 擷取HTML的文字
輸入一段html，需輸出其中的文字部分


----輸入----
<div>Hello<p>world</p></div>
----輸出----
Helloworld

提示:strip_tags -->
<?php
$html = trim(file_get_contents("php://stdin"));

// strip_tags 為 PHP 內建函式，專門用來去除字串中的 HTML 及 PHP 標籤
// 它會保留標籤之間的純文字，自動達成題目要求
echo strip_tags($html) . "\n";
?>