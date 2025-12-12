//x.wait() 我在等待x條件，先叫醒 next 或 mutex 的人接手，自己到 x_sem (條件隊列) 裡面等
//x是條件x x_count是x條件隊列的等待數量
//next是目前monitor裡的優先隊列 
//只有執行 x.signal() 的人，為了禮讓被喚醒者(滿足x條件的人)，自己才會進入 next 隊列
//mutex是monitor的大鎖
x_count++;          // 1. 登記：我要去睡覺了，等待 x條件的人 +1
if (next_count > 0) {
    signal(next);   // 2a. 交棒 (給next隊列)：
                    // 如果有因為發出 signal 而暫停的 Process (在 next 隊列)，
                    // 優先喚醒它們，讓它們繼續執行。
}
else {
    signal(mutex);  // 2b. 交棒 (給外部)：
                    // 如果沒有next隊列的人，就釋放 Monitor 的大鎖，
                    // 讓外面正在排隊想進來的 Process 進來。
}
wait(x_sem);        // 3. 睡眠：自己卡在 semaphore 上，直到有人對 x 發出 signal。
x_count--;          // 4. 醒來：被喚醒了，取消登記，等待人數 -1。

// x.signal() 
if (x_count > 0) {    // 1. 檢查：真的有人在等嗎？ (Monitor 的 signal 若無人等則無效)
    next_count++;     // 2. 登記：我 (Signaler) 準備要暫停了，next隊列人數 +1。
    signal(x_sem);    // 3. 喚醒：叫醒一個正在等 x 的 Process (讓它準備跑)。
    wait(next);       // 4. 讓路 (Signal-and-Wait)：
                      // 停下來 (到next上等)，讓剛被我叫醒的人先跑。
    next_count--;     // 5. 恢復：等到對方跑完或也 wait 了，輪回我執行，取消登記。
}

//writer
while(true){
	wait(rw_mutex); // 1. 嘗試獲取讀寫鎖。
	//writing is performed // 2. 進行寫入動作。
	signal(rw_mutex); // 3. 寫入完成，釋放讀寫鎖。
}

//reader
while(true){
	// --- 進入階段 ---
	wait(mutex); // 1. 準備修改 read_count，先拿到 mutex 鎖。
	read_count++; // 2. 讀者數量 +1。
	if(read_count == 1){ // 3. 檢查我是不是「第一個」讀者？
		wait(rw_mutex); // 4. 如果是，負責搶 rw_mutex 鎖，擋住寫者。
	}
	signal(mutex); // 5. 釋放 mutex 鎖。
	
	//reading is performed // 6. 開始讀取資料 (多個讀者可同時讀)。

	// --- 離開階段 ---
	wait(mutex); // 7. 讀完了，準備修改 read_count，再次拿到 mutex 鎖。
	read_count--; // 8. 讀者數量 -1。
	if(read_count == 0){ // 9. 檢查我是不是「最後一個」讀者？
		signal(rw_mutex); // 10. 如果是，負責釋放 rw_mutex 鎖，讓寫者可以進來。
	}
	signal(mutex); // 11. 釋放 mutex 鎖。
}