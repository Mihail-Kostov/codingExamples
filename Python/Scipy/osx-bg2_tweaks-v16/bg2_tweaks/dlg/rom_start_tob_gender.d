//REPLACE_TRIGGER_TEXT FATESP ~\(Global("\(CD\|FW\)\(LG\|CN\)?\(Aerie\|Anomen\|Dorn\|Hexxat\|Jaheira\|Neera\|Rasaad\|Viconia\)SummonedInRomance","GLOBAL",0)\)~ ~\1~
REPLACE_TRIGGER_TEXT FATESP ~\(Global("\(CD\|FW\)\(LGAnomen\|CNAnomen\|Hexxat\|Rasaad\)SummonedInRomance","GLOBAL",0)\)~ ~\1 Gender(Player1,FEMALE)~
REPLACE_TRIGGER_TEXT FATESP ~\(Global("\(CD\|FW\)\(LG\|CN\)?\(Aerie\|Jaheira\|Neera\|Viconia\)SummonedInRomance","GLOBAL",0)\)~ ~\1 Gender(Player1,MALE)~
