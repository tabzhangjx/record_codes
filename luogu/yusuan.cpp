#include<iostream>
//#include<fstream>

//std::ifstream fin("save.in");
//std::ofstream fout("save.out");

int main(){
    int save[12];
    int rest=0;
    int saves=0;
    for(int i=0; i<12; i++)
        std::cin>>save[i];
    for(int i=0; i<12; i++){
        if(save[i]>(rest+300)){
            std::cout<<'-'<<i+1;
            return 0;
        }
        else{
            //std::cout<<rest<<' '<<saves<<' '<<save[i]<<std::endl;
            rest=(300+rest-save[i]);
            //std::cout<<rest<<' '<<saves<<std::endl;
            saves+=100*((int)(rest/100));
            //std::cout<<rest<<' '<<saves<<std::endl;
            rest=rest%100;
            //std::cout<<rest<<' '<<saves<<std::endl<<std::endl;
        }
    }
    std::cout<<rest+saves*1.2;

    return 0;
}
