const input =document.querySelector(".textinput");
const list = document.querySelector(".list");
const inputbutton = document.querySelector(".input-button")

function changeList(){
    if(input.value===""){
        return;
    }
    const task = document.createElement("li");
    //注意等於這個會在意型別
    task.innerHTML=`                                
        <input type="checkbox" class="checkbox">
        <label>${input.value}</label>
        <button class="trashcan">🗑️</button>
    `;                                              //注意分號;
    const trash = task.querySelector(".trashcan");
    trash.addEventListener("click",function(){
        task.remove();
    });

    const check = task.querySelector(".checkbox")
    check.addEventListener("change",function(){
        if(check.checked){
            task.style.textDecoration="line-through";
            task.style.color="#999";
            list.appendChild(task);
        }
        else{
            task.style.textDecoration="none";
            task.style.color="";
            list.prepend(task);
        }
    });
    list.appendChild(task);
    input.value ="";
}
input.addEventListener("keyup",
    function(e){
    if((e.key) === "Enter"){
        changeList();
    }
});
inputbutton.addEventListener("click",changeList);