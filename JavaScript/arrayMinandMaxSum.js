/* 陣列的最大及最小值的和
輸入一個陣列，回傳陣列中最大值+最小值
EX:
[-100,100,2] => 0
[1,2,3,4,5] => 6

function MyMainFunc(numbers) {
    return 0;
} */
function sumOfMinAndMax(input){
    if(!Array.isArray(input)){
        return null;
    }
    if (input.length === 0) {
        return null; 
    }
    const isAllValidNumbers = input.every(item=>{return typeof item =='number'&&!Number.isNaN(item)})
    if(!isAllValidNumbers){
        return null;
    }
    let minNumber = input[0];
    let maxNumber = input[0];
    for(let i =1;i<input.length;i++){
        minNumber =Math.min(minNumber,input[i]);
        maxNumber = Math.max(maxNumber,input[i]);
    }
    let result = minNumber + maxNumber;
    return result;
}