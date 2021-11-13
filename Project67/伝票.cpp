#include<iostream>
#include<string.h>

using namespace std;

class DrinkBox{
public:
	//コンストラクタ
	DrinkBox(){}
	DrinkBox(const char *str, int n1, int n2) {
		name = new char[strlen(str) + 1];//文字数に合わせて動的にメモリを確保
		strcpy(name, str);
		price = n1;
		count = n2;
	}
	//デストラクタ
	~DrinkBox(){
		delete[] name; //メモリを解放
	}

int GetTotalPrice() {
	return count * price;
}

void PrintTitle() {
	cout << "商品名\t\t単価\t数量\t金額" << endl;
}

void PrintData() {
	cout << name << "\t" << price << "\t"
		<< count << "\t" << GetTotalPrice() << endl;
}

char *name;
int price;
int count;
};

class AlcoholBox : public DrinkBox {
public:
	AlcoholBox(const char *str, int n1, int n2, float f) {
		name = new char[strlen(str) + 1];
		strcpy(name, str);
		price = n1;
		count = n2;
		alcper = f;
	}
	void PrintTitle() {
		cout << "商品名(度数[%])\t単価\t数量\t金額" << endl;
	}
	void PrintData() {
		cout << name << "(" << alcper << ") \t" << price << "\t"
			<< count << "\t" << GetTotalPrice() << endl;
	}

private:
	float alcper;
};

int main()
{
	DrinkBox coffee("コーヒー",200, 3);
	DrinkBox oolongtea("ウーロン茶", 150, 2);
	AlcoholBox wine("ワイン", 300, 2, 15.0);

	coffee.PrintTitle();
	coffee.PrintData();
	oolongtea.PrintData();
	wine.PrintTitle();
	wine.PrintData();

	int sum = coffee.GetTotalPrice()
		+ oolongtea.GetTotalPrice() + wine.GetTotalPrice();
	cout << "\n*** 合計金額" << sum << "円***"<< endl;
	return 0;

}


