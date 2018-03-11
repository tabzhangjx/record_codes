#include<stdio.h>
#include<string.h>
struct goods{
    char name[10];
    int price;
    int num;
};

struct goods goods_change(struct goods a, int counts, int decrease){
	struct goods b;
	strcpy(b.name, a.name);
    b.price = a.price * counts / 10;
    b.num = a.num - decrease;
    printf("%s%s%s%d, %s%s%s%d\n", "new price of ", a.name, " is ", b.price, "new num of ", a.name, " is ", b.num);
    return b;
}

int main(){
    struct goods apple={"apple", 10, 100};
    int cou = 5;
    int decrea = 20;
    struct goods new_apple = goods_change(apple, cou, decrea);
    printf("%s%s%s%d, %s%s%s%d\n", "new price of ", "new_apple", " is ", new_apple.price, "new num of ", "new_apple", " is ", new_apple.num);
    apple = goods_change(apple, cou, decrea);
    printf("%s%s%s%d, %s%s%s%d\n", "new price of ", "apple", " is ", apple.price, "new num of ", "apple", " is ", apple.num);
    return 0;
}