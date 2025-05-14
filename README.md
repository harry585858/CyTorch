AI with CPP


How to use

Layer_4 newone(4); //or Layer_8
Layer_4 otherone(5); //this is float(4byte)
Endlayer endone(5); // last layer
newone.append(&otherone); // append(link)
newone.runlayer(); // run this is not 'fit'
otherone.runlayer(); // 
endone.runlayer(); // running 'Endlayer' will print the result
