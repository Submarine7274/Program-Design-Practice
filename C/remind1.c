#include<stdio.h>
#include<string.h>
#define MAX_REMIND 50
#define MSG_LEN 60
void read_line(char str[], int n);

int main (void){
    int day,num_remind = 0,i =0, j=0;     
    char reminder[MSG_LEN][MAX_REMIND],day_str[3],msg_str[MSG_LEN +1];

    while(1){
        if(num_remind == MAX_REMIND){               //如果現在的remind數量達到上限 就跳出主迴圈
            printf("No space.");
            break;
        }
        printf("Enter day and reminder: ");         //每次跳出使用提示
        scanf("%2d", &day);                         //讓使用者輸入日期
        if(day == 0){                               //如果0就離開主迴圈
            break;
        }
        sprintf(day_str,"%2d", day);                //sprintf(要轉成的字串名,要轉出去的東西格式,轉出前的東西)
        read_line(msg_str, MSG_LEN);                //呼叫read_line 把訊息存進去msg_str[]
        for(i = 0; i<num_remind;i++){               //這個for的用意是找到比目前資料day_str小的地方i插入
            if(strcmp(day_str,reminder[i]) <0){     //strcmp(比較物1-比較物2)等於0表示相同，小於0表示比較物1<比較物2,大於0表示比較物1>比較物2
                break;
            }
        }
        for(j =num_remind; j>i; j--){               //從目前的訊息筆數開始遞減到i的下一筆,把資料往後班一格
            strcpy(reminder[j],reminder[j-1]);      //strcpy(要複製到的地方(CTR +V),要複製的東西(CTR +C))
        }
        strcpy(reminder[i], day_str);               //地方找好，原本資料搬去下一格後，把day_str放到該位置
        strncat(reminder[i], msg_str,MSG_LEN);      //然後把訊息也串接到該位置strncat(位置，訊息，限制的大小)
        num_remind++;                               //別忘了最後訊息筆數要加1;
    }
    printf("\nDay Reminder\n");
    for(i = 0; i<num_remind; i++){                  //全部印出來
        printf("%s\n", reminder[i]);
    }
    return 0;
}
void read_line(char str[], int n){                  //暫時存訊息
    int i;
    char ch;
    for(i = 0; (ch=getchar())!='\n';i++){
        if(i < n){
            str[i]=ch;
        }
    }
    str[i] = '\0';
    //return i;
}