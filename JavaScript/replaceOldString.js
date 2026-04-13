/* 取代字串
輸入一個陣列，將index0中的指定字串(index1)取代成新的字串(index2)
EX:
MyMainFunc(["123456","2","1"]) => "113456"
MyMainFunc(["abcabc","abc","def"]) => "defdef"

function MyMainFunc(input) {
    return "";
} */
function MyMainFunc(input){
    if(!Array.isArray(input)){
        return null;
    }
    if(input.length!==3){
        return null;
    }
    const isAllString = input.every(item=>{return typeof item ==='string'});
    if(!isAllString){
        return null;
    }
    let oldString = input[0];
    if(oldString ===""){
        return oldString;
    }
    let targetString = input[1];
    if (targetString === "") {
        return oldString; 
    }
    let replaceString = input[2];
    return oldString.split(targetString).join(replaceString);
}
//return oldString.replaceAll(targetString,replaceString);