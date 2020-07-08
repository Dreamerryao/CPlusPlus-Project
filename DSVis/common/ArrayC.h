#ifndef ARRAYC_H
#define ARRAYC_H

#include <vector>

class ARRAYC{
  private:
    int size;
    std::vector<int> Num;
  public:
    ARRAYC(){
        size = 0;
    }
    ~ARRAYC(){}
    void InitArrayc(){
        size = 2;
        Num.resize(2);
        Num[0] = 1;
        Num[1] = 100;
    }
    void takeClear(){
        Num.clear();
        size = 0;
    }
    bool isArrayNull(){
        if(Num.size()==0)return false;
        return true;
    }
    int getSize(){
        return size;
    }
    std::vector<int>&getArray(){
        return Num;
    }
    int getNumIndex(int index){
        return Num[index];
    }
    int Add(int a){
        Num.push_back(a);
        size++;
        return 1;
    }
    int Del(int a){
        int flag = 0;
        for(int i=0;i<Num.size();i++){
            if(Num[i] ==a){
                flag  = 1;
                Num.erase(Num.begin()+i);
                break;
            }
        }
        if(flag) return 0;
        return 1;
    }
};

#endif // ARRAYC_H
