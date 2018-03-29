#include <iostream>

int main(){
    int n;
    std::cin>>n;
    char a;
    std::cin>>a;
    char str[55];
    std::cin.getline(str+1,55);
    str[0]=a;
    int i=0;
    while(str[i]!='\0'){
        str[i]=((str[i]-'a'+n)%26+'a');
        i++;
    }
    std::cout<<str;

    return 0;
}
