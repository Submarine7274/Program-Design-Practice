/* 7. 取代字串
輸入一個陣列，將index0中的指定字串(index1)取代成新的字串(index2)
EX:
MyMainFunc(["123456","2","1"]) => "113456"
MyMainFunc(["abcabc","abc","def"]) => "defdef"

function MyMainFunc(input) {
    return "";
} */
function MyMainFunc(input) {
    if(!Array.isArray(input)){
        return null;
    }
    if(input.length !==3){
        return null;
    }
    if(typeof input[0]!=='string'||typeof input[1] !== 'string'||typeof input[2] !=='string'){
        return null;
    }
    let mainString = input[0];
    let targetString = input[1];
    let replaceString = input[2];
    if(targetString ===""){
        return mainString;
    }

    //return mainString.replaceAll(targetString,replaceString);//新版可以這樣寫
    return mainString.split(targetString).join(replaceString);
}
