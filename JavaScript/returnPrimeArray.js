/* 質數判斷
輸入一個陣列，找出其中的所有質數，回傳時按照輸入的順序排列
EX:
[2,11,5,6,7,8,100,101] => [2,11,5,7,101]

function MyMainFunc(numbers) {
    return [];
} */
function findPrimeArray(input){
    if(!Array.isArray(input)){
        return null;
    }
    const isAllValidNumbers = input.every(item=>{return typeof item =='number'&&!Number.isNaN(item)});
    if(!isAllValidNumbers){
        return null;
    }
    let result=[];
    for(let i = 0; i<input.length;i++){
        if(input[i]<=1||!Number.isInteger(input[i])){
           continue;
        }
        if (input[i] === 2) {
            result.push(input[i]);
            continue;
        }
        if (input[i] % 2 === 0) {
            continue;
        }
        let isPrime = true;
        for(let j = 3;j<=Math.sqrt(input[i]);j+=2){
            if(input[i]%j===0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            result.push(input[i]);
        }
    }
    return result;
}