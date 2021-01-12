console.log(":_:XD");

var entSys = new EntSys();

entSys.addSys(new PhySys());

entSys.addCmp(new PhyCmp(5));
entSys.addCmp(new PhyCmp(6));
entSys.addCmp(new PhyCmp(7));

console.log(entSys.systems[0].components);