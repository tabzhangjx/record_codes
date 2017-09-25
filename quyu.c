
#include <stdio.h>

int main(){
    int x=10;
    while(x-->0){
        printf("%d \n",x);
    }
    
    static unsigned short stopwatch[]={
            0x07C6,
            0x1FF7,
            0x383B,
            0x600C,
            0x600C,
            0xC006,
            0xC006,
            0xDF06,
            0xC106,
            0xC106,
            0x610C,
            0x610C,
            0x3838,
            0x1FF0,
            0x07C0,
            0x0000
    };
    
    int y=8;
    y=~-y;
    y=~-y;
    
    
    
    printf("%d",y);
    return 0;
}
