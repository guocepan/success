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