/* 4. 質數判斷
輸入一個陣列，找出其中的所有質數，回傳時按照輸入的順序排列
EX:
[2,11,5,6,7,8,100,101] => [2,11,5,7,101]

function MyMainFunc(numbers) {
    return [];
} */
function MyMainFunc(numbers) {
    if(!Array.isArray(numbers)){
        return null;
    }
    let resultArray = [];
    for(let i =0;i<numbers.length;i++){
        if(findPrime(numbers[i])){
            resultArray.push(numbers[i]);
        }
    }
    return resultArray;
}
function findPrime(number){
    if(number <=1){
        return false;
    }
    if(number ===2){
        return true;
    }
    if (number % 2 === 0) {
        return false;
    }
    for( let i = 3; i*i <=number;i+=2){
        if((number %i) ===0){
            return false;
        }
    }
    return true;
}