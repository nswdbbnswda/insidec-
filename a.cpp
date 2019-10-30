#include<iostream>
#include<stdio.h>
#include<vector>
#include<typeinfo>
#include<string>


using namespace std;


class X{};
class Y : public virtual X{};
class Z : public virtual X{};
class AX : public Y, public Z{};


class ZooAnimal{
public:
	ZooAnimal(){
	}

	virtual ~ZooAnimal(){
	}
protected:
	int loc;
	string name;
};


class Bear : public ZooAnimal{
public:
	Bear(){}
	~Bear(){}
	void rotate(){}
	virtual void dance(){
	}
protected:
	int cell_block;
};



template<typename T>
class Point{
public:
	long _x = 11;
	long _y = 30;
	long _z = 40;
public:
	void show(){
		cout<<this->_x<<" "<<&_x<<endl;
		cout<<this->_y<<" "<<&_y<<endl;
		cout<<this->_z<<" "<<&_z<<endl;
	}


	virtual void test1(){
		cout<<"This is virtual test1"<<endl;
	}
	virtual void test2(){
		cout<<"This is virtual test2"<<endl;
	}
	virtual void test3(){
		cout<<"This is virtual test3"<<endl;
	}
};

template<typename T>
class Line{
protected:
	int type = 99;
public:
	virtual void drawLine(){
		cout<<"drawLine..."<<endl;
	}
};

template<typename T>
class Shape : public Point<T>, public Line<T>{
protected:
	int weight = 88;
};


template<typename T>
class Point2 : public Point<T>{
protected:
	int _g = 70;
public:
	virtual void test2(){
		cout<<"This is Point2 virutal test2"<<endl;
	}
	virtual void test4(){
		cout<<"This is Point2 virtual test4"<<endl;
	}
 };



template<typename T>
class Point2_b : public Point<T>{
public:
	virtual void test2(){
		cout<<"This is Point2_b test2"<<endl;
	}
	virtual void test2b(){
		cout<<"This is point2 test2b"<<endl;
	}

};


template<typename T>
class Point3 : virtual public Point<T>,  virtual public Point2_b<T>{
public:
	virtual void testPoint3(){
		cout<<"This  is Point3 testPoint3"<<endl;
	}
};


struct Student{
	int age;
	int score;
};

void test(void){
	cout<<"This is test func"<<endl;
}

class A{
public:
	virtual ~A(void){
	}
};

class B:public A{
};


class C:public B{
};



