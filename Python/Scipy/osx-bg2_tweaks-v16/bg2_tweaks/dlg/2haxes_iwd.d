
REPLACE_TRIGGER_TEXT_REGEXP ~\(^dedion$\)\|\(^dtiernon$\)~  ~PartyHasItem("young")~ ~OR(3) PartyHasItem("young") PartyHasItem("cdax34") PartyHasItem("c!ax34")~
REPLACE_ACTION_TEXT_REGEXP  ~\(^dedion$\)\|\(^dtiernon$\)~  ~\(TakeParty\|Destroy\)Item("young")~ ~\1Item("young") \1Item("cdax34") \1Item("c!ax34")~