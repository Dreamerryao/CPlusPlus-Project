#ifndef ARRAYC_H
#define ARRAYC_H

#include <vector>
class ARRAYC{
  private:
    int size;
    std::vector<int> Num;
  public:
    int type;
    ARRAYC(){
        size = 2;
        Num.resize(2);
        Num[0] = 1;
        Num[1] = 100;
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
        if(Num.size()==0)return true;
        return false;
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
        if(type==0){
            Num.push_back(a);
            size++;
            return 1;
        }
        else if(type==1){
            Num.push_back(a);
            size++;
            int pos=size-1;
            int temp;
            while(pos>0){
                if(Num[pos]<Num[(pos+1)/2-1]){
                    temp=Num[pos];
                    Num[pos]=Num[(pos+1)/2-1];
                    Num[(pos+1)/2-1]=temp;
                    pos=(pos+1)/2-1;
                }else{
                    break;
                }
            }
            return 1;
        }
    }
    int Del(int a){
        int flag = 0;
        for(int i=0;i<Num.size();i++){
            if(Num[i] ==a){
                flag  = 1;
                size--;
                Num.erase(Num.begin()+i);
                break;
            }
        }
        if(!flag) return 0;
        return 1;
    }
    int Pop(){
        int flag = 0;
        if(Num.size()!=0){
            flag = 1;
            size--;
            Num.erase(Num.begin()+(Num.size()-1));
        }
        if(!flag) return 0;
        return 1;
    }
    int Deq(){
        if(type==0){
            int flag = 0;
            if(Num.size()!=0){
                flag = 1;
                size--;
                Num.erase(Num.begin());
            }
            if(!flag) return 0;
            return 1;
        }
        else{
            if(Num.size()!=0){
                Num[0]=Num[size-1];
                Num.erase(Num.begin()+size-1);
                size--;
            }
            int pos=0,temp;
            while((pos+1)*2-1<=size-1){
                if((pos+1)*2<=size-1){
                    if(Num[pos]>Num[(pos+1)*2-1]||Num[pos]>Num[(pos+1)*2]){
                        if(Num[(pos+1)*2-1]<Num[(pos+1)*2]){
                            temp=Num[pos];
                            Num[pos]=Num[(pos+1)*2-1];
                            Num[(pos+1)*2-1]=temp;
                            pos=(pos+1)*2-1;
                        }else{
                            temp=Num[pos];
                            Num[pos]=Num[(pos+1)*2];
                            Num[(pos+1)*2]=temp;
                            pos=(pos+1)*2;
                        }
                    }else{
                        break;
                    }
                }
                else{
                    if(Num[pos]>Num[(pos+1)*2-1]){
                            temp=Num[pos];
                            Num[pos]=Num[(pos+1)*2-1];
                            Num[(pos+1)*2-1]=temp;
                            pos=(pos+1)*2-1;
                    }else{
                        break;
                    }
                }

            }
            return 1;
        }
    }
    int Replace(int index,int newValue){
        if(index>=size)return 0;
        Num[index]= newValue;
        return 1;
    }
    void New(int index){
        size = index;
        Num.resize(index);
        for(int i=0;i<size;i++){
            Num[i] = 0;
        }

    }
};

#endif // ARRAYC_H