int main(){
	
	puts("---------------------Student----------------------");
	cout<<sizeof(int)<<endl;
	Student lichao;
	lichao.age=25;
	lichao.score=20;
	cout<<sizeof(lichao)<<endl;
	cout<<sizeof(Student)<<endl;
	
	puts("---------------------Point1----------------------");
	typedef void(*Fun)(void);
	Point<float> point;
	long *vptr = (long*)&point;

	long *bAddress = (long*)&point;    
    long mem1 = (long)*(bAddress + 1);
    long mem2 = (long)*(bAddress + 2);
    long mem3 = (long)*(bAddress + 3);
	
	cout<<"x is ： "<<mem1<<" mem addr"<<&mem1<<endl;
	cout<<"y is ： "<<mem2<<" mem addr"<<&mem2<<endl;
	cout<<"z is ： "<<mem3<<" mem addr"<<&mem3<<endl;
	point.show();

	printf("vptb %p\n", *vptr);
	Fun fun1 = (Fun)*(long*)(*vptr);
	Fun fun2 = (Fun)*((long*)(*vptr) + 1);
	Fun fun3 = (Fun)*((long*)(*vptr) + 2);
	//Fun fun4 = (Fun)*((long*)(*vptr) + 3);
	fun1();
	fun2();
	fun3();
	//fun4();

	Point<float>  *p1;
	cout<<sizeof(*p1)<<endl;

	//cout<<"y is ： "<<y<<" mem addr"<<&y<<endl;
	puts("---------------------Point2----------------------");
	Point2<float> point2;
	long *vptr2 = (long*)&point2;
	printf("vptb %p\n", *vptr2);
	Fun point2_fun1 = (Fun)*(long*)(*vptr2);
	Fun point2_fun2 = (Fun)*((long*)(*vptr2) + 1);
	Fun point2_fun3 = (Fun)*((long*)(*vptr2) + 2);
	Fun point2_fun4 = (Fun)*((long*)(*vptr2) + 3);
	long *b2Address = (long*)&point2;    
    long mem21 = (long)*(b2Address + 1);
    long mem22 = (long)*(b2Address + 2);
    long mem23 = (long)*(b2Address + 3);
    long mem24 = (long)*(b2Address + 4);
	point2_fun1(); 
	point2_fun2(); 
	point2_fun3(); 
	point2_fun4(); 
	cout<<mem21<<endl;
	cout<<mem22<<endl;
	cout<<mem23<<endl;
	cout<<mem24<<endl;

	puts("--------------------data--------------------------");
	cout<<sizeof(point)<<endl;
	cout<<sizeof(Point<float>)<<endl;
	cout<<sizeof(Point2<float>)<<endl;


	puts("--------------------point3--------------------------");
	Point3<float> point3;
	long *vptr3 = (long*)&point3;
	Fun p3fun1 = (Fun)*((long*)(*vptr3));
	Fun p3fun2 = (Fun)*((long*)(*vptr3) + 1);
	Fun p3fun3 = (Fun)*((long*)(*vptr3) + 2);
	Fun p3fun4 = (Fun)*((long*)(*vptr3) + 3);
	Fun p3fun5 = (Fun)*((long*)(*vptr3) + 4);
	long *m1 =  (vptr3 + 1);
	long *m2 =  (vptr3 + 2);
	long *m3 =  (vptr3 + 3);
	long *m4 =  (vptr3 + 4);
	long *m5 =  (vptr3 + 5);
	long *m6 =  (vptr3 + 6);
	long *m7 =  (vptr3 + 7);
	long *m8 =  (vptr3 + 8);
	cout<<*m1<<endl;
	cout<<*m2<<endl;
	cout<<*m3<<endl;
	cout<<*m4<<endl;
	cout<<*m5<<endl;
	cout<<*m6<<endl;
	cout<<*m7<<endl;
	cout<<*m8<<endl;
	p3fun1(); 
	//point3.test1();
	//p3fun2(); 
	//p3fun3(); 
	///p3fun4(); 
	puts("--------------------dynamic_cast--------------------------");
	B b;
	A  *pa = &b;
	C c;
	cout<<"pa="<<pa<<endl;
	cout<<"----dynamic_cast---"<<endl;
	

	//pa实际指向的B对象,转换成功
	B *pb = dynamic_cast<B*>(pa);
	cout<<"pb="<<pb<<endl;
	//pa没有指向C对象，转换失败
	C *pc = dynamic_cast<C*>(pa);
	cout<<"pc="<<pc<<endl;//pc=NULL

	double a1 = 1.999;
	int b1 = static_cast<double>(a1);
	cout<<b1<<endl;

	puts("--------------------typeid-----------------------");
	cout<<typeid(a1).name()<<endl;
	cout<<typeid(b1).name()<<endl;
	cout<<typeid(b).name()<<endl;
	cout<<typeid(point).name()<<endl;
	cout<<typeid(point3).name()<<endl;


	puts("--------------------多继承非菱形继承对象内存布局探索-----------------------");
	Shape<float> shape;
	long *vptr4 = (long*)&shape;
	Fun sp3fun1 = (Fun)*((long*)(*vptr4));
	Fun sp3fun2 = (Fun)*((long*)(*vptr4) + 1);
	Fun sp3fun3 = (Fun)*((long*)(*vptr4) + 2);
	Fun sp3fun4 = (Fun)*((long*)(*vptr4) + 3);
	sp3fun1();
	sp3fun2();
	sp3fun3();
	//sp3fun4();

	long *sm1 =  (vptr4 + 1);
	long *sm2 =  (vptr4 + 2);
	long *sm3 =  (vptr4 + 3);
	long *sm4 =  (vptr4 + 4);
	long *sm5 =  (vptr4 + 5);
	cout<<*sm1<<endl;
	cout<<*sm2<<endl;
	cout<<*sm3<<endl;
	cout<<*sm4<<endl;


	puts("--------------------XYZA-----------------------");
	cout<<sizeof(X)<<endl;
	cout<<sizeof(Y)<<endl;
	cout<<sizeof(Z)<<endl;

	return 0;
}
