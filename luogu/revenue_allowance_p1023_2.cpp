#include<iostream>
#include<algorithm>

int pre, x1;
int a[10001], b[10001];
int change, nums = 1;
int i, j, nums_1, label1, label2, label3, n1, n2;

int cmp(int a, int b)
{
    return a > b;
}

void ope() {
    for (j = a[i - 1] + 1; j<a[i]; j++) {
        a[nums_1] = j;
        b[nums_1] = b[i - 1] - (b[i - 1] - b[i]) / (a[i] - a[i - 1])*(j - a[i - 1]);
        nums_1++;
    }
}

int main()
{
    std::cin >> pre >> a[0] >> b[0];
    while (a[nums - 1] != -1 && b[nums - 1] != -1) {
        std::cin >> a[nums] >> b[nums];
        nums++;
    }
    nums--;
    std::cin >> change;
    nums_1 = nums;
    for (i = 1; i < nums; i++) if (a[i] - a[i - 1] > 1) ope();
    std::sort(a, a + nums_1);
    std::sort(b, b + nums_1, cmp);
    for (i = 1; i<nums_1; i++)
        if (a[i] == pre) {
            x1 = b[i];
            label1 = 1;
        }
    if (label1 == 0)
        x1 = b[nums_1 - 1] - (pre - a[nums_1 - 1])*change;
    for (i = 0;; i++) {
        label2 = 0;
        label3 = 0;
        n1 = (pre - a[0] + i)*x1;
        n2 = (pre - a[0] - i)*x1;
        for (j = 1;; j++) {
            if (j >= nums_1) {
                b[j] = b[j - 1] - change;
                a[j] = a[j - 1] + 1;
            }
            if (b[j] <= 0)break;
            if (n1<(a[j] - a[0] + i)*b[j])label2 = 1;
            if (n2<(a[j] - a[0] - i)*b[j] || n2 <= 0)label3 = 1;   
        }
        if (label2 == 0 && label3 == 1)break;
        else if (label2 == 1 && label3 == 0)break;
        else if (label2 == 0 && label3 == 0)break;
        else if (i == b[0] * 10) {
            label2 = -2; 
            break;
        }
    }
    if (label2 == 1 && label3 == 0) std::cout << '-' << i;
    else if (label2 == 0 && label3 == 1) std::cout << i;
    else if (label2 == 0 && label3 == 0) std::cout << i;
    else if (label2 == -2) std::cout << "NO SOLUTION";
    return 0;
}
