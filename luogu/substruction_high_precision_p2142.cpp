#include <bits/stdc++.h>
using namespace std;

struct pe{
    int a, b, c;
}p[100005];

bool cmp(const pe &a, const pe &b){
    if(a.c!=b.c)
        return a.c<b.c;
    else
        return a.b>b.b;
}

class high_precision{
public:
	int sign;
    int w[30010];//低位在左
    int count;
    high_precision(){};
    high_precision(int a);
    ~high_precision();
    high_precision operator+(const high_precision a);
    high_precision operator-(const high_precision a);
    high_precision operator-(const int a);
    high_precision operator*(const int a);
    high_precision operator/(const int a);
    friend istream& operator>>(istream &in, high_precision &c);
    friend ostream& operator<<(ostream &out, high_precision &c);
};

high_precision::~high_precision(){
	sign=0;
    for(int i=1;i<30010;i++)
        w[i]=0;
    count=0;
}

high_precision::high_precision(int a){
	sign=0;
	if(a<0){
		sign=1;
		a=-a;
	}
    for(int i=1;i<30010;i++)
        w[i]=0;
    int i=0;
    count=0;
    while(a>0){
        w[i]=a%10;
        a/=10;
        count++;
    }
}

high_precision high_precision::operator+(const high_precision a){
	if(a.sign==0&&this->sign==1){
		return a-this;
	}
	else if(a.sign==1&&this->sign==0){
		return this-a;
	}
	else if(a.sign==1&&this->sign==1){
		
	}
    high_precision m;
    for(int i=0;i<this->count||i<a.count;i++){
        m.w[i+1]=m.w[i+1]+(m.w[i+1]+this->w[i]+a.w[i])/10;
        m.w[i]=(m.w[i]+this->w[i]+a.w[i])%10;
        m.count++;
    }
    return m;
}

high_precision high_precision::operator-(const high_precision a){
    high_precision m;
    for(int i=0;i<this->count||i<a.count;){
    	if(this->w[i]>=a.w[i]){
    		m.w[i]=this->w[i]-a.w[i];
    		i++;
    		m.count++;
    	}
    	else{
    		this->w[i]+=10;
    		this->w[i+1]-=1;
    	}
    }
    for(int i=count-1;i>=0;i--){
    	if(m.w[i]==0){
    		m.count--;
    	}
    	else{
    		break;
    	}
    }
    return m;
}

high_precision high_precision::operator*(const int a){
    for(int i=0;i<count;i++)
        w[i]*=a;
    for(int i=0;i<count;i++){
        if(w[i]>9){
            w[i+1]+=(w[i]/10);
            w[i]%=10;
        }
    }
    int t=w[count];
    while(t>0){
        count+=1;
        w[count+1]=0;
        if(t>9){
            w[count]=w[count-1]/10;
            w[count-1]%=10;
        }
        else{
            break;
        }
        t=w[count];
    }
    high_precision m;
    for(int i=0;i<count;i++){
        m.w[i]=w[i];
    }
    m.count=count;
    return m;
}

high_precision high_precision::operator/(const int a){//abandun rest
    high_precision m;
    int t=0, label=0;
    for(int i=count-1;i>=0;i--){
        t=t*10+w[i];
        if(t>=a){
            m.w[i]=t/a;
            t%=a;
            if(label==0){
                m.count=i+1;
                label=1;
            }
        }
        else{
            m.w[i]=0;
        }
    }
    if(label==0) count=0;
    return m;
}

istream  &operator>>(istream &in, high_precision &c)
{
    string str;
    cin>>str;
    int i=(int)str.length();
    int t=0;
    c.count=0;
    while(t<i){
        c.w[t]=(int)(str[i-1-t]-'0');
        t++;
        c.count++;
    }
    return in;
}

ostream  &operator<<(ostream &out, high_precision &c)
{
    for(int i=c.count-1;i>=0;i--){
        cout<<c.w[i];
    }
    return out;
}

int main(){
    high_precision a1;
    high_precision a2;
    cin>>a1>>a2;
    a1=a1-a2;
    cout<<a1;
    return 0;
}
