<pre name="code" class="cpp">#include <iostream>  
//#include <fstream>  
#include <string>  
#include <stdlib.h>  
#include <time.h>  
  
  
  
using namespace std;  
  
const int PACK_MAX_W = 80;                  //背包最大承受重量  
const int PACK_MAX_V = 75;                  //背包最大承受容积  
const int NUM = 32;                         //物品数  
const int MAX_GENERATION = 100;             //遗传最大代数  
const int PS = 500;                         //种群规模  
const float PC = 0.8;                       //交叉率  
const float PV = 0.1;                      //变异率  
  
  
const int zl[NUM]={22,15,4,5,10,19,21,20,8,13,2,3,3,17,12,5,12,4,1,21,14,23,17,15,20,22,25,0,22,15,25,13};  
const int tj[NUM]={11,22,12,21,21,13,1,10,13,8,6,25,13,27,12,23,12,24,23,11,6,24,28,10,20,13,25,23,5,26,30,15};  
const int value[NUM]={8,9,15,6,16,9,1,4,14,9,3,7,12,4,15,5,18,5,15,4,6,2,12,14,11,9,13,13,14,13,19,4};  
  
//随机产生01  
int pp(){  
    float p;  
    p = rand() % 1000 / 1000.0;  
    if(p < 0.8)  
        {//cout<<0<<" ";  
        return 0;}  
    else  
        {//cout<<1<<" ";  
        return 1;}  
}  
//个体类  
class Entity{  
public:  
    int fit;  
    int sum_w;  
    int sum_v;  
    int sum_val;  
    int gene[NUM];  
    int _count;  
  
    Entity(){  
    fit = 0;  
    sum_v = 0;  
    sum_w = 0;  
    sum_val = 0;  
    int i;  
    for(i = 0;i < NUM;i++)  
        gene[i] = 0;  
    }  
  
};  
  
//遗传算法类  
class GA{  
  
private:  
  
        Entity zq[PS];                          //种群  
        Entity max_single;                      //最优个体  
  
public:  
        //读取物品的价值体积重量  
        //void readData();  
        //初始化种群  
        void Init();  
        //计算个体价值重量重量  
        int Cal_SingleValue(int row);  
  
        int Cal_SingleW(int row);  
  
        int Cal_SingleV(int row);  
        //计算个体适应度  
        void Cal_Fitness();  
        //计算价值最大个体  
        void Cal_Maxval_Single(int _generation);  
        //选择  
        void Select();  
        //是否交叉  
        bool IsCross() {  return ( ( rand() % 1000 / 1000.0 ) <= PC ); }  
        //交叉  
        void Cross();  
        //是否变异  
        bool IsVariation() {  return ( ( rand() % 1000 / 1000.0 ) <= PV ); }  
        //变异  
        void Variation();  
        //进行遗传，每五代几率变异  
        void Run(){  
  
            int i;  
            //readData();  
            Init();  
            for(i = 0; i < MAX_GENERATION; i++){  
                Cal_Fitness();  
                Cal_Maxval_Single(i);  
                Select();  
                Cross();  
                if(i % 5 == 0 && i != 0){  
                    Variation();  
                }  
            }  
            Cal_Fitness();  
            Cal_Maxval_Single(MAX_GENERATION);  
            cout<<"The best value is:"<<max_single.fit<<endl;  
            cout<<"The best entity's gene is:"<<endl;  
            for(int i = 0;i < NUM;i++){  
                cout<<max_single.gene[i];  
                if(i!=NUM-1)  
                    cout<<" ";  
            }  
  
            cout<<endl<<"The best entity is in the "<<max_single._count<<" generation."<<endl;  
  
        }  
};  
/* 
void GA::readData(){ 
    ifstream fin; 
    fin.open("input.txt"); 
    if(!fin) 
        cout<<"error"<<endl; 
    int n,i; 
            //fin>>n;PACK_MAX_V = n; 
            //fin>>n;PACK_MAX_W= n; 
            //fin>>n;NUM = n; 
    for(i = 0;i < NUM;i++){ 
        fin>>n; 
        value[i] = n; 
    } 
    for(i = 0;i < NUM;i++){ 
        fin>>n; 
        tj[i] = n; 
    } 
    for(i = 0;i < NUM;i++){ 
        fin>>n; 
        zl[i] = n; 
    } 
 
    //for(i=0;i<NUM;i++){ 
    //    cout<<value[i]<<" "<<tj[i]<<" "<<zl[i]<<endl; 
    //} 
 
} 
*/  
  
  
void GA::Init(){  
    int i,j,wsum,vsum;  
    for(i = 0;i < PS;i++){  
        wsum = 0;  
        vsum = 0;  
        for(j = 0;j < NUM;j++){  
            zq[i].gene[j] = pp();  
            wsum += zq[i].gene[j]*zl[j];  
            vsum += zq[i].gene[j]*tj[j];  
            }  
        if(wsum > PACK_MAX_W||vsum > PACK_MAX_V)    //产生符合条件的个体  
            i--;  
    }  
/* 
    cout<<"Init:"<<endl; 
    for (i = 0;i < PS;i++){ 
        for (j = 0;j < NUM;j++) 
            cout<<zq[i].gene[j]<<" "; 
        cout<<endl; 
    } 
*/  
}  
  
