//
//  main.cpp
//  circle
//
//  Created by 徐宁 on 2020/5/27.
//  Copyright © 2020 徐宁. All rights reserved.
//

//圆排列问题
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define N 4
double r[N];//记录圆的半径
double x[N];//记录排列圆的圆心横坐标
double best[N+1];//记录最优圆排列序号
float Min=1000;//记录当前最优值  要给一个较大值 小的才能进 不然给个0结果不会比他小
double center(int t){
    double length=0;
    for(int i=1;i<t;i++){//逐一计算 当前圆t可能和之前每个圆都相切
       double temp=x[i]+2*sqrt((r[t]*r[i]));//前一个的圆心横坐标 加上二者圆心距的水平分量
        if(temp>length)
        length=temp;
    }
    return length;
}
void compute(){//计算当前圆排列的长度
    double left=0;
    double right=0;
    for(int i=1;i<N;i++){
        if(x[i]-r[i]<left)//计算出最左端
        left=x[i]-r[i];
        if(x[i]+r[i]>right)//计算出最右端
        right=x[i]+r[i];
    }
    if((right-left)<Min){
    Min=right-left;//更新最优值
    for(int i=1;i<N;i++)//设置一个数组 记录最优圆排列的顺序
    best[i]=r[i];
    }
    
}
void dfs(int t){
    if(t==N)//最后一个圆
    compute();//计算当前的圆排列长度
    else{
        for(int i=t;i<N;i++){
            swap(r[t],r[i]);//全排列
            double cen=center(t);//得到圆t的圆心横坐标
        if(r[1]+cen+r[t]<Min){
            x[t]=cen;//更新
            dfs(t+1);
        }
        swap(r[t],r[i]);//全排列回换
        }
    }
}
int main(){
    cout<<"请依次输入圆的半径："<<endl;
    for(int i=1;i<N;i++)
    cin>>r[i];
    dfs(1);
    cout<<"最优圆排列长度："<<Min<<endl;
    cout<<"最优圆排列顺序：(按半径排)"<<endl;
    for(int i=1;i<N;i++){
        cout<<best[i]<<" ";
    }
}
