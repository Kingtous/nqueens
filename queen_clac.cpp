#include "queen_clac.h"

queen_clac::queen_clac(int num)
{
    this->num=num;
}


int* locateQueen(int num){
    //num的范围为10^3-10^6，所以不能用二维数组存储数据，只存下标
    int * arr=new int[num];
    std::set<int> s;
    for (int i=0;i<num;i++) {
        //随机将queen放入各个列
        loop:
        int n=rand()%num;
        if(s.find(n)==s.end()){
            s.insert(n);
        }
        else{
            goto loop;
        }

        arr[i]=rand()%num;
    }
    return arr;
}

long long calc_h(int * arr,int maxNum,int col,int row){
    //计算启发函数：在（arr[col]=row时，皇后有冲突的个数）
    int * arr_copy=new int[maxNum];
    memcpy(arr_copy,arr,maxNum*sizeof (int));
    arr_copy[col]=row;

    long long cnt=0;
    for(int j=0;j<maxNum;j++){
        for (int k=1;k<maxNum;k++) {
//            QCoreApplication::processEvents();
            if(j==k)
                continue;
            if(abs(arr_copy[j]-arr_copy[k])==abs(k-j) || arr_copy[j]==arr_copy[k]){
                cnt++;
            }
        }
    }
    return cnt;
}


void showStatus(int * queens,int num,QTextBrowser * browser,QStatusBar * statusBar){
    QString output="";
    for (int j=0;j<num;j++) {
        output.append(QString::number(queens[j])+" ");
    }
    browser->append(output);
}

void resetQueens(int * &queens,int maxNum){
    //释放内存
    free(queens);
    //重新编排
    queens=locateQueen(maxNum);
}




void queen_clac::startClac(QTextBrowser * browser,QStatusBar * statusBar){

    //计时
    QTime t;
    t.start();

    int * queens=locateQueen(this->num);
    long long h=calc_h(queens,this->num,0,queens[0]);

    long long maxStep=this->num*this->num;
    long long currentStep=0;

    showStatus(queens,this->num,browser,statusBar);
    //从第0行开始爬山
    int col=0;
    while (h!=0) {
        //图形输出
        //步数超过定义的最大步数
        if(currentStep>maxStep){
            resetQueens(queens,this->num);
            currentStep=0;
            continue;
        }

        //取得放的最好的位置
        int best_row=0;
        long long best_h=this->num*2;
        for (int i=0;i<num;i++) {
            long long best_h_tmp=calc_h(queens,this->num,col,i);
            if (best_h_tmp<best_h){
                best_h=best_h_tmp;
                best_row=i;
            }
        }

        queens[col]=best_row;
        h=best_h;
        showStatus(queens,this->num,browser,statusBar);

        // 列循环
        col=(col+1)%this->num;
        ++currentStep;

    }
    showStatus(queens,this->num,browser,statusBar);
    browser->append("已完成，最终结果：");

    showStatus(queens,this->num,browser,statusBar);
    browser->append("用时:"+QString::number(t.elapsed()/1000.0)+'s');

}