int GA::Cal_SingleValue(int row){  
    int j,valuesum = 0;  
    for(j = 0;j < NUM;j++){  
        valuesum += zq[row].gene[j]*value[j];  
    }  
    zq[row].sum_val = valuesum;  
    return valuesum;  
}  
  
int GA::Cal_SingleW(int row){  
    int j,wsum = 0;  
    for(j = 0;j < NUM;j++){  
        wsum += zq[row].gene[j]*zl[j];  
    }  
    zq[row].sum_w = wsum;  
    return wsum;  
}  
  
int GA::Cal_SingleV(int row){  
    int j,vsum = 0;  
    for(j = 0;j < 32;j++){  
        vsum += zq[row].gene[j]*tj[j];  
    }  
    zq[row].sum_v = vsum;  
    return vsum;  
}  
  
void GA::Cal_Fitness(){  
    int i,w,v,val;  
    for(i = 0; i < PS; i++) {  
        w = Cal_SingleW(i);  
        v = Cal_SingleV(i);  
        val = Cal_SingleValue(i);  
        if(w > PACK_MAX_W || v > PACK_MAX_V) { zq[i].fit = 0; continue; }  
        zq[i].fit = val;  
        //cout<<zq[i].fit<<endl;  
        }  
  
}  
  
void GA::Cal_Maxval_Single(int _generation){  
    int i,maxval = zq[0].fit,id = 0;  
    for(i = 0;i < PS;i++)  
        if(maxval < zq[i].fit){  
            maxval = zq[i].fit;  
            id = i;  
        }  
    if(maxval > max_single.fit){  
        max_single = zq[id];  
        max_single._count = _generation;  
    }  
}  
  
void GA::Select(){  
  
    int fit_sum = 0,i,j;  
    float rand_rate,cur_rate;  
    float selected_rate[PS];  
    Entity new_zq[PS];  
  
    for(i = 0;i < PS; i++){  
        fit_sum += zq[i].fit;  
    }  
    //使用轮赌法进行选择  
    selected_rate[0] = float(zq[0].fit) / fit_sum;  
  
    for(i = 1; i < PS; i++){  
        cur_rate = selected_rate[i-1] + float(zq[i].fit) / fit_sum;  
        selected_rate[i] = cur_rate;  
    }  
  
    for(i = 0; i < PS; i++) {  
        rand_rate = ( rand() % 1000 / 1000.0 );  
        for (j = 0; j < PS; j++) {  
            if(rand_rate <= selected_rate[j]) {  
                new_zq[i] = zq[j];  
                break;  
            }  
        }  
    }  
    for(i = 0;i < PS;i++){  
        zq[i]= new_zq[i];  
        //cout<<zq[i].fit<<endl;  
    }  
  
}  
  
void GA::Cross(){  
    int i,j;  
    for(i = 0;i < PS - 1;i += 2){  
        Entity en1 = zq[i];  
        Entity en2 = zq[i + 1];  
  
        for(j = 0;j < NUM; j++){  
            if(IsCross()){  
                int tmp = en1.gene[j];  
                en1.gene[j] = en2.gene[j];  
                en2.gene[j] = tmp;  
            }  
        }  
        zq[i]=en1;  
        zq[i+1]=en2;  
    }  
}  
  
void GA::Variation(){  
    int i,j;  
    for(i = 0;i < PS;i++){  
        if(IsVariation()){  
            for (j = 0;j < NUM;j++){  
                if(IsVariation()){  
                    zq[i].gene[j] = zq[i].gene[j] ? 0 : 1;  
                }  
            }  
        }  
    }  
}  
  
int main(){  
    srand(time(NULL));  
    GA temp;  
    temp.Run();  
    return 0;  
}</pre><br>  
<br>  
<pre></pre>  
<br>  