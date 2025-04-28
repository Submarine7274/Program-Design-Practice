#include"package.h"         //這邊再include package一次的原因是，怕有人動到.h檔的內容，造成不必要的問題
#include"TwoDayPackage.h"
#include<stdexcept>
#include<sstream>
/*Constructor 一樣很長， */
TwoDayPackage::TwoDayPackage(const string& newSenderName,
    const string& newSenderAddress,
    const string& newSenderCity,
    const string& newSenderState,
    unsigned int newSenderZIPCode,
    const string& newRecipientName,
    const string& newRecipientAddress,
    const string& newRecipientCity,
    const string& newRecipientState,
    unsigned int newRecipientZIPCode,
    double newWeight,
    double newCostPerOunce,
    double newFlatFee)
    : Package(newSenderName,newSenderAddress,newSenderCity,newSenderState,newSenderZIPCode,newRecipientName,newRecipientAddress,newRecipientCity,newRecipientState,newRecipientZIPCode,newWeight,newCostPerOunce)
    //上面這邊是呼叫父類別constructor，也就是Package的constructor，因為這些data member都是父類別才有，TwoDayPackage這個class的data member只有 flatfee(處理費用)而已
    {   
        setFlatFee(newFlatFee);         //一樣把資料檢查的功能用set處理
}
void TwoDayPackage::setFlatFee(double newFlatFee){      //處理費如果是負的，就throw
    if(newFlatFee <0){
        throw invalid_argument("Flat fee must lagger than 0.");
    }
    flatFee =newFlatFee;
}
double TwoDayPackage::getFlatFee(){return flatFee;}
double TwoDayPackage::calculateCost(){          //這邊是計算費用，重量乘以運費 加上處理費，我們可以直接呼叫父類別的計算運費，再加上TwoDayPackage這個class的處理費
    return Package::calculateCost()+getFlatFee();
}
string TwoDayPackage::toString(){
    ostringstream output;
    output<<Package::toString()     //因為前面的輸出字串一樣，所以呼叫Package的輸出字串，後面加上TwoDayPackage的額外資訊
    <<"\nTwo day flat fee:$"<<getFlatFee()
    <<"\nDelivery fee:$"<<calculateCost();
    return output.str();
}