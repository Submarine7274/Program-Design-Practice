/* 3. 陣列總和
將輸入的陣列數值全部加總
EX:
[1,2,3]  =>  6

完成以下函式並使用return回傳答案
function MyMainFunc(numbers) {
    return 0;
} */
function MyMainFunc(numbers) {
    if(!Array.isArray(numbers)){
        return null;
    }
    return numbers.reduce((sum ,currentValue)=>{
        if(typeof currentValue !=='number' || Number.isNaN(currentValue)){
            return sum;
        }
        return sum +currentValue;
    }
        ,0);
}