REPLACE_ACTION_TEXT ANOMENJ  ~EscapeAreaMove("AR0903",852,1235,\(NNW\|7\))~ ~EscapeAreaMove("AR0903",1516,1235,9)~
REPLACE_ACTION_TEXT ANOMENP  ~EscapeAreaMove("AR0903",852,1235,\(NNW\|7\))~ ~EscapeAreaMove("AR0903",1516,1235,9)~
REPLACE_ACTION_TEXT HPRELATE ~CreateCreature("demson",\[1194\.1129\],13)~   ~CreateCreature("demson",[1174.1129],3)~
REPLACE_ACTION_TEXT KELDOR   ~EscapeAreaMove("AR0903",1634,368,\(SWW\|3\))~ ~EscapeAreaMove("AR0903",734,368,13)~
REPLACE_ACTION_TEXT KELDORJ  ~EscapeAreaMove("AR0903",1724,501,\(S\|0\))~   ~EscapeAreaMove("AR0903",644,501,0)~
REPLACE_ACTION_TEXT KELDORJ  ~EscapeAreaMove("AR0903",637,1146,\(S\|0\))~   ~EscapeAreaMove("AR0903",1731,1146,0)~
REPLACE_ACTION_TEXT KELDORP  ~EscapeAreaMove("AR0903",1724,501,\(S\|0\))~   ~EscapeAreaMove("AR0903",644,501,0)~

// jastey's ajantis mod
REPLACE_ACTION_TEXT_REGEXP ~c#ajan[jp]?~ ~EscapeAreaMove("AR0903",1730,\([0-9]+\),0)~ ~EscapeAreaMove("AR0903",638,\1,0)~