/* 專案任務排程
請撰寫一個程式，找出一個可以完成所有任務的執行順序，並以陣列格式回傳。
【規則說明】
1.專案中總共有 numTasks 個任務，編號從 0 到 numTasks - 1。
2.有些任務有前置作業的限制，用一個二維陣列表示，例如 [A, B] 代表必須先完成任務 B，才能開始進行任務 A。 
3.如果同一時間有多個任務都可以執行，請優先選擇「編號較小」的任務。
4. 如果任務之間存在「循環依賴」（例如 A 依賴 B，B 依賴 C，C 又依賴 A），代表專案永遠無法完成，請回傳空陣列 []。

EX:
輸入: {"numTasks": 4, "dependencies": [[1,0], [2,0], [3,1], [3,2]]}
輸出: [0, 1, 2, 3]


完成以下函式並使用 return 回傳答案：

function MyMainFunc(input) {
    return [];
} */
function MyMainFunc(input) {
    let data = input;
    if (typeof data === 'string') {
        try { data = JSON.parse(data); } catch (e) {}
    }
    while (Array.isArray(data) && data.length === 1) data = data[0];
    if (!data || typeof data.numTasks !== 'number') return [];
    const numTasks = data.numTasks;
    const dependencies = data.dependencies || [];
    const graph = Array.from({ length: numTasks }, () => []);
    const inDegree = new Array(numTasks).fill(0);
    for (const dep of dependencies) {
        const u = dep[1]; // 前置課程
        const v = dep[0]; // 後續課程
        graph[u].push(v);
        inDegree[v]++;
    }
    let queue = [];
    for (let i = 0; i < numTasks; i++) {
        if (inDegree[i] === 0) {
            queue.push(i);
        }
    }
    const result = [];
    while (queue.length > 0) {
        queue.sort((a, b) => a - b);
        const currentTask = queue.shift();
        result.push(currentTask); // 記錄修課順序
        for (const neighbor of graph[currentTask]) {
            inDegree[neighbor]--; 

            if (inDegree[neighbor] === 0) {
                queue.push(neighbor);
            }
        }
    }

    return result.length === numTasks ? result : [];
}