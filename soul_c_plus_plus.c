c语言的工作模式，将要处理的数据放在全局，这使得所有的函数都可以去更改他。
因为没有足够的数据类型。
将数据放在全局，意味着什么呢？好比一个家，没有了门，没有了看护者，随便一个人进来就能把
金银财宝拿走。

如果是c++呢？c++的模式就是给这些数据建筑围墙，进门需要经过门，门有保安，给你传话，你想要见到
某个人，就必须经过一个人传话，想要给某个人东西，就要经过特定的人传递。非常像监狱里的人，
监狱里的人就是这些数据，被保护的数据。要改变这些人，都得经过狱警，而狱警的职责都已经确定，
能开门的和能传话的不是同一个人，你要求的问题很过分，狱警就不会给你传递信息。这里的过分，就是
你设计的函数没有这个选项。和狱警没有上级获取权限一样，不能进行。
	这种制度，保证了数据的安全，也就是犯人的安全。
	
	
2 防卫式声明

#ifndef  _DOG_
#define  _DOG_
...

#endif  //_DOG_

为什么要这样声明。
这个好比上流人士都戴劳力士手表，都大保镖一样。
在程序里，这个防卫式声明就是为了
防止同一个头文件被重复包含。
在预编译阶段，编译器的目的就是将 XX.h展开。

例子：

car.h中：

class Car
{
	...
}

在che.h中：

#include "car.h"
class che
{
	
	public:
	Car  car;
	
}

在main.c中

#include  “car.h”
#include  "che.h"
#include <iostream>
using namespace std;

int main
{
	
	....
	
}

在预编译时，展开数据就变成了；


class Car
{
	...
}

class Car     //显然这两个已经重复定义了，这就是平时所说的redifinition  
{
	...
}

class che
{
	
	public:
	Car  car;
	
}

#include <iostream>
using namespace std;
int main
{
	
	....
	
}

所以防卫式的声明就是防止头文件同一个头文件被重复包含，就是同一个XX.h 被重复包含。



3、模板的语法；
模板就是现在还不去定义数据的类型是什么，而是在以后再对它进行定义。

template <typename T>  
class Dog
{
public:
	dog(T e = 0, T l = 0):eye(e),leg(l)
	{
		//这个地方的T也是后面定义写的。
	}

private :
T eye; //这个就是要被替换的t的类型
T leg;


};	

int main{
	
	Dog<double> xiaohei(2,4);
	Dog<int >   xiaohang(2,4);
}
这样就很简单的将他们的类型换掉了，而不用再设计一个新的class 就因为这个数据的类型不同。 






