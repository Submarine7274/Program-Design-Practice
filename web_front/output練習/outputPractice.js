function testInnerHTML(){
    document.getElementById("innerhtml").innerHTML = "<h2>This is the example of innerHTML method.</h2>";
}
function testInnerText(){
    document.getElementById("innerText").innerText ="This is the example of innerText method.";
}
function testDocumentWrite(){
    document.write("<p>This will overwrite all of html.</p>");
}
function testWindowAlert(){
    window.alert("Surprise!");
}