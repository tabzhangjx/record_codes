#include <iostream>

int main(){
    int a1=1, a2=1;
    char str1[7], str2[7];
    std::cin.getline(str1, 7);
    std::cin.getline(str2, 7);
    for (int i=0; str1[i]!='\0';i++){
        a1*=(str1[i]-'A'+1);
        a1=a1%47;
    }
    for (int i=0; str2[i]!='\0';i++){
        a2*=(str2[i]-'A'+1);
        a2=a2%47;
    }
    if (a1==a2)
    	std::cout<<"GO";
    else
    	std::cout<<"STAY";
    return 0;
}
