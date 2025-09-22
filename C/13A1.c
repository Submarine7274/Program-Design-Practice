/*Write the following function:

void build_index_url(const char *domain, char *index_url);

domain points to a string containing an Internet domain, such as "knking.corn". 
The function should add "http: //www." to the beginning of this string and "/index.html" to the end of the string, 
storing the result in the string pointed to by index_url.
(In this example, the result will be "http://www.knking.com/index.htm1".) 
You may assume that index_url points to a variable that is long enough to hold the resulting string. 
Keep the function as simple as possible by having it use the strcat and strcopy functions.
把domain字串前面加上"http: //www." 後面加上"/index.html" 並將結果存到index_url字串中
*/
#include <stdio.h>
#include <string.h>
void build_index_url(const char *domain, char *index_url); //函式宣告 保持先宣告函式原型的好習慣
int main(void){
    char domain[100];   //宣告變數 domain是輸入的網域名稱
    char index_url[200];    //宣告變數 index_url是輸出的完整網址
    fgets(domain, sizeof(domain), stdin);   //讀取輸入的網域名稱
    size_t len= strlen(domain);  //取得字串長度
    if(domain[len -1] =='\n'){  //如果最後一個字元是換行符號
        domain[len -1] ='\0';   //將換行符號改成字串結束符號
    }
    build_index_url(domain,index_url);  //呼叫函式並傳入參數
    return 0;
}
void build_index_url(const char *domain, char *index_url){  
    strcpy(index_url,"http: //www.");   //將"http: //www."複製到index_url字串中
    strcat(index_url,domain);   //將domain字串接到index_url字串後面
    strcat(index_url,"/index.html");    //將"/index.html"接到index_url字串後面
    printf("%s", index_url);    //輸出完整網址
}