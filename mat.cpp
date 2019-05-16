#include "mat.h"

mat::mat()
{
    this->x=15;
    this->y=15;
}

mat::mat(int x,int y)
{
    this->x=x;
    this->y=y;
}

int mat::getX(){
    return this->x;
}

int mat::getY(){
    return this->y;
}

QString choose(int num);

void mat::draw(QGridLayout* layout){

    for(int j=0;j<this->x;j++){
        for(int k=0;k<this->y;k++){
            QPushButton *btn=new QPushButton();

            QSizePolicy policy=btn->sizePolicy();
            policy.setHorizontalPolicy(QSizePolicy::Expanding);
            policy.setVerticalPolicy(QSizePolicy::Expanding);
            btn->setSizePolicy(policy);
            btn->setStyleSheet("background-color: rgb(255, 255, 255);");
//            QIcon icon(":/img/img/queen.png");


            layout->addWidget(btn,j,k);
        }
    }
}




QString choose(int num){

        srand((unsigned)time(NULL));
        vector<QString> vec(num);

        const vector<QString> samples{
            ":/res/res/gold.png",
            ":/res/res/stone.png",
            ":/res/res/strap.png",
            ":/res/res/road.png"
        };
        const vector<double> probabilities{ 0.01, 0.15, 0.05, 0.79 };

        std::default_random_engine generator;
        std::discrete_distribution<int> distribution(probabilities.begin(), probabilities.end());

        vector<int> indices(vec.size());
        std::generate(indices.begin(), indices.end(), [&generator, &distribution]() { return distribution(generator); });

        std::transform(indices.begin(), indices.end(), vec.begin(), [&samples](int index) { return samples[index]; });

        vector<QString>::iterator it=vec.begin();

        return *it;
}
