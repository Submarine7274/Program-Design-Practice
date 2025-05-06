<script lang="ts">
    let count =0;
    function addOne(){
        count+=1;
    }
    //svelte在不同的區塊，有不同的註解方式，這邊是JavaScript的註解
    /*JavaScript是支援多行及單行註解的*/
</script>
<style>
    button {
      padding: 0.6em 1.2em;
      background-color: #1e88e5;
      color: white;
      border: none;
      border-radius: 8px;
      font-size: 1rem;
      cursor: pointer;
      transition: background-color 0.3s ease;
    }
    
    button:hover {
      background-color: #1565c0;
    }
    
    button:active {
      transform: scale(0.98);
    }
    /*CSS是沒有單行註解的*/
</style>
<button on:click={addOne}>
    Click {count} Times
</button>
<!--這段程式碼是按一下按鈕後，記數會+1 -->
<!-- on:click 是 Svelte 的事件綁定語法，對應 JavaScript 的 addEventListener -->