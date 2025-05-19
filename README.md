AI with CPP


How to use

```
srand(static_cast<unsigned int>(time(NULL))); //set random
Model model(3, {3,3,3});//make model 3 layers input:3 hiddenlayer:3 output:3(Vecters)
model.fit({1,1,1}, {1,1,1}); // fit
model.foward({1,1,1},{1,1,1}); // foward(get expectaions)

```
