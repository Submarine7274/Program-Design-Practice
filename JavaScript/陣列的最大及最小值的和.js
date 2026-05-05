/* 5. 陣列的最大及最小值的和
輸入一個陣列，回傳陣列中最大值+最小值
EX:
[-100,100,2] => 0
[1,2,3,4,5] => 6

function MyMainFunc(numbers) {
    return 0;
} */
function MyMainFunc(numbers) {
    if(!Array.isArray(numbers)){
        return null;
    }
    if(numbers.length ===0){
        return null;
    }
    const isAllAvalidNumbers = numbers.every(item=>{
        return  typeof(item) ==='number' && !Number.isNaN(item);
    });
    if(!isAllAvalidNumbers){
        return null;
    }
    let minValue = numbers[0];
    let maxValue = numbers[0];
    numbers.forEach(element => {
        if(element >=maxValue){
            maxValue = element;
        }
        if(element<= minValue){
            minValue = element;
        }
    });
    return minValue + maxValue;
}