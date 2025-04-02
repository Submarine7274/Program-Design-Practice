let verifycode ="";
function generateVerifyCode(){
    const canvas = document.getElementById("verifycode");
    const background = canvas.getContext('2d');
    canvas.width=126;
    canvas.height=44;
    background.clearRect(0,0,canvas.width,canvas.height);   //清空畫布
    const chars = "ABCDEFGHJKLMNPQRSTUVWXYZ23456789";       //避免混淆字元
    for(let i =1;i<=5;i++){
        verifycode+=chars[Math.floor(Math.random()*chars.length)];  //random()是0~1的隨機小數，乘以總長度，得到其中某個數如21.15245等，然後用floor去掉小數
    }
    verifycode =verifycode.toUpperCase();
    background.fillStyle = "#fff";
    background.fillRect(0,0,canvas.width,canvas.height);
    for(let i=0; i<verifycode.length;i++){
        background.fillStyle ="#000";
        background.font = "20px Arial"
        const x = 10+i*20;
        const y = 30;
        background.save();
        background.translate(x,y);
        background.fillText(verifycode[i], 0, 0);
        background.restore();
    }
    console.log("產生的驗證碼:", verifycode); 
    return verifycode;
}
verifycode = generateVerifyCode();
const inputAccount = document.querySelector(".input-account");
const inputPassword = document.querySelector(".input-password");
const inputVerifycode = document.querySelector(".input-verifycode");
const loginButton = document.querySelector(".sent-login-data");

function loginAction(){
    const accountValue = inputAccount.value.trim();
    const passwordValue = inputPassword.value.trim();
    const verifyCodeValue = inputVerifycode.value.trim().toUpperCase();
    //下面用!跟空白的提早return避免使用巢狀判別式
    /*
    if (accountValue === "") {
    alert("請輸入帳號");
    } 
    else {
        if (passwordValue === "") {
        alert("請輸入密碼");
        }   
        else {
            if (verifyCodeValue === "") {
            alert("請輸入驗證碼");
            }   
            else {
                if (accountValue !== "admin") {
                alert("帳號錯誤");
            }       
                else {
                    if (passwordValue !== "1234") {
                    alert("密碼錯誤");
                } else {
                        if (verifyCodeValue !== verifycode) {
                        alert("驗證碼錯誤");
                    } else {
                        alert("登入成功");
                    }
                }
            }
        }
    }
}     */
    if(accountValue ===""){
        alert("請輸入帳號");
        return;
    }
    if(passwordValue ===""){
        alert("請輸入密碼");
        return;
    }
    if(verifyCodeValue ===""){
        alert("請輸入驗證碼");
        return;
    }
    if(accountValue!=="admin"){
        alert("帳號錯誤");
        return;
    }
    if(passwordValue!=="1234"){
        alert("密碼錯誤");
        return;
    }
    if(verifyCodeValue!==verifycode){
        alert("驗證碼錯誤");
        return;
    }
    alert("登入成功");
}
loginButton.addEventListener("click",loginAction);
[inputAccount, inputPassword, inputVerifycode].forEach(input => {
    input.addEventListener("keyup",  (event) =>{
        if (event.key === "Enter") {
            loginAction();
        }
    });
});
/*語法:
[元素1,元素2,元素3,...].forEach(
    input => {
    input.addEventListener("keyup", (event)=> {
        if (event.key === "Enter") {
            loginAction();
        }
    }
    );
    }
);
*/
// inputAccount.addEventListener("keyup",function e(){
//     if((e.key) ==="Enter"){
//         loginAction();
//     }
// });
// inputPassword.addEventListener("keyup",function e(){
//     if((e.key) ==="Enter"){
//         loginAction();
//     }
// });
// inputVerifycode.addEventListener("keyup",function e(){
//     if((e.key) ==="Enter"){
//         loginAction();
//     }
// });