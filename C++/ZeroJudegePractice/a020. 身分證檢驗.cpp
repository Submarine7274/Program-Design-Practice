/*我國的身分證字號有底下這樣的規則，因此對於任意輸入的身分證字號可以有一些基本的判斷原則，請您來判斷一個身分證字號是否是正常的號碼(不代表確有此號、此人)。

(1) 英文代號以下表轉換成數字

      A=10 台北市     J=18 新竹縣     S=26 高雄縣
      B=11 台中市     K=19 苗栗縣     T=27 屏東縣
      C=12 基隆市     L=20 台中縣     U=28 花蓮縣
      D=13 台南市     M=21 南投縣     V=29 台東縣
      E=14 高雄市     N=22 彰化縣     W=32 金門縣
      F=15 台北縣     O=35 新竹市     X=30 澎湖縣
      G=16 宜蘭縣     P=23 雲林縣     Y=31 陽明山
      H=17 桃園縣     Q=24 嘉義縣     Z=33 連江縣
      I=34 嘉義市     R=25 台南縣

  (2) 英文轉成的數字, 個位數乘９再加上十位數的數字

  (3) 各數字從右到左依次乘１、２、３、４．．．．８

  (4) 求出(2),(3) 及最後一碼的和

  (5) (4)除10 若整除，則為 real，否則為 fake

 例：T112663836
    0123456789

2 + 7*9 + 1*8 + 1*7 + 2*6 + 6*5 + 6*4 + 3*3 + 8*2 + 3*1 + 6 = 180

除以 10 整除，因此為 real */
#include<iostream>
#include<string>
bool isRealID(const std::string& id);
int letterValue(char letter);
int main(){
    std::string id;
    while(std::cin>>id){
        if(isRealID(id)){
            std::cout<<"real"<<std::endl;
        }else{
            std::cout<<"fake"<<std::endl;
        }
    }
    return 0;
}
bool isRealID(const std::string& id){
    if(id.length()!=10) return false;
    if(!std::isalpha(id[0])){
        return false;
    }
    int Value=letterValue(id[0]);
    int sum=(Value%10)*9 + (Value/10);
    for(int i=1;i<=8;i++){
        if(!std::isdigit(id[i])){
            return false;
        }
        int numberPart =id[i]-'0';
        sum += numberPart * (9 - i);
    }
    sum += (id[9]-'0');
    return (sum % 10) == 0;
}
int letterValue(char letter){
    const int letterMap[26]={
        10,11,12,13,14,15,16,17,34,18,
        19,20,21,22,35,23,24,25,26,27,
        28,29,32,30,31,33
    };
    letter = std::toupper(letter);
    return letterMap[letter-'A'];
}